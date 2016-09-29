#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int mat[11][11];
int n;
int f[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
void printnext(int num, int x, int y,int dx) {
	mat[x][y] = num;
	if (num != n*n) {
		if (mat[x + f[dx][0]][y + f[dx][1]] != 0)
			dx = (dx + 1) % 4;
		printnext(num + 1 , x + f[dx][0], y + f[dx][1], dx);
	}
}
int main() {
	scanf("%d",&n);
	int i, j;
	for (i = 0; i < n + 1; i++) {
		mat[i][0] = 1;
		mat[0][i] = 1;
		mat[i][n + 1] = 1;
		mat[n + 1][i] = 1;
	}
	printnext(1, 1, 1, 0);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}
	return 0;
}