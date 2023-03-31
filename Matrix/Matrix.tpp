#ifndef MATRIX_TPP
#define MATRIX_TPP

namespace MyLib {
    namespace MyMatrix {
  
        template<class T>
        Matrix<T>::Matrix() {
            this->arr = new MyArray::Array<MyArray::Array<T>>(1, MyArray::Array<T>(1));
            rows = 1;
            cols = 1;
        }

        template<class T>
        Matrix<T>::Matrix(size_t rows, size_t cols, const T& val) {
            this->arr = new MyArray::Array<MyArray::Array<T>>(rows, MyArray::Array<T>(cols, val));
            this->rows = rows;
            this->cols = cols;
        }

        template<class T>
        Matrix<T>::Matrix(const Matrix& other) {
            this->arr = new MyArray::Array<MyArray::Array<T>>(other.rows, MyArray::Array<T>(other.cols));
            this->cols = other.cols;
            this->rows = other.rows;
            for (size_t i = 0; i < other.rows; ++i) {
                (*this->arr)[i] = (*other.arr)[i]; 
            }
        }

        template<class T>
        Matrix<T>::Matrix(Matrix&& other) {
            this->arr = other.arr;
            this->rows = other.rows;
            this->cols = other.cols;
            other.arr = nullptr;
            other.cols = 0;
            other.rows = 0;
        }

        template<class T>
        Matrix<T>::~Matrix() {
            delete this->arr;
        }

        template<class T>
        std::ostream& operator<<(std::ostream& out, const Matrix<T>& mat) {
            out << "Matrix " << mat.rows << "x" << mat.cols << " {" << std::endl;
            for (size_t i = 0; i < mat.rows; ++i) {
                out << "\t" << (*mat.arr)[i] << std::endl;
            } 
            out << "} " << std::endl;
            return out;
        }

        template<class T>
        MyArray::Array<T>& Matrix<T>::operator[](size_t idx) {
            if (idx >= this->rows) {
                throw std::runtime_error("index out of range");
            }
            return (*this->arr)[idx];
        }

        template<class T>
        const MyArray::Array<T>& Matrix<T>::operator[](size_t idx) const {
            if (idx >= this->rows) {
                throw std::runtime_error("index out of range");
            }
            return (*this->arr)[idx];
        }

        template<class T>
        std::pair<size_t, size_t> Matrix<T>::get_size() const {
            return std::make_pair(this->rows, this->cols);
        }

        template<class T>
        bool Matrix<T>::is_empty() const {
            return ((this->rows == 0) || (this->cols == 0));
        }

        template<class T>
        Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
            if (this->get_size() != other.get_size()) {
                throw std::runtime_error("size mismatch");
            }
            Matrix<T> m(*this);
            m += other;
            return m;
        }

        template<class T>
        Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
            if (this->get_size() != other.get_size()) {
                throw std::runtime_error("size mismatch");
            }
            Matrix<T> m(*this);
            m -= other;
            return m;
        }

        template<class T>
        Matrix<T>& Matrix<T>::operator+=(const Matrix& other) {
            if (this->get_size() != other.get_size()) {
                throw std::runtime_error("size mismatch");
            }
            for (size_t i = 0; i < this->rows; ++i) {
                (*this->arr)[i] += (*other.arr)[i];
            }
            return *this;
        }

        template<class T>
        Matrix<T>& Matrix<T>::operator-=(const Matrix& other) {
            if (this->get_size() != other.get_size()) {
                throw std::runtime_error("size mismatch");
            }
            for (size_t i = 0; i < this->rows; ++i) {
                (*this->arr)[i] -= (*other.arr)[i];
            }
            return *this;
        }

        template<class T>
        bool Matrix<T>::operator==(const Matrix& other) const {
            if (this->get_size() != other.get_size()) {
                throw std::runtime_error("size mismatch");
            }        
            for (size_t i = 0; i < this->rows; ++i) {
                if ((*this->arr)[i] != (*other.arr)[i]) {
                    return false;
                }
            }
            return true;
        }

        template<class T>
        bool Matrix<T>::operator!=(const Matrix& other) const {
            return !(*this == other);
        }
    }; 
};

#endif
 