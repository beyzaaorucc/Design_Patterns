#include <iostream>

using namespace std;

class Komut
{
public:
  virtual void calistir() = 0;
};

class Kapi
{
public:
  Kapi() {}

  void ac()
  {
    cout << "Kapi Acildi..." << endl;
  }

  void kapat()
  {
    cout << "Kapi Kapandi..." << endl;
  }
};

class AcKomut : public Komut
{
private:
 Kapi &kapi;

public:
  AcKomut(Kapi &kapi) : kapi(kapi)
  {
  }

  virtual void calistir() override
  {
    kapi.ac();
  }
};


class KapatKomut : public Komut
{
private:
  Kapi &kapi;

public:
  KapatKomut(Kapi &kapi) : kapi(kapi)
  {
  }
  virtual void calistir() override
  {
    kapi.kapat();
  }
};

class Degistir
{
  private:
  Komut &acKomut;
  Komut &kapatKomut;

public:
  Degistir(Komut &acKomut, Komut &kapatKomut)
      : acKomut(acKomut), kapatKomut(kapatKomut)
  {
  }

  void ac()
  {
    acKomut.calistir();
  }

  void kapat()
  {
    kapatKomut.calistir();
  }
};

int main()
{
  Kapi otoKapi;
  AcKomut degistirAc(otoKapi);
  KapatKomut degistirKapat(otoKapi);

  Degistir s(degistirAc, degistirKapat);
  s.ac();
  s.kapat();
}
