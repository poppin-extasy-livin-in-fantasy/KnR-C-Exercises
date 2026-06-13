#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);
int reverse(char s[], int len);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}
	return 0;
}

/* read line into s, return length */
int getline(char s[], int lim) {
	int c, i;
	c = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy from[] into to[] */
void copy(char to[], char from[]) {
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}

/* reverse string in place, excluding newline */
int reverse(char s[], int len) {
	int bt, i, lenght;
	bt = i = 0;
	lenght = len - 2;

	for (i = 0; i < lenght; ++i, --lenght) {
		bt = s[i];
		s[i] = s[lenght];
		s[lenght] = bt;
	}
}