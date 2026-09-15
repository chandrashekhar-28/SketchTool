#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPoint>
#include <QJsonObject>

enum class ShapeType {
    Line,
    Rectangle,
    Circle
};

class Shape
{
public:
    Shape(ShapeType type, const QPoint &start, const QPoint &end);
    virtual ~Shape();

    virtual void draw(QPainter &painter) const = 0;

    ShapeType type() const;
    QJsonObject toJson() const;

protected:
    ShapeType shapeType;
    QPoint startPoint;
    QPoint endPoint;
};

#endif // SHAPE_H