#ifndef GRAYIMAGE_H
#define GRAYIMAGE_H
#include "imageprocessing.h"

namespace ImageProcessing
{
    template <typename Type>
    class GrayImage
    {
        public:
            GrayImage(){}
            GrayImage(const LinAlg::Matrix<Type> &gray);
            GrayImage(const ImageProcessing::GrayImage<Type> &gray);

            void setGray(const LinAlg::Matrix<Type> &gray); //{this->gray = gray;}

            void setWidth(unsigned width) {this->width = width;}
            void getHeight(unsigned height){this->height = height;}


            LinAlg::Matrix<Type> getGray() const {return this->gray;}

            unsigned getWidth() const {return this->width;}
            unsigned getHeight()const {return this->height;}

            ImageProcessing::GrayImage<Type>& operator= (const ImageProcessing::GrayImage<Type> &grayImg);

            Type& operator() (unsigned row, unsigned column) {return this->gray(row,column);}
            Type  operator() (unsigned  row, unsigned column) const{return this->gray(row,column);}

            ImageProcessing::GrayImage<Type>& operator+= (const ImageProcessing::GrayImage<Type>& grayImg);
            ImageProcessing::GrayImage<Type>& operator+= (const Type& value);

            ImageProcessing::GrayImage<Type>& operator-= (const ImageProcessing::GrayImage<Type>& grayImg);
            ImageProcessing::GrayImage<Type>& operator-= (const Type& value);

            ImageProcessing::GrayImage<Type>& operator*= (const ImageProcessing::GrayImage<Type>& grayImg);
            ImageProcessing::GrayImage<Type>& operator*= (const Type& value);

            ImageProcessing::GrayImage<Type>& operator/= (const Type& value);

        private:
            LinAlg::Matrix<Type> gray;
            unsigned height, width, alpha;
    };

    template <typename Type>
    ImageProcessing::GrayImage<Type> operator +(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs += rhs;}
    template <typename Type>
    ImageProcessing::GrayImage<Type> operator +(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs += lhs;}
    template <typename Type>
    ImageProcessing::GrayImage<Type> operator +(ImageProcessing::GrayImage<Type> lhs,ImageProcessing::GrayImage<Type> rhs){return lhs += rhs;}

    template <typename Type>
    ImageProcessing::GrayImage<Type> operator -(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs -= rhs;}
    template <typename Type>
    ImageProcessing::GrayImage<Type> operator -(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs -= lhs;}
    template <typename Type>
    ImageProcessing::GrayImage<Type> operator -(ImageProcessing::GrayImage<Type> lhs,ImageProcessing::GrayImage<Type> rhs){return lhs -= rhs;}

    template <typename Type>
    ImageProcessing::GrayImage<Type> operator *(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs *= rhs;}
    template <typename Type>
    ImageProcessing::GrayImage<Type> operator *(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs *= lhs;}
    template <typename Type>
    ImageProcessing::GrayImage<Type> operator *(ImageProcessing::GrayImage<Type> lhs,ImageProcessing::GrayImage<Type> rhs){return lhs *= rhs;}

    template <typename Type>
    ImageProcessing::GrayImage<Type> operator /(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs /= rhs;}

    // faz parte da aula 5
    template <typename Type>
    ImageProcessing::GrayImage<Type> reScale(ImageProcessing::GrayImage<Type> grayImage, const double &scale);
    // fim da aula 5

    // faz parte da aula6
    template <typename Type>
    ImageProcessing::GrayImage<Type> rotation(ImageProcessing::GrayImage<Type> grayImage, const double &angle);
    template <typename Type>
    ImageProcessing::GrayImage<Type> horizontalFlip(ImageProcessing::GrayImage<Type> mat);
    template <typename Type>
    ImageProcessing::GrayImage<Type> verticalFlip(ImageProcessing::GrayImage<Type> mat);
    template <typename Type>
    ImageProcessing::GrayImage<Type> translation(ImageProcessing::GrayImage<Type> mat, const double &xPos, const double &yPos);// fim da aula 6
    // fim aula 6

    // Aula 7
    template <typename Type>
    LinAlg::Matrix<Type> Histogram(const ImageProcessing::GrayImage<Type> &img);
    // fim aula 7

    // Aula 8
    template <typename Type>
    ImageProcessing::GrayImage<Type> contrastEnhancement(ImageProcessing::GrayImage<Type> grayImage,const LinAlg::Matrix<Type> &position);
    // fim aula 8

    // Aula 11
    template <typename Type>
    ImageProcessing::GrayImage<Type> filterPrewittVertical(ImageProcessing::GrayImage<Type> GrayImage);
    template <typename Type>
    ImageProcessing::GrayImage<Type> filterPrewittHorizontal(ImageProcessing::GrayImage<Type> GrayImage);

    template <typename Type>
    ImageProcessing::GrayImage<Type> filterSobelVertical(ImageProcessing::GrayImage<Type> GrayImage);
    template <typename Type>
    ImageProcessing::GrayImage<Type> filterSobelHorizontal(ImageProcessing::GrayImage<Type> GrayImage);

    template <typename Type>
    ImageProcessing::GrayImage<Type> filterRobertsVertical(ImageProcessing::GrayImage<Type> GrayImage);
    template <typename Type>
    ImageProcessing::GrayImage<Type> filterRobertsHorizontal(ImageProcessing::GrayImage<Type> GrayImage);
    // fim aula 11
    // Aula 12
    template <typename Type, typename OtherType>
    ImageProcessing::GrayImage<Type> discreteLaplacian(ImageProcessing::GrayImage<Type> img, const OtherType &borderWeigth, const OtherType &maskWeigth);
    // fim aula 12

    // Aula 13
    template <typename Type>
    ImageProcessing::GrayImage<Type> averageFilter(ImageProcessing::GrayImage<Type> GrayImage, const unsigned &sizeMask);
    template <typename Type>
    ImageProcessing::GrayImage<Type> medianFilter(ImageProcessing::GrayImage<Type> GrayImage, const unsigned &sizeMask);
    template <typename Type>
    ImageProcessing::GrayImage<Type> selfreinforceFilter(ImageProcessing::GrayImage<Type> GrayImage, const unsigned &sizeMask, const double &reinforceWeigth);
    // fim aula 13
}
#include "grayimage.hpp"
#endif // GRAYIMAGE_H
