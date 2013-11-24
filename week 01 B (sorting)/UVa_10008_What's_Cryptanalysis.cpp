#include <cstdio>
#include <cstdlib>
using namespace std;

struct node { 
	int x;
	int y;
} count[26]; 

int cmp(const void *a, const void *b) 
{ 
	struct node *c = (node *)a; 
	struct node *d = (node *)b; 
	if (c->y != d->y)
		return d->y - c->y; 
	else
		return c->x - d->x; 
} 

int main()
{
	int n;
	char str[200];
	scanf_s("%d", &n);  getchar();
	for (int i = 0; i < 26; i++) {
		count[i].x = i;
		count[i].y = 0;
	}
	for (int i = 0; i < n; i++) {
		gets_s(str);
		int j = 0;
		while (str[j] != '\0') {
			if (str[j] >= 'a' && str[j] <= 'z')
				count[str[j]-'a'].y++;
			if (str[j] >= 'A' && str[j] <= 'Z')
				count[str[j]-'A'].y++;
			j++;
		}
	}
	qsort(count, 26, sizeof(count[0]), cmp);
	for (int i = 0; i < 26; i++)
		if (count[i].y > 0)
			printf("%c %d\n", count[i].x+'A', count[i].y);
	return 0;
}