/** Simple On-board LED flashing program - written in C++ by Derek Molloy
*    simple functional struture for the Exploring BeagleBone book
*
*    This program uses USR LED 3 and can be executed in three ways:
*         makeLED on
*         makeLED off
*         makeLED flash  (flash at 100ms intervals - on 50ms/off 50ms)
*         makeLED status (get the trigger status)
*
* * Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h> 
#include<stdio.h> //Defines FILENAME_MAX
using namespace std;

#define GetCurrentDir getcwd

std::string GetCurrentWorkingDir( void ) {
   char buff[FILENAME_MAX];
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}
int main(int argc, char* argv[]){   
float temp = 0.0;
  if(argc!=2){
	cout << "Usage is reading-file and file name: " << endl;
	cout << " e.g. reading-file sample.txt" << endl;
        return 2;
   }
   string directory=GetCurrentWorkingDir();
   string file(argv[1]);
   string file_name = "/" + file;
   string cmd = directory + file_name;
   cout << "Starting the reading-file program" << endl;
   cout << "The current Path is: " << directory << endl;

        std::fstream fs;
	fs.open( cmd, std::fstream::in);
	string line;
	while(getline(fs,line)){
		cout << line << endl;
		temp = temp + stof(line);}
	fs.close();
	float avgtemp = temp/10;
	cout << "The average temperature is : "<< avgtemp << endl;
   return 0;
}
