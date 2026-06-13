#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
		printf("%s", line);
	return 0;
}

/* getline: read line into s, return length */
int getline(char s[], int lim) {
	int c, i, prev;
	c = prev = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		if ((c == ' ' || c == '\t') && (prev == ' ' || prev == '\t')) {
			--i; /* skip duplicate whitespace */
		}
		else
			s[i] = (c == '\t') ? ' ' : c; /* replace tab with space */
		prev = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy from[] into to[] */
void copy(char to[], char from[]) {
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}