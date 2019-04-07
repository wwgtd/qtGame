#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Player: public QGraphicsRectItem {
public:
    Player(QGraphicsItem * parent = 0);

    double getCenterX();

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
};

#endif // PLAYER_H
