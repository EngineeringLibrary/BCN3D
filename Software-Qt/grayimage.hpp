#include "grayimage.h"

template <typename Type>
ImageProcessing::GrayImage<Type>::GrayImage(const LinAlg::Matrix<Type> &gray)
{
    this->gray = ImageProcessing::checkValue<Type>(gray);

    this->width = gray.getNumberOfRows();
    this->height = gray.getNumberOfColumns();
    this->alpha = 255;
}


template <typename Type>
ImageProcessing::GrayImage<Type>::GrayImage(const ImageProcessing::GrayImage<Type> &gray)
{
    this->gray = gray.getGray();

    this->width = gray.getWidth();
    this->height = gray.getHeight();
    this->alpha = 255;
}
template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator =(const ImageProcessing::GrayImage<Type>& grayImg)
{
    this->gray = grayImg.getGray();
    this->width = grayImg.getWidth();
    this->height = grayImg.getHeight();
    this->alpha = 255;

    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const Type& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}


template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    this->gray = ImageProcessing::checkValue<Type>(this->getGray() + grayImg.getGray());
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const Type& value)
{
    this->gray -= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}


template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const ImageProcessing::GrayImage<Type>& grayImg)
{

    this->gray = ImageProcessing::checkValue<Type>(this->getGray() - grayImg.getGray());
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const Type& value)
{
    this->gray *= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = ImageProcessing::hadamardProduct(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue<Type>(aux);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator /=(const Type& value)
{
    this->gray /= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::reScale(ImageProcessing::GrayImage<Type> grayImage, const double &scale)
{
    grayImage.setGray(ImageProcessing::reScale(grayImage.getGray(),scale));
    return grayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::rotation(ImageProcessing::GrayImage<Type> grayImage, const double &angle)
{
    grayImage.setGray(ImageProcessing::rotation(grayImage.getGray(),angle));
    return grayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::horizontalFlip(ImageProcessing::GrayImage<Type> grayImage)
{
    grayImage.setGray(ImageProcessing::horizontalFlip(grayImage.getGray()));
    return grayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::verticalFlip(ImageProcessing::GrayImage<Type> grayImage)
{
    grayImage.setGray(ImageProcessing::verticalFlip(grayImage.getGray()));
    return grayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::translation(ImageProcessing::GrayImage<Type> grayImage, const double &xPos, const double &yPos)
{
    grayImage.setGray(ImageProcessing::translation(grayImage.getGray(),xPos,yPos));
    return grayImage;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Histogram(const ImageProcessing::GrayImage<Type> &img)
{
    LinAlg::Matrix<Type> ret;
    ret = ImageProcessing::Histogram(img.getGray());
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::contrastEnhancement(ImageProcessing::GrayImage<Type> grayImage,const LinAlg::Matrix<Type> &position)
{
    grayImage.setGray(ImageProcessing::contrastEnhancement(grayImage.getGray(),position(1,1),position(1,2),position(1,3),position(1,4)));
    return grayImage;
}
