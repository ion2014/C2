#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int primes[10000], pmax, pn;
int n, m , annotation[30010];
int sum[10000];
char buf[30000];
int main() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	annotation[0] = 1;
	annotation[1] = 1;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i <= n; i++) {
		if (!annotation[i]) {
			j = 2 * i;
			while (j <= n) {
				annotation[j] = 1;
				j += i;
			}
		}			
	}
	for (i = 0, j = 0; i <= n; i++) {
		if (!annotation[i])primes[j++] = i;
	}
	pmax = j;
	for (i = 2; i <= n; i++) {
		m = i;
		for (j = 0; j < pmax; j++) {
			while (m%primes[j] == 0) {
				m /= primes[j];
				sum[j]++;
			}
		}
	}
	int flag = 0;
	for (i = 0; i < pmax; i++) {
		if (sum >= 1) {
			if (flag)printf("*");
			flag = 1;
			printf("%d", primes[i]);
			if (sum[i] > 1)printf("^%d", sum[i]);
		}
	}
	return 0;
}