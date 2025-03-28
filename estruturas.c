/**
 * @file estruturas.c
 * @author goncalo rodrigues a31507@alunos.ipca.pt
 * @brief 
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "estruturas.h"


 Antena* CriarAntena(char frequencia, int x, int y){

    Antena* nova = (Antena*)malloc(sizeof(Antena));   // é criado o espaço de memória e colocado os dados da antena nova
    nova->frequencia = frequencia;                    // os apontadores recebem os seus valores
    nova->x = x;
    nova->y = y;
    nova->prox = NULL;                                // como a antena ainda não está na lista ligada o valor é nulo
    return nova;

 }

 Antena* CarregarAntenas(Antena* listalig, const char* filename){

   FILE* file = fopen(filename,"r");
   if(!file){
   printf("Erro ao abrir o arquivo\n");
   return listalig;
   }
   char linha[100];
    int y = 0;
    while (fgets(linha, sizeof(linha), file)) 
    {                                                    // ciclo que percorre o ficheiro
        for (int x = 0; linha[x]; x++) {
            if (linha[x] != '.' && linha[x] != '\n') {
                listalig = InserirAntenaInicio(listalig, linha[x], x, y);  // a antena é inserida na lista ligada
            }
        }
        y++;                                             // acaba de percorrer a linha e então passa para a próxima
    }
    fclose(file);
    return listalig;                                     // por fim devolve a lista ligada já com as antenas do ficheiro inseridas
}

 Antena* InserirAntenaInicio(Antena* listalig, char frequencia, int x, int y){

    Antena* nova = CriarAntena(frequencia, x, y);

   if(nova==NULL)      //não há nada para inserir
   return listalig;

   if(listalig==NULL)  // a lista ligada está vazia
   listalig = nova;    // a antena "nova" passa a ser a primeira e única da lista ligada
   
   else{
   
   nova->prox = listalig; // a nova antena é integrada na lista ligada
    return nova;
 }
    return listalig;
}

Antena* InserirAntenaFim(Antena* listalig, char frequencia, int x, int y) {
   Antena* nova = CriarAntena(frequencia, x, y);
   
   if (nova == NULL) // não há nada para inserir
       return listalig;

   if (listalig == NULL)    // a lista ligada está vazia
       return nova;         // a antena "nova" passar a ser a primeira e a única da lista ligada

   Antena* atual = listalig;
   
   while (atual->prox != NULL) // percorre a lista ligada até à sua última antena
       atual = atual->prox;
   
   atual->prox = nova;        // a nova antena é adicionada no fim da lista ligada

   return listalig; 
}

Antena* RemoverAntena(Antena* listalig, int x, int y){

   Antena* atual = listalig;
   Antena* anterior = NULL;

   while(atual != NULL && (atual->x != x || atual->y !=y)) // enquanto a antena atual estiver alocada e as suas coordenadas forem diferentes da antena que queremos remover, o ciclo irá percorrer o resto da lista ligada
   {
      anterior = atual;
      atual = atual->prox;
   }
   if(atual == NULL)        // a antena nao foi encontrada
   return listalig;         //a lista volta a ser a original, sem modificações
   if(anterior == NULL)     // a antena a ser removida é a primeira da lista
   listalig = atual->prox;  // o apontador da lista é redirecionado para o novo formato, alterando a primeira antena da lista

   else{
      anterior->prox = atual->prox; // o apontador anterior é atualizado para atual
      free(atual);                  // a antena é removida da lista
      return listalig;
   }

    return listalig;
}

Efeito* DetetarEfeito(Antena* listalig, Efeito* locefeito){

   for(Antena* a1 = listalig; a1 != NULL; a1= a1->prox){          //          percorre a lista ligada
      for(Antena* a2 = listalig; a2 != NULL; a2= a2->prox){       //             ...
         if(a1->frequencia==a2->frequencia){                      // caso a frequencia de duas antenas seja igual é adicionado o efeito nefasto
                                
            locefeito = AdicionarEfeito(locefeito, 2 * a2->x - a1->x, 2 * a2->y - a1->y);                 // efeito nefasto adicionado para um dos lados
            locefeito = AdicionarEfeito(locefeito, 2 * a1->x - a2->x, 2 * a1->y - a2->y);                 // efeito nefasto adicionado para um dos lados
      }
   }
}
      return locefeito;
}

Efeito* AdicionarEfeito(Efeito* listaligne, int x, int y) {          // função com o mesmo conceito que a função CriarAntena, só que é utilizada como auxiliar para a função DetetarEfeito
   
    Efeito* temp = listaligne;
    while(temp){
        if(temp->x == x && temp->y == y){               //caso o efeito já exista, não é adicionado
            return listaligne;
        }
        temp = temp->prox;
    }

    Efeito *nova = (Efeito*)malloc(sizeof(Efeito));

   nova->x = x;
   nova->y = y;
   nova->prox = listaligne;
   return nova;
}

Antena* ModificarAntena(Antena *listalig, int x, int y, char novafrequencia, int novax, int novay){

    Antena* atual = listalig;           

    while( atual != NULL){                                                 // ciclo para percorrer a lista ligada das antenas
        if( (atual->x == x) && (atual->y == y)){       // verifica se as coordenadas da antena que é pretendido modificar está na lista ligada

            atual->x = novax;                                            //          ...
            atual->y = novay;                                            // os novos valores sao tomados
            atual->frequencia = novafrequencia;                          //          ...

            return listalig;                                                // retorna a lista com os novos valores da antena ja inseridos
        }
        atual = atual->prox;
    }
    
    return listalig;   // não foi alterada nenhuma antena e a lista retoma inalterada

}

void MostrarAntenas(Antena* listalig){

    for (int i = 0; i < 5; i++) {               // percorre as linhas do mapa
        for (int j = 0; j < 8; j++) {           // percorre as colunas do mapa
            Antena *atual = listalig;
            char ponto = '.'; 

            while (atual != NULL) {                     // percorre a lista ligada
                if (atual->x == j && atual->y == i) {   // procura as coordenandas de cada antena na lista ligada
                    ponto = atual->frequencia;          // troca o ponto pelo carater que representa a frequencia da antena
                    break;
                }
                atual = atual->prox;
            }

            printf("%c", ponto);
        }
        printf("\n");
    }
}

void MostrarAntenasEEfeito(Antena* listalig, Efeito* listaligne){

    for (int i = 0; i < 5; i++) {               // percorre as linhas do mapa
        for (int j = 0; j < 8; j++) {           // percorre as colunas do mapa
            Antena *atual = listalig;
            char ponto = '.'; 

            while (atual != NULL) {                     // percorre a lista ligada
                if (atual->x == j && atual->y == i) {   // procura as coordenandas de cada antena na lista ligada
                    ponto = atual->frequencia;          // troca o ponto pelo carater que representa a frequencia da antena
                    break;
                }
                atual = atual->prox;
            }

            printf("%c", ponto);
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {               // percorre as linhas do mapa
        for (int j = 0; j < 8; j++) {           // percorre as colunas do mapa
            Efeito *atual = listaligne;
            char ponto = '.'; 

            while (atual != NULL) {                     // percorre a lista ligada
                if (atual->x == j && atual->y == i) {   // procura as coordenandas de cada antena na lista ligada
                    ponto = '#';          // troca o ponto pelo carater que representa o local onde existe efeito nefasto entre duas antenas
                    break;
                }
                atual = atual->prox;
            }

            printf("%c", ponto);
        }
        printf("\n");
    }
}

void LimparListaAntenas(Antena* listalig){

   Antena* inicio = listalig;    // criada uma variavel para tomar o inicio da lista ligada
   Antena* temp;                 // criada uma variavel temporaria para servir de auxiliar e utilizada para libertar a memória

   while (inicio != NULL) {      // percorre a lista ligada
       temp = inicio;
       inicio = inicio->prox;
       free(temp);               // liberta a memória
   }
}

void LimparListaEfeitos(Efeito* listaligne){

   Efeito* inicio = listaligne;    // criada uma variavel para tomar o inicio da lista ligada
   Efeito* temp;                 // criada uma variavel temporaria para servir de auxiliar e utilizada para libertar a memória

   while (inicio != NULL) {      // percorre a lista ligada
       temp = inicio;
       inicio = inicio->prox;
       free(temp);               // liberta a memória
   }
}

void ListarAntenasEfeito(Antena* listalig, Efeito* listaligne) {
    printf("|------------+------------+------------+------------+------------+\n");
    printf("| Frequência |     X      |     Y      | Loc. Nef X | Loc. Nef Y |\n");
    printf("|------------+------------+------------+------------+------------+\n");

    Antena* antena = listalig;
    Efeito* nefasto = listaligne;

    while (antena != NULL || nefasto != NULL) {
        if (antena != NULL && nefasto != NULL) {
            printf("| %c | %d | %d | %d | %d |\n", antena->frequencia, antena->x, antena->y, nefasto->x, nefasto->y);
            antena = antena->prox;
            nefasto = nefasto->prox;
        } else if (antena != NULL) { // Só tem antenas restantes
            printf("| %c | %d | %d | - | - |\n", antena->frequencia, antena->x, antena->y);
            antena = antena->prox;
        } else { // Só tem locais nefastos restantes
            printf("| - | - | - | %d | %d |\n", nefasto->x, nefasto->y);
            nefasto = nefasto->prox;
        }
    }

    printf("+------------+------------+------------+------------+------------+\n");
}
