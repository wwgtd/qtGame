#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

class Ball: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ball(QGraphicsItem* parent = 0);

    double getCenterX();

public slots:
    void move();

private:
    double xVelocity;
    double yVelocity;

    void reverseVelocityIfOutOfBounds();
    void handlePaddleCollision();
    void handleBlockCollision();
};

#endif // BALL_H
