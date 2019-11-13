#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;
using std::string;


class LED{
   private:
      string path;
      int number;
      virtual void writeLED(string filename, string value);
      virtual void removeTrigger();
   public:
      LED(int number);
      virtual void turnOn();
      virtual void turnOff();
      virtual void flash(string delayms);
      virtual void blink(int num);
      virtual void outputState();
      virtual ~LED();
};
