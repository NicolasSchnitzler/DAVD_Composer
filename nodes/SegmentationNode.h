/* SegmentationNode.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef SEGMENTATIONNODE_H
#define SEGMENTATIONNODE_H

#include <dtkComposerSupport/dtkComposerNodeLeafProcess.h>
#include "SegmentationProcess.h"
#include "Image.h"

class SegmentationNodePrivate;

// /////////////////////////////////////////////////////////////////
// SegmentationNode interface
// /////////////////////////////////////////////////////////////////

class SegmentationNode : public dtkComposerNodeLeafProcess
{
public:
    SegmentationNode(void);
    ~SegmentationNode(void);

public:
    QString type(void);
    QString titleHint(void);

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

public:
    bool isAbstractProcess(void) const;

    QString abstractProcessType(void) const;

public:
    void setProcess(dtkAbstractProcess *process);

    dtkAbstractProcess *process(void) const;

public:
    void run(void);


private:
    SegmentationNodePrivate *d;
};

#endif


