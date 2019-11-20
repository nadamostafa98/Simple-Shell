#include "Forking.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

Forking::Forking()
{

}
void signalHandler( int signum ) {
    fstream fileStream;
    fileStream.open("\NewFile.txt", std::ios_base::app);
    if (fileStream.fail()) {                            // check if file exists
        ofstream output("\NewFile.txt");                //creates new file
        output << "Child process was terminated" << endl;
        output.close();
    }
    else{
        fileStream << "Child process was terminated" << endl; //appends to existing file
        fileStream.close();
    }
    fileStream.close();
    return;
}

void Forking ::forking(char **input, int flagFork){
    pid_t child;
    pid_t waitResult;
    int stat_loc;

    child = fork();         // creats a new fork for child process
    signal(SIGCHLD,signalHandler);  //calls for the signal that will indicate when the child process is terminated

    // The child process
    if(child == -1 ){
        perror("Incorrect Command!");
    }
    if (child == 0) {
       int result = execvp(input[0], input);
       if(result < 0){
        perror("Failure");
       }
       exit(child);
    }
    else {
        if(flagFork == 0){
            waitpid(child, &stat_loc, WUNTRACED);
        }
                            //a background process where the parent doesn't wait
    }
}

