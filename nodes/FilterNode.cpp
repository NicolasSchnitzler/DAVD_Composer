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
    d->process = NULL;
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
    //  Here is a sample of what can be the logic of a process node. (You
    //  can erase it of course ;-) !)

    /*
    if (!d->receiver_index.isEmpty() && !d->receiver_vector.isEmpty() && !d->receiver_process_array.isEmpty()) {

        if (!d->process) {
            dtkWarn() << Q_FUNC_INFO << "No process instanciated, abort:"<< this->currentImplementation();
            d->emitter_data.clearData();
            d->emitter_scalar_array.clearData();
            return;
        }

        qlonglong index = *d->receiver_index.process();
        dtkVectorReal *vector = d->receiver_vector.process();
        dtkContainerVector<dtkAbstractProcess*> *process_array = d->receiver_process_array.process();

        d->process->setParamater(index, 0);

        for(int i = 0; i < vector->size(); ++i)
            d->process->setParamater(*vector[i], i+1);

        d->process->setData(process_array->first());

        d->process->update();

        d->emitter_process.setData(d->process->output());
        d->emitter_scalar_array.setProcess(reinterpret_cast<dtkContainerVector<qreal> *>(d->process->data()));

    } else {
        dtkWarn() << Q_FUNC_INFO << "The input are not all set. Nothing is done.";
        d->emitter_data.clearData();
        d->emitter_scalar_array.clearData();
        return;
    }
    */
}

