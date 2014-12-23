/* FilterNode.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef FILTERNODE_H
#define FILTERNODE_H

#include <dtkComposer/dtkComposerNodeLeafProcess.h>

class FilterNodePrivate;

// /////////////////////////////////////////////////////////////////
// FilterNode interface
// /////////////////////////////////////////////////////////////////

class FilterNode : public dtkComposerNodeLeafProcess
{
public:
    FilterNode(void);
    ~FilterNode(void);

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
    FilterNodePrivate *d;
};

#endif


