// c++ header file
#include <iostream>
#include <string.h>


struct people {
    char name[32];
    int count;
};

void vote(struct people *p) {
    p->count++;
}

void print(struct people *p) {
    std::cout << p->name <<" " <<p->count << std::endl;
}

// c语言版本
void test_c()
{
    ///// 变量
    struct people p1 = {"a", 0};
    struct people p2 = {"b", 0};
    struct people p3 = {"c", 0};

    ///// 函数

    // 投票
    vote(&p1);
    vote(&p1);
    vote(&p2);

    // 打印票数
    print(&p1);
    print(&p2);
    print(&p3);
}

// 类的声明
class people2 {
public:
    //构造函数
    people2(char *name, int count);
    
    // 析构函数
    ~people2();

    // 成员函数
    void vote();
    void print();

    // 私有的，不能被其他类访问
private:
    // 成员变量
    char m_name[32];
    int m_count;
};

people2::people2(char *name, int count)
{
    strcpy(m_name, name);
    m_count = count;
}

people2::~people2()
{
}

// 实现people2的vote成员函数
// 1. 没有声明count局部变量
// 2. 没有声明count全局变量
void people2::vote()
{
    // 成员变量, 在people2类里面定义
    m_count++;
}

void people2::print()
{
    std::cout << m_name << " " << m_count << std::endl;
}

void test_cpp()
{
    people2 p1("a", 0);
    people2 p2("b", 0);
    people2 p3("c", 0);

    p1.vote();
    p1.vote();
    p2.vote();

    p1.print();
    p2.print();
    p3.print();
}

int main()
{
    test_cpp();
    return 0;
}
