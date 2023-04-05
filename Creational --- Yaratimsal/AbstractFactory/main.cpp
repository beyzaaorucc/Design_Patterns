#include <iostream>

using namespace std;

//#define Dil
#define Matematik

class Ders
{
  public:
    virtual void dersturu() = 0;
};

class Matematik : public Ders
{
  public:
    void dersturu() override
    {
        cout << "Matematik Dersi" << endl;
    }
};

class Dil : public Ders
{
  public:
    void dersturu() override
    {
        cout << "Dil Dersi" << endl;
    }
};

class Okul
{
  public:
    virtual Ders *dersOlustur() = 0;
};

class DilDersi : public Okul
{
  public:
    Ders *dersOlustur() override
    {
        return new Dil;
    }
};

class MatematikDersi : public Okul
{
  public:
    Ders *dersOlustur() override
    {
        return new Matematik;
    }
};

int main()
{
#ifdef Dil
    Okul *okul = new DilDersi;
#elif Matematik
    Okul *okul = new MatematikDersi;
#endif
    Ders *ders = okul->dersOlustur();
    ders->dersturu();



    delete[] okul;
    delete[] ders;
    return 0;
}
