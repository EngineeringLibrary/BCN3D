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

// Aula 11
template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::filterPrewittVertical(ImageProcessing::GrayImage<Type> GrayImage)
{
    GrayImage.setGray(ImageProcessing::convolution2d<Type,int>(GrayImage.getGray(),"-1,0,1;-1,0,1;-1,0,1"));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::filterPrewittHorizontal(ImageProcessing::GrayImage<Type> GrayImage)
{
    GrayImage.setGray(ImageProcessing::convolution2d<Type,int>(GrayImage.getGray(),"1,1,1;0,0,0;-1,-1,-1"));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::filterSobelVertical(ImageProcessing::GrayImage<Type> GrayImage)
{
    GrayImage.setGray(ImageProcessing::convolution2d<Type,int>(GrayImage.getGray(),"-1,0,1;-2,0,2;-1,0,1"));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::filterSobelHorizontal(ImageProcessing::GrayImage<Type> GrayImage)
{
    GrayImage.setGray(ImageProcessing::convolution2d<Type,int>(GrayImage.getGray(),"1,2,1;0,0,0;-1,-2,-1"));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::filterRobertsVertical(ImageProcessing::GrayImage<Type> GrayImage)
{
    GrayImage.setGray(ImageProcessing::convolution2d<Type,int>(GrayImage.getGray(),"0,1;-1,0"));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::filterRobertsHorizontal(ImageProcessing::GrayImage<Type> GrayImage)
{
    GrayImage.setGray(ImageProcessing::convolution2d<Type,int>(GrayImage.getGray(),"1,0;0,-1"));
    return GrayImage;
}
// fim Aula 11

// Aula 12
template <typename Type, typename OtherType>
ImageProcessing::GrayImage<Type> ImageProcessing::discreteLaplacian(ImageProcessing::GrayImage<Type> img, const OtherType &borderWeigth, const OtherType &maskWeigth)
{
    img.setGray(ImageProcessing::discreteLaplacian<Type,OtherType>(img.getGray(),borderWeigth, maskWeigth));
    return img;
}
// fim Aula 12

// Aula 13
template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::averageFilter(ImageProcessing::GrayImage<Type> GrayImage, const unsigned &sizeMask)
{
    LinAlg::Matrix<double> mask = LinAlg::Ones<double>(sizeMask,sizeMask)/(sizeMask*sizeMask);
    GrayImage.setGray(ImageProcessing::convolution2d<Type,double>(GrayImage.getGray(),mask));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::medianFilter(ImageProcessing::GrayImage<Type> GrayImage, const unsigned &sizeMask)
{
    GrayImage.setGray(ImageProcessing::medianFilter(GrayImage.getGray(),sizeMask));
    return GrayImage;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::selfreinforceFilter(ImageProcessing::GrayImage<Type> GrayImage, const unsigned &sizeMask, const double &reinforceWeigth)
{
    ImageProcessing::GrayImage<Type> temp = ImageProcessing::averageFilter(GrayImage,sizeMask);
    GrayImage.setGray(ImageProcessing::checkValue(reinforceWeigth*GrayImage.getGray() - temp.getGray()));
    return GrayImage;
}
