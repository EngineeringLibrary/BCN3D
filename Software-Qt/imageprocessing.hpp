#include "imageprocessing.h"

template<typename Type>
LinAlg::Matrix<Type> ImageProcessing::checkValue(
        const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),
                             mat.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
        {
            if(mat(i,j) > 255)
                ret(i,j) = 255;
            else if(mat(i,j) < 0)
                ret(i,j) = 0;
            else
                ret(i,j) = mat(i,j);
        }
    return ret;
}

template<typename Type, typename OtherType>
LinAlg::Matrix<Type> ImageProcessing::hadamardProduct(
        const LinAlg::Matrix<Type> &left,
        const LinAlg::Matrix<OtherType> &right)
{
    LinAlg::Matrix<Type> ret(left.getNumberOfRows(),
                             left.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
            ret(i,j) = left(i,j)*right(i,j);
    return ret;
}

template<typename Type, typename OtherType>
LinAlg::Matrix<Type> ImageProcessing::hadamardDivision(
        const LinAlg::Matrix<Type> &left,
        const LinAlg::Matrix<OtherType> &right)
{
    LinAlg::Matrix<Type> ret(left.getNumberOfRows(),
                             left.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
            ret(i,j) = left(i,j)/right(i,j);
    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> ImageProcessing::reScale( const LinAlg::Matrix<Type> &mat,const double &scale){
//aumentando ou reduzindo a escala da imagem
    LinAlg::Matrix<Type> ret;

    if(scale > 1)
        ret = LinAlg::Zeros<Type>(
                    (unsigned)ceil(mat.getNumberOfRows()*scale),
                    (unsigned)ceil(mat.getNumberOfColumns()*scale));
    else
        ret = LinAlg::Zeros<Type>(
                    (unsigned)floor(mat.getNumberOfRows()*scale),
                    (unsigned)floor(mat.getNumberOfColumns()*scale));

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i){
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
            if(scale > 1){
                if(unsigned(ceil(i/scale)) <= mat.getNumberOfRows() && unsigned(ceil(j/scale)) <= mat.getNumberOfColumns()){
                    ret(i,j) = mat(unsigned(ceil(i/scale)),unsigned(ceil(j/scale)));
                }else{
                     if(unsigned(ceil(i/scale)) >= 1 && unsigned(ceil(j/scale)) >= 1){
                         ret(i,j) = mat(unsigned(floor(i/scale)),unsigned(floor(j/scale)));
                     }
                }
            }
        }
    }
    return ret;
 }
