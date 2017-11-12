#include "binaryimage.h"

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator! () const
{
    ImageProcessing::BinaryImage ret = (*this);
    for(unsigned i = 1; i <= this->height; ++i)
        for(unsigned j = 1; j <= this->width; ++j)
            ret.binary(j,i) = !this->binary(j,i);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator== (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(j,i) = (bin.binary(j,i) == this->binary(j,i));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator!= (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(j,i) = (bin.binary(j,i) != this->binary(j,i));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator&& (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(j,i) = (bin.binary(j,i) && this->binary(j,i));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator|| (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(j,i) = (bin.binary(j,i) || this->binary(j,i));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::BinaryImage::operator^ (const ImageProcessing::BinaryImage& bin)
{
    ImageProcessing::BinaryImage ret = *this;

    if(this->height == bin.getHeight() && this->width == bin.getWidth())
        for(unsigned i = 1; i <= this->height; ++i)
            for(unsigned j = 1; j <= this->width; ++j)
                ret.binary(j,i) = (bin.binary(j,i) ^ this->binary(j,i));

    else
        std::cout << "Dimensoes não compativeis em operacao com imagens" << std::endl;

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator== (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(j,i) = (grayImage(j,i) == value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator!= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(j,i) = (grayImage(j,i) != value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator>  (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(j,i) = (grayImage(j,i) > value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator>= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(j,i) = (grayImage(j,i) >= value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator<  (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(j,i) = (grayImage(j,i) < value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator<= (const ImageProcessing::GrayImage<unsigned> &grayImage, const unsigned& value)
{
    ImageProcessing::BinaryImage ret(grayImage.getHeight(),grayImage.getWidth());

    for(unsigned i = 1; i <= grayImage.getHeight(); ++i)
        for(unsigned j = 1; j <= grayImage.getWidth(); ++j)
            ret(j,i) = (grayImage(j,i) <= value);

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::operator== (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage == value);
}

ImageProcessing::BinaryImage ImageProcessing::operator!= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage != value);
}

ImageProcessing::BinaryImage ImageProcessing::operator>  (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage > value);
}

ImageProcessing::BinaryImage ImageProcessing::operator>= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage >= value);
}

ImageProcessing::BinaryImage ImageProcessing::operator<  (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage < value);
}

ImageProcessing::BinaryImage ImageProcessing::operator<= (const unsigned& value, const ImageProcessing::GrayImage<unsigned> &grayImage)
{
    return (grayImage <= value);
}

//Aula 14
LinAlg::Matrix<bool> ImageProcessing::erosionMask(const ImageProcessing::BinaryImage &img, const unsigned &row, const unsigned &col)
{
    LinAlg::Matrix<bool> mask = LinAlg::Zeros<bool>(3,3);
    mask(2,2) = 1;

    if(row-1 > 0)
        if(img(row-1,col) == 1)
            mask(1,2) = 1;

    if(row-1 > 0 && col+1 <= img.getWidth())
        if(img(row-1,col+1) == 1)
            mask(1,3) = 1;

    if(col+1 <= img.getWidth())
        if(img(row,col+1) == 1)
            mask(2,3) = 1;

    if(row+1 <= img.getWidth() && col+1 <= img.getWidth())
        if(img(row+1,col+1) == 1)
            mask(3,3) = 1;

    if(row+1 <= img.getWidth())
        if(img(row+1,col) == 1)
            mask(3,2) = 1;

    if(row+1 <= img.getWidth() && col-1 > 0)
        if(img(row+1,col-1) == 1)
            mask(3,1) = 1;

    if(col-1 > 0 )
        if(img(row,col-1) == 1)
            mask(2,1) = 1;

    if(row-1 > 0 && col-1 > 0)
        if(img(row-1, col-1) == 1)
            mask(1,1) = 1;

    return mask;
}

ImageProcessing::BinaryImage ImageProcessing::erosion(const ImageProcessing::BinaryImage &img)
{
    LinAlg::Matrix<bool> ret(img.getWidth(),img.getHeight());
    LinAlg::Matrix<bool> one = LinAlg::Ones<bool>(3,3);

    for(unsigned i = 1; i < ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j < ret.getNumberOfColumns(); ++j)
        {
            if(img(i,j) == 1){
                LinAlg::Matrix<bool> mask = ImageProcessing::erosionMask(img,i,j);
                if(LinAlg::isEqual<bool>(mask,one))
                    ret(i,j) = 1;
            }
        }

    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::dilation(const ImageProcessing::BinaryImage &img)
{
    ImageProcessing::BinaryImage ret = !img;
    ret = (ImageProcessing::erosion(ret));
    ret = (!ret);
    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::closing(const ImageProcessing::BinaryImage &img)
{
    ImageProcessing::BinaryImage ret = ImageProcessing::dilation(img);
    ret = ImageProcessing::erosion(ret);
    return ret;
}

ImageProcessing::BinaryImage ImageProcessing::opening(const ImageProcessing::BinaryImage &img)
{
    ImageProcessing::BinaryImage ret = ImageProcessing::erosion(img);
    ret = ImageProcessing::dilation(ret);
    return ret;
}

LinAlg::Matrix<LinAlg::Matrix<unsigned>* >* ImageProcessing::bound(const ImageProcessing::BinaryImage &mat)
{
    LinAlg::Matrix< LinAlg::Matrix<unsigned>* > *t = new LinAlg::Matrix< LinAlg::Matrix<unsigned>* >(1,2);
    (*t)(1,1) = new LinAlg::Matrix<unsigned>(1,1);
    (*t)(1,2) = new LinAlg::Matrix<unsigned>(mat.getWidth(),mat.getHeight());
    LinAlg::Matrix<unsigned> aux,   x = LinAlg::Zeros<unsigned>(1,4*mat.getWidth()*mat.getHeight()),
                                    y = LinAlg::Zeros<unsigned>(1,4*mat.getWidth()*mat.getHeight());
    aux = mat.getBinaryImageMatrix();
    unsigned ret;
    unsigned cont = 0, cont2 = 1;
    bool ok = false;

    if(sizeof(mat(1,1)) == sizeof(bool))
    {
        for(unsigned i = 1; i <= aux.getNumberOfRows(); ++i){
            for(unsigned j= 1; j <= aux.getNumberOfColumns(); ++j){
                if(aux(i,j) == 1){
                    x(1,1) = i;
                    y(1,1) = j;
                    aux(i,j) = cont + 1;
                    ok = true;
                    break;
                }else{
                    x(1,1) = 0;
                    y(1,1) = 0;
                }
            }
            if(ok)
                break;
        }

        cont2 = 2;

        while(x(1,1) != 0 && x(1,1) != 0){
            for(unsigned j = 1; j <= aux.getNumberOfColumns()*aux.getNumberOfRows(); ++j){
                if(cont2-1 < j)
                    continue;
                if(x(1,j)-1 > 0){
                    if(aux(x(1,j)-1,y(1,j)) == 1){
                        aux(x(1,j)-1,y(1,j)) = cont + 1;
                        x(1,cont2) = x(1,j)-1;
                        y(1,cont2) = y(1,j);
                        cont2 = cont2+1;
                    }
                }
                if(x(1,j)+1 <= aux.getNumberOfRows()){
                    if(aux(x(1,j)+1,y(1,j)) == 1){
                        aux(x(1,j)+1,y(1,j)) = cont+1;
                        x(1,cont2) = x(1,j)+1;
                        y(1,cont2) = y(1,j);
                        cont2=cont2+1;
                    }
                }
                if(y(1,j)-1 > 0){
                   if(aux(x(1,j),y(1,j)-1) == 1){
                        aux(x(1,j),y(1,j)-1) = cont+1;
                        x(1,cont2) = x(1,j);
                        y(1,cont2) = y(1,j)-1;
                        cont2=cont2+1;
                   }
                }
                if(y(1,j)+1 <= aux.getNumberOfColumns()){
                    if(aux(x(1,j),y(1,j)+1) == 1){
                        aux(x(1,j),y(1,j)+1) = cont+1;
                        x(1,cont2) = x(1,j);
                        y(1,cont2) = y(1,j)+1;
                        cont2 = cont2+1;
                    }
                }
            }
            cont  = cont+1;
            cont2 = 2;
            ok = false;
            for(unsigned i = 1; i <= aux.getNumberOfRows(); ++i){
                for(unsigned j = 1; j <= aux.getNumberOfColumns(); ++j){
                    if(aux(i,j) == 1){
                        x(1,1) = i;
                        y(1,1) = j;
                        aux(i,j) = cont + 1;
                        ok = true;
                        break;
                    }else{
                        x(1,1) = 0;
                        y(1,1) = 0;
                    }
                }
                if(ok)
                    break;
            }
        }
        ret = cont - 1;
    }
    else
    {
        std::cout << "Apenas com Imagens Booleanas, ou seja binarias" << std::endl;
    }
    (*((*t)(1,1))) = LinAlg::Matrix<unsigned>((unsigned)ret);
    (*((*t)(1,2))) = aux;
    return t;
}

unsigned ImageProcessing::area(const ImageProcessing::BinaryImage &img)
{
    unsigned ret = 0;
    for(unsigned i = 1; i <= img.getWidth(); ++i)
        for(unsigned j = 1; j <= img.getHeight(); ++j)
            ret += img(i,j);
    return ret;
}

LinAlg::Matrix<unsigned> ImageProcessing::centroid(const ImageProcessing::BinaryImage &img)
{
    unsigned inc=0, x = 0, y = 0;
    for(unsigned i = 1; i <= img.getWidth(); ++i)
    {
        unsigned temp = 0;
        for(unsigned j = 1; j <= img.getHeight(); ++j)
            if(img(i,j)==1)
                temp += 1;
        x += i*temp;
        inc += temp;
    }
    x /= inc;

    inc = 0;
    for(unsigned j = 1; j <= img.getHeight(); ++j)
    {
        unsigned temp = 0;
        for(unsigned i = 1; i <= img.getWidth(); ++i)
            if(img(i,j)==1)
                temp += 1;
        y += j*temp;
        inc += temp;
    }
    y /= inc;

    LinAlg::Matrix<unsigned> ret(1,2);
    ret(1,1) = x; ret(1,2) = y;
    return ret;
}
