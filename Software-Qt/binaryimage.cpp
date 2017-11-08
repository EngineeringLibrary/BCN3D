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



//Aula 14
LinAlg::Matrix<bool> ImageProcessing::erosionMask(const ImageProcessing::BinaryImage &img, const unsigned &row, const unsigned &col)
{
    LinAlg::Matrix<bool> mask = LinAlg::Zeros<bool>(3,3);
    mask(2,2) = 1;

    if(row-1 > 0)
        if(img(row-1,col) == 1)
            mask(1,2) = 1;

    if(row-1 > 0 && col+1 <= img.getWidth())
        if(img(row-1,col+1) == 1)
            mask(1,3) = 1;

    if(col+1 <= img.getWidth())
        if(img(row,col+1) == 1)
            mask(2,3) = 1;

    if(row+1 <= img.getWidth() && col+1 <= img.getWidth())
        if(img(row+1,col+1) == 1)
            mask(3,3) = 1;

    if(row+1 <= img.getWidth())
        if(img(row+1,col) == 1)
            mask(3,2) = 1;

    if(row+1 <= img.getWidth() && col-1 > 0)
        if(img(row+1,col-1) == 1)
            mask(3,1) = 1;

    if(col-1 > 0 )
        if(img(row,col-1) == 1)
            mask(2,1) = 1;

    if(row-1 > 0 && col-1 > 0)
        if(img(row-1, col-1) == 1)
            mask(1,1) = 1;

    return mask;
}

ImageProcessing::BinaryImage ImageProcessing::erosion(const ImageProcessing::BinaryImage &img)
{
    LinAlg::Matrix<bool> ret(img.getHeight(), img.getWidth());
    LinAlg::Matrix<bool> one = LinAlg::Ones<bool>(3,3);

    for(unsigned i = 1; i < ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j < ret.getNumberOfColumns(); ++j)
        {
            if(img(i,j) == 1){
                LinAlg::Matrix<bool> mask = ImageProcessing::erosionMask(img,i,j);
                if(LinAlg::isEqual<bool>(mask,one))
                    ret(i,j) = 1;
            }
        }

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::dilation(const ImageProcessing::BinaryImage &img)
{
    ImageProcessing::BinaryImage ret = img;
//    LinAlg::Matrix<bool> aux = LinAlg::Zeros<bool>(ret.getNumberOfRows(),ret.getNumberOfColumns());
    ret = ImageProcessing::erosion(ret);
    ret = (!ret);
//    for(unsigned i = 3; i <= aux.getNumberOfRows()-4;++i)
//        for(unsigned j = 3; j <= aux.getNumberOfColumns()-4;++j)
//            aux(i,j) = ret(i,j);
// aux;
    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::closing(const ImageProcessing::BinaryImage &img)
{
    ImageProcessing::BinaryImage ret = ImageProcessing::dilation(img);
    ret = ImageProcessing::erosion(ret);
    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::opening(const ImageProcessing::BinaryImage &img)
{
    ImageProcessing::BinaryImage ret = ImageProcessing::erosion(img);
    ret = ImageProcessing::dilation(ret);
    return ret;
}
