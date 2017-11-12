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
        BinaryImage(){}
        BinaryImage(const unsigned &height, const unsigned &width){ this->height = height; this->width = width; binary = LinAlg::Matrix<bool>(width,height);}
        BinaryImage(LinAlg::Matrix<bool> bin){this->binary = bin; this->height = bin.getNumberOfColumns(); this->width = bin.getNumberOfRows();}
        BinaryImage (const BinaryImage& bin){this->height = bin.getHeight();this->width = bin.getWidth();this->binary = bin.getBinaryImageMatrix();}

        ~BinaryImage(){binary.~Matrix();}

        unsigned getWidth() const {return this->width;}
        unsigned getHeight()const {return this->height;}

        LinAlg::Matrix<bool> getBinaryImageMatrix() const {return this->binary;}

        void setWidth (const unsigned &width) {this->width = width;}
        void setHeight(const unsigned &height){this->height = height;}

        void setBinaryImageMatrix(const LinAlg::Matrix<bool> &bin){this->height = bin.getNumberOfColumns(); this->width = bin.getNumberOfRows();this->binary = getBinaryImageMatrix();}

        ImageProcessing::BinaryImage& operator= (const ImageProcessing::BinaryImage &bin){this->height = bin.getHeight();this->width = bin.getWidth();this->binary = bin.getBinaryImageMatrix();return (*this);}

        bool& operator() (unsigned row, unsigned column) {return this->binary(row,column);}
        bool  operator() (unsigned  row, unsigned column) const{return this->binary(row,column);}

        ImageProcessing::BinaryImage operator! () const;
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


    LinAlg::Matrix<bool> erosionMask(const ImageProcessing::BinaryImage &img, const unsigned &row, const unsigned &col);
    ImageProcessing::BinaryImage erosion (const ImageProcessing::BinaryImage &img);
    ImageProcessing::BinaryImage dilation(const ImageProcessing::BinaryImage &img);

    ImageProcessing::BinaryImage closing (const ImageProcessing::BinaryImage &img);
    ImageProcessing::BinaryImage opening (const ImageProcessing::BinaryImage &img);

    LinAlg::Matrix< LinAlg::Matrix<unsigned>* >* bound(const ImageProcessing::BinaryImage &mat);

    unsigned area(const ImageProcessing::BinaryImage &img);
    LinAlg::Matrix<unsigned> centroid(const ImageProcessing::BinaryImage &img);


}

//#include "binaryimage.cpp"
#endif // BINARYIMAGE_H
