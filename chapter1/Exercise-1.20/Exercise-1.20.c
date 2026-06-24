#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 8

int main() {
	char line[MAXLINE];
	while (detab(line, MAXLINE) > 0)
		printf("%s", line);
}

/* detab: replace tab characters with spaces up to the next tab stop (every 8 columns) */
int detab(char s[], int lim) {
	int spaces = 0;
	int c = 0;
	int col = 0;
	int i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF) {
		if (c == '\t') {
			spaces = TAB_WIDTH - (col % TAB_WIDTH);
			if (i + spaces >= lim - 1) {
				s[i] = '\0';
				return i;
			}
			else
			{
				for (int j = 0; j < spaces; ++j) {
					s[i++] = ' ';
					col++;
				}
			}
		}

		else if (c == '\n') {
			if (i < lim - 1) {
				s[i++] = c;
				col = 0;
				break;
			}
		}
		else if (c != '\t') {
			s[i++] = c;
			col++;
		}

	}
	s[i] = '\0';
	return i;
}