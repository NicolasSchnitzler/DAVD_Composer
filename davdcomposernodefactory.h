#ifndef DAVDCOMPOSERNODEFACTORY_H
#define DAVDCOMPOSERNODEFACTORY_H

#include <dtkComposerSupport/dtkComposerFactory.h>
#include <QWidget>
#include <dtkCreatorMainWindow.h>
#include "nodes/ImageReaderNode.h"
#include "nodes/ImageWriterNode.h"
#include "nodes/SegmentationNode.h"
#include "nodes/FilterNode.h"

class DavdComposerNodeFactory : public dtkComposerFactory
{
public:
    DavdComposerNodeFactory(dtkCreatorMainWindow* mainWin=0);
    ~DavdComposerNodeFactory();

    void setMainWindow(dtkCreatorMainWindow* mainWin) {m_mainWindow=mainWin;}
    virtual dtkComposerNode* create(const QString& type);
    

virtual QList<QString> nodes(void){return m_nodes;}
virtual QHash<QString, QString> descriptions(void){return m_descriptions;}
virtual QHash<QString, QStringList> tags(void){return m_tags;}
virtual QHash<QString, QString> types(void){return m_types;}

private:
    dtkCreatorMainWindow* m_mainWindow;
    QList<QString> m_nodes;
    QHash<QString, QString> m_descriptions;
    QHash<QString, QStringList> m_tags;
    QHash<QString, QString> m_types;
};



#endif // DAVDCOMPOSERNODEFACTORY_H
