#include <iostream>

using namespace std;

enum HayvanTuru{
    KopekTuru,
    KediTuru,
    KusTuru
};
//ABSTRACT CLASS
class Hayvan
{
    public:
        virtual void sesCikar()=0;
        static Hayvan *olustur(HayvanTuru);

};

class Kopek : public Hayvan
{
    public:
        void sesCikar() override
        {
            cout<<"hav hav"<<endl;

        }

};

class Kedi : public Hayvan
{
    public:
        void sesCikar() override
        {
            cout<<"miyav miyav"<<endl;
        }
};

class Kus : public Hayvan
{
    public:
        void sesCikar() override
        {
           cout<<"cik cik"<<endl;
        }

};

//FACTORY PATTERN
Hayvan *Hayvan :: olustur(HayvanTuru tur)
{
    if(tur == KopekTuru){
        return new Kopek();
    }
    else if(tur == KediTuru){
        return new Kedi();
    }
    else if(tur == KusTuru){
        return new Kus();
    }else{
        return 0;
    }
}

int main()
{
    HayvanTuru tur = KopekTuru;
    Hayvan *hayvanptr = Hayvan ::olustur(tur);
    hayvanptr->sesCikar();

    delete[] hayvanptr;
    return 0;

}

