#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void strrvs(char* s1,int n) {
	int i;
	char tmp;
	for (i = 0; i < n >>1; i++) {
		tmp = s1[i];
		s1[i] = s1[n - 1 - i];
		s1[n - 1 - i] = tmp;
	}
}
char ss[100], sub[100];
int main()
{	
	freopen("invertsub.in", "r", stdin);
	freopen("invertsub.out", "w", stdout);
	char tmp, newline;
	char *rvs;
	int len1 = 0, len2 = 0, i, j = 0;
	while (scanf("%c", &tmp) != EOF) {
		if (tmp == '\n' || tmp == '\r') { ss[len1] = '\0'; break; }
		else ss[len1++] = tmp;
	}
	while (scanf("%c", &tmp) != EOF) {
		if (tmp == '\n' || tmp == '\r') { sub[len2] = '\0'; break; }
		else sub[len2++] = tmp;
	}
	for (i = 0; i < len1; i++) {
		while (sub[j] != '\0'&&ss[i + j] == sub[j])j++;
		if (j == len2)break;
		j = 0;
	}
	strrvs(&ss[i], len2);
	printf("%s\n", ss);
	return 0;
}