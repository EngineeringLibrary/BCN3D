#ifndef BINARYIMAGE_H
#define BINARYIMAGE_H

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "grayimage.h"

namespace ImageProcessing
{
    class BinaryImage
    {
    public:
        BinaryImage(const unsigned &height, const unsigned &width){ this->height = height; this->width = width; binary = LinAlg::Matrix<bool>(height,width);}
        BinaryImage(const LinAlg::Matrix<bool> &bin){this->binary = bin; this->height = bin.getNumberOfRows(); this->width = bin.getNumberOfColumns();}
        BinaryImage(const ImageProcessing::BinaryImage &bin){this->binary = bin.getBinaryImageMatrix(); this->height = bin.getHeight(); this->width = bin.getWidth();}
//        ~BinaryImage();

        unsigned getWidth() const {return this->width;}
        unsigned getHeight()const {return this->height;}

        LinAlg::Matrix<bool> getBinaryImageMatrix() const {return this->binary;}

        void setWidth (const unsigned &width) {this->width = width;}
        void setHeight(const unsigned &height){this->height = height;}

        void setBinaryImageMatrix(const LinAlg::Matrix<bool> &bin){this->binary = bin;}

        ImageProcessing::BinaryImage& operator= (const ImageProcessing::BinaryImage& bin){this->binary = bin.binary; this->height = bin.getHeight(); this->width = bin.getWidth(); return (*this);}

        bool& operator() (unsigned row, unsigned column) {return this->binary(row,column);}
        bool  operator() (unsigned  row, unsigned column) const{return this->binary(row,column);}

        ImageProcessing::BinaryImage operator! ();
        ImageProcessing::BinaryImage operator== (const ImageProcessing::BinaryImage& bin);
        ImageProcessing::BinaryImage operator!= (const ImageProcessing::BinaryImage& bin);
        ImageProcessing::BinaryImage operator&& (const ImageProcessing::BinaryImage& bin);
        ImageProcessing::BinaryImage operator|| (const ImageProcessing::BinaryImage& bin);
        ImageProcessing::BinaryImage operator^ (const ImageProcessing::BinaryImage& bin);

    private:
        LinAlg::Matrix<bool> binary;
        unsigned height, width;
    };

    ImageProcessing::BinaryImage operator== (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value);
    ImageProcessing::BinaryImage operator!= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value);
    ImageProcessing::BinaryImage operator>  (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value);
    ImageProcessing::BinaryImage operator>= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value);
    ImageProcessing::BinaryImage operator<  (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value);
    ImageProcessing::BinaryImage operator<= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value);

    ImageProcessing::BinaryImage operator== (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage);
    ImageProcessing::BinaryImage operator!= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage);
    ImageProcessing::BinaryImage operator>  (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage);
    ImageProcessing::BinaryImage operator>= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage);
    ImageProcessing::BinaryImage operator<  (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage);
    ImageProcessing::BinaryImage operator<= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage);
}

//#include "binaryimage.cpp"
#endif // BINARYIMAGE_H
