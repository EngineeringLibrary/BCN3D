#include "imageprocessing.h"

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::checkValue(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());

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

template <typename Type, typename OtherType>
LinAlg::Matrix<Type> ImageProcessing::hadamardProduct(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(left.getNumberOfRows(),left.getNumberOfColumns());

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i){
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
            ret(i,j) = left(i,j)*right(i,j);
        }
    }
    return ret;
}

template <typename Type, typename OtherType>
LinAlg::Matrix<Type> ImageProcessing::hadamardDivision(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(left.getNumberOfRows(),left.getNumberOfColumns());

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i){
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
            ret(i,j) = left(i,j)/right(i,j);
        }
    }
    return ret;
}

// faz parte da aula 5
template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::reScale(const LinAlg::Matrix<Type> &mat, const double &scale)
{
    LinAlg::Matrix<Type> ret;

    if(scale > 1)
        ret = LinAlg::Zeros<Type>((Type)ceil(mat.getNumberOfRows()*scale),(Type)ceil(mat.getNumberOfColumns()*scale));
    else
        ret = LinAlg::Zeros<Type>((Type)floor(mat.getNumberOfRows()*scale),(Type)floor(mat.getNumberOfColumns()*scale));

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
        {
            if(scale > 1){
                if(unsigned(ceil(i/scale)) <= mat.getNumberOfRows() && unsigned(ceil(j/scale)) <= mat.getNumberOfColumns())
                    ret(i,j) = mat(unsigned(ceil(i/scale)),unsigned(ceil(j/scale)));
            }
            else
                if(unsigned(ceil(i/scale)) >= 1 && unsigned(ceil(j/scale)) >= 1)
                    ret(i,j) = mat(unsigned(floor(i/scale)),unsigned(floor(j/scale)));
        }

    return ret;
}
// fim da aula 5

// faz parte da aula 6
template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::rotation(const LinAlg::Matrix<Type> &mat, const double &angle)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());
    LinAlg::Matrix<double> p1(2,1), p2(2,1), pos;
    LinAlg::Matrix<double> rot(2,2);

    double ang  = angle * M_PI/180;

    rot(1,1) = cos(ang); rot(1,2) = sin(ang);
    rot(2,1) = -sin(ang); rot(2,2) = cos(ang);

    p2(1,1) = mat.getNumberOfColumns()/2;
    p2(2,1) = mat.getNumberOfRows()/2;

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
            p1(1,1) = i - p2(2,1);
            p1(2,1) = j - p2(1,1);
            pos = (rot *p1) + p2;
            if(unsigned(pos(2,1))>0 && unsigned(pos(2,1)) <= mat.getNumberOfColumns() && unsigned(pos(1,1))>0 && unsigned(pos(1,1)) <= mat.getNumberOfRows())
                ret(i,j) = mat(Type(pos(1,1)),Type(pos(2,1)));
        }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::horizontalFlip(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
            ret(i,j) = mat(ret.getNumberOfRows() - i + 1, j);

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::verticalFlip(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
            ret(i,j) = mat(i, ret.getNumberOfColumns() - j + 1);

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::translation(const LinAlg::Matrix<Type> &mat, const double &xPos, const double &yPos)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
            if(i-xPos >= 1 && j+yPos >= 1 && i-xPos <= ret.getNumberOfRows() && j+yPos <= ret.getNumberOfColumns() )
                ret(i,j) = mat(i-xPos,j+yPos);

    return ret;
}
// fim da aula 6

//Aula 7
template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Histogram(const LinAlg::Matrix<Type> &img)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(1,256);

    for(unsigned i = 1; i <= img.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= img.getNumberOfColumns(); ++j)
        {
            int k = img(i,j);
            if(k == 0){ k=1;}
            ret(1,k) += 1;
        }

       return ret;
}
//fim Aula 7


//Aula 8
template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::contrastEnhancement(const LinAlg::Matrix<Type> &img,
                                                          const double &x1, const double &y1,
                                                          const double &x2, const double &y2)
{
    LinAlg::Matrix<Type> ret = img;
    double a1 = y1/x1;
    double b1 = 0.0;
    double a2 = (y2-y1)/(x2-x1);
    double b2 = y2 - a2*x2;
    double a3 = (255.0-y2)/(255.0-x2);
    double b3 = y2-a3*x2;

    for (unsigned i = 1; i <= img.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= img.getNumberOfColumns(); ++j)
        {
            if (ret(i,j) < x1)
                ret(i,j) = round(a1*ret(i,j)+b1);
            else if (ret(i,j) >= x1 && ret(i,j) < x2)
                ret(i,j) = round(a2*ret(i,j)+b2);
            else if (ret(i,j) >= x2)
                ret(i,j) = round(a3*ret(i,j)+b3);
            if(ret(i,j) > 255)
                ret(i,j) = 255;
            else if(ret(i,j) < 0)
                ret(i,j) = 0;
        }

    return ret;
}


//fim Aula 8

//Aula 9
template<typename Type>
LinAlg::Matrix<bool> ImageProcessing::limiarizationUpperOne(const LinAlg::Matrix<Type> &img, const Type &value)
{
    LinAlg::Matrix<bool> ret(img.getNumberOfRows(), img.getNumberOfColumns());

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
        {
            if(img(i,j) >= value)
                ret(i,j) = true;
            else
                ret(i,j) = false;
        }
    return ret;
}
//fim Aula 9

//Aula 10
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

//fim Aula 10

//Aula 12
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

//fimAula 12


//Aula 13
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
//fimAula 13

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::pixelToWorldMetric(const LinAlg::Matrix<Type> &img, const unsigned &realWorldWidth,
                                                                         const unsigned &realWorldHeight,
                                                                         const LinAlg::Matrix<Type> &pixelPosition2Transform)
{
   LinAlg::Matrix<Type> ret(1,2);
   ret(1,1)  = realWorldWidth*pixelPosition2Transform(1,1)/img.getNumberOfRows();
   ret(1,2)  = realWorldHeight*pixelPosition2Transform(1,2)/img.getNumberOfColumns();
   return ret;
}
