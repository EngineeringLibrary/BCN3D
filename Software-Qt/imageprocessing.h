#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

namespace ImageProcessing
{
    template<typename Type>
    LinAlg::Matrix<Type> checkValue(
            const LinAlg::Matrix<Type> &mat);
    template<typename Type, typename OtherType>
    LinAlg::Matrix<Type> hadamardProduct(
            const LinAlg::Matrix<Type> &left,
            const LinAlg::Matrix<OtherType> &right);
    template<typename Type, typename OtherType>
    LinAlg::Matrix<Type> hadamardDivision(
            const LinAlg::Matrix<Type> &left,
            const LinAlg::Matrix<OtherType> &right);

    template<typename Type>
    LinAlg::Matrix<Type> reScale(const LinAlg::Matrix<Type> &mat,  const double &scale);

    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> convolution2d(const LinAlg::Matrix<Type> &img, const LinAlg::Matrix<OtherType> &mask);

    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> discreteLaplacian(const LinAlg::Matrix<Type> &img, const OtherType &borderWeigth, const OtherType &maskWeigth);

    template <typename Type>
    LinAlg::Matrix<Type> medianFilter(const LinAlg::Matrix<Type> &img, const unsigned &sizeMask);
}

#include "imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
