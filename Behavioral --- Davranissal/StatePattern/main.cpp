
#include <iostream>
using namespace std;

class Machine
{
  private:
    class State *state;

  public:
    Machine();
    void setState(State *state);
    void on();
    void off();
};

class State
{
  public:
    virtual void on(Machine *machine)
    {
        cout << "  Machine is on now \n";
    }
    virtual void off(Machine *machine)
    {
        cout << "  Machine is off now\n";
    }
};

class ON : public State
{
  public:
    ON()
    {
        cout << "  ON's Constructor\n ";
    }

    ~ON()
    {
        cout << " ON's De-Constructor  \n";
    }

    void off(Machine *m);
};

class OFF : public State
{
  public:
    OFF()
    {
        cout << "  OFF's Constructor\n  ";
    }
    ~OFF()
    {
        cout << " OFF's De-Constructor\n  ";
    }
    void on(Machine *machine);
};

Machine::Machine()
{
    state = new OFF();
    cout << '\n';
}

void Machine::setState(State *state)
{
    this->state = state;
}

void Machine::on()
{
    state->on(this);
}

void Machine::off()
{
    state->off(this);
}

void ON::off(Machine *m)
{
    cout << " Switched from ON to OFF \n ";
    m->setState(new OFF());
    delete this;
}

void OFF::on(Machine *machine)
{
    cout << "  Switched from OFF to ON\n ";
    machine->setState(new ON());
    delete this;
}

int main()
{
    void (Machine::*ptrs[])() = {&Machine::off, &Machine::on};
    Machine fsm;
    int num;
    while (1)
    {
        cout << "Choose your status : 0 - 1: ";
        cin >> num;
        (fsm.*ptrs[num])();
    }
}
