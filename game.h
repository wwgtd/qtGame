#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView {
public:
    Game(QWidget* parent = 0);

    void start();
    void createBlockCol(double x);
    void createBlockGrid();
    QGraphicsScene * scene;

};

#endif // GAME_H
