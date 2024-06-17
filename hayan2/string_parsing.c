#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: Destructively modifies its argument
void parse(char* str) {
	static const char* ws = " \t"; // Whitespace characters that separate tokens
	char* command = str;

	// Find the end of the first word
	str += strcspn(str, ws);
	if (*str) {
		*str++ = 0; // Terminate command
	}
	printf("Command: %s\n", command);

	while (*str) {
		// Skip leading whitespace
		str += strspn(str, ws);
		if (!*str) {
			// That was actually trailing whitespace at the end of the string
			break;
		}

		// Split at = sign
		char* option = str;
		str = strchr(str, '=');
		if (!str) {
			fputs("Missing = after option!\n", stderr);
			exit(EXIT_FAILURE);
		}
		*str++ = 0; // Terminate option

		// Parse the numeric argument
		char* valstr = str;
		double val = strtod(valstr, &str);
		if (valstr == str || !strchr(ws, *str)) {
			fprintf(stderr, "Non-numeric argument to %s!\n", option);
			exit(EXIT_FAILURE);
		}

		printf(" Option %s, value %f\n", option, val);
	}
}

int main(void) {
	char command_string[] = "set_speed M1=10 M2=20";
	parse(command_string);

	return 0;
}