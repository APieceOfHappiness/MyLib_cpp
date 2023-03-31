#ifndef ARRAY_TPP
#define ARRAY_TPP

namespace MyLib {
    namespace MyArray {

        template<class T>
        Array<T>::Array() {
            this->data = new T();
            size = 1;
        };

        template<class T>
        Array<T>::Array(size_t n, const T& val) {
            this->data = new T[n];
            for (size_t i = 0; i < n; i++) {
                this->data[i] = val;
            }
            size = n;
        };

        template<class T>
        Array<T>::Array(const Array<T>& other) {
            *this = other; // Оператор присвоения переопределён ниже
        }
        
        template<class T>
        Array<T>::Array(Array&& other) {
            this->data = other.data;
            this->size = other.size;
            other.data = nullptr;
            other.size = 0;
        }

        template<class T>
        std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
            for (size_t i = 0; i < array.size; i++) {
                out << array.data[i] << " ";
            }
            return out;
        }

        template<class T>
        Array<T>::~Array() {
            delete[] this->data;
        }

        template<class T>
        size_t Array<T>::is_empty() const {
            return (size == 0);
        }

        template<class T>
        size_t Array<T>::get_size() const {
            return size;
        }

        template<class T>
        Array<T> operator+(const Array<T>& first, const Array<T>& second) {
            if (first.size != second.size) {
                throw std::runtime_error("size mismatch");
            }
            Array<T> temp(first.size);
            for (size_t i = 0; i < first.size; ++i) {
                temp.data[i] = first.data[i] + second.data[i];
            }
            return temp;
        }

        template<class T>
        Array<T> operator-(const Array<T>& first, const Array<T>& second) {
            if (first.size != second.size) {
                throw std::runtime_error("size mismatch");
            }
            Array<T> temp(first.size);
            for (size_t i = 0; i < first.size; ++i) {
                temp.data[i] = first.data[i] - second.data[i];
            }
            return temp;
        }

        template<class T>
        Array<T>& operator+=(Array<T>& first, const Array<T>& second) {
            if (first.size != second.size) {
                throw std::runtime_error("size mismatch");
            }
            for (size_t i = 0; i < first.size; ++i) {
                first.data[i] += second.data[i];
            }
            return first;
        }

        template<class T>
        Array<T>& operator-=(Array<T>& first, const Array<T>& second) {
            if (first.size != second.size) {
                throw std::runtime_error("size mismatch");
            }
            for (size_t i = 0; i < first.size; ++i) {
                first.data[i] -= second.data[i];
            }
            return first;
        }

        template<class T>
        bool Array<T>::operator==(const Array<T>& other) const {
            if (this->size != other.size) {
                throw std::runtime_error("size mismatch");
            }
            for (size_t i = 0; i < this->size; ++i) {
                if (this->data[i] != other.data[i]) {
                    return false;
                }
            }
            return true;
        };

        template<class T>
        bool Array<T>::operator!=(const Array<T>& other) const {
            return !(*this == other);
        };

        template<class T>
        T& Array<T>::operator[](size_t idx) {
            if (idx >= size) {
                throw std::runtime_error("idx out of range");
            }
            return this->data[idx];
        }

        template<class T>
        const T& Array<T>::operator[](size_t idx) const {
            if (idx >= size) {
                throw std::runtime_error("idx out of range");
            }
            return this->data[idx];
        }

        template<class T>
        Array<T>& Array<T>::operator=(const Array<T>& other) {
            if (this == &other) {
                return *this;
            }
            this->data = new T[other.size];
            for (size_t i = 0; i < other.size; i++) {
                this->data[i] = other.data[i];
            }
            size = other.size;
            return *this;
        }

        template<class T>
        Array<T>& Array<T>::operator=(Array<T>&& other) {
            if (this == &other) {
                return *this;
            }
            this->data = other.data;
            this->size = other.size;
            other.data = nullptr;
            other.size = 0;
            return *this;
        }
    };
};

#endif