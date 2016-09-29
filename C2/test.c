#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	localIO:freopen("io/in.txt", "r", stdin);freopen("io/out.txt", "w", stdout);
	//fileIO:freopen("test.in", "r", stdin);freopen("test.out", "w", stdout);
	int i;
	char a = 0x95, b, c;
	b = (a & 0xf) << 4;
	c = (a & 0xf0) >> 4;
	a = b | c;
	printf("%x\n", a);
	return 0;
}