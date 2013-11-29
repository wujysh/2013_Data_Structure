#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>

const int MAXN = 1000003;

char word[120000][50];
int head[MAXN], next[MAXN], num;

int hash(char s[]) {
	int v = 0;
	for (unsigned i = 0; i < strlen(s); i++) {
		v = v * 3 + (s[i] - 'a' + 1);
		v %= MAXN;
	}
	return v % MAXN;
}

void Insert(char s[], int i) {
	int h, u;
	h = hash(s);
	u = head[h];
	while (u) {
		u = next[u];
	}
	next[i] = head[h];
	head[h] = i;
}
int isExist(char s[]) {
	int h, u;
	h = hash(s);
	u = head[h];
	if (!strcmp(s, word[u])) return u;
	while (u) {
		if (!strcmp(s, word[u])) return u;
		u = next[u];
	}
	return -1;
}

int main() {
	int cnt = 0, flag;
	char tmp[100];
	while (gets(word[cnt]) != NULL) {
		Insert(word[cnt], cnt);
		cnt++;
	}
	num = cnt;
	for (int i = 0; i < num; i++) {
		if (word[i][1]) {
			for (unsigned j = 0; j < strlen(word[i]) - 1; j++) {
				strcpy(tmp, word[i]);
				tmp[j + 1] = '\0';
				if (isExist(tmp) != -1 && isExist(word[i] + j + 1) != -1) {
					printf("%s\n", word[i]);
					break;
				}
			}
		}
	}
	return 0;
}
