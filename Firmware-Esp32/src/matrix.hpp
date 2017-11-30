#include "matrix.h"


template<typename Type>
LinAlg::Matrix<Type>::Matrix (Type Number)
{
    this->Init(1,1);
    this->mat[0][0] = Number;
}

template<typename Type>
LinAlg::Matrix<Type>::Matrix (const char* Mat)
{
    this->rows = 0;
    this->columns = 0;
    this->Init(Mat);
}

template<typename Type>
LinAlg::Matrix<Type>::Matrix (unsigned row, unsigned column)
{
    if(row == 0 || column == 0)
    {
        this->rows = 0; this->columns = 0;
    }
    else
    {
        this->Init(row, column);
    }
}

template<typename Type>
LinAlg::Matrix<Type>::Matrix (const LinAlg::Matrix<Type>& otherMatrix)
{
    this->Init(otherMatrix.rows, otherMatrix.columns);

    for(unsigned i = 0; i < otherMatrix.rows; i++)
        for(unsigned j = 0; j < otherMatrix.columns; j++)
            this->mat[i][j] = otherMatrix.mat[i][j];
}

template<typename Type>
LinAlg::Matrix<Type>::~Matrix ()
{
    if(columns != 0 || rows != 0)
    {
        for(unsigned i = 0; i < this->rows; i++)
            delete[] this->mat[i];
        delete this->mat;
    }

    this->rows = 0;
    this->columns = 0;

    this->mat = NULL;
}

template<typename Type>
void LinAlg::Matrix<Type>::Init (std::string Mat)
{
    unsigned commas = 1, semiColons = 1, row, column, lin = 0, col = 0;
    int posComma = 0, posSemiColon = 0;
    std::string temp;

    for(unsigned i = 0; i < Mat.length(); ++i)
    {
        if(Mat[i] == ';')
            semiColons += 1;
        else if (Mat[i] == ',')
            commas += 1;
    }

    row = semiColons;
    column = (commas + semiColons - 1)/semiColons;

    this->Init(row, column);

    while(!(Mat.empty()))
    {
        posSemiColon = Mat.find(";");
        if(posSemiColon != -1)
            temp = Mat.substr(0, posSemiColon);
        else
        {
            temp = Mat;
            posSemiColon = Mat.length();
        }

        while(!(temp.empty()))
        {
            posComma = temp.find(",");
            if (posComma == -1)
                posComma = temp.length();

            std::string temp2 = temp.substr(0, posComma);
            Type number;
            std::stringstream ss(temp2);

            if(temp2 == "")
                number = 0;
            else
                ss >> number;

            this->mat[lin][col] =  number;
            temp.erase(0, posComma + 1);
            col++;
        }

        Mat.erase(0, posSemiColon + 1);
        col = 0;
        lin++;
    }
}

template<typename Type>
void LinAlg::Matrix<Type>::Init (unsigned row, unsigned column)
{
    if(row == 0  && column == 0){
        this->rows = 0;
        this->columns = 0;
    }
    else{
        this->rows = row;
        this->columns = column;

        this->mat = new Type*[row]();
        for(unsigned i = 0; i < row; i++)
            this->mat[i] = new Type[column]();
    }
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator= (const LinAlg::Matrix<Type>& rhs) const
{
    if(rhs.rows !=0 || rhs.columns !=0)
        for(unsigned i = 0; i < this->rows; i++)
        	for(unsigned j = 0; j < this->columns; j++)
            	this->mat[i][j] = rhs.mat[i][j];

    return *this;
}

template<typename Type>
bool LinAlg::Matrix<Type>::CheckDimensions (const LinAlg::Matrix<Type>& rhs, unsigned operation)
{
    bool checked = false;

    switch(operation)
    {
    case 0:
        if((this->rows == rhs.getNumberOfRows()) && (this->columns == rhs.getNumberOfColumns()))
            checked = true;
        else
            printf("As dimensoes nao batem. Impossivel realizar operacao.\n");
        break;
    case 1:
        if(this->columns == rhs.getNumberOfRows())
            checked = true;
        else
            printf("As dimensoes nao batem. Impossivel realizar operacao.\n");
        break;
    }

    return checked;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator+= (const Type& rhs)
{
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this-> columns; j++)
            this->mat[i][j] += rhs;

    return *this;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator+= (const LinAlg::Matrix<Type>& rhs)
{
    if(CheckDimensions(rhs, 0))
    {
        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->columns; j++)
                this->mat[i][j] += rhs.mat[i][j];
    }

    return *this;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator-= (const Type& rhs /*scalar*/)
{
    return *this += -1*rhs;
}


template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator-= (const LinAlg::Matrix<Type>& rhs)
{
    return *this += -rhs;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator*= (const Type& rhs /*scalar*/)
{
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this->columns; j++)
            this->mat[i][j] *= rhs;

    return *this;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator*= (const LinAlg::Matrix<Type>& rhs)
{

    if ((this->rows == 1) && (this->columns == 1))
    {
        LinAlg::Matrix<Type> Temp = rhs;
        for(unsigned i = 0; i < rhs.rows; ++i)
            for(unsigned j = 0; j < rhs.columns; ++j)
                Temp.mat[i][j] = rhs.mat[i][j] * this->mat[0][0];
        *this = Temp;
    }

    else if(CheckDimensions(rhs, 1))
    {
        Type temp;
        LinAlg::Matrix<Type> tempMat(*this);
        this->Init(this->rows, rhs.columns);

        for(unsigned i = 0; i < tempMat.rows; i++)
            for(unsigned col = 0; col < rhs.columns; col++)
            {
                temp = 0;
                for(unsigned j = 0; j < tempMat.columns; j++)
                    temp += tempMat.mat[i][j] * rhs.mat[j][col];
                this->mat[i][col] = temp;
            }
    }

    return *this;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::operator- (const LinAlg::Matrix<Type>& mat)
{
    LinAlg::Matrix<Type> temp(mat);

    for(unsigned i = 0; i < temp.getNumberOfRows(); i++)
        for(unsigned j = 0; j < temp.getNumberOfColumns(); j++)
            temp(i, j) *= -1;

    return temp;
}

template<typename Type>
std::ostream& LinAlg::operator<< (std::ostream& output, const LinAlg::Matrix<Type> mat)
{
    if(mat.getNumberOfColumns() == 0){
        return output;
    }

    for(unsigned i = 0; i < mat.getNumberOfRows(); i++)
    {
        for(unsigned j = 0; j < mat.getNumberOfColumns(); j++)
            if(mat(i, j) != 0)
                output << std::setw(2*coutPrecision+1) << std::setprecision(coutPrecision) << std::fixed << mat(i, j) << ' ';
            else
                output << std::setw(2*coutPrecision+1) << std::setprecision(0) << std::fixed << mat(i, j) << ' ';

        output << std::endl;
    }

    return output;
}
