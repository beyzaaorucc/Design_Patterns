#include <iostream>
using namespace std;

class Dikdortgen
{
  public:
    virtual void ciz() = 0;
};

class Kare
{
  private:
    double kenar;

  public:
    Kare(double kenar)
    {
        this->kenar = kenar;
        cout << "Kare :  Kenar = " << kenar << endl;
    }
    void cizim()
    {
        cout << "Kare:  Kenar. " << kenar << endl;
    }
};

class Adapter : public Dikdortgen, private Kare //Adapter Class
{
  public:
    Adapter(double kenarlar)
        : Kare(kenarlar / 4)
    {
        cout << "Adapter = " << kenarlar << endl;
    }
    virtual void ciz() override
    {
        cout << "Adapter:" << endl;
        cizim();
    }
};

int main()
{
    Dikdortgen *k = new Adapter(4);
    k->ciz();

    delete[] k;
}

