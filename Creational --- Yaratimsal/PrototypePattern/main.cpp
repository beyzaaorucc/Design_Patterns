#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

class Kayit
{
  public:
    virtual ~Kayit() {}
    virtual void print() = 0;
    virtual unique_ptr<Kayit> clone() = 0;
};

class CalisanKayit : public Kayit
{
  private:
    string calisanIsim;
    int calisanID;

  public:
    CalisanKayit(string calisanIsim, int ID) : calisanIsim(calisanIsim), calisanID(ID)
    {
    }

    void print() override
    {
        cout << "Calisan Kayd�" << endl
             << "�sim  : " << calisanIsim << endl
             << "ID  : " << calisanID << endl
             << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<CalisanKayit>(*this);
    }
};

class MusteriKayit : public Kayit
{
  private:
    string musteriIsim;
    int musteriID;

  public:
    MusteriKayit(string musteriIsim, int ID) : musteriIsim(musteriIsim), musteriID(ID)
    {
    }

    void print() override
    {
        cout << "Musteri Kayd�" << endl
             << "�sim  : " << musteriIsim << endl
             << "ID  : " << musteriID << endl
             << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<MusteriKayit>(*this);
    }
};

enum KayitTipi
{
    CAL�SAN,
    MUSTER�

};

class KayitFactory
{
  private:
    unordered_map<KayitTipi, unique_ptr<Kayit>, hash<int>> kayit;

  public:
    KayitFactory()
    {
        kayit[CAL�SAN] = make_unique<CalisanKayit>("Beyza", 1234);
        kayit[MUSTER�] = make_unique<MusteriKayit>("Revza", 5678);

    }

    unique_ptr<Kayit> kayitOlustur(KayitTipi recordType)
    {
        return kayit[recordType]->clone();
    }
};

int main()
{
    KayitFactory kayitFactory;

    auto kayit = kayitFactory.kayitOlustur(CAL�SAN);
    kayit->print();

    kayit = kayitFactory.kayitOlustur(MUSTER�);
    kayit->print();


}
