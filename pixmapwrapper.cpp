#include "pixmapwrapper.h"

PixmapWrapper::PixmapWrapper()
{
}

PixmapWrapper::PixmapWrapper(const QString& file) : QPixmap (file)
{

}

PixmapWrapper::PixmapWrapper(QPixmap pix): QPixmap(pix)
{

}

PixmapWrapper::PixmapWrapper(const PixmapWrapper& pix) : QPixmap(((QPixmap)(pix)).copy()),Image(pix)
{

}


PixmapWrapper::~PixmapWrapper()
{

}

