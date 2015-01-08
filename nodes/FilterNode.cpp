/* FilterNode.cpp ---
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

#include "FilterNode.h"
#include "FilterProcess.h"

// /////////////////////////////////////////////////////////////////
// FilterNodePrivate interface
// /////////////////////////////////////////////////////////////////

class FilterNodePrivate
{
public:
    /*
      Here one must declare the pointer to the process that is wrapped by
      the node.
    */
    FilterProcess *process;

public:

      dtkComposerTransmitterReceiver<Image*> imageReceiver;
      dtkComposerTransmitterReceiver<Image*> maskReceiver;


public:

      dtkComposerTransmitterEmitter<Image*> imageEmitter;

};

// /////////////////////////////////////////////////////////////////
// FilterNode implementation
// /////////////////////////////////////////////////////////////////

//! Node constructor



FilterNode::FilterNode(void) : dtkComposerNodeLeafProcess(), d(new FilterNodePrivate)
{
    this->appendReceiver(&(d->imageReceiver));
    this->appendReceiver(&(d->maskReceiver));

    this->appendEmitter(&(d->imageEmitter));
    d->process = new FilterProcess();
}

//! Node destructor
FilterNode::~FilterNode(void)
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
QString FilterNode::type(void)
{
    return "Filter";
}

//! Returns the title of the node that appears in the composer GUI.
QString FilterNode::titleHint(void)
{
    return "FilterProcess";
}

//! Returns the name of the input identified by its index \a port.
QString FilterNode::inputLabelHint(int port)
{

    switch (port) {
    case 0:
        return "image";
    case 1:
        return "mask";
    default:
        return dtkComposerNodeLeaf::inputLabelHint(port);
    }

}

//! Returns the name of the output identified by its index \a port.
QString FilterNode::outputLabelHint(int port)
{
        return port==0?"image":dtkComposerNodeLeaf::outputLabelHint(port);
}

//! Return true if the wrapped process is abstract.
bool FilterNode::isAbstractProcess(void) const
{
    return false;
}

//! Returns identifier of the wrapped process.
QString FilterNode::abstractProcessType(void) const
{
    return "FilterProcess";
}

void FilterNode::setProcess(dtkAbstractProcess *process)
{
    d->process = dynamic_cast<FilterProcess *>(process);
}

dtkAbstractProcess *FilterNode::process(void) const
{
    return d->process;
}

//! Executes the logic of the node.
void FilterNode::run(void)
{
    qDebug()<<"filterNode";
    if (d->imageReceiver.isEmpty()||d->maskReceiver.isEmpty())
    {

        qDebug() << Q_FUNC_INFO << "No data, abort:"<< this->currentImplementation();
        return;
    }

    if (!d->process)
    {
        qDebug() << Q_FUNC_INFO << "No process instanciated, abort:"<< this->currentImplementation();
        d->imageEmitter.clearData();
        return;
    }
    Image* img= d->imageReceiver.data();
    Image* mask=d->maskReceiver.data();

    qDebug()<<"filterNode received all its data";
    d->process->setInput(mask,0);
    d->process->setInput(img,1);
    d->process->update();
    qDebug()<<"returned from process";
    d->imageEmitter.setData(d->process->output());

}

