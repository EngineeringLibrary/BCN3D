#include "imageconversion.h"

template <typename Type>
QImage ImageProcessing::RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> r = rgbImg.getRed(),
                         g = rgbImg.getGreen(),
                         b = rgbImg.getBlue();
    QImage ret(r.getNumberOfRows(), r.getNumberOfColumns(),
               QImage::Format_RGB32);
    for (unsigned i = 0; i < r.getNumberOfRows(); ++i)
        for (unsigned j = 0; j < r.getNumberOfColumns(); ++j)
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

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::RGBImage2GrayImage(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<Type> gray(rgbimg.getWidth(), rgbimg.getHeight()),
                        r = rgbimg.getRed(),
                        g = rgbimg.getGreen(),
                        b = rgbimg.getBlue();

    for(unsigned i = 1; i <= gray.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= gray.getNumberOfColumns(); ++j)
            gray(i,j) = qGray(r(i,j),g(i,j),b(i,j));

    return ImageProcessing::GrayImage<Type>(gray);
}

template <typename Type>
QImage ImageProcessing::GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg)
{
    LinAlg::Matrix<Type> gray = grayImg.getGray();
    QImage ret(gray.getNumberOfRows(),gray.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < gray.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < gray.getNumberOfColumns(); ++j)
            ret.setPixel(i,j,QColor(gray(i+1,j+1),gray(i+1,j+1),gray(i+1,j+1)).rgb());

    return ret;
}

template <typename Type>//DE GRAY PARA RGB
ImageProcessing::RGBImage<Type> GrayImage2RGBImage(const ImageProcessing::GrayImage<Type> &grayImg){
    LinAlg::Matrix<Type> gray = grayImg.getGray();
    LinAlg::Matrix<Type> r(gray.width(),gray.height());
    for (int i = 0; i < gray.width(); ++i){
        for (int j = 0; j < gray.height(); ++j) {
            r(i+1,j+1) = gray(i,j);
        }
    }
    return ImageProcessing::RGBImage<Type>(r,r,r);
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::QImage2GrayImage(const QImage &img)
{
    LinAlg::Matrix<Type> gray(img.width(),img.height());
    for(int i = 0; i < img.width(); ++i)
            for(int j = 0; j < img.height(); ++j){
                QColor color(img.pixel(i,j));
                gray(i+1,j+1) = qGray(color.red(),color.green(),color.blue());
            }


    return ImageProcessing::GrayImage<Type>(gray);
}

template <typename Type>
QImage ImageProcessing::BinaryImage2QImage(const ImageProcessing::BinaryImage &binaryImg)
{
    LinAlg::Matrix<bool> bin = binaryImg.getBinaryImageMatrix();
    QImage ret(bin.getNumberOfRows(),bin.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < bin.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < bin.getNumberOfColumns(); ++j)
            ret.setPixel(i,j,QColor(255*bin(i+1,j+1),255*bin(i+1,j+1),255*bin(i+1,j+1)).rgb());

    return ret;
}
