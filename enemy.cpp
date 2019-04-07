#include "enemy.h"
#include <QBrush>

Enemy::Enemy(QGraphicsItem * parent): QGraphicsRectItem(parent){
    setRect(0, 0, 50, 25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
