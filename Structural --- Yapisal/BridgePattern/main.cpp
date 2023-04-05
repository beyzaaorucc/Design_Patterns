#include <iostream>

using namespace std;

/* Uygulatýcý*/
class AnaCizim
{
  public:
    virtual void dortgenCiz(double x, double y) = 0;
};

/* Somut Uygulatýcý A*/
class Cizim1 : public AnaCizim
{
  public:
    void dortgenCiz(double x, double y) override
    {
        cout << "Cizim-1 Verileri x:  " << x <<" "<< " y :" << y << endl;
    }
};

/* Somut Uygulatýcý B*/
class Cizim2 : public AnaCizim
{
  public:
    void dortgenCiz(double x, double y) override
    {
        cout << "Cizim-2 Verileri x:  " << x <<" " << " y :" << y << endl;
    }
};

/* Soyutlama*/
class Sekil
{
  public:
    virtual void ciz() = 0;
    virtual void boyutArttir(double boyut) = 0;
};

/* Soyut Ýþleme*/
class DortgenSekil : public Sekil
{
  private:
    double m_x, m_y;
    AnaCizim *cizim;

  public:
    DortgenSekil(double x, double y,AnaCizim *cizim) : m_x(x), m_y(y),cizim(cizim)
    {
    }
    void ciz() override
    {
        cizim->dortgenCiz(m_x, m_y);
    }
    void boyutArttir(double boyut) override
    {
         m_x *= boyut;
         m_y *= boyut;
    }
};

int main()
{
    DortgenSekil dortgen1(2, 2,new Cizim1());
    DortgenSekil dortgen2(3, 8,new Cizim2());
    dortgen1.boyutArttir(2.0);
    dortgen2.boyutArttir(4.0);
    dortgen1.ciz();
    dortgen2.ciz();
    return 0;
}
