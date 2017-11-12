#ifndef RGBIMAGE_H
#define RGBIMAGE_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "imageprocessing.h"

namespace ImageProcessing
{
    template <class Type>
    class RGBImage
    {
        public:
            RGBImage(){}
            RGBImage(const LinAlg::Matrix<Type> &r,
                     const LinAlg::Matrix<Type> &g,
                     const LinAlg::Matrix<Type> &b);
            RGBImage(const ImageProcessing::RGBImage<Type> &rgb);
            ~RGBImage(){}

            void setRed(LinAlg::Matrix<Type> red) {this->red = ImageProcessing::checkValue<Type>(red);}
            void setGreen(LinAlg::Matrix<Type> green) {this->green = ImageProcessing::checkValue<Type>(green);}
            void setBlue(LinAlg::Matrix<Type> blue) {this->blue = ImageProcessing::checkValue<Type>(blue);}

            void setWidth(unsigned width) const {this->width = width;}
            void setHeight(unsigned height)const {this->height = height;}
            void setAlpha(unsigned alpha) const {this->alpha = alpha;}

            const LinAlg::Matrix<Type>& getRed()   const {return this->red;}
            const LinAlg::Matrix<Type>& getGreen() const {return this->green;}
            const LinAlg::Matrix<Type>& getBlue()  const {return this->blue;}

            const unsigned& getWidth() const {return this->width;}
            const unsigned& getHeight()const {return this->height;}
            const unsigned& getAlpha() const {return this->alpha;}

            ImageProcessing::RGBImage<Type>& operator! () const;

            ImageProcessing::RGBImage<Type>& operator =(const ImageProcessing::RGBImage<Type>& rgbImg);

            ImageProcessing::RGBImage<Type>& operator+= (const ImageProcessing::RGBImage<Type>& rgbImg);
            ImageProcessing::RGBImage<Type>& operator+= (const Type& value);

            ImageProcessing::RGBImage<Type>& operator-= (const ImageProcessing::RGBImage<Type>& rgbImg);
            ImageProcessing::RGBImage<Type>& operator-= (const Type& value);

            ImageProcessing::RGBImage<Type>& operator*= (const ImageProcessing::RGBImage<Type>& rgbImg);
            ImageProcessing::RGBImage<Type>& operator*= (const Type& value);

            ImageProcessing::RGBImage<Type>& operator/= (const Type& value);
            ImageProcessing::RGBImage<Type>& operator/= (const ImageProcessing::RGBImage<Type>& rgbImg);

            ImageProcessing::RGBImage<Type>& operator~ ();

        private:
            LinAlg::Matrix<Type> red,green,blue;
            unsigned height, width, alpha;
    };

    template <typename Type>
    ImageProcessing::RGBImage<Type> operator +(ImageProcessing::RGBImage<Type> lhs,const Type& rhs){return lhs += rhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator +(const Type& lhs,ImageProcessing::RGBImage<Type> rhs){return rhs += lhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator +(ImageProcessing::RGBImage<Type> lhs,ImageProcessing::RGBImage<Type> rhs){return lhs += rhs;}

    template <typename Type>
    ImageProcessing::RGBImage<Type> operator -(ImageProcessing::RGBImage<Type> lhs,const Type& rhs){return lhs -= rhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator -(const Type& lhs,ImageProcessing::RGBImage<Type> rhs){return rhs -= lhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator -(ImageProcessing::RGBImage<Type> lhs,ImageProcessing::RGBImage<Type> rhs){return lhs -= rhs;}

    template <typename Type>
    ImageProcessing::RGBImage<Type> operator *(ImageProcessing::RGBImage<Type> lhs,const Type& rhs){return lhs *= rhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator *(const Type& lhs,ImageProcessing::RGBImage<Type> rhs){return rhs *= lhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator *(ImageProcessing::RGBImage<Type> lhs,ImageProcessing::RGBImage<Type> rhs){return lhs *= rhs;}

    template <typename Type>
    ImageProcessing::RGBImage<Type> operator /(ImageProcessing::RGBImage<Type> lhs,const Type& rhs){return lhs /= rhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator /(const Type& lhs,ImageProcessing::RGBImage<Type> rhs){return rhs /= lhs;}
    template <typename Type>
    ImageProcessing::RGBImage<Type> operator /(ImageProcessing::RGBImage<Type> lhs,ImageProcessing::RGBImage<Type> rhs){return lhs /= rhs;}


    template <typename Type>
    ImageProcessing::RGBImage<Type> reScale(ImageProcessing::RGBImage<Type> rgbImage, const double &scale);

    template <typename Type>
    ImageProcessing::RGBImage<Type> rotation(ImageProcessing::RGBImage<Type> rgbImage, const double &angle);
    template <typename Type>
    ImageProcessing::RGBImage<Type> horizontalFlip(ImageProcessing::RGBImage<Type> mat);
    template <typename Type>
    ImageProcessing::RGBImage<Type> verticalFlip(ImageProcessing::RGBImage<Type> mat);
    template <typename Type>
    ImageProcessing::RGBImage<Type> translation(ImageProcessing::RGBImage<Type> mat, const double &xPos, const double &yPos);

    template <typename Type>
    LinAlg::Matrix<Type> Histogram(const ImageProcessing::RGBImage<Type> &img);

    template <typename Type>
    ImageProcessing::RGBImage<Type> contrastEnhancement(ImageProcessing::RGBImage<Type> RGBImage, const LinAlg::Matrix<Type> &positions);

    template <typename Type>
    ImageProcessing::RGBImage<Type> filterPrewittVertical(ImageProcessing::RGBImage<Type> RGBImage);
    template <typename Type>
    ImageProcessing::RGBImage<Type> filterPrewittHorizontal(ImageProcessing::RGBImage<Type> RGBImage);

    template <typename Type>
    ImageProcessing::RGBImage<Type> filterSobelVertical(ImageProcessing::RGBImage<Type> RGBImage);
    template <typename Type>
    ImageProcessing::RGBImage<Type> filterSobelHorizontal(ImageProcessing::RGBImage<Type> RGBImage);

    template <typename Type>
    ImageProcessing::RGBImage<Type> filterRobertsVertical(ImageProcessing::RGBImage<Type> RGBImage);
    template <typename Type>
    ImageProcessing::RGBImage<Type> filterRobertsHorizontal(ImageProcessing::RGBImage<Type> RGBImage);

    template <typename Type, typename OtherType>
    ImageProcessing::RGBImage<Type> discreteLaplacian(ImageProcessing::RGBImage<Type> img, const OtherType &borderWeigth, const OtherType &maskWeigth);

    template <typename Type>
    ImageProcessing::RGBImage<Type> averageFilter(ImageProcessing::RGBImage<Type> RGBImage, const unsigned &sizeMask);
    template <typename Type>
    ImageProcessing::RGBImage<Type> medianFilter(ImageProcessing::RGBImage<Type> RGBImage, const unsigned &sizeMask);
    template <typename Type>
    ImageProcessing::RGBImage<Type> selfreinforceFilter(ImageProcessing::RGBImage<Type> RGBImage, const unsigned &sizeMask, const double &reinforceWeigth);

}

#include "rgbimage.hpp"
#endif // RGBIMAGE_H
