#ifndef DRAWABLELABEL_H
#define DRAWABLELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QVector>

#include "Image.h"
#include "pixmapwrapper.h"

class DrawableLabel : public QLabel
{
    Q_OBJECT;
public:
    DrawableLabel(Image* immg);
    ~DrawableLabel();

signals:
    void done(QPolygon);

protected:
    Image* m_image;
    QVector<QPoint> m_points;

    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void paintEvent ( QPaintEvent * evt);
    virtual void keyPressEvent ( QKeyEvent * evt );
};

#endif // DRAWABLELABEL_H
