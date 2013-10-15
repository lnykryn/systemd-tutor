#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <readline/readline.h>

enum greeting_type {
	STAR_TREK = 0,
	STAR_WARS,
	SPANISH,
	ENGLISH,
	INDIAN,
	_MAX_GREETING,
	_GREETING_INVALID
};

static const char *greetings[_MAX_GREETING] = {
	[STAR_TREK]  = "Live long and prosper",
	[STAR_WARS]  = "May the Force with you",
	[ENGLISH]    = "Hello there",
	[SPANISH]    = "Hola",
	[INDIAN]     = "Namaste"
};

int main() {
	char *name = NULL;

	srand(time(NULL));

	printf("What is your name?\n");

	name = readline(NULL);
	if (!name)
		return EXIT_FAILURE;

	printf("%s %s!\n", greetings[rand() % _MAX_GREETING], name);

	return 0;
}
