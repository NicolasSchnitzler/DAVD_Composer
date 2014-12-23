/* Image_p.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef IMAGE_P_H
#define IMAGE_P_H

#include <dtkCoreSupport/dtkAbstractData_p.h>

class Image;

////////////////////////////////////////////////////
// ImagePrivate interface
////////////////////////////////////////////////////

class ImagePrivate : public dtkAbstractDataPrivate
{
public:
    ImagePrivate(Image *q = 0) : dtkAbstractDataPrivate(q) {}
    ImagePrivate(const ImagePrivate& other) : dtkAbstractDataPrivate(other) {}

public:
    virtual ~ImagePrivate(void) {}

public:
    // private members of the class are put here in the d-pointer, eg
    // int index;
};

////////////////////////////////////////////////////
// Image protected constructors
////////////////////////////////////////////////////

DTK_IMPLEMENT_PRIVATE(Image, dtkAbstractData)

#endif

