#include <iostream>
#include <string>

using namespace std;

class TrafikKurallari
{
protected:
  TrafikKurallari *trafikKurallari;

public:
  TrafikKurallari()
  {
    trafikKurallari = NULL;
  }

  virtual ~TrafikKurallari() {}

  virtual void sorgula(int value) = 0;

  void setKuralDegistir(TrafikKurallari *yolTipi)
  {
    trafikKurallari = yolTipi;
  }
};

class Yol : public TrafikKurallari
{
private:
  int hizLimiti;
  string yolTipi;

public:
  Yol(string yolTipi, int hizLimiti)
  {
    this->hizLimiti = hizLimiti;
    this->yolTipi = yolTipi;
  }

  ~Yol() {}

  void sorgula(int yapilanHiz) override
  {
    if (yapilanHiz < hizLimiti)
    {
      cout << "--------------------------------------------------" << endl;
      cout << "Yol Tipi : " << yolTipi << endl
           << "Hiz Limiti : " << hizLimiti << endl
           << "Yapilan Hiz : " << yapilanHiz << endl
           << "Sonuc : Ceza Almadiniz." << endl;
    }
    else if (trafikKurallari != NULL)
    {
      trafikKurallari->sorgula(yapilanHiz);
    }
    else
    {
      cout << "--------------------------------------------------" << endl;
      cout << "Dikkat !!! Hiz Limit Asimi" << endl
           << "Yol Tipi : " << yolTipi << endl
           << "Yapilan Hiz " << yapilanHiz << endl
           << "Bu Yolda Limit : " << hizLimiti << endl
           << "Lutfen Limitte Kaliniz." << endl;
    }
  }
};

int main()
{
  TrafikKurallari *ulke1 = new Yol("Tek Serit", 100);
  TrafikKurallari *ulke2 = new Yol("Cift Serit", 120);
  TrafikKurallari *ulke3 = new Yol("Otoban", 150);

  ulke1->sorgula(80);
  ulke1->sorgula(115);

  ulke1->setKuralDegistir(ulke2);
  ulke1->sorgula(90);
  ulke1->sorgula(115);

  ulke2->sorgula(85);
  ulke2->sorgula(130);
  ulke2->setKuralDegistir(ulke3);
  ulke2->sorgula(140);

  delete ulke1;
  delete ulke2;
  delete ulke3;

  return 0;
}
