#include <cstdlib>
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int rows, int columns) : r(rows), c(columns)
{
    mtrx.resize(r);

    for(int i = 0; i < r; i++)
    {
        mtrx.at(i).resize(c);
    }
}

Matrix::Matrix() : r(1), c(1)
{
    mtrx.resize(r);

    for(int i = 0; i < r; i++)
    {
        mtrx.at(i).resize(c);
    }
}

int Matrix::getRows() const {
    return r;
}

int Matrix::getColumns() const {
    return c;
}

int Matrix::getValue(int row, int column) const {
    return mtrx.at(row).at(column);
}

Matrix Matrix::operator+(const Matrix &m1) const {
    if(c != m1.getColumns() || r != m1.getRows())
    {
        std::cout << "Columns and rows must be equal in each matrix!" << std::endl;
        exit(EXIT_FAILURE);
    }

    Matrix w;
    w.resizeMatrix(r, c);

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            w.setValue(i, j, getValue(i, j) + m1.getValue(i, j));
        }
    }
    return w;
}

void Matrix::setValue(int row, int column, int value) {
    mtrx.at(row).at(column) = value;
}

void Matrix::resizeMatrix(int rows, int columns)
{
    r = rows;
    c = columns;

    mtrx.resize(r);
    for(int i = 0; i < r; i++)
    {
        mtrx.at(i).resize(c);
    }
}

void Matrix::info() const {
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            std::cout << mtrx.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }
}

void Matrix::fillMatrix(std::vector<std::vector<int>> &a) {
    r = a.size();
    c = a.at(0).size();
    mtrx.resize(r);
    for(int i = 0; i < r; i++)
    {
        mtrx.at(i).resize(c);
    }
    mtrx = a;
}
