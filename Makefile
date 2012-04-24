CC = gcc
CFLAGS = -Wall -g -O3
SRCS = main.c vector.c point.c agent.c
PROG = main
OBJS = $(SRCS:.c=.o)
LFLAGS = -lm -lX11 -o $(PROG)
.c.o:
	$(CC) -c $(CFLAGS) $<

$(PROG): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS)

test: $(PROG)
	./$(PROG) 

clean:
	rm -f $(OBJS) $(PROG) *~
