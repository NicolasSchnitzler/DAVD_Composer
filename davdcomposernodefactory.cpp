#include "davdcomposernodefactory.h"

DavdComposerNodeFactory::DavdComposerNodeFactory()
{
    this->record("imageReader",&dtkComposerNodeCreator<ImageReaderNode>);
    this->record("imageWriter",&dtkComposerNodeCreator<ImageWriterNode>);
    this->record("Segmentation",&dtkComposerNodeCreator<SegmentationNode>);
    this->record("Filter",&dtkComposerNodeCreator<FilterNode>);
}

DavdComposerNodeFactory::~DavdComposerNodeFactory()
{

}

