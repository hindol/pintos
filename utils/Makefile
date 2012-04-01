all: setitimer-helper squish-pty squish-unix

CC = gcc
CFLAGS = -Wall -W
LDFLAGS = -lm
setitimer-helper: setitimer-helper.c
	$(CC) -c setitimer-helper.c $(CFLAGS)
	$(CC) setitimer-helper.o -o setitimer-helper $(LDFLAGS)
squish-pty: squish-pty.c
	$(CC) -c squish-pty.c $(CFLAGS)
	$(CC) squish-pty.o -o squish-pty $(LDFLAGS)
squish-unix: squish-unix.c
	$(CC) -c squish-unix.c $(CFLAGS)
	$(CC) squish-unix.o -o squish-unix $(LDFLAGS)

clean: 
	rm -f *.o setitimer-helper squish-pty squish-unix
