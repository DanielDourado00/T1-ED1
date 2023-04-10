#include "parameters.h"
#include "biblioteca.h"
#include "lista.h"
#include "systempath.h"
#include "systemgeo.h"
#include "circ.h"
#include "svg.h"
#include "retangulo.h"
#include "linha.h"
#include "txto.h"

// tirando o Path e deixando void no create

int main(int argc, char **argv)
{
  // Primeiro: Receber parametros e salvar em um tipo abstrato de dados
  void *parameters = createParameters(); // vai para systempath.c alocar espaço para struct all_paths

  if (readParam(argc, argv, parameters) == -1)
  {           // vai para systempath.c ler os parametros e salvar em um tad (parameters)
    return 0; // se der erro na leitura dos parametros, retorna 0
  }

  // criar uma lista
  Lista list = createLst(-1);               // vai para lista.c alocar espaço para struct list, p valor da capacidade é -1 pq não tem limite de elementos na lista
  printf("lista criada com sucesso\n");     // printa que a lista foi criada com sucesso

  ReadGeo(list, parameters);                // le o .geo
  printSvg(list, getpsageosvg(parameters)); // vai para svg.c e cria o .svg com as informações da lista e o caminho do .svg passado por parametro no terminal
  
}
