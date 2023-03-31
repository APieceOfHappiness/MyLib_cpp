#include <iostream>
#include "Array/Array.hpp"

int main () {
    MyLib::MyArray::Array<int> arr_0arg;
    MyLib::MyArray::Array<int> arr_1arg(5);
    MyLib::MyArray::Array<int> arr_2arg(5, 3);
    MyLib::MyArray::Array<int> arr_copy(arr_1arg);
    MyLib::MyArray::Array<int> arr_2arg_other(5, -2);
    MyLib::MyArray::Array<int> arr_empty(0, -1);

    std::cout << "-------------- Log: ------------" << std::endl;
    std::cout << "arr_0arg:\t" << arr_0arg << std::endl;
    std::cout << "arr_1arg:\t" << arr_1arg << std::endl;
    std::cout << "arr_copy:\t" << arr_copy << std::endl;
    std::cout << "arr_2arg:\t" << arr_2arg << std::endl;
    std::cout << "arr_2arg_other:\t" << arr_2arg_other << std::endl;
    std::cout << "arr_empty:\t" << arr_empty << std::endl;

    std::cout << std::endl << "-------------- is empty: ------------" << std::endl;

    std::cout << "arr_0arg:\t" << arr_0arg.is_empty() << std::endl;
    std::cout << "arr_1arg:\t" << arr_1arg.is_empty() << std::endl;
    std::cout << "arr_2arg:\t" << arr_2arg.is_empty() << std::endl;
    std::cout << "arr_empty:\t" << arr_empty.is_empty() << std::endl;

    std::cout << std::endl << "-------------- get_size: ------------" << std::endl;

    std::cout << "arr_0arg:\t" << arr_0arg.get_size() << std::endl;
    std::cout << "arr_1arg:\t" << arr_1arg.get_size() << std::endl;
    std::cout << "arr_2arg:\t" << arr_2arg.get_size() << std::endl;
    std::cout << "arr_empty:\t" << arr_empty.get_size() << std::endl;

    std::cout << std::endl << "-------------- operator+: ------------" << std::endl;

    std::cout << "arr_1arg + arr_2arg:\t" << arr_1arg + arr_2arg << std::endl;
    std::cout << "arr_2arg + arr_2arg_other:\t" << arr_2arg + arr_2arg_other << std::endl;
    std::cout << "arr_empty + arr_empty:\t" << arr_empty + arr_empty << std::endl;
    // std::cout << "arr_0arg + arr_1arg:\t" << arr_0arg + arr_1arg << std::endl;
    // std::cout << "arr_0arg + arr_empty:\t" << arr_0arg + arr_empty << std::endl;

    std::cout << std::endl << "-------------- operator-: ------------" << std::endl;

    std::cout << "arr_1arg - arr_2arg:\t" << arr_1arg - arr_2arg << std::endl;
    std::cout << "arr_2arg - arr_2arg_other:\t" << arr_2arg - arr_2arg_other << std::endl;
    std::cout << "arr_empty - arr_empty:\t" << arr_empty - arr_empty << std::endl;
    // std::cout << "arr_0arg - arr_1arg:\t" << arr_0arg - arr_1arg << std::endl;
    // std::cout << "arr_0arg - arr_empty:\t" << arr_0arg - arr_empty << std::endl;

    std::cout << std::endl << "-------------- operator+=: ------------" << std::endl;

    std::cout << "arr_1arg += (arr_2arg + arr_2arg_other):\t" << (arr_1arg += (arr_2arg + arr_2arg_other)) << std::endl;
    std::cout << "arr_1arg += arr_1arg:\t" << (arr_1arg += arr_1arg) << std::endl;
    std::cout << "arr_empty += arr_empty:\t" << (arr_empty += arr_empty) << std::endl;

    std::cout << std::endl << "-------------- operator-=: ------------" << std::endl;

    std::cout << "arr_1arg -= (arr_2arg + arr_2arg_other):\t" << (arr_1arg -= (arr_2arg + arr_2arg_other)) << std::endl;
    std::cout << "arr_1arg -= arr_1arg:\t" << (arr_1arg -= arr_1arg) << std::endl;
    std::cout << "arr_empty -= arr_empty:\t" << (arr_empty -= arr_empty) << std::endl;

    std::cout << std::endl << "-------------- operator==: ------------" << std::endl;

    std::cout << "arr_1arg == arr_copy:\t" << (arr_1arg == arr_copy) << std::endl;
    std::cout << "arr_1arg == arr_1arg:\t" << (arr_1arg == arr_1arg) << std::endl;
    std::cout << "arr_1arg == arr_2arg:\t" << (arr_1arg == arr_2arg) << std::endl;
    std::cout << "arr_empty == arr_empty:\t" << (arr_empty == arr_empty) << std::endl;
    // std::cout << "arr_1arg == arr_empty:\t" << (arr_1arg == arr_empty) << std::endl;

    std::cout << std::endl << "-------------- operator!=: ------------" << std::endl;

    std::cout << "arr_1arg != arr_copy:\t" << (arr_1arg != arr_copy) << std::endl;
    std::cout << "arr_1arg != arr_1arg:\t" << (arr_1arg != arr_1arg) << std::endl;
    std::cout << "arr_1arg != arr_2arg:\t" << (arr_1arg != arr_2arg) << std::endl;
    std::cout << "arr_empty != arr_empty:\t" << (arr_empty != arr_empty) << std::endl;
    // std::cout << "arr_1arg != arr_empty:\t" << (arr_1arg != arr_empty) << std::endl;

    std::cout << std::endl << "-------------- operator[]: ------------" << std::endl;

    MyLib::MyArray::Array<int> arr_idx(5, 0);
    for (size_t i = 0; i < arr_idx.get_size(); ++i) {
        arr_idx[i] = i;
    }
    std::cout << "arr_idx:\t" << arr_idx << std::endl;
    std::cout << "arr_idx[2]:\t" << arr_idx[2] << std::endl;
    std::cout << "arr_idx[0]:\t" << arr_idx[0] << std::endl;
    std::cout << "arr_idx[0]++:\t" << arr_idx[0]++ << std::endl;
    std::cout << "arr_idx:\t" << arr_idx << std::endl;
    // std::cout << "arr_idx[5]:\t" << arr_idx[5] << std::endl;
    // std::cout << "arr_empty[0]:\t" << arr_empty[0] << std::endl;

    std::cout << std::endl << "-------------- move: ------------" << std::endl;
    
    MyLib::MyArray::Array<int> src(5, 0);
    std::cout << "src: " << src << std::endl;
    MyLib::MyArray::Array<int> dest(std::move(src));
    std::cout << "src(after moving): " << src << std::endl;
    std::cout << "dest(after moving): " << dest << std::endl;
    return 0;
}