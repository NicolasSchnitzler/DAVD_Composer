#ifndef DAVDCOMPOSERNODEFACTORY_H
#define DAVDCOMPOSERNODEFACTORY_H

#include <dtkComposer/dtkComposerNodeFactory.h>
#include "nodes/ImageReaderNode.h"
#include "nodes/ImageWriterNode.h"
#include "nodes/SegmentationNode.h"
#include "nodes/FilterNode.h"

class DavdComposerNodeFactory : public dtkComposerNodeFactory
{
public:
    DavdComposerNodeFactory();
    ~DavdComposerNodeFactory();
};

#endif // DAVDCOMPOSERNODEFACTORY_H
