#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class MenuButton : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MenuButton(QString textValue, QGraphicsItem * parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

signals:
    void clicked();
private:
    QGraphicsTextItem * text;
};

#endif // MENUBUTTON_H
