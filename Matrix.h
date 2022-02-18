#ifndef MATRIX_CALCULATOR_MATRIX_H
#define MATRIX_CALCULATOR_MATRIX_H

#include <vector>

class Matrix {

    std::vector<std::vector<int>> mtrx;

    int r, c;

    int getRows() const ;   //returns number of rows in matrix
    int getColumns() const ;    //returns number of columns in matrix
    int getValue(int row, int column) const ;   //returns value in given coordinates

    void setValue(int row, int column, int value);  //sets given value in given coordinates
    void resizeMatrix(int rows, int columns);   //resizes matrix, anc changes r and c values

public:
    Matrix(int rows, int columns);
    Matrix();

    Matrix operator+(const Matrix &m1) const ;  //overloads operator +
    Matrix operator-(const Matrix &m1) const ;  //overloads operator -
    friend Matrix operator*(int a, const Matrix &m1);
    friend Matrix operator*(Matrix &m1, int a);

    void info() const ;     //used for debug, prints matrix
    void fillMatrix(std::vector<std::vector<int>> &a);  //fills matrix with given vector

};

Matrix operator*(int a, const Matrix &m1);
Matrix operator*(Matrix &m1, int a);


#endif //MATRIX_CALCULATOR_MATRIX_H
