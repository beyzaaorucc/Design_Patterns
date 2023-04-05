#include <string>
#include <iostream>
using namespace std;

class Message // Abstract
{
protected:
  string aciklama;

public:
  Message()
  {
    aciklama = "Bilinmeyen Mesaj";
  }

  virtual string getAciklama()
  {
    return aciklama;
  }


  virtual ~Message()
  {
    cout << "~Message()\n";
  }
};

class MessageDecorator : public Message // Decorator
{
public:
  virtual string getAciklama() = 0;

  virtual ~MessageDecorator()
  {
    cout << "~MessageDecorator()\n";
  }
};

class MessageModel : public Message
{
public:
  MessageModel()
  {
    aciklama = "Mesaj gondermek icin ";
  }

  ~MessageModel()
  {
    cout << "~MessageModel()\n";
  }
};

class Facebook : public MessageDecorator
{
  Message *message;

public:
  Facebook(Message *message)
  {
    this->message = message;
  }
  string getAciklama() override
  {
    return message->getAciklama() + ", Facebook";
  }

  ~Facebook()
  {
    cout << "~Facebook()\n";
    delete message;
  }
};

class Instagram : public MessageDecorator
{
  Message *message;

public:
  Instagram(Message *message)
  {
    this->message = message;
  }
  string getAciklama() override
  {
    return message->getAciklama() + ",Instagram";
  }

  ~Instagram()
  {
    cout << "~Instagram()\n";
    delete message;
  }
};

class Twitter : public MessageDecorator
{
  Message *message;

public:
  Twitter(Message *message)
  {
    this->message = message;
  }
  string getAciklama() override
  {
    return message->getAciklama() + ",Twitter";
  }

  ~Twitter()
  {
    cout << "~Twitter()\n";
    delete message;
  }
};

int main()
{
  // Boş mesaj yaratıyoruz
  Message *message = new MessageModel();
  cout << "Hizli " << message->getAciklama() << endl;

  // Mesaj icin platform ekliyoruz
  message = new Facebook(message);
  cout << message->getAciklama() << " kullanabilirsiniz.."<<endl;
  cout << "----------------------------------------------" << endl;
  message = new Instagram(message);
  cout << message->getAciklama() << " kullanabilirsiniz.."<<endl;
  cout << "----------------------------------------------" << endl;
  message = new Twitter(message);
  cout << message->getAciklama() << " kullanabilirsiniz.."<<endl;

  cout << "----------------------------------------------" << endl;

  delete message;

  return 0;
}
