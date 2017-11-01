#include "imageconversion.h"

template <typename Type>
QImage ImageProcessing::RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> r = rgbImg.getRed(),
                         g = rgbImg.getGreen(),
                         b = rgbImg.getBlue();
    QImage ret(r.getNumberOfRows(), r.getNumberOfColumns(),
               QImage::Format_RGB32);
    for (int i = 0; i < r.getNumberOfRows(); ++i)
        for (int j = 0; j < r.getNumberOfColumns(); ++j)
            ret.setPixelColor(i,j,
            QColor(r(i+1,j+1),g(i+1,j+1),b(i+1,j+1)));
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::QImage2RGBImage(const QImage &img)
{
    LinAlg::Matrix<Type> r(img.width(),img.height()),
                         g(img.width(),img.height()),
                         b(img.width(),img.height());
    for (int i = 0; i < img.width(); ++i)
        for (int j = 0; j < img.height(); ++j) {
            QColor color(img.pixel(i,j));
            r(i+1,j+1) = color.red();
            g(i+1,j+1) = color.green();
            b(i+1,j+1) = color.blue();
        }
    return ImageProcessing::RGBImage<Type>(r,g,b);
}
