#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

#define MAX_LENGTH 60
#define CONF_PATH "/etc/my_little_daemon.conf"

volatile sig_atomic_t f_reload = 1;
volatile sig_atomic_t f_exit = 0;

static void signal_handler(int sig) {
    switch (sig) {
    case SIGHUP:
        f_reload = 1;
        break;
    case SIGINT:
    case SIGTERM:
        f_exit = 1;
        break;
    }
}



int main(int argc, char **argv)
{
	char msg[MAX_LENGTH + 1] = {};
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGHUP, signal_handler);

    while (!f_exit) {
        if (f_reload) {
			FILE *f;
            f_reload = 0;
			f = fopen(CONF_PATH, "r");
			if (f == NULL) {
				fprintf(stderr, "configuration file does not exist\n");
				return 6;
			}
			fgets(msg, MAX_LENGTH, f);
			fclose(f);
        }
        puts(msg);
        fflush(stdout);
        sleep(1);
    }

	return 0;
}
