/**
 * @file estruturas.h
 * @author gonçalo rodrigues a31507@alunos.ipca.pt
 * @brief ficheiro que contem as structs e funcoes utilizadas
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */



/**
 * @brief Estrutura que contém a Antena, a sua frequencia e a sua posição
 * 
 */
 typedef struct Antena{

    char frequencia;
    int x,y;
    struct Antena *prox;

 }Antena;

 /**
  * @brief Estrutura que contém o Efeito Nefasto e a sua posição
  * 
  */
 typedef struct Efeito{

   int x,y;
   struct Efeito *prox;

 }Efeito;

/**
 * @brief Função que tem como objetivo criar uma antena nova
 * 
 * @param frequencia Parametro que contem a Frequência da Antena
 * @param x Parametro que contem a coordenada x da Antena
 * @param y Parametro que contem a coordenadas y da Antena
 * @return Antena* 
 */
 Antena* CriarAntena(char frequencia, int x, int y);

/**
 * @brief Função que tenm como objetivo carregar um ficheiro que contem antenas
 * 
 * @param listalig Parametro que contem a lista ligada de antenas
 * @param antenas nome do ficheiro
 * @return Antena* 
 */
 Antena* CarregarAntenas(Antena* listalig, const char* antenas);

/**
 * @brief Função que tem como objetivo inserir a nova antena criada na lista ligada
 * 
 * @param listalig Parametro que contem a lista ligada de antenas
 * @param frequencia Parametro que contem a Frequência da Antena
 * @param x Parametro que contem a coordenada x da Antena
 * @param y Parametro que contem a coordenada y da Antena
 * @return Antena* 
 */
 Antena* InserirAntenaInicio(Antena* listalig, char frequencia, int x, int y);

 /**
  * @brief 
  * 
  * @param listalig 
  * @param frequencia 
  * @param x 
  * @param y 
  * @return Antena* 
  */
 Antena* InserirAntenaFim(Antena* listalig, char frequencia, int x, int y);

/**
 * @brief Função que tem como objetivo remover uma antena da lista ligada
 * 
 * @param listalig Parametro que contem a lista ligada de antenas 
 * @param x Parametro que contem a coordenada x da Antena
 * @param y Parametro que contem a coordenada y da Antena
 * @return Antena* 
 */
 Antena* RemoverAntena(Antena* listalig, int x, int y);

/**
 * @brief Função que tem como objetivo detetar os locais onde existe efeito nefasto
 * 
 * @param listalig Parametro que contem a lista ligada de antenas 
 * @return Efeito* 
 */
Efeito* DetetarEfeito(Antena* listalig, Efeito* locefeito);

/**
 * @brief Função que tem como objetivo ser complementar à função DetetarEfeito para que quando a mesma detetar que existe efeito nefasto entre antenas, adiciona-lo
 * 
 * @param listalig
 * @param x 
 * @param y 
 * @return Efeito* 
 */
 Efeito* AdicionarEfeito(Efeito* listaligne, int x, int y);

 /**
  * @brief Função com o objetivo de modificar uma antena já existente
  * 
  * @param listalig Parametro que contem a lista ligada de antenas
  * @param x Parametro que contem a coordenada x da antena
  * @param y Parametro que contem a coordenada y da antena
  * @param novafrequencia Parametro que contem a nova frequencia a ser introduzida na antena
  * @param novax Parametro que contem a nova coordenada x da antena
  * @param novay Parametro que contem a nova coordenada y da antena
  * @return Antena* 
  */
 Antena* ModificarAntena(Antena *listalig, int x, int y, char novafrequencia, int novax, int novay);
/**
 * @brief Função que tem como objetivo mostrar na consola em formato de mapa as antenas contidas na lista ligada de antenas
 * 
 * @param listalig Parametro que contem a lista ligada de antenas
 */
void MostrarAntenas(Antena* listalig);

/**
 * @brief 
 * 
 * @param listalig 
 * @param listaligne 
 */
void MostrarAntenasEEfeito(Antena* listalig, Efeito* listaligne);

/**
 * @brief Função com o objetivo de libertar memória
 * 
 * @param listalig Parametro que contem a lista ligada de antenas
 */
 void LimparListaAntenas(Antena* listalig);

 /**
  * @brief Função com o objetivo de listar na consola as antenas e os locais com efeito nefasto
  * 
  * @param listalig Parametro que contem a lista ligada de antenas
  * @param listaligne Parametro que contem a lista ligada de locais com efeito nefasto
  */
 void ListarAntenasEfeito(Antena* listalig, Efeito* listaligne);

 /**
  * @brief Função com o objetivo de libertar memória
  * 
  * @param listaligne 
  */
 void LimparListaEfeitos(Efeito* listaligne);

 