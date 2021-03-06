CC = gcc
CFLAGS = -Wall -g -fopenmp
SRCS = main.c vector.c point.c agent.c steering_behaviors.c window.c
PROG = main
OBJS = $(SRCS:.c=.o)
LFLAGS = -lm -fopenmp -lX11 -o $(PROG)
.c.o:
	$(CC) -c $(CFLAGS) $<

$(PROG): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS)

test: $(PROG)
	./$(PROG) 

clean:
	rm -f $(OBJS) $(PROG) *~
