#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include <types.h>


extern char* errored_file;

/**
 * @brief Tells the person reading the output the file we are seeing the error we are currently monitoring from. Usually in an attempt to educate
 * the user on where to go combing for errors.
 * 
 * @param file The path to the file we are signalling them from.
 */
void zic_flagFile(char* file);

/**
 * @brief Prints as system level error.
 * 
 * @param error The error to print.
 */
void zic_printError(char* error);

/**
 * @brief Prints a parse error. Usually used to do things like "Unexpected end of file" and so on.
 * 
 * @param error The error as a string.
 * @param line The line we found the error.
 * @param expected The type of token we were expecting to see.
 * @param column The column we found the error.
 */
void zic_printParseError(char* error, int expected, int line, int column);

/**
 * @brief Tells the user we found an unexpected token.
 * 
 * @param token The unexpected token we found.
 * @param line The line we found this token.
 * @param column The column we found this token.
 */
void zic_printUnexpectedToken(char* token, int line, int column);

/**
 * @brief Tells the user we found something that is potentially dangerous but can be ignored.
 * 
 * @param warning The warning to print.
 * @param line The line where the warning was faulted from.
 * @param column The column on the said line.
 */
void zic_printWarning(char* warning, int line, int column);

/// @brief Prints a compile-time error.
void zic_printCompileError(char* error, int line, int column);

/**
* @brief Checks if two strings are equal in value.
* 
* @param one The first string to check...
* @param other The other string to check...
* @param ignoreCase Is this a case insensitive comparison?
* @return boolean 
*/
boolean zic_stringEquals(char* one, char* other, boolean ignoreCase);

/**
 * @brief Calculates and returns a probably unique number for any given string.
 * @param type Some string to calculate a PROBABLY unique value for it.
 */
zi_int zic_typeToInt(char* type);

/**
 * @brief Checks to see if a given string starts with a particular substring. If it does, we return true, else, we return false.
 * 
 * @param str The string to check.
 * @param args The substring to check for.
 * @return true if it does and false otherwise.
 */
boolean zic_startsWith(char* str, char* args);

/**
 * @brief Obtain the substring of a given string that starts at a specified index and ends at that index. Fair enough, this should work.
 * 
 * @param str The string to take from.
 * @param start The starting index.
 * @param end The ending index
 * @return The substring represented by start - end.
 */
char* zic_substring(char* str, int start, int end);

/**
 * @brief Parse a string representing a number in any given base.
 * 
 * @param lexer The tokenizer we found this number in.
 * @param str The string to parse a number.
 * @param base The base of the number
 * @return The number represented by this string.
 */
zi_int zic_parseNumber(ZiTokenizer* lexer, char* str, int base);