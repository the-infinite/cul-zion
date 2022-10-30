#include <stdlib.h>
#include <zic/token.h>

ZiToken* init_token(char* value, int type) {
	ZiToken* token = malloc(sizeof(ZiToken));
	token->value = value;
	token->type = type;
	token->column = 1;
	token->line = 1;
	return token;
}

const char* token_expectedValue(int type) {
	switch(type) {
		case TOKEN_PLUS:
		case TOKEN_MINUS:
		case TOKEN_DIVIDE:
		case TOKEN_MULTIPLY:
		case TOKEN_POW: {
			return "'+', '-', '/', '*', or '**'";
		}

		case TOKEN_MODULUS: {
			return "'+', '-', '/', '*', '^', or '%'";
		}	

		case TOKEN_DECREMENT:
		case TOKEN_INCREMENT: {
			return "'++' or '--'";
		}

		case TOKEN_ASSIGN_EQUAL:
		case TOKEN_ASSIGN_PLUS:
		case TOKEN_ASSIGN_MINUS: {
			return "'=', '+=', or '-='";
		}

		case TOKEN_ASSIGN_DIVIDE:
		case TOKEN_ASSIGN_MULTIPLY:
		case TOKEN_ASSIGN_MODULUS:
		case TOKEN_ASSIGN_POW: {
			return "'=', '+=', '-=', '/=', '*=', '%=', or '^='";
		}

		case TOKEN_LOGICAL_EQUALS:
		case TOKEN_LESSER: 
		case TOKEN_GREATER: 
		case TOKEN_LESSER_OR_EQUAL:
		case TOKEN_GREATER_OR_EQUAL: {
			return "'>', '<', '>=', '<=', '!=', or '=='";
		}

		case TOKEN_LOGICAL_AND: 
		case TOKEN_LOGICAL_OR: {
			return "'&&' or '||'";
		}

		case TOKEN_BITWISE_NOT:
		case TOKEN_BITWISE_NEGATE: 
		case TOKEN_BITWISE_OC:
		case TOKEN_BITWISE_TC: {
			return "'`', '~', '``' or '!'";
		}

		case TOKEN_LITERAL_CHARACTER: {
			return "a valid character literal";
		}

		case TOKEN_LITERAL_FLOAT: {
			return "a valid floating-point literal";
		}

		case TOKEN_LITERAL_STRING: {
			return "a valid string literal";
		}

		case TOKEN_BITWISE_AND:
		case TOKEN_BITWISE_OR:
		case TOKEN_BITWISE_XOR: 
		case TOKEN_BITWISE_LSHIFT:
		case TOKEN_BITWISE_RSHIFT: {
			return "'&', '|', '^', '<<', or '>>'";
		}

		case TOKEN_LPAREN: {
			return "'('";
		}

		case TOKEN_RPAREN: {
			return "')'";
		}

		case TOKEN_LBRACE: {
			return "'{'";
		}

		case TOKEN_RBRACE: {
			return "'}'";
		}

		case TOKEN_LBRACKET: {
			return "'['";
		}

		case TOKEN_RBRACKET: {
			return "']'";
		}

		case TOKEN_COMMA: {
			return "','";
		}

		case TOKEN_ARROW_RIGHT: {
			return "'=>'";
		}

		case TOKEN_SEMICOLON: {
			return "';'";
		}

		case TOKEN_COLON: {
			return "':'";
		}

		case TOKEN_LITERAL_INT: {
			return "a valid integer literal";
		}

		case TOKEN_DOT: {
			return "'.'";
		}

		case TOKEN_LITERAL_BOOLEAN: {
			return "'true' or 'false'";
		}

		case TOKEN_IDENTIFIER: {
			return "a valid identifier";
		}

		case TOKEN_LITERAL_NULL: {
			return "a valid object or null";
		}

		case TOKEN_VALUE_AS: {
			return "the 'as' operator or any other one valid for this data type";
		}

		case TOKEN_VALUE_FROM: {
			return "the 'from' operator";
		}

		case TOKEN_VALUE_IN: {
			return "the 'in' operator";
		}

		case TOKEN_VALUE_WITH: {
			return "the 'with' operator";
		}

		case TOKEN_TYPE: {
			return "a valid identifier naming a data type";
		}
	}

	return "nothing at all";
}

char* token_toString(ZiToken* token) {
	return token->value;
}

const char* token_typeToString(int type) {
	switch(type) {
		case TOKEN_EOF: {
			return "end of file";
		}

		case TOKEN_MODULUS: 
		case TOKEN_PLUS: 
		case TOKEN_MINUS: 
		case TOKEN_DIVIDE: 
		case TOKEN_MULTIPLY:
		case TOKEN_POW: 
		case TOKEN_DECREMENT: 
		case TOKEN_INCREMENT: {
			return "mathematical operator";
		}

		case TOKEN_ASSIGN_EQUAL: 
		case TOKEN_ASSIGN_PLUS: 
		case TOKEN_ASSIGN_MINUS: 
		case TOKEN_ASSIGN_DIVIDE: 
		case TOKEN_ASSIGN_MULTIPLY: 
		case TOKEN_ASSIGN_MODULUS: 
		case TOKEN_ASSIGN_POW: 
		case TOKEN_ASSIGN_OR: {
			return "atomic mathematical operator";
		}

		case TOKEN_LESSER: 
		case TOKEN_GREATER: 
		case TOKEN_LESSER_OR_EQUAL: 
		case TOKEN_GREATER_OR_EQUAL:
		case TOKEN_LOGICAL_EQUALS: 
		case TOKEN_LOGICAL_NOT: 
		case TOKEN_LOGICAL_AND: 
		case TOKEN_LOGICAL_OR: {
			return "logical operator";
		}

		case TOKEN_BITWISE_NOT: 
		case TOKEN_BITWISE_AND: 
		case TOKEN_BITWISE_OR: 
		case TOKEN_BITWISE_XOR: 
		case TOKEN_BITWISE_NEGATE:
		case TOKEN_BITWISE_OC: 
		case TOKEN_BITWISE_TC: 
		case TOKEN_BITWISE_LSHIFT: 
		case TOKEN_BITWISE_RSHIFT: {
			return "bitwise operator";
		} 

		case TOKEN_LPAREN: 
		case TOKEN_RPAREN: 
		case TOKEN_LBRACE: 
		case TOKEN_RBRACE: 
		case TOKEN_LBRACKET: 
		case TOKEN_RBRACKET:
		case TOKEN_ARROW_RIGHT: 
		case TOKEN_SEMICOLON: 
		case TOKEN_COLON:
		case TOKEN_DOT:
		case TOKEN_COMMA:
		case TOKEN_VALUE_FROM:
		case TOKEN_VALUE_AS:
		case TOKEN_VALUE_IN:
		case TOKEN_VALUE_WITH:
		case TOKEN_QUESTION: {
			return "symbol";
		}

		case TOKEN_IDENTIFIER: {
			return "identifier";
		}

		case TOKEN_LITERAL_BOOLEAN: {
			return "boolean literal";
		}

		case TOKEN_LITERAL_INT: {
			return "integer literal";
		}

		case TOKEN_LITERAL_FLOAT: {
			return "floating-point literal";
		}

		case TOKEN_LITERAL_CHARACTER: {
			return "character literal";
		}

		case TOKEN_LITERAL_STRING: {
			return "string literal";
		}

		case TOKEN_TYPE: {
			return "type name";
		}
	}

	return "null literal";
}