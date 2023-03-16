#Make file do siguel

# Nome do arquivo final
PROJ_NAME=ted

#arquivos .c
C_SOURCE=$(wildcard *.c)

#arquivos .h
H_SOURCE=$(wildcard *.h)

#arquivos .o
OBJ=$(C_SOURCE: .c=.o)

#compilador

CC=gcc

#flags de compilação
CC_FLAGS=-c         \
		 -g         \
		 -w         \
         -W         \
         -Wall      \
	 -std=c99	\
	 -fstack-protector-all


#
#Compila e linka os arquivos
#
ted: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o #@ $^ -lm

%.o: %.c %.h

	$(CC) -o $@ $< $(CC_FLAGS)
 
main: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
	rm -rf *.o $(PROJ_NAME) *~