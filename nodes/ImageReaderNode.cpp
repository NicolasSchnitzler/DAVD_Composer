/* ImageReaderNode.cpp ---
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
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <dtkLog/dtkLog.h>
#include "ImageReaderNode.h"
#include "drawablelabel.h"
#include "pixmapreaderclass.h"

#include <QLabel>

// /////////////////////////////////////////////////////////////////
// ImageReaderNodePrivate interface
// /////////////////////////////////////////////////////////////////

class ImageReaderNodePrivate
{
public:
    /*
      no input
    */

public:


      dtkComposerTransmitterEmitter<Image*> emitter_data;


public:
    /*
      Here one must declare the pointer to the data that is wrapped by
      the node. Uncomment the following line if necessary.*/

      Image *image;

};

// /////////////////////////////////////////////////////////////////
// ImageReaderNode implementation
// /////////////////////////////////////////////////////////////////


ImageReaderNode::ImageReaderNode(void) : dtkComposerNodeLeafData(), d(new ImageReaderNodePrivate)
{
    //! Node constructor
    /*
        Here the declared receivers must be appended to the current
        node.


        Then the declared emitters must be appended to the current
        node.*/

        this->appendEmitter(&(d->emitter_data));


        //Do not forget to set the any pointers to NULL.

    d->image=NULL;

}

//! Node destructor
/*
    If the node is the owner of the wrapped data, one must delete the
    related pointer as follows:*/


ImageReaderNode::~ImageReaderNode(void)
{
    if (d->image)
        delete d->image;
    d->image = NULL;
}

//! Returns the string that enables the node factory to identify the
//! node.
/*
    By convention, this string is the name of the node class.
 */
QString ImageReaderNode::type(void)
{
    return "ImageReader";
}

//! Returns the title of the node that appears in the composer GUI.
/*
    The title should indicates the kind of data that it wraps.
 */
QString ImageReaderNode::titleHint(void)
{
    return "ImageReader";
}

//! Returns the name of the input identified by its index \a port.
/*

 */
QString ImageReaderNode::inputLabelHint(int port)
{
    return dtkComposerNodeLeaf::inputLabelHint(port);
}

//! Returns the name of the output identified by its index \a port.
/*

 */
QString ImageReaderNode::outputLabelHint(int port)
{
    return port==0 ? "image" :dtkComposerNodeLeaf::outputLabelHint(port);
}

//! Return true if the wrapped data is abstract, that is if there are
//! likely plugins that implement this data.
/*

 */
bool ImageReaderNode::isAbstractData(void) const
{

    return true;
}

//! Returns identifier of the wrapped data.
/*

 */
QString ImageReaderNode::abstractDataType(void) const
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
        d->data = reinterpret_cast<ImageReader*>(this->data());
    \endcode

    After these first steps, one can set the input of the data, update
    it and then set the emitters using data outputs.
 */
void ImageReaderNode::run(void)
{
    QString path="/user/nschnitz/home/Pictures/med.png";
    d->image=NULL;
    PixmapWrapper* pix=new PixmapWrapper(path);
    d->image=pix;


    d->image->update();



    d->emitter_data.setData(d->image);

}


