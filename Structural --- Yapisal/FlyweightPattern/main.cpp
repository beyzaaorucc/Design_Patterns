#include <iostream>

using namespace std;

class Siralama
{
  public:
    Siralama(int ilkDeger)
    {
        ilk_deger = ilkDeger;
        cout << "ctor: " << ilk_deger << '\n';
    }
    ~Siralama()
    {
        cout << ilk_deger << ' ';
    }
    void report(int sonrakiDeger)
    {
        cout << ilk_deger << sonrakiDeger << ' ';
    }
  private:
    int ilk_deger;
};

class Factory //deðiþtirilemez sekilde olmasý için static
{
  public:
    static Siralama *get_fly(int in)
    {
        if (!havuz[in])
          havuz[in] = new Siralama(in);
        return havuz[in];
    }
    static void temizle()
    {
        cout << "dtors: ";
        for (int i = 0; i < X; ++i)
          if (havuz[i])
            delete havuz[i];
        cout << '\n';
    }
    static int X, Y;
  private:
    static Siralama*havuz[];
};

int Factory::X = 10, Factory::Y = 10;
Siralama *Factory::havuz[] =
{
  0, 0, 0, 0, 0, 0
};

int main()
{
  for (int i = 0; i < Factory::X; ++i)
  {
    for (int j = 0; j < Factory::Y; ++j)
      Factory::get_fly(i)->report(j);
    cout << '\n';
  }
  Factory::temizle();
}
