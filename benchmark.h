#include "struct.h"

/**
 * @file benchmark.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém funções relacionadas a medição do tempo gasto para realizar as operações de entrada//saida de dados
 */

#ifndef BENCHMARK_H
#define BENCHMARK_H

/**
 * @brief Benchmark da entrada de dados
 *
 * A função infoBenchmark() é responsável pela medição do tempo que a função @c function demora para
 * realizar a inserção dos dados na estrutura.
 *
 * @param function Função da qual será medido o tempo. OBS.: Ela precisa ser do tipo @c Info*, e receber como parâmetro @c FILE*
 * @param entrada Arquivo que contém os dados de entrada. Será passado como parâmetro para @c function.
 *
 * @return @c Info* que é o mesmo que é retornado por @c function.
 */
Info* infoBenchmark(Info*(*function)(FILE*), FILE* entrada);

/**
 * @brief Benchmark da saida de dados.
 *
 * A função operacoesBenchmark() é responsável pela medição do tempo que a função @c function demora para
 * realizar as operações e escrever a saída dos dados em um arquivo.
 *
 * @param function Função da qual será medido o tempo. OBS.: Ela precisa ser do tipo @c int, e receber como parâmetro @<FILE*, FILE*, Info*@>
 * @param operacoes Arquivo que contém os dados das operações a serem realizadas em @c dados. Será passado como parâmetro para @c function.
 * @param saida  Arquivo onde serão impressos os dados de saída. Será passado como parâmetro para @c function.
 * @param dados Dados onde serão realizadas as operações descritas em @c operacoes. Será passado como parâmetro para @c function.
 *
 * @return @c int que é a quantidade de operações realizadas com sucesso.
 */
void operacoesBenchmark(int(*function)(FILE*, FILE*, Info*), FILE* operacoes, FILE* saida, Info* dados);

#endif // BENCHMARK_H
