EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): lista.o main.c parameters.o systempath.o systemgeo.o circ.o svg.o retangulo.o linha.o txto.o
	$(EXEC) $(CFLAGS) lista.o main.c parameters.o systempath.o systemgeo.o circ.o svg.o retangulo.o linha.o txto.o -o $(PROJECT_NAME) -lm

lista.o: lista.c lista.h
	$(EXEC) $(CFLAGS) -c lista.c

parameters.o: parameters.c parameters.h
	$(EXEC) $(CFLAGS) -c parameters.c

systempath.o: systempath.c systempath.h
	$(EXEC) $(CFLAGS) -c systempath.c

systemgeo.o: systemgeo.c systemgeo.h
	$(EXEC) $(CFLAGS) -c systemgeo.c

circ.o: circ.c circ.h
	$(EXEC) $(CFLAGS) -c circ.c

svg.o: svg.c svg.h
	$(EXEC) $(CFLAGS) -c svg.c

retangulo.o: retangulo.c retangulo.h
	$(EXEC) $(CFLAGS) -c retangulo.c

linha.o: linha.c linha.h
	$(EXEC) $(CFLAGS) -c linha.c

txto.o: txto.c txto.h
	$(EXEC) $(CFLAGS) -c txto.c

