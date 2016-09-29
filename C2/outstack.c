#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int seq[11], st[11], sp;
int i, n, j;
int main() {
	//freopen("io/in.txt", "r", stdin);freopen("io/out.txt", "w", stdout);
	//fileIO:freopen("outstack.in", "r", stdin);freopen("outstack.out", "w", stdout);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	for (i = 1; i <= n; i++) {
		st[sp++] = i;
		while (sp >= 0 && j < n&& seq[j] == st[sp - 1]) { j++; sp--; }
	}
	if (sp == 0)printf("YES\n");
	else printf("NO\n");
	return 0;
}