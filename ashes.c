#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    char filed[512];
    pid_t pid;
    int status;
    
    while (1) {
      printf("# ");
      fgets(filed, sizeof(char)*512, stdin);
      filed[strcspn(filed, "\n")] = 0;
      char* args[64];
      int i = 0;
      args[i] = strtok(filed, " ");
      while(args[i] != NULL && i < 63){
        i++;
        args[i] = strtok(NULL, " ");
      }
      pid = fork();
      if(pid == 0){
        execvp(args[0], args);
      }
      else {
        waitpid(pid, &status, 0);
      }
    }
    return 0;

}
