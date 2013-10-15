#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <systemd/sd-journal.h>

#define L_ALERT  "<1>"
#define L_ERROR  "<3>"
#define L_NOTICE "<5>"
#define L_DEBUG  "<7>"

int main(int argc, char *argv[]) {
        pid_t pid;

        sd_journal_print(LOG_DEBUG, "Hi, I am a Screamer and I will make some mess in your Journal log.");
        sd_journal_print(LOG_NOTICE, "Let me note that you can see various message priorities in Journal and you can filter them.");
        sd_journal_print(LOG_ERR, "While previous messages are mostly informational, this one reports some error that happend in your system.");
        sd_journal_print(LOG_ALERT, "Error and Alert get same color, but the latter is much more severe.");

        sd_journal_send("MESSAGE=You may find some interesting details about logged messages in stored fields. Try to list all fields of messages from process %lu.", (unsigned long) getpid(),
                        "PRIORITY=%i", LOG_NOTICE,
                        "HOME=%s", getenv("HOME"),
                        NULL);

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
