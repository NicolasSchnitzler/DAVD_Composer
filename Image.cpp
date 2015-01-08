/* Image.cpp ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "Image.h"
#include "Image_p.h"

#include <dtkLog/dtkLog.h>

Image::Image(): dtkAbstractData()
{
    //DTK_D(Image);

}

Image::Image(dtkAbstractData &img):dtkAbstractData(img)
{
    qDebug()<<"copy constructor";
    this->copy(img);
}

Image::~Image()
{

}

//! Returns Class name.
/*!
 *
 */
QString Image::identifier(void) const
{
    return "Image";
}

void Image::copy(const dtkAbstractObject& other)
{
    qDebug()<<"clone";
    dtkAbstractData::copy(other);

}
