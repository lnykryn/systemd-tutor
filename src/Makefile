CFLAGS+=$(RPM_OPT_FLAGS) -Wall -D_GNU_SOURCE
LDFLAGS+=$(RPM_LD_FLAGS)

PROGS=my_little_daemon

all:	$(PROGS)

clean:
	rm -f $(PROGS) *.o *~

my_little_daemon: my_little_daemon.c
	$(CC) $(LDFLAGS) -o $@ my_little_daemon.c

install:
	mkdir -p $(ROOT)/usr/bin 
	install -m 755 my_little_daemon $(ROOT)/usr/bin/my_little_daemon
