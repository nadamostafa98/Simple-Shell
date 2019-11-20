#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Parsing.h"
#include "Forking.h"

using namespace std;


int main()
{
   string inputString;
    while(1){
        getline(cin, inputString); //read input line as string
        char* input = new char[1000](); //change input String into char*
        for(int i = 0; i < inputString.length(); i++){
            input[i] = inputString.at(i);
        }
        Parsing p;
        p.parse(input);         //call the parsing class to start parsing the input commands
    }


    return 0;
}
