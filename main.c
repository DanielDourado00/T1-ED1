#include "parameters.h"
#include "biblioteca.h"
#include "fila.h"
#include "svg.h"
#include "systempath.h"
#include "geo.h"


int main(int argc, char **argv)
{
  // Primeiro: Receber parametros e salvar em um tipo abstrato de dados

  Path parameters = createParameters(); // vai para systempath.c alocar espaço para struct all_paths

  if (readParam(argc, argv, parameters) == -1){                                    // vai para systempath.c 
    return 0;
  }else{
    printf("Erro ao ler os parametros\n");
  return -1;
  }


  
}
