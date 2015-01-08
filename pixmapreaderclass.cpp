#include "pixmapreaderclass.h"
#include <QLabel>
#include <QEventLoop>

class PixmapReaderPrivate
{
public:
    // Class variables go here.
};

PixmapReaderClass::PixmapReaderClass():dtkAbstractDataReader()
{
    m_pix=new PixmapWrapper();
    setData(m_pix);

}

PixmapReaderClass::~PixmapReaderClass()
{

}

bool PixmapReaderClass::read(const QString &file)
{
    m_pix->load(file);
    QLabel* l=new QLabel;
    l->setPixmap(*m_pix);
    l->show();
    //setData(m_pix);
    dtkAbstractData* test=NULL;
    test=data();
    qDebug()<<(void*)m_pix<<" "<<(void*)(data());
    QEventLoop el;
    QTimer::singleShot(1000,&el,SLOT(quit()));
    el.exec();
    return true;
}

