#include "rgbimage.h"

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator! () const
{
    ImageProcessing::RGBImage<Type> ret = (*this);
    for(unsigned i = 1; i <= this->height; ++i)
        for(unsigned j = 1; j <= this->width; ++j)
            ret.binary(j,i) = !this->binary(j,i);

    return ret;
}


template <typename Type>
ImageProcessing::RGBImage<Type>::RGBImage(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
{
    this->red = ImageProcessing::checkValue<Type>(r);
    this->green = ImageProcessing::checkValue<Type>(g);
    this->blue = ImageProcessing::checkValue<Type>(b);

    this->width = r.getNumberOfRows();
    this->height = r.getNumberOfColumns();
    this->alpha = 255;
}

template <typename Type>
ImageProcessing::RGBImage<Type>::RGBImage(const ImageProcessing::RGBImage<Type> &rgb)
{
    this->red = rgb.red;
    this->green = rgb.green;
    this->blue = rgb.blue;

    this->width = rgb.width;
    this->height = rgb.height;
    this->alpha = rgb.alpha;
}


template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator =(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->width = rgbImg.width;
    this->height = rgbImg.height;

    this->red = rgbImg.red;
    this->green = rgbImg.green;
    this->blue = rgbImg.blue;

    this->alpha = rgbImg.alpha;

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator +=(const Type& value)
{
    this->red += value;
    this->green += value;
    this->blue += value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator +=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(this->red + rgbImg.red);
    this->green = ImageProcessing::checkValue<Type>(this->green + rgbImg.green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue + rgbImg.blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -=(const Type& value)
{
    this->red -= value;
    this->green -= value;
    this->blue -= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}


template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->red = ImageProcessing::checkValue<Type>(this->red + rgbImg.red);
    this->green = ImageProcessing::checkValue<Type>(this->green + rgbImg.green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue + rgbImg.blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator *=(const Type& value)
{
    this->red *= value;
    this->green *= value;
    this->blue *= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}


template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator *=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    LinAlg::Matrix<Type> aux = ImageProcessing::hadamardProduct<Type>(this->red,rgbImg.getRed());
    this->red = ImageProcessing::checkValue<Type>(aux);

    aux = ImageProcessing::hadamardProduct<Type>(this->green,rgbImg.getGreen());
    this->green = ImageProcessing::checkValue<Type>(aux);

    aux = ImageProcessing::hadamardProduct<Type>(this->blue,rgbImg.getBlue());
    this->blue = ImageProcessing::checkValue<Type>(aux);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator /=(const Type& value)
{
    this->red /= value;
    this->green /= value;
    this->blue /= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator /=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    LinAlg::Matrix<Type> aux = ImageProcessing::hadamardDivision<Type>(this->red,rgbImg.getRed());
    this->red = ImageProcessing::checkValue<Type>(aux);

    aux = ImageProcessing::hadamardDivision<Type>(this->green,rgbImg.getGreen());
    this->green = ImageProcessing::checkValue<Type>(aux);

    aux = ImageProcessing::hadamardDivision<Type>(this->blue,rgbImg.getBlue());
    this->blue = ImageProcessing::checkValue<Type>(aux);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator~ ()
{
    this->green = 255 - this->green;
    this->blue  = 255 - this->blue;
    this->red   = 255 - this->red;

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::reScale(ImageProcessing::RGBImage<Type> rgbImage, const double &scale)
{
    rgbImage.setBlue(ImageProcessing::reScale(rgbImage.getBlue(),scale));
    rgbImage.setGreen(ImageProcessing::reScale(rgbImage.getGreen(),scale));
    rgbImage.setRed(ImageProcessing::reScale(rgbImage.getRed(),scale));
    return rgbImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::rotation(ImageProcessing::RGBImage<Type> rgbImage, const double &angle)
{
    rgbImage.setBlue(ImageProcessing::rotation(rgbImage.getBlue(),angle));
    rgbImage.setGreen(ImageProcessing::rotation(rgbImage.getGreen(),angle));
    rgbImage.setRed(ImageProcessing::rotation(rgbImage.getRed(),angle));
    return rgbImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::horizontalFlip(ImageProcessing::RGBImage<Type> rgbImage)
{
    rgbImage.setBlue(ImageProcessing::horizontalFlip(rgbImage.getBlue()));
    rgbImage.setGreen(ImageProcessing::horizontalFlip(rgbImage.getGreen()));
    rgbImage.setRed(ImageProcessing::horizontalFlip(rgbImage.getRed()));
    return rgbImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::verticalFlip(ImageProcessing::RGBImage<Type> rgbImage)
{
    rgbImage.setBlue(ImageProcessing::verticalFlip(rgbImage.getBlue()));
    rgbImage.setGreen(ImageProcessing::verticalFlip(rgbImage.getGreen()));
    rgbImage.setRed(ImageProcessing::verticalFlip(rgbImage.getRed()));
    return rgbImage;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::translation(ImageProcessing::RGBImage<Type> rgbImage, const double &xPos, const double &yPos)
{
    rgbImage.setBlue(ImageProcessing::translation(rgbImage.getBlue(),xPos,yPos));
    rgbImage.setGreen(ImageProcessing::translation(rgbImage.getGreen(),xPos,yPos));
    rgbImage.setRed(ImageProcessing::translation(rgbImage.getRed(),xPos,yPos));
    return rgbImage;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Histogram(const ImageProcessing::RGBImage<Type> &img)
{
    LinAlg::Matrix<Type> ret;
    ret = ImageProcessing::Histogram(img.getRed()) || ImageProcessing::Histogram(img.getGreen()) || ImageProcessing::Histogram(img.getBlue());
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::contrastEnhancement(ImageProcessing::RGBImage<Type> RGBImage,
                                                                      const LinAlg::Matrix<Type> &positions)
{
    RGBImage.setRed(ImageProcessing::contrastEnhancement(RGBImage.getRed(),positions(1,1),positions(1,2),positions(1,3),positions(1,4)));
    RGBImage.setGreen(ImageProcessing::contrastEnhancement(RGBImage.getGreen(),positions(2,1),positions(2,2),positions(2,3),positions(2,4)));
    RGBImage.setBlue(ImageProcessing::contrastEnhancement(RGBImage.getBlue(),positions(3,1),positions(3,2),positions(3,3),positions(3,4)));
    return RGBImage;
}

// Aula 11
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
// fim Aula 13
