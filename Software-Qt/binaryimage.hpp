#include "binaryimage.h"

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator! ()
{
    for(unsigned i = 1; i <= this->height; ++i)
        for(unsigned j = 1; j <= this->width; ++j)
            this->binary(i,j) = !this->binary(i,j);

    return (*this);
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator== (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(i,j) = (bin.binary(i,j) == this->binary(i,j));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator!= (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(i,j) = (bin.binary(i,j) != this->binary(i,j));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator&& (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(i,j) = (bin.binary(i,j) && this->binary(i,j));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator|| (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(i,j) = (bin.binary(i,j) || this->binary(i,j));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator^ (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(i,j) = (bin.binary(i,j) ^ this->binary(i,j));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator== (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(i,j) = (grayImage(i,j) == value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator!= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(i,j) = (grayImage(i,j) != value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator>  (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(i,j) = (grayImage(i,j) > value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator>= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(i,j) = (grayImage(i,j) >= value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator<  (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(i,j) = (grayImage(i,j) < value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator<= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(i,j) = (grayImage(i,j) <= value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator== (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage == value);
}

ImageProcessing::BinaryImage ImageProcessing::operator!= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage != value);
}

ImageProcessing::BinaryImage ImageProcessing::operator>  (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage > value);
}

ImageProcessing::BinaryImage ImageProcessing::operator>= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage >= value);
}

ImageProcessing::BinaryImage ImageProcessing::operator<  (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage < value);
}

ImageProcessing::BinaryImage ImageProcessing::operator<= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage <= value);
}
