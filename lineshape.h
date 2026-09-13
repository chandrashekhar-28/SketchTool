#ifndef LINESHAPE_H
#define LINESHAPE_H

#include "shape.h"

class LineShape : public Shape
{
public:
    LineShape(const QPoint &start, const QPoint &end);

    void draw(QPainter &painter)const override;
};

#endif // LINESHAPE_H
