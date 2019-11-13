#include <iostream>
#include <sstream>
#include <fstream>
#include<string>
#include<unistd.h> 
#include<stdio.h> //Defines FILENAME_MAX
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0
#define GetCurrentDir getcwd

std::string GetCurrentWorkingDir( void ) {
   char buff[FILENAME_MAX];
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}


float getTemperature(int adc_value) {     // from the TMP36 datasheet
   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   return (25.0f + diff_degreesC);
}

int readAnalog(int number){
   stringstream ss;
   ss << ADC_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int main(){
   std::cout << "Starting the TMP36 example" << std::endl;
   string directory=GetCurrentWorkingDir();
   string file = "/temperatures.txt";
   string write = directory + file;
   float temp = getTemperature(readAnalog(ADC));
   float fahr = 32 + ((temp * 9)/5);    // convert deg. C to deg. F
   std::fstream fs;
   fs.open( write, std::fstream::out);
   for(int i=0; i<10;i++){ 
   fs << temp << endl;
   temp = getTemperature(readAnalog(ADC));
   sleep(1);
   }
   fs.close();

   cout << "Done reading the temperature samples" << endl;
}

