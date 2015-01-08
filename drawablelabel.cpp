#include "drawablelabel.h"

DrawableLabel::DrawableLabel(Image* img)
{
    m_image=img;
    PixmapWrapper* pix=dynamic_cast<PixmapWrapper*> (img);
    if(pix)
        this->setPixmap(*pix);
}

DrawableLabel::~DrawableLabel()
{

}


void DrawableLabel::mouseReleaseEvent(QMouseEvent* evt)
{
    m_points.append(QPoint(evt->x(),evt->y()));
    repaint();
}

void DrawableLabel::paintEvent ( QPaintEvent * evt)
{
    QLabel::paintEvent(evt);
    QPainter painter(this);
    for(int i=0;i<m_points.size();i++)
    {
        painter.drawLine(m_points[i].x()-3,m_points[i].y(),m_points[i].x()+3,m_points[i].y());
        painter.drawLine(m_points[i].x(),m_points[i].y()-3,m_points[i].x(),m_points[i].y()+3);
    }
    painter.drawPolygon(QPolygon(m_points));
}

void DrawableLabel::keyPressEvent ( QKeyEvent * evt)
{
    if(evt->key()==Qt::Key_Return || evt->key()==Qt::Key_Enter)
    {
        emit done(QPolygon(m_points));
    }
    else if(evt->key()==Qt::Key_Backspace)
    {
        if(m_points.size()>0)
        {
            m_points.removeLast();
            repaint();
        }
    }
}
