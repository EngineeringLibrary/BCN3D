#include "rgbimage.h"

template <typename Type>
ImageProcessing::RGBImage<Type>::RGBImage(const LinAlg::Matrix<Type> &red, const LinAlg::Matrix<Type> &green, const LinAlg::Matrix<Type> &blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;

    this->width = red.getNumberOfRows();
    this->height = red.getNumberOfColumns();
    this->alpha = 255;
}

template <typename Type>
ImageProcessing::RGBImage<Type>::RGBImage( const ImageProcessing::RGBImage<Type> &rgb)
{
    this->red = rgb.getRed();
    this->green = rgb.getGreen();
    this->blue = rgb.getBlue();

    this->width = rgb.getWidth();
    this->height = rgb.getHeight();
    this->alpha = rgb.getAlpha();
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator = (const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = rgbImg.getRed();
    this->green = rgbImg.getGreen();
    this->blue = rgbImg.getBlue();

    this->width = rgbImg.getWidth();
    this->height = rgbImg.getHeight();
    this->alpha = rgbImg.getAlpha();

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator += (const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                this->red + rgbImg.getRed());
    this->green = ImageProcessing::checkValue<Type>(
                this->green + rgbImg.getGreen());
    this->blue = ImageProcessing::checkValue<Type>(
                this->blue + rgbImg.getBlue());
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator +=(const Type& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                this->red + rgbImg);
    this->green = ImageProcessing::checkValue<Type>(
                this->green + rgbImg);
    this->blue = ImageProcessing::checkValue<Type>(
                this->blue + rgbImg);
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -= (const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                this->red - rgbImg.getRed());
    this->green = ImageProcessing::checkValue<Type>(
                this->green - rgbImg.getGreen());
    this->blue = ImageProcessing::checkValue<Type>(
                this->blue - rgbImg.getBlue());
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -= (const Type& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                this->red - rgbImg);
    this->green = ImageProcessing::checkValue<Type>(
                this->green - rgbImg);
    this->blue = ImageProcessing::checkValue<Type>(
                this->blue - rgbImg);
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator *= (const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                ImageProcessing::hadamardProduct(
                    this->red,  rgbImg.getRed()));
    this->green = ImageProcessing::checkValue<Type>(
                ImageProcessing::hadamardProduct(
                    this->green , rgbImg.getGreen()));
    this->blue = ImageProcessing::checkValue<Type>(
                ImageProcessing::hadamardProduct(
                    this->blue, rgbImg.getBlue()));
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>&ImageProcessing::RGBImage<Type>::operator *= (const Type& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                this->red * rgbImg);
    this->green = ImageProcessing::checkValue<Type>(
                this->green * rgbImg);
    this->blue = ImageProcessing::checkValue<Type>(
                this->blue * rgbImg);
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator /= (const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                ImageProcessing::hadamardDivision(
                    this->red,  rgbImg.getRed()));
    this->green = ImageProcessing::checkValue<Type>(
                ImageProcessing::hadamardDivision(
                    this->green , rgbImg.getGreen()));
    this->blue = ImageProcessing::checkValue<Type>(
                ImageProcessing::hadamardDivision(
                    this->blue, rgbImg.getBlue()));
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator /= (const Type& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(
                this->red / rgbImg);
    this->green = ImageProcessing::checkValue<Type>(
                this->green / rgbImg);
    this->blue = ImageProcessing::checkValue<Type>(
                this->blue / rgbImg);
    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator ~()
{
    this->red = ImageProcessing::checkValue<Type>(255 - this->red);
    this->green = ImageProcessing::checkValue<Type>(255 - this->green);
    this->blue = ImageProcessing::checkValue<Type>(255 - this->blue);
    return *this;
}


template <class Type>
ImageProcessing::RGBImage<Type> ImageProcessing::reScale( ImageProcessing::RGBImage<Type> rgbImage,const double     &scale){
   rgbImage.setRed(ImageProcessing::reScale(rgbImage.getRed(),scale));

   rgbImage.setGreen(ImageProcessing::reScale(rgbImage.getGreen(),scale));

   rgbImage.setBlue(ImageProcessing::reScale(rgbImage.getBlue(),scale));

    return rgbImage;
}




















