#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "shape.h"

class RectangleShape : public Shape
{
public:
    RectangleShape(const QPoint &start, const QPoint &end);

    void draw(QPainter &painter)const override;
};

#endif // RECTANGLESHAPE_H