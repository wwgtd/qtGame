#include "game.h"
#include "menubutton.h"
#include "ball.h"
#include "player.h"
#include "enemy.h"
#include <QFont>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

Game::Game(QWidget * parent): QGraphicsView(parent)
{
    _enemiesAmount = 0;
    scene = new QGraphicsScene(0, 0, 800, 600);
    setScene(scene);

    setMouseTracking(true);
    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();
    QTimer * musicRepeatTimer = new QTimer();
    QObject::connect(musicRepeatTimer, SIGNAL(timeout()), music, SLOT(play()));
    musicRepeatTimer->start(42000);
}

void Game::displayMainMenu()
{
    scene->clear();
    QGraphicsTextItem * titleText(new QGraphicsTextItem(QString("WEIRD ARKANOID")));
    QFont titleFont("sans serif", 60);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);


    MenuButton * playButton = new MenuButton(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 325;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);



    MenuButton * quitButton = new MenuButton(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 400;
    quitButton->setPos(qxPos, qyPos);
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

void Game::displayWinning()
{
    scene->clear();

    QGraphicsTextItem * titleText(new QGraphicsTextItem(QString("YOU HAVE WON")));
    QFont titleFont("sans serif", 60);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 200;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);


    QTimer::singleShot(1500, this, SLOT(displayMainMenu()));

}

void Game::displayLosing()
{
  /*  scene->clear();

    QGraphicsTextItem * titleText(new QGraphicsTextItem(QString("YOU HAVE LOST")));
    QFont titleFont("sans serif", 60);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 200;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);
*/
    scene->clear();

    QGraphicsPixmapItem * image = new QGraphicsPixmapItem(QPixmap(":/images/memeLoseCat.jpg"));
    scene->addItem(image);
    image->setPos(this->width()/2 - 200, 40);

    QTimer::singleShot(1500, this, SLOT(start()));

}

void Game::start(){
    scene->clear();

    _enemiesAmount = 0;

    Ball * ball = new Ball();
    ball->setPos(395, 500);
    scene->addItem(ball);

    Player * player = new Player();
    player->setPos(350, 575);
    scene->addItem(player);
    player->grabMouse();

    createBlockGrid();
}

void Game::createBlockCol(double x, size_t amount){
    for (size_t i = 0; i < amount; ++i){
        Enemy * enemy = new Enemy();
        enemy->setPos(x, i * 27);
        scene->addItem(enemy);
        _enemiesAmount++;
    }
}

void Game::createBlockGrid(){
    size_t i = 0;
    for (size_t n = 8, amount = 1; i < n; ++i, amount++){
        createBlockCol(i * 53, amount);
    }

    for (size_t n = 15, amount = 7; i < n; ++i, amount--){
        createBlockCol(i * 53, amount);
    }

 // for testing   createBlockCol(400, 2);
}

void Game::decreaseEnemiesAmount()
{
    _enemiesAmount--;
}

int Game::getEnemiesAmount()
{
    return _enemiesAmount;
}
