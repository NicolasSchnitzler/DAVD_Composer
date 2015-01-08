#ifndef PIXMAPREADERCLASS_H
#define PIXMAPREADERCLASS_H

#include <QString>
#include <QStringList>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include "pixmapwrapper.h"
class PixmapReaderClass : public dtkAbstractDataReader
{
public:
    PixmapReaderClass();
    ~PixmapReaderClass();
    virtual QString description() const { return "Reader for QPixmap";              }
     virtual QString identifier() const { return "PixmapReaderClass";              }
     virtual QStringList handled() const { QStringList s; s<<"QPixmap"<<"PixmapWrapper"; return s; }

     static bool initialize() {
          QStringList s; s<<"QPixmap"<<"PixmapWrapper";
         return dtkAbstractDataFactory::instance()->registerDataReaderType("PixmapReaderClass",s,create);
     }

     static dtkAbstractDataReader* create() { return new PixmapReaderClass(); }

 public slots:

     virtual bool canRead(const QString& file) {return true;}

     virtual bool read(const QString& file);

private:
    PixmapWrapper *m_pix;

};

#endif // PIXMAPREADERCLASS_H
