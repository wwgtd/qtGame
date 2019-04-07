#include "game.h"
#include "ball.h"
#include "player.h"
#include "enemy.h"

Game::Game(QWidget *parent): QGraphicsView(parent){
    scene = new QGraphicsScene(0, 0, 800, 600);
    setScene(scene);

    setMouseTracking(true);
    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::start(){
    Ball * ball = new Ball();
    ball->setPos(200, 500);
    scene->addItem(ball);

    Player * player = new Player();
    player->setPos(150, 575);
    scene->addItem(player);
    player->grabMouse();

    createBlockGrid();
}

void Game::createBlockCol(double x){
    for (size_t i = 0, n = 5; i < n; ++i){
        Enemy * enemy = new Enemy();
        enemy->setPos(x, i * 52);
        scene->addItem(enemy);
    }
}

void Game::createBlockGrid(){
    for (size_t i = 0, n = 7; i < n; ++i){
        createBlockCol(i * 52);
    }
}
