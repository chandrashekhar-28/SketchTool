#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPoint>

class Shape
{
public:
    Shape(const QPoint &start, const QPoint &end);
    virtual ~Shape();

    virtual void draw(QPainter &painter) const = 0;

protected:
    QPoint startPoint;
    QPoint endPoint;
};

#endif // SHAPE_H