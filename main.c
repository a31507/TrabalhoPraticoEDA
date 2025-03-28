/**
 * @file main.c
 * @author goncalo rodrigues a31507@alunos.ipca.pt
 * @brief Ficheiro principal onde é executado o programa
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "estruturas.h"
 
#define FILENAME "antenas.txt"

int main() {
    Antena *listaAntenas = NULL;
    Efeito *listaEfeitos = NULL;

    
    listaAntenas = CarregarAntenas(listaAntenas, FILENAME);
    
    MostrarAntenas(listaAntenas);


    listaEfeitos = DetetarEfeito(listaAntenas, listaEfeitos);

    MostrarAntenasEEfeito(listaAntenas, listaEfeitos);

    ListarAntenasEfeito(listaAntenas, listaEfeitos);

    LimparListaAntenas(listaAntenas);
    LimparListaEfeitos(listaEfeitos);

    return 0;
}
