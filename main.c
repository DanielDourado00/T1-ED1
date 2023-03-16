#include "parameters.h"
#include "biblioteca.h"

int main(int argc, char **argv)
{
  // Primeiro: Receber parametros e salvar em um tipo abstrato de dados

  Path parameters = createParameters(); // Cria um tipo abstrato de dados para armazenar os parametros    //vai para parameters.h
  if (readParam(argc, argv, parameters) == -1){                                    //vai para parameters.c
    return 0;
  }else{
    printf("Erro ao ler os parametros\n");
  return -1;
  }
}
