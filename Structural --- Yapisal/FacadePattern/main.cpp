#include <string>
#include <iostream>

using namespace std;

class Alarm
{
  public:
    void alarmAc()
    {
        cout << "Alarm Acik -> " << endl;

    }

    void alarmKapat()
    {
        cout << "Alarm Kapali ->" << endl;

    }
};

class Kapi
{
  public:
    void kapiAc()
    {
        cout << "Kapilar Acik..." << endl;
    }

    void kapiKapat()
    {
        cout << "Kapilar Kapali..." << endl;
    }
};

class Isik
{
  public:
    void isikAc()
    {
        cout << "Isiklar Acik..." << endl;
    }

    void isikKapat()
    {
        cout << "Isiklar Kapali..." << endl;
    }
};

class ArabaFacade
{
    Alarm alarm;
    Kapi kapi;
    Isik isik;

  public:
    ArabaFacade() {}

    void arabaDisi()
    {
        alarm.alarmAc();
        kapi.kapiKapat();
        isik.isikKapat();

    }

    void arabaIci()
    {
        alarm.alarmKapat();
        kapi.kapiAc();
        isik.isikAc();
    }
};

int main()
{
    ArabaFacade facade;

    cout << "*****Arabadan Cikis*****" << endl;
    facade.arabaDisi();

    cout << "---------------------------------------------" << endl;

    cout << "*****Arabaya Binis*****" << endl;
    facade.arabaIci();
}
