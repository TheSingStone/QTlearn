#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsItem>

class food : public QGraphicsItem
{
public:
    food(qreal x, qreal y);

    QRectF boundingRect() const;
    void
};

#endif // FOOD_H
