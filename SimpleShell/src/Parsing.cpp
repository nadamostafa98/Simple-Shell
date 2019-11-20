#include "Parsing.h"
#include <stdlib.h>
#include <string.h>
#include "Forking.h"

using namespace std;

Parsing::Parsing()
{
    //ctor
}
void Parsing :: parse(char *input){

    char **commandParsed;
    char *separator = " ";
    char *parsed;
    int i = 0;
    int flagwait = 0;

    parsed = strtok(input, separator);  //seperate the input string by commas
    while (parsed != NULL) {
        commandParsed[i] = parsed;      //add each command seperately in an array
        i++;
        parsed = strtok(NULL, separator);
    }
    if(strcmp(commandParsed[0],"exit") == 0){      //check if user chose to terminate the process
           exit(0);
        }
    if( strcmp(commandParsed[i-1] ,"&") == 0){      //check if the command includes an "&" which means that the parent will no wait for child to finish
        flagwait = 1;
        commandParsed[i - 1] = NULL;
    }
    else{
        commandParsed[i] = NULL;        //en the array with a NULL
    }
    Forking f;
    f.forking(commandParsed,flagwait);      //pass the commands to the forking class to start executing
}


