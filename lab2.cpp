#include <bits/stdc++.h>
using namespace std;

int a[6][6] = {{1,0,0,0,1,1},
			   {1,1,0,0,1,1},
			   {1,1,-1,-1,1,1},
			   {0,0,0,0,2,-1},
			   {1,1,-1,-1,1,1},
			   {0,0,0,0,-1,-1}};
char s[1002], l[1000];
int i, j;

int cmp(char i, char j) {
	int x = 0,y = 0;
	switch (i) {
		case '+':x=0;break;
		case '*':x=1;break;
		case 'i':x=2;break;
		case '(':x=3;break;
		case ')':x=4;break;
		case '#':x=5;break;
		default:x=7;
	}
	switch (j) {
		case '+':y=0;break;
		case '*':y=1;break;
		case 'i':y=2;break;
		case '(':y=3;break;
		case ')':y=4;break;
		case '#':y=5;break;
		default:y=7;
	}
	if(x >= 0 && x <= 6 && y >= 0 && y <= 6)
		return a[x][y];
	else
		return -1;
}

int main() {
	s[0] = '#';
	while(scanf("%s", &l) != EOF) {
		s[0] = '#';
		while(true) {
//			printf("l:%s\n", l);
//			printf("s:%s\n", s);
			if(l[j] == '\r' && l[j+1] == '\n' && s[i] != '#') {
				l[j] = '#';
				continue;
			}
			else if(l[j] == '#' && l[j+1] == '\n' && s[i] != '#') {
				printf("RE\n");
				break;
			}
			else if(cmp(s[i], l[j]) == 0 || cmp(s[i], l[j]) == 2) {
				printf("I%c\n", l[j]);
				i++;
				s[i] = l[j];
				j++;
			}
			else if(cmp(s[i], l[j]) == 1) {
				printf("R\n");
				i--;
			}
			else if(cmp(s[i], l[j]) == -1) {
				printf("E\n");
				break;
			}
		}
		memset(l, 0, sizeof(l));
		memset(s, 0, sizeof(s));
	}
	return 0;
} 
