#include "SignalInterrupt.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>


SignalInterrupt::SignalInterrupt()
{
    //ctor
}
void signalHandler( int signum ) {
    fstream fileStream;
    fileStream.open("\NewFile.txt", std::ios_base::app);
    if (fileStream.fail()) {                            // check if file exists
        ofstream output("\NewFile.txt");
        output << "Child process was terminated" << endl;
        output.close();
    }
    else{                                               //creates new file
        ofstream output;
        output.open("\NewFile.txt", std::ios_base::app);
        output << "Child process was terminated" << endl;
        output.close();
    }
}
void SignalInterrupt::handle(){
    signal(SIGCHLD,signalHandler);
}
