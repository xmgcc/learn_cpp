// c++ header file
#include <iostream>

namespace jike1 {
    // 第一个
    int xidada;
};

// 第2个
int xidada;

int main()
{
    xidada = 0;

    // 第二个
    jike1::xidada = 0;
    std::cout << "aa";
    return 0;
}
