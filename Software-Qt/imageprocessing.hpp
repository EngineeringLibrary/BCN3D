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

template <typename Type, typename OtherType>
LinAlg::Matrix<Type> ImageProcessing::convolution2d(const LinAlg::Matrix<Type> &img, const LinAlg::Matrix<OtherType> &mask)
{
    LinAlg::Matrix<Type> ret(img.getNumberOfRows(),img.getNumberOfColumns());
    for(unsigned i = 1; i <= img.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= img.getNumberOfColumns(); ++j)
        {
            for(unsigned p = 1; p <= mask.getNumberOfRows(); ++p)
            {
                for(unsigned q = 1; q <= mask.getNumberOfColumns(); ++q)
                    if(i-p+1 > 0 && i-p+1 <= img.getNumberOfRows() && j-q+1 > 0 && j-q+1 <= img.getNumberOfColumns())
                        ret(i,j) += (Type)(mask(p,q)*img(i-p+1,j-q+1));
            }
        }

    ret = ImageProcessing::checkValue(ret);
    return ret;
}

template <typename Type, typename OtherType>
LinAlg::Matrix<Type> ImageProcessing::discreteLaplacian(const LinAlg::Matrix<Type> &img, const OtherType &borderWeigth, const OtherType &maskWeigth)
{
    LinAlg::Matrix<OtherType> mask(3,3);
    mask(1,2) = -maskWeigth;
    mask(2,1) = -maskWeigth; mask(2,2) = 1+4*maskWeigth; mask(2,3) = -maskWeigth;
    mask(3,2) = -maskWeigth;

    LinAlg::Matrix<OtherType> border = ImageProcessing::convolution2d(img,mask);

    return ImageProcessing::checkValue(img - borderWeigth*border);
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::medianFilter(const LinAlg::Matrix<Type> &img, const unsigned &sizeMask)
{
    if(sizeMask%2 == 0)
    {
        std::cout << "a mascara deve ser impar" << std::endl;
        return LinAlg::Matrix<Type>();
    }

    unsigned x = unsigned(round((sizeMask-1)/2.0));
    LinAlg::Matrix<Type> ret = img;
    for(unsigned i = 1 + x; i <= img.getNumberOfRows() - x; ++i)
        for(unsigned j = 1 + x; j <= img.getNumberOfColumns() - x; ++j)
        {
            unsigned counter = 1;
            LinAlg::Matrix<Type> mask = img(from(i-x)-->(i+x),from(j-x)-->(j+x));
            LinAlg::Matrix<Type> linearMask(1,mask.getNumberOfRows()*mask.getNumberOfColumns());

            for(unsigned k = 1; k <= mask.getNumberOfRows(); ++k)
                for(unsigned l = 1; l <= mask.getNumberOfColumns(); ++l)
                {
                    linearMask(1,counter) = mask(k,l);
                    counter++;
                }

            for(unsigned k = 1; k <= linearMask.getNumberOfColumns(); ++k)
                for(unsigned l = k+1; l <= linearMask.getNumberOfColumns(); ++l)
                    if(linearMask(1,l) > linearMask(1,k))
                    {
                        Type temp =  linearMask(1,k);
                        linearMask(1,k) = linearMask(1,l);
                        linearMask(1,l) = temp;
                    }

            ret(i,j) = linearMask(1,unsigned(round((linearMask.getNumberOfColumns())/2.0)));
        }

    ret = ImageProcessing::checkValue(ret);
    return ret;
}
