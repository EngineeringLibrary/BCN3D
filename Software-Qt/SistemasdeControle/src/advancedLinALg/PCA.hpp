#include "SistemasdeControle/headers/advancedLinALg/PCA.h"

template <typename Type>
LinAlg::PCA<Type>::PCA(LinAlg::Matrix<Type> data, const unsigned &reducedDimensionQuantities)
{
    this->data = data;
    this->dataMean = LinAlg::mean(data,2);
    LinAlg::Matrix<Type> adjustedData;

//    std::cout << (~this->dataMean);
    for(unsigned i = 1; i<= data.getNumberOfRows(); ++i)
        adjustedData = adjustedData || data.GetRow(i) - this->dataMean(i,1);

//    std::cout << (~adjustedData);
    LinAlg::Matrix<Type> matrixcov = ((adjustedData*(~adjustedData))/(adjustedData.getNumberOfColumns()-1));
//    std::cout << (matrixcov);
    LinAlg::Matrix<Type> eigenvalues  = LinAlg::EigenValues(matrixcov);
    LinAlg::Matrix<Type> eigenvectors = -LinAlg::EigenVector(matrixcov);
//    std::cout << (eigenvalues) << std::endl << eigenvectors;
    this->eigenvalueOrder = LinAlg::sortColumnVectorIndices(-eigenvalues);
    eigenvectors = eigenvectors(from(1)-->eigenvectors.getNumberOfRows(), this->eigenvalueOrder);
//    std::cout << (eigenvalues) << std::endl << eigenvectors;
    this->projectioMatrix = eigenvectors(from(1)-->eigenvectors.getNumberOfRows(), LinAlg::LineVector<Type>(1,reducedDimensionQuantities));
//    std::cout << this->projectioMatrix;
    LinAlg::Matrix<Type> Y = (~this->projectioMatrix) * adjustedData;

//    std::cout << (~Y);
    this->eigenvalueOrder = LinAlg::sortColumnVectorIndices(this->eigenvalueOrder);
    data =  this->projectioMatrix * Y;
    for (unsigned i = 1; i <= data.getNumberOfRows(); ++i)
        this->originalData = this->originalData || data.GetRow(i) + this->dataMean(i,1);
//    std::cout << (~this->originalData);

}

