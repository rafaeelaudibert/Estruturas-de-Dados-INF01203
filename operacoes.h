#include "struct.h"

/**
 * @file operacoes.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém funções executadas durante a leitura do arquivo de operacoes
 */

#ifndef OPERACOES_H_
#define OPERACOES_H_
#define TAM_VET 11000


/**
 * @brief Encontra e escreve em um arquivo as consultas mais realizadas em uma dada cidade
 *
 * A função consultasPorLocalidade() encontra e escreve em um arquivo as @c qtdConsultas mais realizadas
 * em uma dada cidade.
 * Se 0 for passado como parametro para @c qtdConsultas, são mostradas todas as consultas realizadas naquela
 * localidade.
 *
 * @param arvore Arvore que contem os dados
 * @param cidade String da cidade que estamos procurando os dados
 * @param qtdConsultas Quantidade de consultas que serão printadas no arquivo
 * @param saida Arquivo no qual serão printadas as @c qtdConsultas mais consultadas.
 */
void consultasPorLocalidade(Consulta* arvore, char* cidade, int qtdConsultas, FILE* saida);


/**
 * @brief Encontra as consultas mais realizadas em todo o arquivo
 *
 * A função consultasArquivo() encontra as consultas que foram mais buscadas.
 * Se 0 for passado como parametro para @c qtdConsultas, são mostradas todas as consultas realizadas.
 *
 * @param arvore Arvore que contem os dados
 * @param retorno Array de tamanho @c qtdConsultas (inicialmente), contendo as @c qtdConsultas mais realizadas em todo o arquivo
 * @param qtdConsultas Quantidade de consultas que serão buscadas na @c arvore.
 *
 * @return @c int que é a quantidade de elementos em @c retorno.
 * @warning Essa função é extremamente custosa quando se está procurando TODAS as consultas do arquivo.
 */
int consultasArquivo(Consulta* arvore, Consulta retorno[], int qtdConsultas);


/**
 * @brief Encontra os termos consultados em uma localidade
 *
 * A função termosPorLocalidade() encontra todos os termos que foram consultados em uma localidade.
 * Funciona RECURSIVAMENTE.
 *
 * @param arvore Arvore que contem os dados
 * @param lista @c LDE onde serão inseridos os termos do nodo atual da arvore.
 * @param cidade Cidade a qual estamos procurando os termos
 *
 * @return @c LDE* que é a lista com todos os termos pesquisados naquela cidade.
 * @warning Na primeira chamada dessa função, a @c lista precisa ser VAZIA.
 */
LDE* termosPorLocalidade(Consulta* arvore, LDE *lista, char cidade[]);

/**
 * @brief Encontra os termos consultados em um arquivo.
 *
 * A função termosArquivo() encontra todos os termos que foram consultados em um arquivo.
 *
 * @param listaTermos Lista de todos os termos consultados no arquivo
 * @param cidade Cidade a qual estamos procurando os termos
 *
 * @return @c LDE* que é a lista de todos os termos consultados no arquivo.
 * @warning Essa função é apenas um placeholder, para manter uma convenção de sempre chamarmos uma função para as operações, já que já temos todos os termos do arquivo separados em uma estrutura própria.
 */
LDE* termosArquivo(LDE* listaTermos);


/**
 * @brief Retorna a média do tamanho das consultas realizadas em uma cidade.
 *
 * A função mediaTamanhoConsultasLocalidade() retorna a média do tamanho das consultas realizadas em uma determinada localidade
 *
 * @param arvore Arvore com todas as consultas
 * @param cidade Cidade a qual estamos procurando
 *
 * @return @c int* que é a média do tamanho das consultas realizadas em uma determinada cidade.
*/
int mediaTamanhoConsultasLocalidade(Consulta* arvore, char* cidade);


/**
 * @brief Retorna a média do tamanho das consultas realizadas em todo o arquivo.
 *
 * A função mediaTamanhoConsultasArquivo() retorna a média do tamanho das consultas realizadas em no arquivo
 * @param arvore Arvore com todas as consultas
 *
 * @return @c int* que é a média do tamanho das consultas realizadas no arquivo
*/
int mediaTamanhoConsultasArquivo(Consulta* arvore);










/*================================================================|
|AS FUNÇÕES ABAIXO DAQUI SÃO FUNÇÕES AUXILIARES PARA AS ANTERIORES|
|================================================================*/

/**
 * @brief Concatena todos os termos de uma LSE em uma LDE
 *
 * A função insereTermosNodo() concatena todos os termos que existem em @c termos em @c lista.
 * É passado como parametro numérico da função insereLDENumerico() o que é recebido no parametro @c qtde.
 *
 * @param lista Lista que receberá os termos
 * @param termos Lista da qual são copiados os termos
 * @param qtde Valor que será passado como parametro para a função insereLDENumerico(). É a quantidade de vezes que cada termo aparecia originalmente.
 * @return @c LDE* que é a @c lista com a adição dos novos termos.
 * @note Essa função é uma função auxiliar para termosPorLocalidade()
*/
LDE* insereTermosNodo(LDE *lista, LSE* termos, int qtde);


/**
 * @brief Calcula a quantidade total de consultas e a quantidade total de termos no arquivo
 *
 * A função auxiliarMediaTamanhoConsultasArquivo() varre uma arvore buscando a quantidade total de consultas
 * assim como a quantidade total de termos que possuem naquela arvore.
 *
 * @param arvore Arvore a ser varrida
 * @param totTermos Ponteiro para um inteiro que armazena a quantidade total de termos na árvore
 * @param totConsultas Ponteiro para um inteiro que armazena a quantidade total de consultas na árvore
 * @note Essa função é uma função auxiliar para mediaTamanhoConsultasArquivo()
*/
void auxiliarMediaTamanhoConsultasArquivo(Consulta *arvore, int *totTermos, int *totConsultas);


/**
 * @brief Calcula a quantidade total de consultas e a quantidade total de termos em uma dada cidade
 *
 * A função auxiliarMediaTamanhoConsultasLocalidade() varre uma arvore buscando a quantidade total de consultas
 * assim como a quantidade total de termos que possuem naquela arvore e que tenham acontecido nas consultas
 * de uma determinada cidade
 *
 * @param arvore Arvore a ser varrida
 * @param totTermos Ponteiro para um inteiro que armazena a quantidade total de termos consultados pela cidade na árvore
 * @param totConsultas Ponteiro para um inteiro que armazena a quantidade total de consultas realizadas pela cidade na árvore
 * @param cidade String com o nome da cidade que está sendo procurada
 * @note Essa função é uma função auxiliar para mediaTamanhoConsultasLocalidade()
*/
void auxiliarMediaTamanhoConsultasLocalidade(Consulta *arvore, int *totTermos, int *totConsultas, char* cidade);


/**
 * @brief Retorna a "quantidade" de vezes que um termo aparece em uma LDE
 *
 * A função temCidadeNaLista() varre uma LDE, procurando um termo identico a @c cidade.
 * Caso exista esse termo na LDE, retorna a "quantidade" de vezes que ele ocorre, caso contrário retorna 0.
 * Essa @<quantidade de vezes que ele ocorre@> é dada pelo campo LDE#qtde da cidade.
 *
 * @param cidade String a ser procurada em @c lista
 * @param lista Lista que será varrida procurando por @c cidade
 * @return @c int 1 se existe a string na lista e 0 se não existe a string na lista
 * @note Essa função é uma função auxiliar para achaVetorRepsLocalidade(), auxiliarMediaTamanhoConsultasLocalidade() e termosPorLocalidade()
*/
int temCidadeNaLista(char* cidade, LDE* lista);


/**
 * @brief Copia a quantidade de acessos de cada nodo da arvore pra posições de um vetor
 *
 * A função achaVetorReps() recebe uma arvore, e pra cada nodo dessa árvore encontrado recursivamente,
 * copia a quantidade de acessos dele para um vetor
 *
 * @param arvore Arvore que contem as informações a serem inseridas em vetor
 * @param vetor Vetor com as quantidades de consultas realizadas.
 * @param contador Conta em qual posição de @c vetor será inserido a quantidade
 * @return @c int Quantidade de consultas encontradas
 * @note Essa função é uma função auxiliar para consultasArquivo()
*/
int achaVetorReps(Consulta* arvore, int *vetor, int contador);


/**
 * @brief Encontra as repetições de uma consulta por localidade
 *
 * A função achaVetorRepsLocalidade() recebe uma estrutura especial, criada somente para ela,
 * fazendo com que ela coloque em um vetor, todas as consultas realizadas em uma cidade.
 *
 * @param arvore Arvore que contem as informações a serem inseridas em vetor
 * @param vetor Vetor com as quantidades de consultas realizadas.
 * @param contador Conta em qual posição de @c vetor será inserido a quantidade
 * @param cidade Cidade a qual estamos procurando as consultas
 * @param qtdCons Vetor de QtdCons onde serão guardados as consultas e sua quantidade
 * @return @c int Quantidade de consultas encontradas
 * @note Essa função é uma função auxiliar para consultasPorLocalidade()
*/
int achaVetorRepsLocalidade(Consulta* arvore, int *vetor, int contador, char *cidade, Qtdcons *qtdCons);


/**
 * @brief Copia uma arvore para a outra, de maneira ordenada
 *
 * A função copiaArvore() copia a arvore @c arvore, para a arvore @c retorno, de maneira ordenada,
 * seguindo o ordenamento dado por @c vetor
 *
 * @param arvore Arvore que contem as informações
 * @param retorno Arvore para a qual serao copiados os valores
 * @param vetor Vetor ordenado, com o qual procuramos os nodos certos a serem inseridos
 * @param qtd Até qual posição de @c vetor preciso preencher
 * @param pos Minha posição de preenchimento atual de @c vetor
 * @param vezesRep Vezes que a repetição ocorreu
 * @return @c int Usado dentro das recursões para saber em que repetição da recursão estamos
 * @note Essa função é uma função auxiliar para consultasArquivo()
*/
int copiaArvore(Consulta* arvore, Consulta* retorno, int *vetor, int qtd, int pos, int vezesRep);

/**
 * @brief Quick sort de vetores int genéricos
 *
 * Ordena um vetor de int genéricos usando o algoritmo de Quick Sort (https://pt.wikipedia.org/wiki/Quicksort)
 *
 * @param a Vetor a ser ordenado
 * @param left Detalhe de implementação relacionado ao algoritmo de Divide&Conqueror
 * @param right Detalhe de implementação relacionado ao algoritmo de Divide&Conqueror
 * @note Essa função é uma função auxiliar
*/
void quick_sort(int *a, int left, int right);

#endif // OPERACOES_H_
