/**
 * @file manipulaString.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém funções relacionadas a manipulação de strings
 */

#ifndef STRING_H_
#define STRING_H_

/**
 * @brief Tira os acentos de uma string
 *
 * A função converteAcentos() tira todos os acentos de uma string, transformando, i.e. à -> a
 * @param str String que será convertida
 *
 * @warning A função funciona com strings escritas dentro do terminal, porém se for lido de um arquivo, pode ser
 * que não funcione por causa das diferentes codificações.
 */
void converteAcentos(char *str);

/**
 * @brief Remove não-letras de uma string
 *
 * A função removeCaracteres() tira todos os caracteres que não sejam letras e/ou números de uma string.
 * @param str String na qual será feita a remoção
 *
 */
void removeCaracteres(char *str);

/**
 * @brief Remove um caractere de uma string
 *
 * A função puxaChar() é a função auxiliar da removeCaracteres(). Ela remove um caractere de uma string,
 * "puxando" todos os outros caracteres para não ficar um buraco no lugar do caractere a ser removido.
 * @param c Caractere a ser removido.
 *
 * @note A função precisa que esse caractere esteja dentro de uma string, já que puxará todos os caracteres
 * até encontrar um '\0'.
 */
void puxaChar(char *c);
#endif // STRING_H_
