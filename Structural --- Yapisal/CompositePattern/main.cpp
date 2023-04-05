#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

class Ders
{
  public:
    virtual void yazdir() const = 0;
};

class Matematik : public Ders
{
  public:
    void yazdir() const override
    {
        cout << "Matematik \n";
    }
};

class Turkce : public Ders
{
  public:
    void yazdir() const override
    {
        cout << "Turkce \n";
    }
};

class Tarih : public Ders
{
  public:
    void yazdir() const override
    {
        cout << "Tarih \n";
    }
};

class CompositeDers : public Ders
{
  private:
    vector<Ders *> dersListesi;

  public:
    void yazdir() const override
    {
        for (Ders *ders : dersListesi)
        {
            ders->yazdir();
        }
    }

    void ekle(Ders *ders)
    {
        dersListesi.push_back(ders);
    }
};

int main()
{
    // Dersler
    const unique_ptr<Matematik> matematik1(new Matematik());
    const unique_ptr<Matematik> matematik2(new Matematik());
    const unique_ptr<Turkce> turkce(new Turkce());
    const unique_ptr<Tarih> tarih(new Tarih());

    //Composite Pattern
    const unique_ptr<CompositeDers> ders1(new CompositeDers());
    const unique_ptr<CompositeDers> ders2(new CompositeDers());
    const unique_ptr<CompositeDers> ders3(new CompositeDers());


    ders2->ekle(matematik1.get());
    ders2->ekle(matematik2.get());
    ders2->ekle(tarih.get());

    ders3->ekle(turkce.get());

    ders1->ekle(ders2.get());
    ders1->ekle(ders3.get());


    ders1->yazdir();
    return 0;
}
