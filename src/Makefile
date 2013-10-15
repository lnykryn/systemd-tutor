CFLAGS+=$(RPM_OPT_FLAGS) -Wall -D_GNU_SOURCE
LDFLAGS+=$(RPM_LD_FLAGS)

PROGS=my_little_daemon screamer

all:	$(PROGS)

clean:
	rm -f $(PROGS) *.o *~

my_little_daemon: my_little_daemon.c
	$(CC) $(LDFLAGS) -o $@ my_little_daemon.c

screamer: screamer.c
	$(CC) $(LDFLAGS) `pkg-config --cflags --libs libsystemd-journal` -o $@ screamer.c

install:
	mkdir -p $(ROOT)/usr/bin 
	install -m 755 my_little_daemon $(ROOT)/usr/bin/my_little_daemon
	install -m 755 screamer $(ROOT)/usr/bin/screamer

