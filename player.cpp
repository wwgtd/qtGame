#include "player.h"
#include <QBrush>

Player::Player(QGraphicsItem * parent) : QGraphicsRectItem (parent){
    setRect(0, 0, 100, 15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}

double Player::getCenterX(){
    return x() + rect().width()/2;
}

void Player::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (mapToScene(event->pos()).x() < 800 - this->rect().width() && mapToScene(event->pos()).x() > 0) {
        double mouseX = mapToScene(event->pos()).x();
        setPos(mouseX, y());
    }
}
