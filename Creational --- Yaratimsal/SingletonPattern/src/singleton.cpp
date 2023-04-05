#include <iostream>

using namespace std;

class Singleton{
    static Singleton *message;
    int data=0;


    Singleton()//ctor
    {
        //data=0;
        cout<<"Ben bir kere olustum."<<endl;
    };


    public:
        static Singleton *getInstance()
        {

            if(!message)
                message = new Singleton;
                return message;
        }
    int getData()
    {
        return this->data;

    }

};
 Singleton *Singleton::message=0;

int main()
{
    for(int i=0;i<10;i++){ //singletonun bir kere oluþma kontrolü
        Singleton *s = s->getInstance();
        cout<<s->getInstance()<<endl;
        //cout <<s->getData() << endl;

    }

    return 0;

}


