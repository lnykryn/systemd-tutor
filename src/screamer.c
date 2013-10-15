#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define L_ALERT  "<1>"
#define L_ERROR  "<3>"
#define L_NOTICE "<5>"
#define L_DEBUG  "<7>"

int main(int argc, char *argv[]) {
        pid_t pid;

        fprintf(stderr, L_DEBUG "Hi, I am a Screamer and I will make some mess in your Journal log.\n");
        fprintf(stderr, L_NOTICE "Let me note that you can see various message priorities in Journal and you can filter them.\n");
        fprintf(stderr, L_ERROR "While previous messages are mostly informational, this one reports some error that happend in your system.\n");
        fprintf(stderr, L_ALERT "Error and Alert get same color, but the latter is much more severe.\n");

//          pid = fork();

//          if (pid == 0) {
//                  sleep(5);
//                  fprintf(stderr, L_ERROR "No! It's not true! That's impossible!!!\n");
//                  sleep(1);
//                  return 0;
//          } else if (pid > 0) {
//                  fprintf(stderr, L_NOTICE "Luke, I am your father!\n");
//          } else {
//                  return errno;
//          }

        sleep(2);
        return 0;
}
