#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long long int s[] = { 2,3,5,7 };
long long int d[] = { 1,3,7,9 };
int n, pmax;
int annotation[10001];
int primes[1230];
void pre() {
	int i, j;
	annotation[0] = 1;
	annotation[1] = 1;
	for (i = 0; i < 10000; i++) {
		if (annotation[i] == 0) {
			primes[pmax++] = i;
			for (j = 2*i;j <= 10000; j+=i)
				annotation[j ] = 1;
		}
	}
}
int isprime(long long int x) {
	int i;
	for (i = 0; i<pmax&&primes[i]<x; i++)
		if (x%primes[i] == 0)return 0;
	return 1;
}
void dfs(long long int num, int step) {
	if (isprime(num)) {
		if (step == n) {
			printf("%lld\n", num); return;
		}
		int i;
		for (i = 0; i < 4; i++)
			dfs(num * 10 + d[i], step + 1);
	}
}
int main() {
	//localIO:
	//freopen("io/in.txt", "r", stdin);freopen("io/out.txt", "w", stdout);
	//fileIO:freopen("nprime.in", "r", stdin);freopen("nprime.out", "w", stdout);
	int i;
	scanf("%d", &n);
	pre();
	for (i = 0; i < 4; i++)
		dfs(s[i], 1);
	return 0;
}