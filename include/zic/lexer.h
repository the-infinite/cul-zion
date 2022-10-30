#pragma once

#include <zic/token.h>

typedef struct {
 	/**
 	 * @brief The content string we are reading from. Should be contents of some
 	 * file. 
 	 */
 	char* src;

	/**
	 * @brief The path to the file this lexer is currently trying to tackle.
	 */
	char* file;
 	
 	/**
 	* @brief The size of the source string in bytes.
 	*/
 	unsigned int src_size;
 	
 	/**
 	* @brief The current character observed under the cursor of this stream.
 	*/
 	char c;
 	
 	/**
 	* @brief The current index we are at.
 	*/
 	unsigned int i;

	/**
	 * @brief The current line the lexer is at.
	 */
	unsigned int line;

	/**
	 * @brief The current column the lexer is at.
	 */
	unsigned int column;
}	ZiTokenizer;


/**
 * @brief Initialises a brand new and empty lexer.
 * 
 * @param src The source string to parse.
 * @return A pointer to the lexer we have instantiated.
 */
ZiTokenizer* init_lexer(char* file, char* src);

/**
 * @brief Moves the state of the lexer referenced here forward. Essentially, shifting the context of position forward in memory.
 * 
 * @param lexer The lexer to advance.
 */
void lexer_advance(ZiTokenizer* lexer);

/**
 * @brief Moves the state of the lexer referenced forward like lexer_advance and then returns the token we obtained during our previous
 * round of parsing. 
 * 
 * @param lexer The lexer to advance
 * @param token The token to return.
 * @return A token after advancing the state of the lexer once.
 */
ZiTokenizer* lexer_advanceWith(ZiTokenizer* lexer, ZiToken* token);

/**
 * @brief Keep moving the state of the lexer forward while we are met with whitespace characters.
 *
 * @param lexer The lexer we want to advance while met with whitespace characters.
 */
void lexer_skipWhitespace(ZiTokenizer* lexer);

/**
 * @brief Fetches the next token the lexer can find.
 * 
 * @param lexer The lexer looking for tokens.
 * 
 * @return ZiToken* A pointer to the token we found.
 */
ZiTokenizer* lexer_nextToken(ZiToken* lexer);


/**
 * @brief Parses a symbol. It is worth noting that symbol here means alphanumeric text which can also be used internally as the name of a 
 * string.
 * 
 * @param lexer 
 * @return ZiToken* 
 */
ZiToken* lexer_parseIdentifier(ZiTokenizer* lexer);


/**
 * @brief Checks ahead by @b offset a character with respect to the current index.
 * 
 * @param lexer The lexer we are going to peek into.
 * @param offset The offset we want to look ahead by. If the lexer's current position is 5 and this is 4, we would look at 9. Something like that.
 * @return The character found at @p offset.
 */
char lexer_peek(ZiTokenizer* lexer, unsigned int offset);

/**
 * @brief Lexes the next token and returns a pointer to a token denoting it ahead of time.
 * 
 * @param lexer The lexer to peek ahead into.
 * @param expected The type we expected it to have.
 * @return ZiToken* A pointer to the token in front of this one.
 */
ZiToken* lexer_peekToken(ZiTokenizer* lexer, int expected);

/**
 * @brief Advances the 
 * 
 * @param lexer 
 * @param type 
 * @return ZiToken* 
 */
ZiToken* lexer_advanceCurrent(ZiTokenizer* lexer, int type);


/**
 * @brief Parses the next string inside the stream as an integer literal. Valid integer formats are ±12345(decimal), ±0c1234567(octal),
 *  ±0b11011(binary), and ±0x1234567(hex)
 * 
 * It can also be a floating point literal. Valid formats are ±1.0, ±2.0345e-196, or .234
 * 
 * @param lexer The lexer we are parsing this integer or floating point number from from.
 * @return A token containing an integer parsed as from the current byte stream.
 */
ZiToken* lexer_parseNumber(ZiTokenizer* lexer);