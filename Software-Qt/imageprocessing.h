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
}

#include "imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
