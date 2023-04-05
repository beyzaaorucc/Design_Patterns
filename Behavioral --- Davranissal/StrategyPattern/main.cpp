#include <iostream>
using namespace std;

class Ogrenci
{
  public:
    virtual void yerlestirme(string) const = 0;
};

class OgrenciA : public Ogrenci
{
  public:
    void yerlestirme(string sinif) const override
    {
        cout << "Ogrenci A, " << sinif << " sinifina yerlestirildi." << endl;
    }
};

class OgrenciB : public Ogrenci
{
    public:;
    void yerlestirme(string sinif) const override
    {
        cout << "Ogrenci B, " << sinif << " sinifina yerlestirildi." << endl;
    }
};

class OgrenciC : public Ogrenci
{
  public:
    void yerlestirme(string sinif) const override
    {
        cout << "Ogrenci C, " << sinif << " sinifina yerlestirildi." << endl;
    }
};

class Sinif
{
  private:
    Ogrenci *ogrenci;
    string sinifAdi;

  public:
    Sinif(Ogrenci *ogrenci, string sinifAdi) : ogrenci(ogrenci), sinifAdi(sinifAdi)
    {
    }

    void setOgrenciDegistir(Ogrenci *ogrenci)
    {
        this->ogrenci = ogrenci;
    }

    void yerlestirme() const
    {
        ogrenci->yerlestirme(sinifAdi);
    }
};

int main()
{
    OgrenciA ogrenciA;
    OgrenciB ogrenciB;
    OgrenciC ogrenciC;

    Sinif sinif1(&ogrenciA, "Sinif-1");
    Sinif sinif2(&ogrenciB, "Sinif-2");
    Sinif sinif3(&ogrenciC, "Sinif-3");

    sinif1.yerlestirme();
    sinif2.yerlestirme();
    sinif3.yerlestirme();

    sinif1.setOgrenciDegistir(&ogrenciB);
    sinif1.yerlestirme();
    sinif1.setOgrenciDegistir(&ogrenciC);
    sinif1.yerlestirme();

    return 0;
}
