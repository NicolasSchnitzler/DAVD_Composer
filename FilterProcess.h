/* FilterProcess.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef FILTERPROCESS_H
#define FILTERPROCESS_H

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include "FilterProcess.h"
#include <QEventLoop>
#include <QLabel>
#include <QBitmap>
#include "Image.h"
#include "pixmapwrapper.h"

class FilterProcessPrivate;

// /////////////////////////////////////////////////////////////////
// FilterProcess interface
// /////////////////////////////////////////////////////////////////

class  FilterProcess : public dtkAbstractProcess
{
    Q_OBJECT

public:
    FilterProcess(void);
    virtual ~FilterProcess(void);

    virtual QString identifier(void) const ;
    Image* output();
    virtual int update();
    void setInput(dtkAbstractData*,int);


private:
    FilterProcessPrivate* d;
    DTK_DECLARE_PRIVATE(FilterProcess);
};

Q_DECLARE_METATYPE(FilterProcess)  // If your class is pure virtual, you cannot register to QMetatype.
Q_DECLARE_METATYPE(FilterProcess*) // Hence, you need to comment theses lines.

#endif


