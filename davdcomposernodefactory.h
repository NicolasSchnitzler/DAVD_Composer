#ifndef DAVDCOMPOSERNODEFACTORY_H
#define DAVDCOMPOSERNODEFACTORY_H

#include <dtkComposer/dtkComposerNodeFactory.h>
#include <QWidget>
#include <dtkCreatorMainWindow.h>
#include "nodes/ImageReaderNode.h"
#include "nodes/ImageWriterNode.h"
#include "nodes/SegmentationNode.h"
#include "nodes/FilterNode.h"

class DavdComposerNodeFactory : public dtkComposerNodeFactory
{
public:
    DavdComposerNodeFactory(dtkCreatorMainWindow* mainWin=0);
    ~DavdComposerNodeFactory();

    void setMainWindow(dtkCreatorMainWindow* mainWin) {m_mainWindow=mainWin;}

private:
    dtkCreatorMainWindow* m_mainWindow;
};



#endif // DAVDCOMPOSERNODEFACTORY_H
