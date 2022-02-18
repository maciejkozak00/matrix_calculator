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

Matrix Matrix::operator-(const Matrix &m1) const {
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
            w.setValue(i, j, getValue(i, j) - m1.getValue(i, j));
        }
    }
    return w;
}

Matrix operator*(int a, const Matrix &m1) {
    Matrix w;
    w.resizeMatrix(m1.getRows(),m1.getColumns());

    for(int i = 0; i < m1.getRows(); i++)
    {
        for(int j = 0; j < m1.getColumns(); j++)
        {
            w.setValue(i, j, m1.getValue(i, j) * a);
        }
    }
    return w;
}

Matrix operator*(Matrix &m1, int a) {
    Matrix w;
    w.resizeMatrix(m1.getRows(),m1.getColumns());

    for(int i = 0; i < m1.getRows(); i++)
    {
        for(int j = 0; j < m1.getColumns(); j++)
        {
            w.setValue(i, j, m1.getValue(i, j) * a);
        }
    }
    return w;
}

Matrix Matrix::operator*(const Matrix &m1) const {
    if(c != m1.getRows())
    {
        std::cout << "Number of columns of left matrix must be equal to number of rows of right matrix" << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix w;
    w.resizeMatrix(r, m1.getColumns());

    for(int i = 0; i < w.getRows(); i++)
    {
        for(int j = 0; j < w.getColumns(); j++)
        {
            int h = 0;
            for(int k = 0; k < c; k++)
            {
                h += getValue(i, k) * m1.getValue(k, j);
            }
            w.setValue(i, j, h);
        }
    }

    return w;
}
