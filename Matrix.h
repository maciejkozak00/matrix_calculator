#ifndef MATRIX_CALCULATOR_MATRIX_H
#define MATRIX_CALCULATOR_MATRIX_H

#include <vector>

class Matrix {

    std::vector<std::vector<int>> mtrx;

    int r, c;

    int getRows() const ;
    int getColumns() const ;
    int getValue(int row, int column) const ;

    void setValue(int row, int column, int value);
    void resizeMatrix(int rows, int columns);

public:
    Matrix(int rows, int columns);
    Matrix();

    Matrix operator+(const Matrix &m1) const ;

    void info() const ;
    void fillMatrix(std::vector<std::vector<int>> &a);

};


#endif //MATRIX_CALCULATOR_MATRIX_H
