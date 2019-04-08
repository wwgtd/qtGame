#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent = 0);
\
    void displayWinning();
    void displayLosing();

    void decreaseEnemiesAmount();
    int getEnemiesAmount();


    void createBlockCol(double x, size_t amount);
    void createBlockGrid();

    QGraphicsScene * scene;

public slots:
    void start();
    void displayMainMenu();


private:
    int _enemiesAmount;
};

#endif // GAME_H
