#pragma once

#include <strings.h>
#include <string.h>

#include <types.h>

typedef enum {
	TOKEN_EOF, 

	TOKEN_MODULUS, 
	
	TOKEN_PLUS, 
	TOKEN_MINUS, 
	TOKEN_DIVIDE, 
	TOKEN_MULTIPLY,
	TOKEN_POW, 
	TOKEN_DECREMENT, 
	TOKEN_INCREMENT, 

	TOKEN_ASSIGN_EQUAL, 
	TOKEN_ASSIGN_PLUS, 
	TOKEN_ASSIGN_MINUS, 
	TOKEN_ASSIGN_DIVIDE, 
	TOKEN_ASSIGN_MULTIPLY, 
	TOKEN_ASSIGN_MODULUS, 
	TOKEN_ASSIGN_POW, 
	TOKEN_ASSIGN_OR, 


	TOKEN_LESSER, 
	TOKEN_GREATER, 
	TOKEN_LESSER_OR_EQUAL, 
	TOKEN_GREATER_OR_EQUAL,
	TOKEN_LOGICAL_EQUALS, 
	TOKEN_LOGICAL_NOT, 
	TOKEN_LOGICAL_AND, 
	TOKEN_LOGICAL_OR, 


	TOKEN_BITWISE_NOT, 
	TOKEN_BITWISE_AND, 
	TOKEN_BITWISE_OR, 
	TOKEN_BITWISE_XOR, 
	TOKEN_BITWISE_NEGATE,
	TOKEN_BITWISE_OC, 
	TOKEN_BITWISE_TC, 
	TOKEN_BITWISE_LSHIFT, 
	TOKEN_BITWISE_RSHIFT, 


	TOKEN_LPAREN, 
	TOKEN_RPAREN, 
	TOKEN_LBRACE, 
	TOKEN_RBRACE, 
	TOKEN_LBRACKET, 
	TOKEN_RBRACKET,
	TOKEN_ARROW_RIGHT, 
	TOKEN_SEMICOLON, 
	TOKEN_COLON,
	TOKEN_DOT,
	TOKEN_COMMA,

	TOKEN_QUESTION,
	TOKEN_IDENTIFIER, 

	TOKEN_LITERAL_BOOLEAN,
	TOKEN_LITERAL_NULL,
	TOKEN_LITERAL_INT,
	TOKEN_LITERAL_FLOAT,
	TOKEN_LITERAL_CHARACTER,
	TOKEN_LITERAL_STRING,

	TOKEN_VALUE_FROM,
	TOKEN_VALUE_AS,
	TOKEN_VALUE_IN,
	TOKEN_VALUE_WITH,
	TOKEN_TYPE,
}	TokenType;

typedef struct ZION_TOKEN {
	/**
	 * @brief What is the literal value of this token as a string?
	 */
	char* value;

	/**
	 * @brief What is the type of this token?
	 */
	int type;

	/// @brief the column on the specific line where this starts.
	int column;

	/// @brief the specific line this token sits on.
	int line; 
}	ZiToken;

/**
 * @brief Initializes an empty token.
 *
 * @param value The value of this token as a string.
 * @param type The type of the token you wish to generate.
 * @return ZiToken* A new token of the type specified.
 */
ZiToken* init_token(char* value, int type);

/**
 * @brief Returns a string containing a string representing a given token.
 * 
 * @param token The token to write out.
 * @return char* A string representing the token to return.
 */
char* token_toString(ZiToken* token);

/**
 * @brief Returns the typename of a token as a string.
 * 
 * @param type The type of token we are considering here.
 * @return const char* A string representing the name of a token's type.
 */
const char* token_typeToString(int type);

/**
 * @brief The kind of value we expected for the token of the type specified.
 * 
 * @param type The type of token to consider here.
 * @return const char* A string representing the class possible values for a token we were expecting.
 */
const char* token_expectedValue(int type);