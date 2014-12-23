/* ImageReaderNode.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef IMAGEREADERNODE_H
#define IMAGEREADERNODE_H

#include <dtkComposer/dtkComposerNodeLeafData.h>
#include <dtkCoreSupport/dtkAbstractFactory.h>
#include "Image.h"
class ImageReaderNodePrivate;

// /////////////////////////////////////////////////////////////////
// ImageReaderNode interface
// /////////////////////////////////////////////////////////////////

class ImageReaderNode : public dtkComposerNodeLeafData
{
public:
    ImageReaderNode(void);
    ~ImageReaderNode(void);

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
    ImageReaderNodePrivate *d;
};

#endif


