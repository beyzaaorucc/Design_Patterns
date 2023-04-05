
#include <iostream>

using namespace std;

class AbstractClass
{
  public:
    void templateMethod()
    {
        islem1();
        islem2();
        sabitIslem();
        tercihliIslem();
    }

    virtual void islem1() = 0;
    virtual void islem2() = 0;
    virtual void tercihliIslem() {}
    void sabitIslem()
    {
        cout << "Bu islem sabit. Butunn siniflarda ayni..." << endl;
    }
};

class Sinif1 : public AbstractClass
{
  public:
    void islem1()
    {
        cout << "Sinif1 - islem1 calisti..." << endl;
    }
    void islem2()
    {
        cout << "Sinif1 - islem2 calisti..." << endl;
    }
    void tercihliIslem()
    {
        cout << "Sinif1 - tercihliIslem calisti..." << endl;
    }
    void sabitIslem()
    {
        cout << "Bu sabit Sinif1" << endl;
    }
};

class Sinif2 : public AbstractClass
{
  public:
    void islem1()
    {
        cout << "Sinif2 - islem1 calisti..." << endl;
    }
    void islem2()
    {
        cout << "Sinif2 - islem2 calisti..." << endl;
    }
    void sabitIslem()
    {
        cout << "Bu sabit Sinif2 " << endl;
    }
};

int main()
{
    Sinif1 sinif1;
    Sinif2 sinif2;

    sinif1.templateMethod();

    cout << "-------------------------------" << endl;
    sinif2.templateMethod();

    return 0;
}
