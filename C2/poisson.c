#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main() {
	//localIO:
	//freopen("io/in.txt", "r", stdin);freopen("io/out.txt", "w", stdout);
	//fileIO:
	freopen("poisson.in", "r", stdin);freopen("poisson.out", "w", stdout);
	int i;
	int m, k, t;
	scanf("%d%d", &m, &k);
	t = m;
	double ans = 1;
	double ee = exp(1);
	double lim = 1e10;
	for (i = 1; i <= max(m,k); i++) {	
		if (i <= k) {
			ans /= i;
			ans *= m;
		}
		while (ans > lim&&t > 0) {
			ans /= ee;
			t--;
		}
	}
	while (t) {
		ans /= ee;
		t--;
	}
	printf("%.6e\n", ans);
	return 0;
}