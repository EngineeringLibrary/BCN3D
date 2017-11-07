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

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::filterPrewittVertical(ImageProcessing::RGBImage<Type> RGBImage)
{
    RGBImage.setRed(ImageProcessing::convolution2d<Type,int>(RGBImage.getRed(),"-1,0,1;-1,0,1;-1,0,1"));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,int>(RGBImage.getGreen(),"-1,0,1;-1,0,1;-1,0,1"));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,int>(RGBImage.getBlue(),"-1,0,1;-1,0,1;-1,0,1"));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::filterPrewittHorizontal(ImageProcessing::RGBImage<Type> RGBImage)
{
    RGBImage.setRed(ImageProcessing::convolution2d<Type,int>(RGBImage.getRed(),"1,1,1;0,0,0;-1,-1,-1"));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,int>(RGBImage.getGreen(),"1,1,1;0,0,0;-1,-1,-1"));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,int>(RGBImage.getBlue(),"1,1,1;0,0,0;-1,-1,-1"));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::filterSobelVertical(ImageProcessing::RGBImage<Type> RGBImage)
{
    RGBImage.setRed(ImageProcessing::convolution2d<Type,int>(RGBImage.getRed(),"-1,0,1;-2,0,2;-1,0,1"));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,int>(RGBImage.getGreen(),"-1,0,1;-2,0,2;-1,0,1"));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,int>(RGBImage.getBlue(),"-1,0,1;-2,0,2;-1,0,1"));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::filterSobelHorizontal(ImageProcessing::RGBImage<Type> RGBImage)
{
    RGBImage.setRed(ImageProcessing::convolution2d<Type,int>(RGBImage.getRed(),"1,2,1;0,0,0;-1,-2,-1"));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,int>(RGBImage.getGreen(),"1,2,1;0,0,0;-1,-2,-1"));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,int>(RGBImage.getBlue(),"1,2,1;0,0,0;-1,-2,-1"));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::filterRobertsVertical(ImageProcessing::RGBImage<Type> RGBImage)
{
    RGBImage.setRed(ImageProcessing::convolution2d<Type,int>(RGBImage.getRed(),"0,1;-1,0"));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,int>(RGBImage.getGreen(),"0,1;-1,0"));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,int>(RGBImage.getBlue(),"0,1;-1,0"));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::filterRobertsHorizontal(ImageProcessing::RGBImage<Type> RGBImage)
{
    RGBImage.setRed(ImageProcessing::convolution2d<Type,int>(RGBImage.getRed(),"1,0;0,-1"));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,int>(RGBImage.getGreen(),"1,0;0,-1"));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,int>(RGBImage.getBlue(),"1,0;0,-1"));
    return RGBImage;
}
// fim Aula 11

// Aula 12
template <typename Type, typename OtherType>
ImageProcessing::RGBImage<Type> ImageProcessing::discreteLaplacian(ImageProcessing::RGBImage<Type> img, const OtherType &borderWeigth, const OtherType &maskWeigth)
{
    img.setRed(ImageProcessing::discreteLaplacian<Type,OtherType>(img.getRed(),borderWeigth, maskWeigth));
    img.setGreen(ImageProcessing::discreteLaplacian<Type,OtherType>(img.getGreen(),borderWeigth, maskWeigth));
    img.setBlue(ImageProcessing::discreteLaplacian<Type,OtherType>(img.getBlue(),borderWeigth, maskWeigth));
    return img;
}
// fim Aula 12


// Aula 13
template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::averageFilter(ImageProcessing::RGBImage<Type> RGBImage, const unsigned &sizeMask)
{
    LinAlg::Matrix<double> mask = LinAlg::Ones<double>(sizeMask,sizeMask)/(sizeMask*sizeMask);
    RGBImage.setRed(ImageProcessing::convolution2d<Type,double>(RGBImage.getRed(),mask));
    RGBImage.setGreen(ImageProcessing::convolution2d<Type,double>(RGBImage.getGreen(),mask));
    RGBImage.setBlue(ImageProcessing::convolution2d<Type,double>(RGBImage.getBlue(),mask));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::medianFilter(ImageProcessing::RGBImage<Type> RGBImage, const unsigned &sizeMask)
{
    RGBImage.setRed(ImageProcessing::medianFilter(RGBImage.getRed(),sizeMask));
    RGBImage.setGreen(ImageProcessing::medianFilter(RGBImage.getGreen(),sizeMask));
    RGBImage.setBlue(ImageProcessing::medianFilter(RGBImage.getBlue(),sizeMask));
    return RGBImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::selfreinforceFilter(ImageProcessing::RGBImage<Type> RGBImage, const unsigned &sizeMask, const double &reinforceWeigth)
{
    ImageProcessing::RGBImage<Type> temp = ImageProcessing::averageFilter(RGBImage,sizeMask);
    RGBImage.setRed(ImageProcessing::checkValue(reinforceWeigth*RGBImage.getRed() - temp.getRed()));
    RGBImage.setGreen(ImageProcessing::checkValue(reinforceWeigth*RGBImage.getGreen() - temp.getGreen()));
    RGBImage.setBlue(ImageProcessing::checkValue(reinforceWeigth*RGBImage.getBlue() - temp.getBlue()));
    return RGBImage;
}
