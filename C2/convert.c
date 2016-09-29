#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[4000];
struct node{
	char type;
	struct node	*l, *r;
	int s, e;
};
struct node nodes[1000];
int	stack[100];
int top = 0, sp = 0;
void getNextElement(int s,int len) {
	if ((len != 1) || (str[s] >= '0'&&str[s] <= '9')) {
		nodes[top].type = str[s] == '-' ? 'c' : 'n';
		nodes[top].l = nodes[top].r = NULL;
		nodes[top].s = s; nodes[top].e = s + len;
	}
	else {
		nodes[top].r = &nodes[stack[--sp]];
		nodes[top].l = &nodes[stack[--sp]];
		nodes[top].type = str[s];	
	}
	stack[sp++] = top++;
}
void treePrint(struct node* p,int isP) {
	int i;
	if (p == NULL)return;
	if (isP)printf("(");
	if (p->type == 'n' || p->type == 'c') {
		for (i = p->s; i < p->e; i++)
			printf("%c", str[i]);
	}
	else {
		int lc, rc;
		switch (p->type)
		{
		case('+'):
			lc = p->l->type == 'c';
			rc = p->r->type == 'c';
			break;
		case('-'):
			lc = p->l->type == 'c';
			rc = p->r->type == '+' || p->r->type == '-' || p->r->type == 'c';
			break;
		case('*'):
			lc = p->l->type == '+' || p->l->type == '-' || p->l->type == 'c';
			rc = p->r->type == '+' || p->r->type == '-' || p->r->type == 'c';
			break;
		case('/'):
			lc = p->l->type == '+' || p->l->type == '-' || p->l->type == 'c';
			rc = p->r->type == '+' || p->r->type == '-' || p->r->type == 'c' || p->r->type == '/';
		}
		treePrint(p->l, lc);
		printf("%c", p->type);
		treePrint(p->r, rc);
	}
	if (isP)printf(")");
}
int main() {
	localIO:freopen("io/in.txt", "r", stdin);freopen("io/out.txt", "w", stdout);
	//fileIO:freopen("convert.in", "r", stdin);freopen("convert.out", "w", stdout);
	int i = 0, len;
	char* now = str;
	while (scanf("%s", now) != EOF) {
		i = strlen(now);
		getNextElement(now - str, i);
		now += i + 1;
	}
	treePrint(&nodes[stack[0]],0);
	printf("\n");
	return 0;
}