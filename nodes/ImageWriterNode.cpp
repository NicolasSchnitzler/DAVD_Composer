/* ImageWriterNode.cpp ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include <dtkComposerSupport/dtkComposerTransmitterEmitter.h>
#include <dtkComposerSupport/dtkComposerTransmitterReceiver.h>

#include <dtkLog/dtkLog.h>

#include "ImageWriterNode.h"

// /////////////////////////////////////////////////////////////////
// ImageWriterNodePrivate interface
// /////////////////////////////////////////////////////////////////

class ImageWriterNodePrivate
{
public:
      dtkComposerTransmitterReceiver<Image> receiver;
      Image *data;
};

// /////////////////////////////////////////////////////////////////
// ImageWriterNode implementation
// /////////////////////////////////////////////////////////////////

//! Node constructor
/*
    Here the declared receivers must be appended to the current
    node.

    \code
    this->appendReceiver(&(d->receiver_vector));
    this->appendReceiver(&(d->receiver_data_array));
    \endcode

    Then the declared emitters must be appended to the current
    node.

    \code
    this->appendEmitter(&(d->emitter_data));
    this->appendEmitter(&(d->emitter_scalar_array));
    \endcode

    Do not forget to set the any pointers to NULL.

    \code
    d->data = NULL;
    \endcode
 */
ImageWriterNode::ImageWriterNode(void) : dtkComposerNodeLeafData(), d(new ImageWriterNodePrivate)
{
    this->appendReceiver(&(d->receiver));
    d->data = NULL;

}

//! Node destructor
/*
    If the node is the owner of the wrapped data, one must delete the
    related pointer as follows:

    \code

    \endcode
 */
ImageWriterNode::~ImageWriterNode(void)
{

    if (d->data)
            delete d->data;
    delete d;

        d->data = NULL;NULL;
}

//! Returns the string that enables the node factory to identify the
//! node.
/*
    By convention, this string is the name of the node class.
 */
QString ImageWriterNode::type(void)
{
    return "ImageWriter";
}

//! Returns the title of the node that appears in the composer GUI.
/*
    The title should indicates the kind of data that it wraps.
 */
QString ImageWriterNode::titleHint(void)
{
    return "Image";
}

//! Returns the name of the input identified by its index \a port.
/*

 */
QString ImageWriterNode::inputLabelHint(int port)
{
        return port==0 ? "image": dtkComposerNodeLeaf::inputLabelHint(port);
}

//! Returns the name of the output identified by its index \a port.

QString ImageWriterNode::outputLabelHint(int port)
{   
        return dtkComposerNodeLeaf::outputLabelHint(port);
}

//! Return true if the wrapped data is abstract, that is if there are
//! likely plugins that implement this data.
/*

 */
bool ImageWriterNode::isAbstractData(void) const
{
   return true;
}

//! Returns identifier of the wrapped data.
/*

 */
QString ImageWriterNode::abstractDataType(void) const
{
    return "Image";
}

//! Executes the logic of the node.
/*
    Firstly, one checks that the required receivers are all connected.
    Secondly, one retrieves the data from these receivers. Thirdly, if
    the wrapped data is abstract, one has to instanciate it using
    following code:

    \code
    if (this->implementationHasChanged())
        d->data = reinterpret_cast<Image*>(this->data());
    \endcode

    After these first steps, one can set the input of the data, update
    it and then set the emitters using data outputs.
 */
void ImageWriterNode::run(void)
{
    qDebug()<<"ImageWriter";
    if (d->receiver.isEmpty())
    {
        qDebug() << Q_FUNC_INFO << "No data, abort:"<< this->currentImplementation();
        return;
    }

    Image* img= d->receiver.data();
    QPixmap* pix=dynamic_cast<QPixmap*>(img);
    pix->save("/user/nschnitz/home/Pictures/save.png");


}

