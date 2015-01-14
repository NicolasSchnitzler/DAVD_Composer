/* ImageWriterNode.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef IMAGEWRITERNODE_H
#define IMAGEWRITERNODE_H

#include <dtkComposerSupport/dtkComposerNodeLeafData.h>
#include <QPixmap>
#include "Image.h"

class ImageWriterNodePrivate;

// /////////////////////////////////////////////////////////////////
// ImageWriterNode interface
// /////////////////////////////////////////////////////////////////

class ImageWriterNode : public dtkComposerNodeLeafData
{
public:
    ImageWriterNode(void);
    ~ImageWriterNode(void);

public:
    QString type(void);
    QString titleHint(void);

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

public:
    bool isAbstractData(void) const;

    QString abstractDataType(void) const;

public:
    void run(void);

private:
    ImageWriterNodePrivate *d;
};

#endif


