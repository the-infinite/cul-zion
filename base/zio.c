#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

#include <utils.h>
#include <zio.h>

char* lmc_readFile(char* filename) {
	FILE* file;

	/// @brief A single line of text read from the file.
	char* line = NULL;
	size_t read = 0; // The number of bytes we have read so far.

	file = fopen(filename, "rb");

	if(file == NULL) { // If we could not parse the file.
		lmc_flagFile(filename);
		lmc_printError("Unable to read the file specified");
	}

	/// @brief The buffer we would store the characters from the file inside.
	char* buffer = calloc(1, sizeof(char));
	buffer[0] = '\0'; // The tail of the string.

	while((read = getline(&line, &read, file)) != -1) {
		buffer = (char*) realloc(buffer, (strlen(buffer) + strlen(line) + 1) * sizeof(char));
		strcat(buffer, line);
	}

	// If this pointer is still allocated.
	fclose(file);
	if(line) {
		free(line);
	}

	return buffer;
}