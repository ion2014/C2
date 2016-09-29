#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define isSgn(a) ((a)=='+'||(a)=='-')
#define isDig(a) ((a)>='0'&&(a)<='9')
#define isEnd(a) ((a)=='\0')
#define isExp(a) ((a)=='E'||(a)=='e')
#define isDot(a) ((a)=='.')
char buf[40];
int flag;
int fsm(char *c, int stat,int optionalSgn) {
	if (isSgn(*c))	return optionalSgn == 1 ? fsm(++c, stat, 0) : 0;
	switch (stat)
	{
	case(0):
		if (isDig(*c))	return *c == '0' ? fsm(++c, 2, 0) : fsm(++c, 1, 0);
		break;
	case(1):
		while (isDig(*c))	c++;
	case(2):
		if (isEnd(*c))	return 1;
		if (isDot(*c))	return fsm(++c, 3, 0);
		if (isExp(*c))	return fsm(++c, 4, 1);
		break;
	case(3):
		if (isDig(*c)) {
			while (isDig(*c))c++;
			if (isEnd(*c))	return 1;
			if (isExp(*c))	return fsm(++c, 4, 1);
		}
		break;
	case(4):
		if (isDig(*c)) {
			while (isDig(*c))c++;
			if (isEnd(*c))	return 2;
		}
		break;
	}				  
	return 0;
}
int main() {
	freopen("real.in", "r", stdin);
	freopen("real.out", "w", stdout);
	while (scanf("%s", buf)!=EOF) {
		
		switch (fsm(buf, 0, 0)) {
		case(1):printf("Format1\n"); break;
		case(2):printf("Format2\n"); break;
		default:printf("Wrong\n");
		}
	}
	
	return 0;
}