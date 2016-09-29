#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long long int f[10000][2];//{总量:新出生}
int main() {
	//localIO:
	//freopen("io/in.txt", "r", stdin);freopen("io/out.txt", "w", stdout);
	//fileIO:freopen("cows.in", "r", stdin);freopen("cows.out", "w", stdout);
	int i, x;
	int n, m, p, k, sum = 0;
	scanf("%d%d%d%d", &m, &n, &p, &k);
	long long int nb = 0, dt = 0;
	f[0][1] = 1;
	f[0][0] = 1;
	for (i = 1; i <= k; i++) {
		nb += i >= m ? f[i - m][0] : 0;
		nb -= i > n ? f[i - n - 1][0] : 0;
		dt = i >= p ? f[i - p][0] : 0;
		f[i][0] = nb;
		f[i][1] = f[i - 1][1] + nb - dt;
	}	printf("%lld\n", f[k][1]);
	return 0;
}