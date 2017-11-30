#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <time.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <iostream> 
#include <typeinfo>
#include <algorithm>

namespace LinAlg {
    #ifndef coutPrecision
        #define coutPrecision 3
    #endif
    template<typename Type>
    class Matrix
    {
        public:
            Matrix (Type Number);
            Matrix (const char* Mat);
            Matrix (unsigned row, unsigned column);
            Matrix (): rows(0), columns(0), mat(NULL){}
            Matrix (const LinAlg::Matrix<Type>& otherMatrix);
            virtual ~Matrix ();

            unsigned getNumberOfRows () const{return this->rows;}
            unsigned getNumberOfColumns () const{return this->columns;}

            Type& operator() (unsigned row, unsigned column) {return this->mat[row][column];}
            Type  operator() (unsigned  row, unsigned column) const{return this->mat[row][column];}

            void operator= (const char* rhs){this->Init(rhs);}
            LinAlg::Matrix<Type>& operator= (const LinAlg::Matrix<Type>& rhs) const;

            LinAlg::Matrix<Type>& operator+= (const Type& rhs /*scalar*/);
            LinAlg::Matrix<Type>& operator+= (const LinAlg::Matrix<Type>& rhs);

            LinAlg::Matrix<Type>& operator-= (const Type& rhs /*scalar*/);
            LinAlg::Matrix<Type>& operator-= (const LinAlg::Matrix<Type>& rhs);

            LinAlg::Matrix<Type>& operator*= (const Type& rhs /*scalar*/);
            LinAlg::Matrix<Type>& operator*= (const LinAlg::Matrix<Type>& rhs);



        private:
            void Init (std::string Mat);
            void Init (unsigned row, unsigned column);
            bool CheckDimensions(const LinAlg::Matrix<Type>& rhs, unsigned operation);

            unsigned rows, columns;
            Type** mat;
    };

    template<typename MatrixType, typename ScalarType>
    inline LinAlg::Matrix<MatrixType> operator+ (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs += rhs;}
    template<typename MatrixType, typename ScalarType>
    inline LinAlg::Matrix<MatrixType> operator+ (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs) {return rhs += lhs;}
    template<typename LeftType, typename RightType>
    inline LinAlg::Matrix<LeftType> operator+ (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs += rhs;}

    template<typename MatrixType, typename ScalarType>
    inline LinAlg::Matrix<MatrixType> operator- (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs -= rhs;}
    template<typename MatrixType, typename ScalarType>
    inline LinAlg::Matrix<MatrixType> operator- (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs) {return -rhs -= -lhs;}
    template<typename LeftType, typename RightType>
    inline LinAlg::Matrix<LeftType> operator- (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs -= rhs;}

    template<typename MatrixType, typename ScalarType>
    inline LinAlg::Matrix<MatrixType> operator* (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs *= rhs;}
    template<typename MatrixType, typename ScalarType>
    inline LinAlg::Matrix<MatrixType> operator* (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs) {return rhs *= lhs;}
    template<typename LeftType, typename RightType>
    inline LinAlg::Matrix<LeftType> operator* (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs *= rhs;}

    template<typename Type>
    inline LinAlg::Matrix<Type> operator- (const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    inline std::ostream& operator<< (std::ostream& output, const LinAlg::Matrix<Type> mat);
}

#include "matrix.hpp"
#endif // MATRIX_H