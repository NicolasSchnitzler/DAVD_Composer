/* FilterProcess.cpp ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "FilterProcess.h"
#include "FilterProcess_p.h"

#include <dtkLog/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// FilterProcess implementation
// /////////////////////////////////////////////////////////////////

FilterProcess::FilterProcess(void) : dtkAbstractProcess(*new FilterProcessPrivate(this), 0)
{
    // DTK_D(FilterProcess);
}


FilterProcess::~FilterProcess(void)
{

}

int FilterProcess::update()
{
    DTK_D(FilterProcess);
    QPixmap* maskPix=dynamic_cast<QPixmap*>(d->filter);
    QPixmap* image=dynamic_cast<QPixmap*>(d->imageIn);

    QBitmap mask=maskPix->createMaskFromColor(QColor(Qt::black));
    mask=mask.scaled(image->size());

    image->setMask(mask);


    PixmapWrapper* res=new PixmapWrapper(*image);
    d->filteredImage=res;

    QLabel l;
    l.setPixmap(*res);
    l.show();

    QEventLoop el;
    QTimer::singleShot(1000,&el,SLOT(quit()));
    el.exec();

    return 0;
}

void FilterProcess::setInput(dtkAbstractData *data, int channel)
{
    DTK_D(FilterProcess);
    Image* img=dynamic_cast<Image*>(data);
    if(!img)
        return;
    switch(channel)
    {
    case 0:
        d->filter=img;
        break;

    case 1:
        d->imageIn=img;
        break;
    }
}

Image *FilterProcess::output()
{
    DTK_D(FilterProcess);
    return d->filteredImage;
}

QString FilterProcess::identifier(void) const
{
    return "FilterProcess";
}

