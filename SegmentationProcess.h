/* SegmentationProcess.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef SEGMENTATIONPROCESS_H
#define SEGMENTATIONPROCESS_H

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <QBitmap>
#include "pixmapwrapper.h"
#include "drawablelabel.h"
#include "Image.h"

class SegmentationProcessPrivate;

// /////////////////////////////////////////////////////////////////
// SegmentationProcess interface
// /////////////////////////////////////////////////////////////////

class SegmentationProcess : public dtkAbstractProcess
{
    Q_OBJECT

public:
    SegmentationProcess(void);
    virtual ~SegmentationProcess(void);

public:
    QString identifier(void) const;

public slots:
    void receiveUserData(QPolygon p);

public:
    virtual int update();
    virtual Image* output();
    virtual void setInput(Image *data);

signals:
    void userInputReceived();
    void requestUserInput(Image*,SegmentationProcess*);

private:
    SegmentationProcessPrivate* d;
    DTK_DECLARE_PRIVATE(SegmentationProcess);
};

Q_DECLARE_METATYPE(SegmentationProcess)  // If your class is pure virtual, you cannot register to QMetatype.
Q_DECLARE_METATYPE(SegmentationProcess*) // Hence, you need to comment theses lines.

#endif


