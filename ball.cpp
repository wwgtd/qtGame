#include "Ball.h"
#include <QTimer>
#include <QBrush>
#include "Game.h"
#include "player.h"
#include "enemy.h"
#include <QDebug>

extern Game* game;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsEllipseItem(parent){
    setRect(0, 0, 15, 15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    xVelocity = 0;
    yVelocity = -10;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(15);
}

double Ball::getCenterX(){
    return x() + rect().width()/2;
}

void Ball::move(){
    reverseVelocityIfOutOfBounds();

    handlePaddleCollision();

    handleBlockCollision();

    moveBy(xVelocity,yVelocity);

    if (pos().y() > 600)
    {
        game->displayLosing();
    }


    if (game->getEnemiesAmount() < 1) {
        qDebug() << game->getEnemiesAmount();
        game->displayWinning();
    }
}

void Ball::reverseVelocityIfOutOfBounds(){
    double screenW = game->width();

    if (mapToScene(rect().topLeft()).x() <= 0){
        xVelocity = -1 * xVelocity;
    }

    if (mapToScene(rect().topRight()).x() >= screenW){
        xVelocity = -1 * xVelocity;
    }

    if (mapToScene(rect().topLeft()).y() <= 0){
        yVelocity = -1 * yVelocity;
    }

}

void Ball::handlePaddleCollision(){
    QList<QGraphicsItem *> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Player * player= dynamic_cast<Player *>(cItems[i]);
        if (player){

            yVelocity = -1 * yVelocity;

            double ballX = getCenterX();
            double paddleX = player->getCenterX();

            double dvx = ballX - paddleX;
            xVelocity = (xVelocity + dvx)/15;

            return;
        }
    }
}

void Ball::handleBlockCollision(){
    QList<QGraphicsItem *> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i) {
        Enemy * enemy = dynamic_cast<Enemy *>(cItems[i]);
        if (enemy){
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = enemy->pos().x();
            double blocky = enemy->pos().y();

            if (bally > blocky + yPad && yVelocity < 0){
                yVelocity = -1 * yVelocity;
            }

            if (blocky > bally + yPad && yVelocity > 0 ){
                yVelocity = -1 * yVelocity;
            }

            if (ballx > blockx + xPad && xVelocity < 0){
                xVelocity = -1 * xVelocity;
            }

            if (blockx > ballx + xPad && xVelocity > 0){
                xVelocity = -1 * xVelocity;
            }

            game->scene->removeItem(enemy);
            game->decreaseEnemiesAmount();

            delete enemy;
        }
    }
}
