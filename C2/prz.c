#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define cmp(a,b) ((a).l!=(b).l?((a).l>(b).l):((a).r<=(b).r)) 
struct sec {
	int l, r;
};
struct sec arr[50010];
void swap(struct sec *a,struct sec* b){
	int c1 = a->l, c2 = a->r;
	a->l = b->l; b->l = c1;
	a->r = b->r; b->r = c2;
}
int partition(int left,int right) {
	int l = left, r = right;
	while (l < r) {
		while (r > l&& cmp(arr[r],arr[left])) r--;
		//swap(&arr[l], &arr[r]);
		while (r > l&& cmp(arr[left], arr[l])) l++;
		swap(&arr[l], &arr[r]);
	}
	swap(&arr[left], &arr[l]);
	return l;
}
void sort(int l,int r) {
	if (l < r) {
		int mid = partition(l, r);
		sort(l, mid - 1);
		sort(mid + 1, r);
	}
}
int main() {
	freopen("prz.in", "r", stdin);
	freopen("prz.out", "w", stdout);
	int n = 0, i, l, r, m;
	while (scanf("%d%d", &l, &r) != EOF) {
		arr[n].l = l > r ? r : l;
		arr[n].r = l < r ? r : l;
		n++;
	}
	sort(0, n - 1);
	int left = arr[0].l, right = arr[0].r;
	int flag = 0;
	for (i = 0; i < n; i++) {
		if (arr[i].l > right) {
			printf("%d %d\n", left, right);
			left = arr[i].l;
			right = arr[i].r;
		}
		else if (arr[i].r > right) right = arr[i].r;
	}
	printf("%d %d\n", left, right);
	return 0;
}