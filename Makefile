EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

ALUNO= Daniel Dourado
LIBS= biblioteca.h
OBJETOS= lista.o main.c parameters.o systempath.o systemgeo.o circ.o svg.o retangulo.o linha.o txto.o


clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): $(OBJETOS)
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

#
# EMPACOTAR PARA ENTREGA
#
#   -  se necessario: sudo apt install zip

pack: $(PROJ_NAME)
	rm -f ../$(DanielDourado).zip
	echo $(DanielDourado)
	date >> .entrega
	cd ..; zip $(DanielDourado).zip -r src/*.c src/*.h src/Makefile LEIA-ME.txt .entrega