#include "davdcomposernodefactory.h"

DavdComposerNodeFactory::DavdComposerNodeFactory(dtkCreatorMainWindow* mainWin)
{
    /*this->record("imageReader",&dtkComposerNodeCreator<ImageReaderNode>);
    this->record("imageWriter",&dtkComposerNodeCreator<ImageWriterNode>);
    this->record("Segmentation",&dtkComposerNodeCreator<SegmentationNode>);
    this->record("Filter",&dtkComposerNodeCreator<FilterNode>);*/

    // Initialize attributes on super class

    m_nodes = QList<QString>(dtkComposerFactory::nodes());
    m_descriptions = QHash<QString, QString>(dtkComposerFactory::descriptions());
    // m_tags = QHash<QString, QStringList>(dtkComposerFactory::tags());
    m_types = QHash<QString, QString>(dtkComposerFactory::types());

    // Extend attributes

    m_nodes << "Segmentation";
    m_descriptions["Segmentation"] = "<p>Segmentation</p>";
    m_tags["Segmentation"] = QStringList() << "Segmentation";
    m_types["Segmentation"] = "Segmentation";
    
    
    m_nodes << "ImageReader";
    m_descriptions["ImageReader"] = "<p>ImageReader</p>";
    m_tags["ImageReader"] = QStringList() << "ImageReader";
    m_types["ImageReader"] = "ImageReader";
    
    m_nodes << "ImageWriter";
    m_descriptions["ImageWriter"] = "<p>ImageWriter</p>";
    m_tags["ImageWriter"] = QStringList() << "ImageWriter";
    m_types["ImageWriter"] = "ImageWriter";
    
    m_nodes << "Filter";
    m_descriptions["Filter"] = "<p>Filter</p>";
    m_tags["Filter"] = QStringList() << "Filter";
    m_types["Filter"] = "Filter";
        
}


dtkComposerNode *DavdComposerNodeFactory::create(const QString& type)
{
    if(type == "Segmentation")
        return new SegmentationNode();
    if(type == "ImageReader")
        return new ImageReaderNode();
    if(type == "ImageWriter")
        return new ImageWriterNode();
    if(type == "Filter")
        return new FilterNode();

    return dtkComposerFactory::create(type);
}

DavdComposerNodeFactory::~DavdComposerNodeFactory()
{

}

