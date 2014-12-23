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

#include <dtkLog/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// SegmentationProcess implementation
// /////////////////////////////////////////////////////////////////

SegmentationProcess::SegmentationProcess(void) : dtkAbstractProcess(*new SegmentationProcessPrivate(this), 0)
{
    DTK_D(SegmentationProcess);
}

void SegmentationProcess::run()
{

}

Image *SegmentationProcess::output()
{
    return d->mask;
}

QString SegmentationProcess::identifier(void) const
{
    return "SegmentationProcess";
}

SegmentationProcess::~SegmentationProcess()
{

}

