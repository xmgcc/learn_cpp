#include <iostream>

class people {
public:
    void test() {}

    static void test2() {}

    virtual void test3(){}
    virtual void test4(){}
    // char *p;

private:
    static int m_a;

    int m_b;
};

struct test {
    char *p; //8
    int m_b; //4+4
};

class base {
public:
    virtual void print() {
        std::cout << " I am base" << std::endl;
    }
};

class sub1 : public base {
public:
    // 也实现了一个print函数
    void print() {
        std::cout << " I am sub1" << std::endl;
    }
};

class sub2 : public base {
public:
    // 也实现了一个print函数
    void print() {
        std::cout << " I am sub2" << std::endl;
    }
};


void test()
{
    people p;
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(struct test) << std::endl;
}

int main(int argc, char **argv)
{
    base *b = new base;
    b->print();

    sub1 *s1 = new sub1;
    s1->print();

    // 多态，基类指针指向派生类
    base *p = new sub1;
    p->print();
    return 0;
}
