#include <iostream>

using namespace std;

class Calisan
{
    string isim;
    static string list[];
    static int sonraki;

  public:
    Calisan()
    {
        isim = list[sonraki++];
    }
    string ad()
    {
        return isim;
    }
};
string Calisan::list[] =
    {
        "Beyza", "Feyza", "Revza", "Leyza"};
int Calisan::sonraki = 0;

class NakitKoruma
{
    int bakiye;

  public:
    NakitKoruma()
    {
        bakiye = 500;
    }
    bool cekme(int ucret)
    {
        if (ucret > bakiye)
            return false;
        bakiye -= ucret;
        return true;
    }
    int getBakiye()
    {
        return bakiye;
    }
};

class AnaPara
{
    NakitKoruma anapara;

  public:
    bool cekme(Calisan &c, int ucret)
    {
        if (c.ad() == "Beyza" || c.ad() == "Feyza" || c.ad() == "Leyza")
            return anapara.cekme(ucret);
        else
            return false;
    }
    int getBakiye()
    {
        return anapara.getBakiye();
    }
};

int main()
{
    AnaPara ca;
    Calisan calisan[4];
    for (int i = 0, ucret = 100; i < 4; i++, ucret += 100)
        if (!ca.cekme(calisan[i], ucret))
            cout << "Para kalmadı " << calisan[i].ad() << '\n';
        else
            cout << ucret << " TL  " << calisan[i].ad() << '\n';
    cout << "Kalan bakiye" << ca.getBakiye() << '\n';
}
