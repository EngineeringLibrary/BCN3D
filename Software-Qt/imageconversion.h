#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include <QImage>
#include <QColor>

#include "rgbimage.h"

namespace ImageProcessing
{
    template <typename Type>
    QImage RGBImage2QImage(
    const ImageProcessing::RGBImage<Type> &rgbImg);

    template <typename Type>
    ImageProcessing::RGBImage<Type> QImage2RGBImage(const QImage &img);

}

#include "imageconversion.hpp"
#endif // IMAGECONVERSION_H
