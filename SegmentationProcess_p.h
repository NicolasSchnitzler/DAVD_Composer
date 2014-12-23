/* SegmentationProcess_p.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef SEGMENTATIONPROCESS_P_H
#define SEGMENTATIONPROCESS_P_H


#include <dtkCoreSupport/dtkAbstractProcess_p.h>

class SegmentationProcess;

////////////////////////////////////////////////////
// SegmentationProcessPrivate interface
////////////////////////////////////////////////////

class SegmentationProcessPrivate : public dtkAbstractProcessPrivate
{
public:
    SegmentationProcessPrivate(SegmentationProcess *q = 0) : dtkAbstractProcessPrivate(q) {}
    SegmentationProcessPrivate(const SegmentationProcessPrivate& other) : dtkAbstractProcessPrivate(other) {}

public:
    virtual ~SegmentationProcessPrivate(void) {}

public:
    Image* image;
    Image* mask;
};

////////////////////////////////////////////////////
// SegmentationProcess protected constructors
////////////////////////////////////////////////////

DTK_IMPLEMENT_PRIVATE(SegmentationProcess, dtkAbstractProcess);

#endif

