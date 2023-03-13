#include "biblioteca.h"
#ifndef parameters_h
#define parameters_h

void splitPath(char *fullPath, 
	       char *path, int lenPath,
	       char *nomeArq, int lenNomeArq,
	       char *extArq, int lenExtArq);
/*
    Dado um caminho (fullPath), copia cada um de seus componentes
    nos parametros path (caminho do arquivo), nomeArq (nome do arquivo, sem
    seu path e sem sua extensao) e extArq (extensao do arquivo).
    Estes parametros sao vetores de tamanhos, respectivamente, lenPath, 
    lenNomeArq e lenExtArq. Exemplos:

    fullPath               path        nomeArqq   extArq
    =====================================================
    "aaa/bbb/ccc.txt" =>   "aaa/bbb"   "ccc"      ".txt"
    "ccc.txt"         =>   ""          "ccc"      ".txt"
    ".txt"            =>   ""          ""         ".txt"
    "ccc.ddd.txt"     =>   ""          "ccc.ddd"  ".txt"
    "ccc"             =>   ""          "ccc"      ""  
 */

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath);
/*
  Dado um caminho (path) e um nome de arquivo (possivelmente, com sua extensao),
  copia para fullPath o caminho completo do arquivo. Exemplos:

   path         fileName =>  fullPath
   =============================================
   "aaa/bbb"    "c.txt"  =>  "aaa/bbb/c.txt"
   "aaa/bbb/"   "c.txt"  =>  "aaa/bbb/c.txt"
   ""           "c.txt"  =>  "c.txt"
   "aaa/bbb"    "c"      =>  "aaa/bbb/c"
 */

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenfullPath);
/*
   Semelhante a joinFilePath, porem, a extensao do arquivo e´ informado explicitamente
   pelo parametro ext. Exemplos:

   path       fileName  ext     => fullPath
   =================================================
   "aaa/bbb"  "ccc"     ".txt"  => "aaa/bbb/ccc.txt"
   "aaa/bbb/  "ccc"     ".txt"  => "aaa/bbb/ccc.txt"
   ""         "ccc"     ".txt"  => "ccc.txt"
   "aaa/bbb"  "ccc"     ""      => "aaa/bbb/ccc"
 */

void getFileName(char *fullPath, char *fileName, char *lenFileName);
/*
    Dado um caminho completo (fullPath), copia em fileName o nome do arquivo 
    (possivelmente) com sua extensao. Exemplos:

    fullPath          => fileName
    ==============================
    "aaa/bb/cc.txt"   => "cc.txt"
    "cc.txt"          => "cc.txt"
    "cc."             => "cc."
    "cc"              => "cc"
    ".txt"            => ".txt"
 */

void getPath(char *fullPath, char *path, int lenPath);
/*
   Dado um caminho completo, retorna seu respectivo path.

   fullPath           => path
   ================================
   "aaa/bbb/ccc.txt"  => "aab/bbb"
   "ccc.txt"          => ""
   "aaa/bbb/ccc"      => "aaa/bbb"
 */

void normalizePath(char *path, char *normPath, int lenNormPath);
/*
   Dado um caminho (path), (supostamente) sem nome de arquivo, 
   copia em normPath o caminho, sem o separador do final (se existir).

   path         => normPath
   ==========================
   "aa/bb/cc"   => "aa/bb/cc"
   "aa/bb/cc/"  => "aa/bb/cc" 
 */

#endif