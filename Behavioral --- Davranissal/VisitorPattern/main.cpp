#include <string>
#include <iostream>
#include <vector>

using namespace std;

class USBPort;
class Harddisk;
class Mainboard;
class Computer;

// Bilgisayar Birleþenleri Soyut Sýnýf
class ComputerComponentVisitor
{
  public:
    virtual void visit(USBPort &usbport) const = 0;
    virtual void visit(Harddisk &harddisk) const = 0;
    virtual void visit(Mainboard &mainboard) const = 0;
    virtual void visitComputer(Computer &computer) const = 0;
};

// Bilgisayar Birlesenleri Yapým
class ComputerComponent
{
  public:
    virtual void request(const ComputerComponentVisitor &visitor) = 0;
};

class USBPort : public ComputerComponent
{
  private:
    string name;

  public:
    explicit USBPort(const string &name) : name(name)
    {
    }

    const string &getName() const
    {
        return name;
    }

    void request(const ComputerComponentVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Harddisk : public ComputerComponent
{
  public:
    void request(const ComputerComponentVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Mainboard : public ComputerComponent
{
  public:
    void request(const ComputerComponentVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Computer
{
  private:
    vector<ComputerComponent *> computerComponent;

  public:
    vector<ComputerComponent *> &getComponent()
    {
        return computerComponent;
    }

    Computer()
    {
        computerComponent.push_back(new USBPort("Left-1"));
        computerComponent.push_back(new USBPort("Left-2"));
        computerComponent.push_back(new USBPort("Right-1"));
        computerComponent.push_back(new USBPort("Right-2"));
        computerComponent.push_back(new Mainboard());
        computerComponent.push_back(new Harddisk());
    }
    ~Computer()
    {
        for (vector<ComputerComponent *>::iterator it = computerComponent.begin(); it != computerComponent.end(); ++it)
        {
            delete *it;
        }
    }
};


class ComponentWriterVisitor : public ComputerComponentVisitor
{
  public:
    void visit(USBPort &usbport) const override
    {
        cout << "Visiting " << usbport.getName() << " usbport" << endl;
    }
    void visit(Harddisk &harddisk) const override
    {
        cout << "Visiting harddisk" << endl;
    }
    void visit(Mainboard &mainboard) const override
    {
        cout << "Visiting mainboard" << endl;
    }
    void visitComputer(Computer &computer) const override
    {

        cout << "Visiting computer" << endl;

        vector<ComputerComponent *> &computerElements= computer.getComponent();
        for (vector<ComputerComponent *>::iterator it = computerElements.begin(); it != computerElements.end(); ++it)
        {
            (*it)->request(*this);
        }
        cout << "Visited computer" << endl;
    }
};

class ComputerCreaterVisitor : public ComputerComponentVisitor
{
  public:
    void visit(USBPort &usbport) const override
    {
        cout << "USBPort added: " << usbport.getName() << " usbport" << endl;
    }
    void visit(Harddisk &harddisk) const override
    {
        cout << "Harddisk added" << endl;
    }
    void visit(Mainboard &mainboard) const override
    {
        cout << "Mainboard added" << endl;
    }
    void visitComputer(Computer &computer) const override
    {
        cout << endl
             << "Computer getting ready" << endl;

        vector<ComputerComponent *> &computerElement = computer.getComponent();
        for (vector<ComputerComponent *>::iterator it = computerElement.begin(); it != computerElement.end(); ++it)
        {
            (*it)->request(*this);
        }
        cout << "Computer ready.." << endl;
    }
};

int main()
{
    Computer computer;
    ComponentWriterVisitor computerComponentWriterVisitor;
    ComputerCreaterVisitor computerCreaterVisitor;

    computerComponentWriterVisitor.visitComputer(computer);
    computerCreaterVisitor.visitComputer(computer);

    return 0;
}
