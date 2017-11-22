#ifdef testMatrix
    #include "../../../../headers/primitiveLibs/LinAlg/matrix.h"
#else
    #ifdef testPolynom
        #include "../../../headers/primitiveLibs/LinAlg/matrix.h"
    #else
        #include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
    #endif
#endif

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
LinAlg::Matrix<Type>::Matrix (std::string Mat)
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

template<typename Type> template<typename OtherMatrixType>
LinAlg::Matrix<Type>::Matrix (const LinAlg::Matrix<OtherMatrixType>& otherMatrix)
{
    this->Init(otherMatrix.getNumberOfRows(), otherMatrix.getNumberOfColumns());

    for(unsigned i = 0; i < otherMatrix.getNumberOfRows(); i++)
        for(unsigned j = 0; j < otherMatrix.getNumberOfColumns(); j++)
            this->mat[i][j] = (Type)otherMatrix(i+1,j+1);
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
void LinAlg::Matrix<Type>::removeRow(unsigned row)
{
    if(this->rows == 1)
    {
        this->rows = 0;
        this->columns = 0;
    }
    else
    {
        LinAlg::Matrix<Type> Temp;
        for(unsigned i = 0; i < this->rows; ++i)
                if(i != row-1)
                    Temp = Temp||this->getRow(i+1);
        *this = Temp;
    }
}

template<typename Type>
void LinAlg::Matrix<Type>::removeColumn(unsigned column)
{
    if(this->columns == 1)
    {
        this->rows = 0;
        this->columns = 0;
    }
    else
    {
        LinAlg::Matrix<Type> Temp;
        for(unsigned i = 0; i < this->columns; ++i)
                if(i != column-1)
                   Temp = Temp|this->getColumn(i+1);
        *this = Temp;
    }
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

//    LinAlg::Zeros(*this);
}

template<typename Type>
void LinAlg::Matrix<Type>::ReInit (unsigned row, unsigned column)
{
    LinAlg::Matrix<Type> temp(row, column);

    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this->columns; j++)
            temp.mat[i][j] = this->mat[i][j];

    *this = temp;
}

template<typename Type>
void LinAlg::Matrix<Type>::Add (unsigned row, unsigned column, Type number)
{
    unsigned greaterRow, greaterColumn;

    if(((row + 1) > this->rows) || ((column + 1) > this->columns))
    {
        if((row + 1) > this->rows)
            greaterRow = row + 1;
        else
            greaterRow = this->rows;

        if((column + 1) > this->columns)
            greaterColumn = column + 1;
        else
            greaterColumn = this->columns;

        this->ReInit(greaterRow, greaterColumn);
    }

    this->mat[row][column] = number;
}

template<typename Type> template<typename OtherMatrixType>
bool LinAlg::Matrix<Type>::CheckDimensions (const LinAlg::Matrix<OtherMatrixType>& rhs, unsigned operation)
{
    bool checked = false;

    switch(operation)
    {
    case 0:
        if((this->rows == rhs.getNumberOfRows()) && (this->columns == rhs.getNumberOfColumns()))
            checked = true;
        else
            std::cout << "As dimensoes nao batem. Impossivel realizar operacao." << std::endl;
        break;
    case 1:
        if(this->columns == rhs.getNumberOfRows())
            checked = true;
        else
            std::cout << "As dimensoes nao batem. Impossivel realizar operacao." << std::endl;
        break;
    }

    return checked;
}

template<typename Type> template<typename OtherMatrixType>
void LinAlg::Matrix<Type>::swap (const LinAlg::Matrix<OtherMatrixType>& otherMatrix)
{
    using std::swap;

    LinAlg::Matrix<Type> temp(otherMatrix.getNumberOfRows(), otherMatrix.getNumberOfColumns());

    for(unsigned i = 0; i < temp.rows; i++)
        for(unsigned j = 0; j < temp.columns; j++)
            temp.mat[i][j] = otherMatrix(i + 1, j + 1);

    swap (rows, temp.rows);
    swap (columns, temp.columns);

    swap (mat, temp.mat);
}

template<typename Type>
unsigned LinAlg::Matrix<Type>::getNumberOfRows () const
{
    return this->rows;
}

template<typename Type>
unsigned LinAlg::Matrix<Type>::getNumberOfColumns () const
{
    return this->columns;
}

template<typename Type>
bool LinAlg::Matrix<Type>::isNull ()
{
    bool ret = false;

    if(this->mat == NULL)
        ret = true;

    return ret;
}

template<typename Type>
bool LinAlg::Matrix<Type>::isSquare ()
{
    bool ret = false;

    if(this->rows == this->columns)
        ret = true;

    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::getRow (const unsigned &number_of_the_row) const
{
    LinAlg::Matrix<Type> ret(1, this->columns);

    for(unsigned j = 0; j < ret.columns; j++)
        ret.mat[0][j] = this->mat[number_of_the_row - 1][j];

    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::getColumn (const unsigned &number_of_the_column) const
{
    LinAlg::Matrix<Type> ret(this->rows, 1);

    for(unsigned i = 0; i < ret.rows; i++)
        ret.mat[i][0] = this->mat[i][number_of_the_column - 1];

    return ret;
}

template <typename Type>
void LinAlg::Matrix<Type>::swapRows (unsigned row_to_be_swapped, unsigned row_to_take_place)
{
    LinAlg::Matrix<Type> aux1, aux2;

    aux1 = this->getRow(row_to_be_swapped);
    aux2 = this->getRow(row_to_take_place);

    for(unsigned j = 0; j < this->columns; j++)
    {
        this->mat[row_to_be_swapped - 1][j] = aux2.mat[0][j];
        this->mat[row_to_take_place - 1][j] = aux1.mat[0][j];
    }
}

template <typename Type>
void LinAlg::Matrix<Type>::swapColumns (unsigned column_to_be_swapped, unsigned column_to_take_place)
{
    LinAlg::Matrix<Type>aux1, aux2;

    aux1 = this->getColumn(column_to_be_swapped);
    aux2 = this->getColumn(column_to_take_place);

    for(unsigned i = 0; i < this->rows; i++)
    {
        this->mat[i][column_to_be_swapped - 1] = aux2.mat[i][0];
        this->mat[i][column_to_take_place - 1] = aux1.mat[i][0];
    }
}

template <typename Type>
unsigned LinAlg::Matrix<Type>::length () const
{
    unsigned ret;

    if(this->rows >= this->columns)
        ret = this->rows;
    else
        ret = this->columns;

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::size () const
{
    LinAlg::Matrix<Type> ret(1,2);

    ret(1,1) = this->rows;
    ret(1,2) = this->columns;

    return ret;
}

template<typename Type>
Type& LinAlg::Matrix<Type>::operator() (unsigned row, unsigned column)
{
    return this->mat[row - 1][column - 1];
}

template<typename Type>
Type LinAlg::Matrix<Type>::operator() (unsigned row, unsigned column) const
{
    return this->mat[row - 1][column - 1];
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(unsigned* row_interval, unsigned* column_interval)const
{
    LinAlg::Matrix<Type> Ret;

    if(row_interval[0] < row_interval[1]){
        if(column_interval[0] < column_interval[1]){
            Ret.Init(row_interval[1] - row_interval[0] + 1, column_interval[1] - column_interval[0] + 1);
            for(unsigned i = row_interval[0]; i <= row_interval[1]; ++i)
                for(unsigned j = column_interval[0]; j <= column_interval[1]; ++j)
                    Ret.mat[i - row_interval[0]][j - column_interval[0]] = this->mat[i-1][j-1];

        }else{
            Ret.Init(row_interval[1] - row_interval[0] + 1, column_interval[0] - column_interval[1] + 1);
            for(unsigned i = row_interval[0]; i <= row_interval[1]; ++i)
                for(unsigned j = column_interval[0]; j >= column_interval[1]; --j)
                    Ret.mat[i - row_interval[0]][column_interval[0] - j] = this->mat[i-1][j - 1];
        }

    } else{
        if(column_interval[0] < column_interval[1]){
            Ret.Init(row_interval[0] - row_interval[1] + 1, column_interval[1] - column_interval[0] + 1);
            for(unsigned i = row_interval[0]; i >= row_interval[1]; --i)
                for(unsigned j = column_interval[0]; j <= column_interval[1]; ++j)
                    Ret.mat[row_interval[0] - i][j - column_interval[0]] = this->mat[i-1][j-1];
        }else /*if(column_interval[1] > 0 && column_interval[0] < this->columns)*/{
            Ret.Init(row_interval[0] - row_interval[1] + 1, column_interval[0] - column_interval[1] + 1);
            for(unsigned i = row_interval[0]; i >= row_interval[1]; --i)
                for(unsigned j = column_interval[0]; j >= column_interval[1]; --j)
                    Ret.mat[row_interval[0] - i][column_interval[0] - j] = this->mat[i-1][j - 1];
        }
    }

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(unsigned row, unsigned* column_interval)const
{
    LinAlg::Matrix<Type> Ret;

//    std::cout << column_interval[0] << " , " << column_interval[1] << "\n\n";
    if(column_interval[0] <= column_interval[1]){
        Ret.Init(1, column_interval[1] - column_interval[0] + 1);
        for(unsigned j = column_interval[0]; j <= column_interval[1]; ++j)
            Ret.mat[0][j - column_interval[0]] = this->mat[row - 1][j - 1];

    }else if(column_interval[1] > 0 && column_interval[0] < this->columns){
        Ret.Init(1, column_interval[0] - column_interval[1] + 1);
        for(unsigned j = column_interval[0]; j >= column_interval[1]; --j)
            Ret.mat[0][column_interval[0] - j] = this->mat[row - 1][j - 1];
    }

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(unsigned* row_interval, unsigned column)const
{
    LinAlg::Matrix<Type> Ret;

    if(row_interval[0] <= row_interval[1]){
        Ret.Init(row_interval[1] - row_interval[0] + 1, 1);
        for(unsigned i = row_interval[0]; i <= row_interval[1]; ++i)
            Ret.mat[i - row_interval[0]][0] = this->mat[i - 1][column - 1];
    } else{
//        unsigned aux = row_interval[0] - row_interval[1] + 1;

        Ret.Init(row_interval[0] - row_interval[1] + 1, 1);
        for(unsigned i = row_interval[0]; i >= row_interval[1]; --i)
            Ret.mat[row_interval[0] - i][0] = this->mat[i - 1][column - 1];
    }

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(unsigned* row_interval, LinAlg::Matrix<Type> columns)const
{
    LinAlg::Matrix<Type> Ret;

    if(row_interval[0] <= row_interval[1]){
        Ret.Init(row_interval[1] - row_interval[0] + 1, columns.getNumberOfColumns());
        for(unsigned i = row_interval[0]; i <= row_interval[1]; ++i)
            for(unsigned j = 1; j <= columns.getNumberOfColumns(); ++j)
                Ret.mat[i - row_interval[0]][j-1] = this->mat[i - 1][unsigned(columns(1,j)) - 1];
    } else{
//        unsigned aux = row_interval[0] - row_interval[1] + 1;

        Ret.Init(row_interval[0] - row_interval[1] + 1, columns.getNumberOfColumns());
        for(unsigned i = row_interval[0]; i >= row_interval[1]; --i)
            for(unsigned j = 1; j <= columns.getNumberOfColumns(); ++j)
                Ret.mat[row_interval[0] - i][j-1] = this->mat[i - 1][unsigned(columns(1,j)) - 1];
    }

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(LinAlg::Matrix<Type> rows, unsigned* column_interval)const
{
    LinAlg::Matrix<Type> Ret;

    if(column_interval[0] <= column_interval[1]){
        Ret.Init(rows.getNumberOfColumns(),column_interval[1] - column_interval[0] + 1);
        for(unsigned i = 1; i <= rows.getNumberOfColumns(); ++i)
            for(unsigned j = column_interval[0]; j <= column_interval[1]; ++j)
                Ret.mat[i-1][j - column_interval[0]] = this->mat[unsigned(rows(1,i)) - 1][j - 1];
    } else{
        Ret.Init(rows.getNumberOfColumns(), column_interval[0] - column_interval[1] + 1);
        for(unsigned i = 1; i <= rows.getNumberOfColumns(); ++i)
            for(unsigned j = column_interval[0]; j >= column_interval[1]; --j)
                Ret.mat[i-1][column_interval[0] - j] = this->mat[unsigned(rows(1,i)) - 1][j - 1];
    }


    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(unsigned row, LinAlg::Matrix<Type> columns)const
{
    LinAlg::Matrix<Type> Ret;

    Ret.Init(1, columns.getNumberOfColumns());
    for(unsigned j = 1; j <= columns.getNumberOfColumns(); ++j)
        Ret.mat[0][j-1] = this->mat[row - 1][unsigned(columns(1,j)) - 1];

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(LinAlg::Matrix<Type> rows, unsigned column)const
{
    LinAlg::Matrix<Type> Ret;

    Ret.Init(rows.getNumberOfColumns(), 1);
    for(unsigned j = 1; j <= rows.getNumberOfColumns(); ++j)
        Ret.mat[j-1][0] = this->mat[unsigned(rows(1,j)) - 1][column - 1];

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator ()(LinAlg::Matrix<Type> rows, LinAlg::Matrix<Type> column)const
{
    LinAlg::Matrix<Type> Ret;

    Ret.Init(rows.getNumberOfColumns(), column.getNumberOfColumns());
    for(unsigned i = 1; i <= rows.getNumberOfColumns(); ++i)
        for(unsigned j = 1; j <= column.getNumberOfColumns(); ++j)
            Ret.mat[i-1][j-1] = this->mat[unsigned(rows(1,i)) - 1][unsigned(column(1,j)) - 1];

    return Ret;
}

template<typename Type>
void LinAlg::Matrix<Type>::operator= (const char* Mat)
{
    this->Init(Mat);
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator= (const LinAlg::Matrix<Type>& rhs) const
{
    if(rhs.rows !=0 || rhs.columns !=0)
        swap(rhs);

    return *this;
}

template<typename Type> template<typename MatrixLeftType>
void LinAlg::Matrix<Type>::operator= (LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* > *rhs)
{
    for(unsigned i = 1; i <= this->getNumberOfColumns(); ++i )
        *((*this)(1,i)) = *((*rhs)(1,i));
}

template<typename Type> template<typename OtherMatrixType>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator= (const LinAlg::Matrix<OtherMatrixType>& rhs)
{
    if(rhs.getNumberOfRows() !=0 || rhs.getNumberOfColumns() !=0)
        swap(rhs);

    return *this;
}

template<typename MatrixLeftType, typename MatrixRigthType>
LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* >* LinAlg::operator, (LinAlg::Matrix<MatrixLeftType> &lhs, LinAlg::Matrix<MatrixRigthType> &rhs)
{
    LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* > *A = new LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* >(1,2);
    (*A)(1,1) = &lhs;
    (*A)(1,2) = &rhs;
    return A;
}

template<typename MatrixLeftType, typename MatrixRigthType>
LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* >* LinAlg::operator, (LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* >* lhs, LinAlg::Matrix<MatrixRigthType> &rhs)
{
    LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* > *A = new LinAlg::Matrix< LinAlg::Matrix<MatrixLeftType>* >(1,(*lhs).getNumberOfColumns()+1);
    for(unsigned i = 1; i <= (*lhs).getNumberOfColumns(); ++i)
        (*A)(1,i) = (*lhs)(1,i);
    (*A)(1,(*lhs).getNumberOfColumns()+1) = &rhs;
    return A;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator+= (const Type& rhs /*scalar*/)
{
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this-> columns; j++)
            this->mat[i][j] += rhs;

    return *this;
}

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator+= (const LinAlg::Matrix<RightType>& rhs)
{
    if(CheckDimensions(rhs, 0))
    {
        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->columns; j++)
                this->mat[i][j] += rhs(i + 1, j + 1);
    }

    return *this;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator-= (const Type& rhs /*scalar*/)
{
    return *this += -1*rhs;
}


template<typename Type> template<typename RightType>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator-= (const LinAlg::Matrix<RightType>& rhs)
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

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator*= (const LinAlg::Matrix<RightType>& rhs)
{

    if ((this->rows == 1) && (this->columns == 1))
    {
        LinAlg::Matrix<RightType> Temp = rhs;
        for(unsigned i = 1; i <= rhs.getNumberOfRows(); ++i)
            for(unsigned j = 1; j <= rhs.getNumberOfColumns(); ++j)
                Temp(i,j) = rhs(i,j) * this->mat[0][0];
        *this = Temp;
//        std::cout << ' ';
    }

    else if(CheckDimensions(rhs, 1))
    {
        Type temp;
        LinAlg::Matrix<Type> tempMat(*this);
        this->Init(this->rows, rhs.getNumberOfColumns());

        for(unsigned i = 0; i < tempMat.rows; i++)
            for(unsigned col = 0; col < rhs.getNumberOfColumns(); col++)
            {
                temp = 0;
                for(unsigned j = 0; j < tempMat.columns; j++)
                    temp += tempMat.mat[i][j] * rhs(j + 1, col + 1);
                this->mat[i][col] = temp;
            }
    }

    return *this;
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator/= (const Type& rhs)
{
    return *this *= 1/rhs;
}

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator/= (const LinAlg::Matrix<RightType>& rhs)
{

    if(rhs.getNumberOfRows() == 1 && rhs.getNumberOfColumns() == 1)
        return  *this /= rhs(1,1);
    else
        return *this *= LinAlg::Inverse<RightType>(rhs);
}

template<typename Type>
LinAlg::Matrix<Type>& LinAlg::Matrix<Type>::operator^= (int exp)
{
    LinAlg::Matrix<Type> temp = LinAlg::Eye<Type>(this->rows);

    if(exp < 0)
    {
        if(this->rows == 1 && this->columns == 1)
        {
            this->mat[0][0] = 1/this->mat[0][0];
            return *this;
        }
        else{
            *this = LinAlg::Inverse(*this);
            exp *= -1;
        }
    }

    for(int i = 0; i < exp; ++i) {
        temp *= *this;
    }

    *this = temp;

    return *this;
}

template<typename Type>
LinAlg::Matrix<bool> LinAlg::Matrix<Type>::operator== (const Type& rhs)
{
    LinAlg::Matrix<bool> ret = *this;
    for(unsigned i = 1; i <= this->rows; ++i)
        for(unsigned j = 1; j <= this->columns; ++j)
            ret(i,j) = this->mat[i-1][j-1] == rhs;

    return ret;
}

template<typename Type>
LinAlg::Matrix<bool> LinAlg::Matrix<Type>::operator<= (const Type& rhs)
{
    LinAlg::Matrix<bool> ret = *this;
    for(unsigned i = 1; i <= this->rows; ++i)
        for(unsigned j = 1; j <= this->columns; ++j)
            ret(i,j) = this->mat[i-1][j-1] <= rhs;

    return ret;
}

template<typename Type>
LinAlg::Matrix<bool> LinAlg::Matrix<Type>::operator>= (const Type& rhs)
{
    LinAlg::Matrix<bool> ret = *this;
    for(unsigned i = 1; i <= this->rows; ++i)
        for(unsigned j = 1; j <= this->columns; ++j)
            ret(i,j) = this->mat[i-1][j-1] >= rhs;

    return ret;
}

template<typename Type>
LinAlg::Matrix<bool> LinAlg::Matrix<Type>::operator< (const Type& rhs)
{
    LinAlg::Matrix<bool> ret = *this;
    for(unsigned i = 1; i <= this->rows; ++i)
        for(unsigned j = 1; j <= this->columns; ++j)
            ret(i,j) = this->mat[i-1][j-1] < rhs;

    return ret;
}

template<typename Type>
LinAlg::Matrix<bool> LinAlg::Matrix<Type>::operator> (const Type& rhs)
{
    LinAlg::Matrix<bool> ret = *this;
    for(unsigned i = 1; i <= this->rows; ++i)
        for(unsigned j = 1; j <= this->columns; ++j)
            ret(i,j) = this->mat[i-1][j-1] > rhs;

    return ret;
}

template <typename Type>
void LinAlg::Matrix<Type>::operator<< (const LinAlg::Matrix<Type>& mat)
{

    for(unsigned i = 0; i < this->rows; ++i)
        for(unsigned j = 0; j < this->columns - mat.columns; ++j)
            this->mat[i][j] = this->mat[i][this->columns - mat.columns + j];

    for(unsigned i = 0; i < this->rows; ++i)
        for(unsigned j = 0; j < mat.columns; ++j)
            this->mat[i][this->columns - mat.columns + j] = mat.mat[i][j];
}

template <typename Type>
void LinAlg::Matrix<Type>::operator>> (LinAlg::Matrix<Type>& mat)
{

    for(unsigned i = 0; i < mat.rows; ++i)
        for(unsigned j = 0; j < mat.columns - this->columns; ++j)
            mat.mat[i][mat.columns - this->columns + j] = mat.mat[i][j];

    for(unsigned i = 0; i < mat.rows; ++i)
        for(unsigned j = 0; j < this->columns; ++j)
            mat.mat[i][j] = this->mat[i][j];
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::divPoint(const LinAlg::Matrix<Type> &A, const LinAlg::Matrix<Type> &B)
{
    LinAlg::Matrix<Type> ret = A;
    if(A.getNumberOfColumns() == B.getNumberOfColumns() && A.getNumberOfRows() == B.getNumberOfRows())
        for(unsigned i = 1; i <= A.getNumberOfRows(); ++i)
            for(unsigned j = 1; j <= A.getNumberOfColumns(); ++j)
                ret(i,j) = A(i,j)/B(i,j);
    else
        std::cout << "A dimensao das matrizes esta incorreta";

    return ret;
}

template <typename Type>
LinAlg::Matrix< LinAlg::Matrix<Type>* >* LinAlg::sort(const LinAlg::Matrix<Type> &vector)
{
    LinAlg::Matrix<Type> reorderedMatrix = vector;
    LinAlg::Matrix<Type> indices;
    if(vector.getNumberOfColumns() > 1 && vector.getNumberOfRows() == 1)
    {
        indices = LineVector<Type>(1, vector.getNumberOfColumns());
        for(unsigned i = 1; i <= reorderedMatrix.getNumberOfColumns(); ++i)
            for(unsigned j = i+1; j <= reorderedMatrix.getNumberOfColumns(); ++j)
                if(reorderedMatrix(1,i) > reorderedMatrix(1,j)){
                    Type aux = reorderedMatrix(1,i);
                    reorderedMatrix(1,i) = reorderedMatrix(1,j);
                    reorderedMatrix(1,j) = aux;
                    aux = indices(1,i);
                    indices(1,i) = indices(1,j);
                    indices(1,j) = aux;
                }
    }
    else if(vector.getNumberOfColumns() == 1 && vector.getNumberOfRows() >= 1)
    {
        indices = ~LineVector<Type>(1, vector.getNumberOfRows());
        for(unsigned i = 1; i <= reorderedMatrix.getNumberOfRows(); ++i)
            for(unsigned j = i+1; j <= reorderedMatrix.getNumberOfRows(); ++j)
                if(reorderedMatrix(i,1) > reorderedMatrix(j,1)){
                    Type aux = reorderedMatrix(i,1);
                    reorderedMatrix(i,1) = reorderedMatrix(j,1);
                    reorderedMatrix(j,1) = aux;
                    aux = indices(i,1);
                    indices(i,1) = indices(j,1);
                    indices(j,1) = aux;
                }
    }
    else
    {
        std::cout << "Não foi possível organizar os índices! "
                     "Deveria ter apenas uma linha ou uma coluna!!"
                  << std::endl;
    }
    LinAlg::Matrix< LinAlg::Matrix<Type>* > *A = new LinAlg::Matrix< LinAlg::Matrix<Type>* >(1,2);
    (*A)(1,1) = new LinAlg::Matrix<Type>(vector.getNumberOfRows(),vector.getNumberOfColumns());
    (*A)(1,2) = new LinAlg::Matrix<Type>(vector.getNumberOfRows(),vector.getNumberOfColumns());
    (*((*A)(1,1))) = reorderedMatrix;
    (*((*A)(1,2))) = indices;
    return A;
}

template <typename Type>
LinAlg::Matrix< LinAlg::Matrix<Type>* >* LinAlg::min(const LinAlg::Matrix<Type> &vector)
{
    LinAlg::Matrix<Type> minMatrix, minIndiceMatrix;
    if(vector.getNumberOfRows() > 1)
    {
        minMatrix = LinAlg::Zeros<Type>(1, vector.getNumberOfColumns());
        minIndiceMatrix = LinAlg::Ones<Type>(1, vector.getNumberOfColumns());

        for (unsigned i = 1; i <= vector.getNumberOfColumns(); ++i)
        {
            minMatrix(1,i) = vector(1,i);
            for (unsigned j = 1; j <= vector.getNumberOfRows(); ++j)
                if(minMatrix(1,i) > vector(j,i))
                {
                    minMatrix(1,i) = vector(j,i);
                    minIndiceMatrix(1,i) = j;
                }
        }
    }
    else if(vector.getNumberOfRows() == 1)
    {
        minMatrix = LinAlg::Zeros<Type>(1,1);
        minIndiceMatrix = LinAlg::Ones<Type>(1,1);
        minMatrix(1,1) = vector(1,1);
        for (unsigned j = 1; j <= vector.getNumberOfColumns(); ++j)
            if(minMatrix(1,1) > vector(1,j))
            {
                minMatrix(1,1) = vector(1,j);
                minIndiceMatrix(1,1) = j;
            }
    }


    LinAlg::Matrix< LinAlg::Matrix<Type>* > *A = new LinAlg::Matrix< LinAlg::Matrix<Type>* >(1,2);
    (*A)(1,1) = new LinAlg::Matrix<Type>(vector.getNumberOfRows(),vector.getNumberOfColumns());
    (*A)(1,2) = new LinAlg::Matrix<Type>(vector.getNumberOfRows(),vector.getNumberOfColumns());
    (*((*A)(1,1))) = minMatrix;
    (*((*A)(1,2))) = minIndiceMatrix;
    return A;
}

template <typename Type>
LinAlg::Matrix< LinAlg::Matrix<Type>* >* LinAlg::max(const LinAlg::Matrix<Type> &vector)
{
    LinAlg::Matrix<Type> maxMatrix, maxIndiceMatrix;
    if(vector.getNumberOfRows() > 1)
    {
        maxMatrix = LinAlg::Zeros<Type>(1, vector.getNumberOfColumns());
        maxIndiceMatrix = LinAlg::Ones<Type>(1, vector.getNumberOfColumns());

        for (unsigned i = 1; i <= vector.getNumberOfColumns(); ++i)
        {
            maxMatrix(1,i) = vector(1,i);
            for (unsigned j = 1; j <= vector.getNumberOfRows(); ++j)
                if(maxMatrix(1,i) < vector(j,i))
                {
                    maxMatrix(1,i) = vector(j,i);
                    maxIndiceMatrix(1,i) = j;
                }
        }
    }
    else if(vector.getNumberOfRows() == 1)
    {
        maxMatrix = LinAlg::Zeros<Type>(1,1);
        maxIndiceMatrix = LinAlg::Ones<Type>(1,1);
        maxMatrix(1,1) = vector(1,1);
        for (unsigned j = 1; j <= vector.getNumberOfColumns(); ++j)
            if(maxMatrix(1,1) < vector(1,j))
            {
                maxMatrix(1,1) = vector(1,j);
                maxIndiceMatrix(1,1) = j;
            }
    }


    LinAlg::Matrix< LinAlg::Matrix<Type>* > *A = new LinAlg::Matrix< LinAlg::Matrix<Type>* >(1,2);
    (*A)(1,1) = new LinAlg::Matrix<Type>(vector.getNumberOfRows(),vector.getNumberOfColumns());
    (*A)(1,2) = new LinAlg::Matrix<Type>(vector.getNumberOfRows(),vector.getNumberOfColumns());
    (*((*A)(1,1))) = maxMatrix;
    (*((*A)(1,2))) = maxIndiceMatrix;
    return A;
}

template <typename Type>
LinAlg::Matrix<Type> LinAlg::sum(const LinAlg::Matrix<Type> &mat, const bool &rowColResult)
{
    if(!rowColResult)
    {
        LinAlg::Matrix<Type> sum(1,mat.getNumberOfColumns());

        for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
            for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
                sum(1,j) += mat(i,j);

        return sum;
    }
    else
    {
        LinAlg::Matrix<Type> sum(mat.getNumberOfRows(),1);

        for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
            for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
                sum(i,1) += mat(i,j);

        return sum;
    }
}
//template <typename Type>
//unsigned LinAlg::lineOfMinValue(const LinAlg::Matrix<Type> &mat)
//{
//    unsigned minIndice = 1;
//    Type minValue = mat(1,1);
//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            if(minValue > mat(i,j))
//            {
//                minValue = mat(i,j);
//                minIndice = i;
//            }
//    return minIndice;
//}

//template <typename Type>
//unsigned LinAlg::columnOfMinValue(const LinAlg::Matrix<Type> &mat)
//{
//    unsigned minIndice = 1;
//    Type minValue = mat(1,1);
//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            if(minValue > mat(i,j))
//            {
//                minValue = mat(i,j);
//                minIndice = j;
//            }
//    return minIndice;
//}

//template <typename Type>
//Type LinAlg::MinValue(const LinAlg::Matrix<Type> &mat)
//{
//    Type minValue = mat(1,1);
//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            if(minValue > mat(i,j))
//                minValue = mat(i,j);

//    return minValue;
//}

//template <typename Type>
//unsigned LinAlg::lineOfMaxValue(const LinAlg::Matrix<Type> &mat)
//{
//    unsigned maxIndice = 1;
//    Type maxValue = mat(1,1);
//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            if(maxValue < mat(i,j))
//            {
//                maxValue = mat(i,j);
//                maxIndice = i;
//            }
//    return maxIndice;
//}

//template <typename Type>
//unsigned LinAlg::columnOfMaxValue(const LinAlg::Matrix<Type> &mat)
//{
//    unsigned maxIndice = 1;
//    Type maxValue = mat(1,1);
//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            if(maxValue < mat(i,j))
//            {
//                maxValue = mat(i,j);
//                maxIndice = j;
//            }
//    return maxIndice;
//}

//template <typename Type>
//Type LinAlg::MaxValue(const LinAlg::Matrix<Type> &mat)
//{
//    Type maxValue = mat(1,1);
//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            if(maxValue < mat(i,j))
//                maxValue = mat(i,j);

//    return maxValue;
//}

//template <typename Type>
//LinAlg::Matrix<Type> LinAlg::sumOfRowsElements(const LinAlg::Matrix<Type> &mat) // lembrar de implementar
//{
//    LinAlg::Matrix<Type> sum(mat.getNumberOfRows(),1);

//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            sum(i,1) += mat(i,j);

//    return sum;
//}

//template <typename Type>
//LinAlg::Matrix<Type> LinAlg::sumOfColumnsElements(const LinAlg::Matrix<Type> &mat) // lembrar de implementar
//{
//    LinAlg::Matrix<Type> sum(1,mat.getNumberOfColumns());

//    for (unsigned i = 1; i <= mat.getNumberOfRows(); ++i)
//        for (unsigned j = 1; j <= mat.getNumberOfColumns(); ++j)
//            sum(1,j) += mat(i,j);

//    return sum;
//}

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator| (LinAlg::Matrix<RightType> rhs)
{
    LinAlg::Matrix<Type>ret;

    if(this->mat == NULL)
        ret = rhs;
    else
    {
        unsigned aux = this->columns;

        if(this->rows < rhs.getNumberOfRows())
            ret.Init(rhs.getNumberOfRows(), this->columns + rhs.getNumberOfColumns());
        else
            ret.Init(this->rows, this->columns + rhs.getNumberOfColumns());

        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->columns; j++)
                ret.mat[i][j] = this->mat[i][j];

        for(unsigned i = 1; i <= rhs.getNumberOfRows(); i++)
            for(unsigned j = 1; j <= rhs.getNumberOfColumns(); j++)
                ret(i, aux + j) = rhs(i, j);
    }

    return ret;
}

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator| (RightType rhs)
{
    return ((*this)|LinAlg::Matrix<RightType>(rhs));
}

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator|| (LinAlg::Matrix<RightType> rhs)
{
    LinAlg::Matrix<Type>ret;

    if(this->mat == NULL)
        ret = rhs;
    else
    {
        unsigned aux = this->rows;

        if(this->columns < rhs.getNumberOfColumns())
            ret.Init(this->rows + rhs.getNumberOfRows(), rhs.getNumberOfColumns());
        else
            ret.Init(this->rows + rhs.getNumberOfRows(), this->columns);

        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->columns; j++)
                ret.mat[i][j] = this->mat[i][j];

        for(unsigned i = 1; i <= rhs.getNumberOfRows(); i++)
            for(unsigned j = 1; j <= rhs.getNumberOfColumns(); j++)
                ret(i + aux, j) = rhs(i, j);
    }

    return ret;
}

template<typename Type> template<typename RightType>
LinAlg::Matrix<Type> LinAlg::Matrix<Type>::operator|| (RightType rhs)
{
    return ((*this)||LinAlg::Matrix<RightType>(rhs));
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::operator- (const LinAlg::Matrix<Type>& mat)
{
    LinAlg::Matrix<Type> temp(mat);

    for(unsigned i = 1; i <= temp.getNumberOfRows(); i++)
        for(unsigned j = 1; j <= temp.getNumberOfColumns(); j++)
            temp(i, j) *= -1;

    return temp;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::operator~ (LinAlg::Matrix<Type> mat)
{
    LinAlg::Matrix<Type> temp(mat.getNumberOfColumns(), mat.getNumberOfRows());

    for(unsigned i = 1; i <= mat.getNumberOfRows(); i++)
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); j++)
            temp(j, i) = mat(i, j);

    return temp;
}

template<typename Type>
std::ostream& LinAlg::operator<< (std::ostream& output, const LinAlg::Matrix<Type> mat)
{
    if(mat.getNumberOfColumns() == 0){
        return output;
    }

    for(unsigned i = 1; i <= mat.getNumberOfRows(); i++)
    {
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); j++)
            if(mat(i, j) != 0)
                output << std::setw(2*coutPrecision+1) << std::setprecision(coutPrecision) << std::fixed << mat(i, j) << ' ';
            else
                output << std::setw(2*coutPrecision+1) << std::setprecision(0) << std::fixed << mat(i, j) << ' ';

        output << std::endl;
    }

    return output;
}

template<typename Type>
std::ostream& LinAlg::operator<<= (std::ostream& output, const LinAlg::Matrix<Type> mat)
{
    if(mat.getNumberOfColumns() == 0){
        return output;
    }

    for(unsigned i = 1; i <= mat.getNumberOfRows(); i++)
    {
        for(unsigned j = 1; j <= mat.getNumberOfColumns(); j++)
        {
            if(mat(i, j) != 0)
                output << std::setw(2*coutPrecision+1) << std::setprecision(coutPrecision) << std::fixed << mat(i, j);
            else
                output << std::setw(2*coutPrecision+1) << std::setprecision(0) << std::fixed << mat(i, j);

            if(j != mat.getNumberOfColumns())
                output << ',';
        }

        if(i != mat.getNumberOfRows())
            output << ';';
    }

    return output;
}

template<typename Type>
std::istream& LinAlg::operator>> (std::istream& input, LinAlg::Matrix<Type>& mat)
{
    std::string temp;

    input >> temp;
    mat = temp;

    return input;
}

template<typename Type>
std::string& LinAlg::operator<< (std::string& output, const LinAlg::Matrix<Type> mat)
{
    std::stringstream ss;
    ss << mat;
    output += ss.str();
    return output;
}

template<typename Type>
std::string& LinAlg::operator<<= (std::string& output, const LinAlg::Matrix<Type> mat)
{
    std::stringstream ss;
    ss <<= mat;
    output += ss.str();
    return output;
}

//template<typename Type>
//bool LinAlg::operator== (const LinAlg::Matrix<Type>& lhs, const LinAlg::Matrix<Type>& rhs)
//{
//    bool ret = true;

//    if((lhs.getNumberOfRows() == rhs.getNumberOfRows()) && (lhs.getNumberOfColumns() && rhs.getNumberOfColumns()))
//    {
//        for(unsigned i = 1; i <= lhs.getNumberOfRows(); i++)
//            for(unsigned j = 1; j <= lhs.getNumberOfColumns(); j++)
//                if(!(lhs(i, j) == rhs(i, j)))
//                {
//                    ret = false;
//                    break;
//                }
//    }
//    else
//        ret = false;

//    return ret;
//}

//template<typename Type>
//void LinAlg::Zeros(Matrix<Type>& Mat)
//{
//    for(unsigned i = 1; i <= Mat.getNumberOfRows(); i++)
//        for(unsigned j = 1; j <= Mat.getNumberOfColumns(); j++)
//            if(typeid(Mat(i, j)) == typeid(double) || typeid(Mat(i, j)) == typeid(unsigned) || typeid(Mat(i, j)) == typeid(float) || typeid(Mat(i, j)) == typeid(int))
//                Mat(i, j) = 0;
//}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Zeros (unsigned rows, unsigned columns)
{
    return LinAlg::Matrix<Type>(rows, columns);

}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Eye (unsigned dimension)
{
    LinAlg::Matrix<Type> Ret(dimension, dimension);

    for(unsigned i = 1; i <= dimension; i++)
        for(unsigned j = 1; j <= dimension; j++)
            {
                if( i == j)
                    Ret(i, j) = 1;
                else
                    Ret(i, j) = 0;
            }

    return Ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::LineVector (Type from, Type to, Type step)
{
    LinAlg::Matrix<Type> Ret(1,unsigned((to-from)/step) + 1);
    unsigned j = 1;
    if(step > 0)
        for(Type i = from; i <= to; i+= step)
        {
            Ret(1,j) = i;
            ++j;
        }
    else
        for(Type i = from; i >= to; i+= step)
        {
            Ret(1,j) = i;
            ++j;
        }
    return Ret;
}

//template<typename Type>
//void LinAlg::Ones(LinAlg::Matrix<Type>& mat)
//{
//    for(unsigned i = 1; i <= mat.getNumberOfRows(); i++)
//        for(unsigned j = 1; j <= mat.getNumberOfColumns(); j++)
//            mat(i, j) = 1;
//}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Ones(unsigned rows, unsigned columns)
{
    LinAlg::Matrix<Type> temp(rows, columns);

    for(unsigned i = 1; i <= temp.getNumberOfRows(); i++)
        for(unsigned j = 1; j <= temp.getNumberOfColumns(); j++)
            temp(i, j) = 1;

    return temp;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Random(unsigned rows, unsigned columns)
{
    LinAlg::Matrix<Type> mat(rows, columns);

    for(unsigned i = 1; i <= rows; ++i)
        for(unsigned j = 1; j <= columns; ++j)
            mat(i, j) = (Type)(((double)(rand()%100))/100.0);

    return mat;
}

template<typename Type>
Type LinAlg::Determinant(const LinAlg::Matrix<Type>& mat)
{
    Type determinant = 0;
    unsigned rows = mat.getNumberOfRows(), columns = mat.getNumberOfColumns(), aux1, aux2;
    LinAlg::Matrix<Type> temp(rows - 1, columns - 1);


    if(rows != columns)
    {
        determinant = 0;
        std::cout << "Operacao disponivel somente para matrizes quadradas.";
    }
    else if(rows == 1)
        determinant = mat(1, 1);
    else if(rows == 2)
        determinant = mat(1, 1)*mat(2, 2) - mat(1, 2)*mat(2, 1);
    else
    {
        for(unsigned k = 0; k < rows; k++)
        {
            aux1 = 0;
            aux2 = 0;
            for(unsigned i = 1; i < rows; i++)
            {
                for(unsigned j = 0; j < rows; j++)
                {
                    if(!(j == k))
                    {
                        temp(aux1 + 1, aux2 + 1) = mat(i + 1, j + 1);
                        aux2++;
                    }

                    if(aux2 == rows - 1)
                    {
                        aux1++;
                        aux2 = 0;
                    }
                }
            }

            determinant += pow( -1, k)*mat(1, k + 1) * LinAlg::Determinant(temp);
        }
    }

    return determinant;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Cofactor(const LinAlg::Matrix<Type>& mat)
{
    unsigned rows = mat.getNumberOfRows(), columns = mat.getNumberOfColumns(), aux1, aux2;
    LinAlg::Matrix<Type> temp(rows - 1, columns - 1), ret(rows, columns);

    if(rows != columns)
    {
        ret = LinAlg::Zeros<Type>(0,0);
        std::cout << "Operacao disponivel somente para matrizes quadradas.";
    }
    else if(rows == 2)
    {
        ret(1, 1) = mat(2, 2);
        ret(2, 2) = mat(1, 1);
        ret(1, 2) = -mat(2, 1);
        ret(2, 1) = -mat(1, 2);
    }
    else
    {
        for(unsigned j = 1; j <= rows; j++)
            for(unsigned i = 1; i <= rows; i++)
            {
                aux1 = 1;

                for(unsigned m = 1; m <= rows; m++)
                {
                    if(!(m == i))
                    {
                        aux2 = 1;

                        for(unsigned n = 1; n <= rows; n++)
                        {
                            if(!(n == j))
                            {
                                temp(aux1, aux2) = mat(m, n);
                                aux2++;
                            }
                        }
                        aux1++;
                    }
                }

                ret(i, j) = pow(-1, i + j)*LinAlg::Determinant<Type>(temp);
            }
    }

    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Inverse(const LinAlg::Matrix<Type>& mat)
{
    Type determinant = LinAlg::Determinant(mat);
    unsigned rows = mat.getNumberOfRows(), columns = mat.getNumberOfColumns();
    LinAlg::Matrix<Type> ret(rows, columns);

    if(rows != columns)
        std::cout << "Operacao disponivel somente para matrizes quadradas.";
    else if(rows == 1 && columns == 1)
        ret(1,1) = Type(1)/mat(1,1);
    else if( determinant == Type(0.0))
        std::cout << "Impossivel inverter, determinante igual a 0.";
    else
    {
        ret = LinAlg::Cofactor(mat);
        ret = (~ret)/determinant;
    }

    return ret;
}

template<typename Type>
void LinAlg::Print(const Matrix<Type>& mat)
{
  std::cout << std::endl;

  for(unsigned i = 1; i <= mat.getNumberOfRows(); i++)
  {
    for(unsigned j = 1; j <= mat.getNumberOfColumns(); j++)
        std::cout << std::setw(10) << mat(i, j) << ' ';

    std::cout << std::endl;
  }
}

template<typename Type>
bool LinAlg::isEqual(const LinAlg::Matrix<Type>& lMat, const LinAlg::Matrix<Type>& rMat)
{
    if(lMat.getNumberOfRows() != rMat.getNumberOfRows() || lMat.getNumberOfColumns() != rMat.getNumberOfColumns())
        return false;
    else
    {
        for(unsigned i = 1; i <= lMat.getNumberOfRows(); i++)
        {
          for(unsigned j = 1; j <= lMat.getNumberOfColumns(); j++)
          {
            if(lMat(i,j) != rMat(i,j))
                return false;
          }
        }
    }
    return true;
}

template<typename Type, typename otherType>
bool LinAlg::isEqual(const LinAlg::Matrix<Type>& lMat, const LinAlg::Matrix<otherType>& rMat, Type tol)
{
    if(lMat.getNumberOfRows() != rMat.getNumberOfRows() || lMat.getNumberOfColumns() != rMat.getNumberOfColumns())
        return false;
    else
    {
        for(unsigned i = 1; i <= lMat.getNumberOfRows(); i++)
        {
          for(unsigned j = 1; j <= lMat.getNumberOfColumns(); j++)
          {
            if(fabs(lMat(i,j) - rMat(i,j)) > tol)
                return false;
          }
        }
    }
    return true;
}
