#ifndef INTERCATIVECOMPOSERNODE_H
#define INTERCATIVECOMPOSERNODE_H

#include <QObject>
#include <dtkComposerSupport/dtkComposerNodeLeafProcess>

class InteractiveComposerNode : public QObject,public dtkComposerNodeLeafProcess
{
    Q_OBJECT;
public:
    InteractiveComposerNode();
    ~InteractiveComposerNode();
};

#endif // INTERCATIVECOMPOSERNODE_H
