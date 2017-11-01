#ifndef RGBIMAGE_H
#define RGBIMAGE_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "imageprocessing.h"

namespace ImageProcessing {
    template <class Type>
    class RGBImage
    {
    public:
        RGBImage(){}
        RGBImage(const LinAlg::Matrix<Type> &red,
                 const LinAlg::Matrix<Type> &green,
                 const LinAlg::Matrix<Type> &blue);
        RGBImage(const ImageProcessing::RGBImage<Type> &rgb);

        void setRed  (const LinAlg::Matrix<Type>  &red) { this->red = red;}
        void setGreen(const LinAlg::Matrix<Type>&green) { this->green = green;}
        void setBlue (const LinAlg::Matrix<Type> &blue) { this->blue = blue;}

        void setWidth (const unsigned  &width) { this->width = width;}
        void setHeight(const unsigned &height) { this->height = height;}
        void setAlpha (const unsigned  &alpha) { this->alpha = alpha;}

        LinAlg::Matrix<Type> getRed () const{ return this->red;}
        LinAlg::Matrix<Type> getGreen() const{ return this->green;}
        LinAlg::Matrix<Type> getBlue () const{ return this->blue;}

        const unsigned& getWidth () const{ return this->width;}
        const unsigned& getHeight() const{ return this->height;}
        const unsigned& getAlpha () const{ return this->alpha;}

        ImageProcessing::RGBImage<Type>& operator =
        (const ImageProcessing::RGBImage<Type>& rgbImg);

        ImageProcessing::RGBImage<Type>& operator +=
        (const ImageProcessing::RGBImage<Type>& rgbImg);
        ImageProcessing::RGBImage<Type>& operator +=
        (const Type& rgbImg);

        ImageProcessing::RGBImage<Type>& operator -=
        (const ImageProcessing::RGBImage<Type>& rgbImg);
        ImageProcessing::RGBImage<Type>& operator -=
        (const Type& rgbImg);

        ImageProcessing::RGBImage<Type>& operator *=
        (const ImageProcessing::RGBImage<Type>& rgbImg);
        ImageProcessing::RGBImage<Type>& operator *=
        (const Type& rgbImg);

        ImageProcessing::RGBImage<Type>& operator /=
        (const ImageProcessing::RGBImage<Type>& rgbImg);
        ImageProcessing::RGBImage<Type>& operator /=
        (const Type& rgbImg);

        ImageProcessing::RGBImage<Type>& operator ~();
    private:
        LinAlg::Matrix<Type> red, green, blue;
        unsigned height, width, alpha;
    };

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator + (const ImageProcessing::RGBImage<Type>& lhs,
        const ImageProcessing::RGBImage<Type>& rhs) { return lhs += rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator + (const ImageProcessing::RGBImage<Type>& lhs,
        const Type& rhs) { return lhs += rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator + (const Type& lhs,
        const ImageProcessing::RGBImage<Type>& rhs){ return rhs += lhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator - (const ImageProcessing::RGBImage<Type>& lhs,
        const ImageProcessing::RGBImage<Type>& rhs) { return lhs -= rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator - (const ImageProcessing::RGBImage<Type>& lhs,
        const Type& rhs) { return lhs -= rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator - (const Type& lhs,
        const ImageProcessing::RGBImage<Type>& rhs){ return rhs -= lhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator * (const ImageProcessing::RGBImage<Type>& lhs,
        const ImageProcessing::RGBImage<Type>& rhs) { return lhs *= rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator * (const ImageProcessing::RGBImage<Type>& lhs,
        const Type& rhs) { return lhs *= rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator * (const Type& lhs,
        const ImageProcessing::RGBImage<Type>& rhs){ return rhs *= lhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator / (const ImageProcessing::RGBImage<Type>& lhs,
        const ImageProcessing::RGBImage<Type>& rhs) { return lhs /= rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator / (const ImageProcessing::RGBImage<Type>& lhs,
        const Type& rhs) { return lhs /= rhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type>& operator / (const Type& lhs,
        const ImageProcessing::RGBImage<Type>& rhs){ return rhs /= lhs;}

    template <class Type>
    ImageProcessing::RGBImage<Type> reScale( ImageProcessing::RGBImage<Type> rgbImage,const double &scale);

}
#include "rgbimage.hpp"
#endif // RGBIMAGE_H
