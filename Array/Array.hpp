#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

namespace MyLib {
    namespace MyArray {

        template<class T>
        class Array;

        template<class T>
        std::ostream& operator<<(std::ostream& out, const Array<T> &array);

        template<class T>
        Array<T> operator+(const Array<T>& first, const Array<T>& second);

        template<class T>
        Array<T> operator-(const Array<T>& first, const Array<T>& second);

        template<class T>
        Array<T>& operator+=(Array<T>& first, const Array<T>& second);

        template<class T>
        Array<T>& operator-=(Array<T>& first, const Array<T>& second);

        template<class T>
        class Array {
        private:
            T *data = nullptr;
            size_t size = 0;
        public:

            Array();

            Array(size_t n, const T& val = 0);

            Array(const Array<T>& other);

            Array(Array<T>&& other);

            ~Array();

            size_t get_size() const;

            size_t is_empty() const;

            friend std::ostream& operator<< <>(std::ostream& out, const Array<T> &array);            
            
            friend Array<T> operator+ <>(const Array<T>& first, const Array<T>& second);

            friend Array<T> operator- <>(const Array<T>& first, const Array<T>& second);

            friend Array<T>& operator+= <>(Array<T>& first, const Array<T>& second);

            friend Array<T>& operator-= <>(Array<T>& first, const Array<T>& second);

            T& operator[](size_t idx);

            const T& operator[](size_t idx) const;

            bool operator==(const Array<T>& other) const;

            bool operator!=(const Array<T>& other) const;
            
            Array<T>& operator=(const Array<T>& other);

            Array<T>& operator=(Array<T>&& other);
        };
    };
};

#include "Array.tpp"

#endif