#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../Array/Array.hpp"

namespace MyLib {
    namespace MyMatrix {

        template<class T> 
        class Matrix;

        template<class T>
        std::ostream& operator<<(std::ostream& out, const Matrix<T>& mat);

        template<class T>
        class Matrix {
        private:
            MyArray::Array<MyArray::Array<T>> *arr;
            size_t rows = 0;
            size_t cols = 0;
        public:

            Matrix();

            ~Matrix();

            Matrix(const Matrix& other);

            Matrix(Matrix&& other);

            Matrix(size_t rows, size_t cols, const T& val = T(NULL));

            std::pair<size_t, size_t> get_size() const; 

            bool is_empty() const;

            friend std::ostream& operator<< <>(std::ostream& out, const Matrix<T>& mat);

            MyArray::Array<T>& operator[](size_t idx);

            const MyArray::Array<T>& operator[](size_t idx) const;

            Matrix<T> operator+(const Matrix<T>& other) const;

            Matrix<T> operator-(const Matrix<T>& other) const;

            Matrix<T>& operator+=(const Matrix<T>& other);

            Matrix<T>& operator-=(const Matrix<T>& other);

            bool operator==(const Matrix<T>& other) const;
            
            bool operator!=(const Matrix<T>& other) const;
        };
    }; 
};

#include "Matrix.tpp"


#endif
