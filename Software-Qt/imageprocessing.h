#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

namespace ImageProcessing {
    template <typename Type>
    LinAlg::Matrix<Type> checkValue(const LinAlg::Matrix<Type> &mat);
    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> hadamardProduct(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right);
    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> hadamardDivision(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right);

    template <typename Type>
    LinAlg::Matrix<Type> reScale(const LinAlg::Matrix<Type> &mat, const double &scale);

    template <typename Type>
    LinAlg::Matrix<Type> rotation(const LinAlg::Matrix<Type> &mat, const double &angle);

    template <typename Type>
    LinAlg::Matrix<Type> horizontalFlip(const LinAlg::Matrix<Type> &mat);
    template <typename Type>
    LinAlg::Matrix<Type> verticalFlip(const LinAlg::Matrix<Type> &mat);

    template <typename Type>
    LinAlg::Matrix<Type> translation(const LinAlg::Matrix<Type> &mat, const double &xPos, const double &yPos);

    template <typename Type>
    LinAlg::Matrix<Type> Histogram(const LinAlg::Matrix<Type> &img);

    template <typename Type>
    LinAlg::Matrix<Type> contrastEnhancement(const LinAlg::Matrix<Type> &img, const double &x1, const double &y1,
                                                                              const double &x2, const double &y2);
    template <typename Type>
    LinAlg::Matrix<bool> limiarizationUpperOne(const LinAlg::Matrix<Type> &img, const Type &value);

    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> convolution2d(const LinAlg::Matrix<Type> &img, const LinAlg::Matrix<OtherType> &mask);

    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> discreteLaplacian(const LinAlg::Matrix<Type> &img, const OtherType &borderWeigth, const OtherType &maskWeigth);

    template <typename Type>
    LinAlg::Matrix<Type> medianFilter(const LinAlg::Matrix<Type> &img, const unsigned &sizeMask);

    template <typename Type>
    LinAlg::Matrix<Type> pixelToWorldMetric(const LinAlg::Matrix<Type> &img, const unsigned &realWorldWidth,
                                                                             const unsigned &realWorldHeight,
                                                                             const LinAlg::Matrix<Type> &pixelPosition2Transform);

}

#include "imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
