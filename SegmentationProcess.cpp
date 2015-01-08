/* SegmentationProcess.cpp ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "SegmentationProcess.h"
#include "SegmentationProcess_p.h"
#include <QApplication>
#include <dtkCreatorMainWindow.h>
#include <dtkLog/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// SegmentationProcess implementation
// /////////////////////////////////////////////////////////////////

SegmentationProcess::SegmentationProcess(void) : dtkAbstractProcess(*new SegmentationProcessPrivate(this), 0)
{
    DTK_D(SegmentationProcess);
    d->m_connected=false;

}

int SegmentationProcess::update()
{
    DTK_D(SegmentationProcess);

    qDebug()<<"update";
    PixmapWrapper* img=dynamic_cast<PixmapWrapper*> (d->image);
    if(!d->m_connected)
    {
        dtkCreatorMainWindow* mainWin=0;

        QWidgetList wl=QApplication::allWidgets();
        for(int i=0;i<wl.size();i++)
        {
            dtkCreatorMainWindow* win=0;
            win=dynamic_cast<dtkCreatorMainWindow*> (wl.at(i));
            if(win)
            {
                mainWin=win;
                break;
            }
        }
        if(mainWin)
            connect(this,SIGNAL(requestUserInput(Image*,SegmentationProcess*)),mainWin,SLOT(switchToVisu(Image*,SegmentationProcess*)));
        else
            qDebug()<<"failed to find mainWin";
        d->m_connected=true;
    }

    if(!img) return -1;
    emit requestUserInput(img,this);


    QEventLoop el;
    connect(this,SIGNAL(userInputReceived()),&el,SLOT(quit()));
    el.exec();

    if(d->m_polygon.isEmpty())
        return -1;
    //convert the polygon into a mask
    QImage maskImage(img->size(),QImage::Format_ARGB32_Premultiplied);
    maskImage.fill(Qt::black);
    QPainter painter(&maskImage);
    painter.setPen(QColor(Qt::white));
    painter.setBrush(QBrush(Qt::white));
    painter.drawPolygon(d->m_polygon);

    QBitmap* b=new QBitmap(QBitmap::fromImage(maskImage));

    d->mask=new PixmapWrapper(*b);
}

void SegmentationProcess::receiveUserData(QPolygon p)
{
    DTK_D(SegmentationProcess);
    d->m_polygon=p;
    emit userInputReceived();

}


Image *SegmentationProcess::output()
{
    DTK_D(SegmentationProcess);
    return d->mask;
}

void SegmentationProcess::setInput(Image *data)
{
    DTK_D(SegmentationProcess);
    Image* img=dynamic_cast<Image*>(data);
    if(!img)
        return;
    d->image=dynamic_cast<Image*>(data);
}

QString SegmentationProcess::identifier(void) const
{
    return "SegmentationProcess";
}

SegmentationProcess::~SegmentationProcess()
{

}

