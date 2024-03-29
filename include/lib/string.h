/*!
@file
@defgroup string
@brief  Header file for string
This file contains functions implementation from libs (string.h)
*/
#ifndef STRING_H
#define STRING_H

#include "common.h"
#include "lib/stdint.h"

#define NULL 0

/**
 * @ingroup string
 *
 * @brief Copies bytes between buffers. From src to dest.
 *
 * @param dest Destination area.
 * @param src Source area.
 * @param n, Bytes count.
 * @returns Pointer to dest.
 */
void* memcpy(void* dest, const void* src, size_t n);

/**
 * @ingroup string
 *
 * @brief Sets buffers to a specified character.
 *
 * @param buf Pointer to the object to fill.
 * @param ch  Fill byte.
 * @param count  Number of bytes to fill.
 *
 * @return Pointer to buf.
 */
void* memset(void* buf, char ch, size_t count);

/**
 * @ingroup string
 *
 * @brief Compare strings.
 *
 * @param str1 Null-terminated string to compare.
 * @param str2 Null-terminated string to compare.
 *
 * @return {The return value for each of these functions indicates the ordinal relation of str1, str2.
 *
 * < 0 str1 is less than str2
 *   0 str1 is identical to str2
 * > 0 str1 is greater than str2}
 */
int strcmp(const char* str1, const char* str2);

/**
 * @ingroup string
 *
 * @brief Appends a string.
 *
 * @param buf Null-terminated destination string.
 * @param ch  Null-terminated source string.
 *
 * @return destination is returned.
 */
char* strcat(char* dest, const char* src);

/**
 * @ingroup string
 *
 * @brief Gets the length of a string.
 *
 * @param str Null-terminated string.
 *
 * @return length of a string.
 */
size_t strlen(const char* str);

/**
 * @ingroup string
 *
 * @brief Copies a string.
 *
 * @param dest Destination string.
 * @param src  Null-terminated source string.
 *
 * @return destination is returned.
 */
char* strcpy(char* dest, const char* src);

/**
 * @ingroup string
 *
 * @brief Copies the first num characters of source to destination.
 *
 *
 * @param dest Destination string.
 * @param src  Null-terminated source string.
 * @param num  Maximum number of characters to be copied from source. size_t is an unsigned integral type.
 *
 * @return destination is returned.
 */
char* strcpyn(char* dest, const char* src, size_t num);

/**
 * @ingroup string
 *
 * @brief Returns the length of the initial portion of str1 which consists only of characters that are part of accept.
 *
 * @param str Null-terminated string.
 * @param accept Null-terminated string containing the characters to match.
 *
 * @return The length of the initial portion of str1 containing only characters that appear in accept. size_t is an unsigned integral type.
 */
size_t strspn(const char* str, char* accept);

/**
 * @ingroup string
 *
 * @brief Scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of characters of str1 read before this first occurrence.
 *
 * @param str Null-terminated source string to be scanned.
 * @param not_accept Null-terminated source string containing the characters to match.
 *
 * @return The length of the initial part of str not containing any of the characters that are part of not_accept.
 */
size_t strcspn(const char* str, char* not_accept);

/**
 * @ingroup string
 *
 * @brief Returns a pointer to the first occurrence of character in the C string str.
 *
 * @param str pointer to the object to fill.
 * @param ch  Character to be located. It is passed as its int promotion, but it is internally converted back to char for the comparison.
 *
 * @return A pointer to the first occurrence of character in str.
 */
char* strch(char* str, char ch);

/**
 * @ingroup string
 *
 * @brief Extract a portion of a string.
 *
 * @param str The string from which to extract.
 * @param ch  The byte position at which to begin extracting.
 *
 * @return The byte position at which to end extracting. The end position is included in the extraction.
 */
char* strext(char* buf, const char* str, char sym);

/**
 * @ingroup string
 *
 * @brief Converts an integer value to a null-terminated string using the specified base and stores the result in the array given by str parameter.
 *
 * @param value Value to be converted to a string.
 * @param str  Array in memory where to store the resulting null-terminated string.
 * @param base  Numerical base used to represent the value as a string, between 2 and 36, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
 *
 * @return A pointer to the resulting null-terminated string, same as parameter str.
 */
char* itoa(uint32_t value, char* str, uint32_t base);

/**
 * @ingroup string
 *
 * @brief Inverts the inputted string.
 *
 * @param str String for inverts.
 */
char* strinv(char* str);

/**
 * @ingroup string
 *
 * @brief Print to string.
 */
uint32_t vsprintf(char* s1, const char* s2, va_list list);

/**
 * @ingroup string
 *
 * @brief Print to limited string.
 */
uint32_t vsnprintf(char* s1, uint32_t n, const char* s2, va_list list);

#endif // STRING_H