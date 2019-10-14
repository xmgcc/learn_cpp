#include <iostream>
#include <string.h>

class people {
};

////////////////////////////////////////////////////////

class people2 {
public:
    people2();
    people2(const char *name, int count);
    ~people2();

    // 获取选民的名字
    char *get_name();

    // 设置选民的名字
    void set_name(const char *name);

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
char *people2::get_name()
{
    return m_name;
}

void people2::set_name(const char *name)
{
    strcpy(m_name, name);
}
void people2::inc_count()
{
    m_count++;
}

int people2::get_count()
{
    return m_count;
}

people2::people2(const char *name, int count)
{
    strcpy(m_name, name);
    m_count = count;
}

people2::people2()
{
    memset(m_name, 0, sizeof(m_name));
    m_count = 0;
    std::cout <<"people2构造函数"<<std::endl;
}

people2::~people2()
{
    std::cout <<"people2析构函数"<<std::endl;
}

////////////////////////////////////////////////////////


class daibiao : public people2 {
public:
    // 初始化列表调用基类的构造函数
    daibiao() {
        std::cout <<"daibiao构造函数"<<std::endl;
    }
    ~daibiao() {
        std::cout <<"daibiao析构函数"<<std::endl;
    }

    char *get_wechat() {
        return m_wechat;
    }

    void set_wechat(const char *wechat) {
        strcpy(m_wechat, wechat);
    }

private:
    // 微信
    char m_wechat[32];
};



void test()
{
    people p;
    //people2 p2;
    std::cout <<"-----"<<std::endl;

    std::cout <<"-----"<<std::endl;

    people2 *p3 = new people2;
    p3->set_name("zhangsan");
    std::cout << p3->get_name() << p3->get_count()<< std::endl;
    p3->inc_count();
    std::cout <<p3->get_name() <<p3->get_count()<< std::endl;
    delete p3;


    people2 p4("lisi", 10000);
    std::cout << p4.get_name() << p4.get_count() << std::endl;
    p4.inc_count();
    std::cout << p4.get_name() << p4.get_count() << std::endl;
}

void test2()
{
    daibiao d;

    d.set_wechat("123456");
    d.set_name("wangwu");

    std::cout << d.get_name() << ", " << d.get_wechat() << ", " << d.get_count()<< std::endl;
}

void test10()
{
    people2 *p = new people2;
    delete p;
}
void test11()
{
    daibiao *d = new daibiao;
    delete d;
}
void test12()
{
    people2 *p = new daibiao;
    delete p;
}
int main(int argc, char **argv)
{
    //test10();
    // std::cout << "-------" << std::endl;
    // test11();
    // std::cout << "-------" << std::endl;
    test12();
    return 0;
}
