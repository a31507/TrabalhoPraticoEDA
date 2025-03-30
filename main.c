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
        Antena* listaAntenas = NULL;
        Efeito* listaEfeitos = NULL;
    
        
        listaAntenas = InserirAntenaInicio(listaAntenas, 'A', 0, 3);
        listaAntenas = InserirAntenaInicio(listaAntenas, 'A', 4, 1);
        listaAntenas = InserirAntenaInicio(listaAntenas, 'A', 5, 5);
    
    
        listaEfeitos = DetetarEfeito(listaAntenas, listaEfeitos);
    
        MostrarAntenas(listaAntenas);
        printf("----------------------------\n");
        MostrarAntenasEEfeito(listaAntenas, listaEfeitos);

        ListarAntenasEfeito(listaAntenas, listaEfeitos);
    
        LimparListaAntenas(listaAntenas);
        LimparListaEfeitos(listaEfeitos);
    
        return 0;
    }
