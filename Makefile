EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): lista.o main.c parameters.o systempath.o
	$(EXEC) $(CFLAGS) lista.o main.c parameters.o systempath.o -o $(PROJECT_NAME) -lm

lista.o: lista.c lista.h
	$(EXEC) $(CFLAGS) -c lista.c

parameters.o: parameters.c parameters.h
	$(EXEC) $(CFLAGS) -c parameters.c

systempath.o: systempath.c systempath.h
	$(EXEC) $(CFLAGS) -c systempath.c
