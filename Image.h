/* Image.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractFactory.h>

class ImagePrivate;

// /////////////////////////////////////////////////////////////////
// Image interface
// /////////////////////////////////////////////////////////////////

class Image : public dtkAbstractData
{
    Q_OBJECT

public:
    Image(void);
    Image(dtkAbstractData &img);
    virtual ~Image(void);


public:
    QString identifier(void) const;
    virtual void copy(const dtkAbstractObject& other);


private:
    DTK_DECLARE_PRIVATE(Image);
};

Q_DECLARE_METATYPE(Image)  // If your class is pure virtual, you cannot register to QMetatype.
Q_DECLARE_METATYPE(Image*) // Hence, you need to comment theses lines.

#endif


