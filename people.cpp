#include <iostream>
#include <string.h>

class people {
};

class people2 {
public:
    people2();
    ~people2();

    // 票数+1
    void inc_count();

    // 获取当前票数
    int get_count();
private:
    // 选民的名字
    char m_name[32];
    // 票数
    int m_count;
};
void people2::inc_count()
{
    m_count++;
}

int people2::get_count()
{
    return m_count;
}

people2::people2()
{
    memset(m_name, 0, sizeof(m_name));
    m_count = 0;
    std::cout <<"构造函数"<<std::endl;
}

people2::~people2()
{
    std::cout <<"析构函数"<<std::endl;
}

int main(int argc, char **argv)
{
    people p;
    //people2 p2;
    std::cout <<"-----"<<std::endl;

    std::cout <<"-----"<<std::endl;
    people2 *p3 = new people2;
    std::cout <<p3->get_count()<< std::endl;
    p3->inc_count();
    std::cout <<p3->get_count()<< std::endl;
    delete p3;
    return 0;
}
