/* SegmentationNode.cpp ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include <dtkComposer/dtkComposerTransmitterEmitter.h>
#include <dtkComposer/dtkComposerTransmitterReceiver.h>

#include <dtkLog/dtkLog.h>

#include "SegmentationNode.h"

// /////////////////////////////////////////////////////////////////
// SegmentationNodePrivate interface
// /////////////////////////////////////////////////////////////////

class SegmentationNodePrivate
{
public:
    SegmentationProcess *process;

public:
    dtkComposerTransmitterReceiver<Image*> receiver;
    dtkComposerTransmitterEmitter<Image*> emitter;

};

// /////////////////////////////////////////////////////////////////
// SegmentationNode implementation
// /////////////////////////////////////////////////////////////////

SegmentationNode::SegmentationNode(void) : dtkComposerNodeLeafProcess(), d(new SegmentationNodePrivate)
{
    this->appendReceiver(&(d->receiver));
    this->appendEmitter(&(d->emitter));
    d->process = new SegmentationProcess();
}

SegmentationNode::~SegmentationNode(void)
{
    this->clearProcess();

    if (d->process)
        delete d->process;
    d->process = NULL;
    delete d;

    d = NULL;
}

//! Returns the string that enables the node factory to identify the
//! node.
/*
    By convention, this string is the name of the node class minus the
    root part "ComposerNode".
 */
QString SegmentationNode::type(void)
{
    return "Segmentation"; // Do not forget to remove "ComposerNode" from type name.
}

//! Returns the title of the node that appears in the composer GUI.
QString SegmentationNode::titleHint(void)
{
    return "Segmentation";
}

//! Returns the name of the input identified by its index \a port.
QString SegmentationNode::inputLabelHint(int port)
{

    return port==0 ? "image":dtkComposerNodeLeaf::inputLabelHint(port);

}

//! Returns the name of the output identified by its index \a port.
QString SegmentationNode::outputLabelHint(int port)
{
    return port==0? "mask":dtkComposerNodeLeaf::outputLabelHint(port);
}

//! Return true if the wrapped process is abstract.
bool SegmentationNode::isAbstractProcess(void) const
{
    return false;
}

//! Returns identifier of the wrapped process.
QString SegmentationNode::abstractProcessType(void) const
{
    return "Segmentation";
}

void SegmentationNode::setProcess(dtkAbstractProcess *process)
{
    d->process = dynamic_cast<SegmentationProcess *>(process);
}

dtkAbstractProcess *SegmentationNode::process(void) const
{
    return d->process;
}

//! Executes the logic of the node.
void SegmentationNode::run(void)
{
    if (d->receiver.isEmpty())
    {

        qDebug() << Q_FUNC_INFO << "No data, abort:"<< this->currentImplementation();
        return;
    }

    if (!d->process)
    {
        qDebug() << Q_FUNC_INFO << "No process instanciated, abort:"<< this->currentImplementation();
        d->emitter.clearData();
        return;
    }
    Image* img= d->receiver.data();

    d->process->setInput(img);
    d->process->update();
    d->emitter.setData(d->process->output());


}

