#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#define min(a,b) ((a)<(b)?(a):(b))
long long c[1000005];
long long ans;
int main() {
	//freopen("nickle.in", "r", stdin);
	//freopen("nickle.out", "w", stdout);
	c[0] = 1;
	long long n; 
	long long t;
	int j, nickle[3] = { 1,2,5 };
	scanf("%lld", &n);
	t = 500 * n*n + 40 * n + 1;
	printf("%lld", t);
	return 0;
}
