#ifndef PIXMAPWRAPPER_H
#define PIXMAPWRAPPER_H

#include "Image.h"
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

class PixmapWrapper : public Image,public QPixmap
{
    Q_OBJECT
public:
    PixmapWrapper();
    PixmapWrapper(const QString &file);
    PixmapWrapper(const PixmapWrapper& pix);
    PixmapWrapper(QPixmap pix);
    //virtual void copy(const dtkAbstractObject& other);
    ~PixmapWrapper();


};

#endif // PIXMAPWRAPPER_H
