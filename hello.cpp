// c++ header file
#include <iostream>
// c header file
//#include <stdio.h>

// 全局变量
namespace jike1 {
    // 第一个
    int xidada;
};

// 第2个
int xidada;

int main()
{
    int value;
    int value2;
    std::cout << "hello cpp" << std::endl;
    std::cin >> value;
    std::cin >> value2;

    if (value > value2) {
        std::cout << "value = " << value << std::endl;
    } else {
        std::cout << "value = " << value2 << std::endl;
    }

    //printf("hello, I am c\n");
    return 0;
}
