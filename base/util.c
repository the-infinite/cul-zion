#include <ctype.h>
#include <signal.h>

#include <utils.h>
#include <zic/lexer.h>
#include <types.h>

char* errored_file = NULL;

void zic_flagFile(char* file) {
	if(errored_file == NULL) {
		// Update the errored file.
		errored_file = calloc(strlen(file)+1, sizeof(char));
		strcpy(errored_file, file); // Perfect.
		fprintf(stderr, "From file \"%s\"\n", file);
		return;
	}

	if(!zic_stringEquals(errored_file, file, false)) {
		fprintf(stderr, "From \"%s\" included by \"%s\"\n", file, errored_file);
	}
}

void zic_printError(char* error) {
	zic_printIndents();
	fprintf(stderr, "\t%s\n", error);
	exit(-1); // We always leave when we are done.
}

void zic_printParseError(char* error, int expected, int line, int column) {
#ifdef DEBUG
	ZiToken* token= init_token((char*)token_expectedValue(expected), expected);
	fprintf(stderr, "\tAt line %d column %d:\n Unexpected token '%s' because we were expecting %s.\n", line, column, error, token_toString(token));
	raise(SIGSEGV);
#else
	fprintf(stderr, "\tAt line %d column %d:\n Unexpected token '%s' because we were expecting %s.\n", line, column, error, token_expectedValue(expected));
#endif
	exit(-1);
}

void zic_printWarning(char* error, int line, int column) {
	zic_printIndents();
	fprintf(stderr, "\tAt line %d column %d:\n Warning! %s\n", line, column, error);
}

void zic_printCompileError(char* error, int line, int column) {
	zic_printIndents();
	fprintf(stderr, "\tAt line %d column %d:\n Fatal error! %s\n", line, column, error);
	exit(-1);
}

void zic_printUnexpectedToken(char* token, int line, int column) {
#ifdef DEBUG
	zic_printIndents();
	fprintf(stderr, "\tAt line %d column %d:\n Unexpected token '%s'\n", line, column, token);;
	raise(SIGSEGV);
#else
	zic_printIndents();
	fprintf(stderr, "\tAt line %d column %d:\n Unexpected token '%s'\n", line, column, token);
	exit(-1);
#endif
}

boolean zic_stringEquals(char* one, char* other, boolean ignoreCase) {
	if(one == NULL && other != NULL) {
		return false;
	}

	if(other == NULL && one != NULL) {
		return false;
	}

	unsigned int size_one = strlen(one);
	unsigned int size_other = strlen(other);

	if(size_one != size_other) {
		return false;
	}

	for(int i = 0; i < size_one; ++i) {
		char first = one[i];
		char second = other[i];

		if(ignoreCase) {
			if(isupper(first)) {
				first = tolower(first);
			}

			if(isupper(second)) {
				second = tolower(second);
			}
		}

		if(first != second) {
			return false;
		}
	}

	return true;
}

boolean zic_startsWith(char* str, char* args) {
	size_t strLen = strlen(str);
	size_t argLen = strlen(args);

	if(argLen > strLen) { // If this is just not possible...
		return false;
	}

	for(int i = 0; i < argLen; i++) {
		if(str[i] != args[i]) {
			return false;
		}
	}

	return true;
}

char* zic_substring(char* str, int start, int end) {
	if(end > strlen(str)) {
		return NULL;
	}

	int resultLen  = end - start + 1;
	char* result = calloc(resultLen + 1, sizeof(char));

	for(int i = 0; i < resultLen; i++) {
		result[i] = str[i+start];
	}

	return result;
}

static unsigned int raise10(int times) {
	unsigned int ret = 10;
	int total = times;

	while(total > 1) {
		ret *= 10;
		total --;
	}

	return ret; 
}

zi_int zic_typeToInt(char* type) {
	zi_int ret = 0;
	size_t len = strlen(type);

	for(int i = 0, j = 1; i < len; i++, j++) {
		ret += raise10(j) * (type[i] - 97);
	}

	return ret;
}

static int zic_charValue(char c) {
	if(c >= '0' && c <= '9') {
		return (int)c - '0';
	}	else {
		return (int)c - 'A' + 10;
	}
}

zi_int zic_parseNumber(ZiTokenizer* lexer, char* str, int base) {
	int len = strlen(str);
	int power = 1;
	zi_int num= 0;
	int i;

	for (i = len -1; i >=0 ; i--) {
		int val = zic_charValue(str[i]);

		if(val >= base) {
			zic_flagFile(lexer->file);
			zic_printCompileError("Invalid numeric literal", lexer->line, lexer->column);
		}

		num += val * power;
		power = power * base;
	}

	return num;
}