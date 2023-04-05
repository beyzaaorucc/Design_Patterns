#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Araba
{
  private:
    string marka;
    string model;
    string renk;
    string kademe;

  public:
    void setMarka(const string &marka)
    {
        this->marka = marka;
    }
    void setModel(const string &model)
    {
        this->model = model;
    }
    void setRenk(const string &renk)
    {
        this->renk = renk;
    }

    void setKademe(const string &kademe)
    {
        this->kademe = kademe;
    }

    void bul() const
    {
        cout << kademe << " Araba Ozellikleri - Marka " << Marka << endl << "Model : " << model << endl << "Renk : "
             << renk << endl;
    }
};

class ArabaBuilder
{
  protected:
    std::unique_ptr<Araba> araba;

  public:
    virtual ~ArabaBuilder(){};

    Araba *getAraba()
    {
        return araba.release();
    }
    void yeniAraba()
    {
        araba = std::make_unique<Araba>();
    }
    virtual void buildMarka() = 0;
    virtual void buildModel() = 0;
    virtual void buildRenk() = 0;
    virtual void buildKademe() = 0;
};

//----------------------------------------------------------------

class OrtaArabaBuilder : public ArabaBuilder
{
  public:
    virtual ~OrtaArabaBuilder(){};

    void buildMarka() override
    {
        araba->setMarka("OPEL");
    }

    void buildModel() override
    {
        araba->setModel("Astra");
    }

    void buildRenk() override
    {
        araba->setRenk("Beyaz");
    }

    void buildKademe() override
    {
        araba->setKademe("Orta Kademe Arac");
    }
};

class LuksArabaBuilder : public ArabaBuilder
{
  public:
    virtual ~LuksArabaBuilder(){};

    void buildMarka() override
    {
        araba->setMarka("MERCEDES");
    }

    void buildModel() override
    {
        araba->setModel("GLC Coupe");
    }

    void buildRenk() override
    {
        araba->setRenk("Siyah");
    }

    void buildKademe() override
    {
        araba->setKademe("Luks Kademe Arac");
    }
};

//----------------------------------------------------------------
class Build
{
  private:
    ArabaBuilder *arabaBuilder;

  public:
    void arabaSec(ArabaBuilder *pa)
    {
        arabaBuilder = pa;
        arabaBuilder->yeniAraba();
        arabaBuilder->buildMarka();
        arabaBuilder->buildModel();
        arabaBuilder->buildRenk();
        arabaBuilder->buildKademe();
    }

    void arabaBul()
    {
        arabaBuilder->getAraba()->bul();
    }
};

int main()
{
    Build build;
    OrtaArabaBuilder ortaModel;
    LuksArabaBuilder luksModel;

    build.arabaSec(&ortaModel);
    build.arabaBul();

    build.arabaSec(&luksModel);
    build.arabaBul();
}
