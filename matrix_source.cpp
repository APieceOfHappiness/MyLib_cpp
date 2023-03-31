#include <iostream>
#include <vector>
#include "Matrix/Matrix.hpp"

int main () {

    MyLib::MyMatrix::Matrix<int> mat_0arg;
    MyLib::MyMatrix::Matrix<int> mat_2arg(5, 3);
    MyLib::MyMatrix::Matrix<int> mat_3arg(5, 3, 3);
    MyLib::MyMatrix::Matrix<int> mat_copy(mat_2arg);
    MyLib::MyMatrix::Matrix<int> mat_3arg_other(5, 3, -2);
    MyLib::MyMatrix::Matrix<int> mat_empty(0, 0, -1);

    std::cout << "-------------- Log: ------------" << std::endl;
    std::cout << "mat_0arg:\t" << std::endl << mat_0arg << std::endl;
    std::cout << "mat_2arg:\t" << std::endl << mat_2arg << std::endl;
    std::cout << "mat_copy:\t" << std::endl << mat_copy << std::endl;
    std::cout << "mat_3arg:\t" << std::endl << mat_3arg << std::endl;
    std::cout << "mat_3arg_other:\t" << std::endl << mat_3arg_other << std::endl;
    std::cout << "mat_empty:\t" << std::endl << mat_empty << std::endl;

    std::cout << std::endl << "-------------- is empty: ------------" << std::endl;

    std::cout << "mat_0arg:\t" << mat_0arg.is_empty() << std::endl;
    std::cout << "mat_2arg:\t" << mat_2arg.is_empty() << std::endl;
    std::cout << "mat_3arg:\t" << mat_3arg.is_empty() << std::endl;
    std::cout << "mat_empty:\t" << mat_empty.is_empty() << std::endl;

    std::cout << std::endl << "-------------- get_size: ------------" << std::endl;

    std::cout << "mat_0arg:\t" << mat_0arg.get_size().first << "x" << mat_0arg.get_size().second << std::endl;
    std::cout << "mat_2arg:\t" << mat_2arg.get_size().first << "x" << mat_2arg.get_size().second << std::endl;
    std::cout << "mat_3arg:\t" << mat_3arg.get_size().first << "x" << mat_3arg.get_size().second << std::endl;
    std::cout << "mat_empty:\t" << mat_empty.get_size().first << "x" << mat_empty.get_size().second << std::endl;

    std::cout << std::endl << "-------------- operator+: ------------" << std::endl;

    std::cout << "mat_2arg + mat_3arg:\t" << std::endl << mat_2arg + mat_3arg << std::endl;
    std::cout << "mat_3arg + mat_3arg_other:\t" << std::endl << mat_3arg + mat_3arg_other << std::endl;
    std::cout << "mat_empty + mat_empty:\t" << std::endl << mat_empty + mat_empty << std::endl;
    // std::cout << "mat_0arg + mat_2arg:\t" << mat_0arg + mat_2arg << std::endl;
    // std::cout << "mat_0arg + mat_empty:\t" << mat_0arg + mat_empty << std::endl;

    std::cout << std::endl << "-------------- operator-: ------------" << std::endl;

    std::cout << "mat_2arg - mat_3arg:\t" << std::endl << mat_2arg - mat_3arg << std::endl;
    std::cout << "mat_3arg - mat_3arg_other:\t" << std::endl << mat_3arg - mat_3arg_other << std::endl;
    std::cout << "mat_empty - mat_empty:\t" << std::endl << mat_empty - mat_empty << std::endl;
    // std::cout << "mat_0arg - mat_2arg:\t" << mat_0arg - mat_2arg << std::endl;
    // std::cout << "mat_0arg - mat_empty:\t" << mat_0arg - mat_empty << std::endl;

    std::cout << std::endl << "-------------- operator+=: ------------" << std::endl;

    std::cout << "mat_2arg += (mat_3arg + mat_3arg_other):\t" << std::endl << (mat_2arg += (mat_3arg + mat_3arg_other)) << std::endl;
    std::cout << "mat_2arg += mat_2arg:\t" << std::endl << (mat_2arg += mat_2arg) << std::endl;
    std::cout << "mat_empty += mat_empty:\t" << std::endl << (mat_empty += mat_empty) << std::endl;

    std::cout << std::endl << "-------------- operator-=: ------------" << std::endl;

    std::cout << "mat_2arg -= (mat_3arg + mat_3arg_other):\t" << std::endl << (mat_2arg -= (mat_3arg + mat_3arg_other)) << std::endl;
    std::cout << "mat_2arg -= mat_2arg:\t" << std::endl << (mat_2arg -= mat_2arg) << std::endl;
    std::cout << "mat_empty -= mat_empty:\t" << std::endl << (mat_empty -= mat_empty) << std::endl;

    std::cout << std::endl << "-------------- operator==: ------------" << std::endl;

    std::cout << "mat_2arg == mat_copy:\t" << (mat_2arg == mat_copy) << std::endl;
    std::cout << "mat_2arg == mat_2arg:\t" << (mat_2arg == mat_2arg) << std::endl;
    std::cout << "mat_2arg == mat_3arg:\t" << (mat_2arg == mat_3arg) << std::endl;
    std::cout << "mat_empty == mat_empty:\t" << (mat_empty == mat_empty) << std::endl;
    // std::cout << "mat_2arg == mat_empty:\t" << (mat_2arg == mat_empty) << std::endl;

    std::cout << std::endl << "-------------- operator!=: ------------" << std::endl;

    std::cout << "mat_2arg != mat_copy:\t" << (mat_2arg != mat_copy) << std::endl;
    std::cout << "mat_2arg != mat_2arg:\t" << (mat_2arg != mat_2arg) << std::endl;
    std::cout << "mat_2arg != mat_3arg:\t" << (mat_2arg != mat_3arg) << std::endl;
    std::cout << "mat_empty != mat_empty:\t" << (mat_empty != mat_empty) << std::endl;
    // std::cout << "mat_2arg != mat_empty:\t" << (mat_2arg != mat_empty) << std::endl;

    std::cout << std::endl << "-------------- operator[]: ------------" << std::endl;

    MyLib::MyMatrix::Matrix<int> mat_idx(5, 3, 0);
    for (size_t i = 0; i < mat_idx.get_size().first; ++i) {
        for (size_t j = 0; j < mat_idx.get_size().second; ++j) {
            mat_idx[i][j] = i * mat_idx.get_size().second + j;
        }
    }
    std::cout << "mat_idx:\t" << std::endl << mat_idx << std::endl;
    std::cout << "mat_idx[2]:\t" << mat_idx[2] << std::endl;
    std::cout << "mat_idx[0]:\t" << mat_idx[0] << std::endl;
    std::cout << "mat_idx[0][1] += 1:\t" << (mat_idx[0][1] += 1) << std::endl;
    std::cout << "mat_idx:\t" << std::endl << mat_idx << std::endl;
    // std::cout << "mat_idx[5]:\t" << mat_idx[5] << std::endl;
    // std::cout << "mat_empty[0]:\t" << mat_empty[0] << std::endl;

    std::cout << std::endl << "-------------- move: ------------" << std::endl;
    
    MyLib::MyMatrix::Matrix<int> src(5, 3, 1);
    std::cout << "src: " << src << std::endl;
    MyLib::MyMatrix::Matrix<int> dest(std::move(src));
    std::cout << "src(after moving): " << src << std::endl;
    std::cout << "dest(after moving): " << dest << std::endl;

    return 0;
}