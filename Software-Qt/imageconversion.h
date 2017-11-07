#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include <QImage>
#include <QColor>

#include "rgbimage.h"
#include "grayimage.h"
#include "binaryimage.h"

namespace ImageProcessing
{
    template <typename Type>
    QImage RGBImage2QImage(
    const ImageProcessing::RGBImage<Type> &rgbImg);

    template <typename Type>
    ImageProcessing::RGBImage<Type> QImage2RGBImage(const QImage &img);

    template <typename Type>
    ImageProcessing::GrayImage<Type> RGBImage2GrayImage(const ImageProcessing::RGBImage<Type> &rgbimg);
    template <typename Type>
    QImage GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg); //ok
    template <typename Type>
    ImageProcessing::GrayImage<Type> QImage2GrayImage(const QImage &img); //ok

    template <typename Type>
    QImage BinaryImage2QImage(const ImageProcessing::BinaryImage &binaryImg); //ok
}

#include "imageconversion.hpp"
#endif // IMAGECONVERSION_H
