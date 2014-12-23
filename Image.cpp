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
{}

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

