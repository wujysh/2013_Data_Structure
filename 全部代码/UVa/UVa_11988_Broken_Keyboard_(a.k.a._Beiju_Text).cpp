#include <cstdio>
#include <list>
using namespace std;

int main() {
	char ch;
	list <char> strlist;
	list <char>::iterator iter = strlist.begin();
	while (~(ch = getchar())) {
		if (ch == '[')  // home
			iter = strlist.begin();
		else if (ch == ']')  // end
			iter = strlist.end();
		else if (ch == '\n') {  // output
			for (iter = strlist.begin(); iter != strlist.end(); iter++)
				printf("%c", *iter);
			printf("\n");
			strlist.clear();
			iter = strlist.begin();
		}
		else  // normal input
			strlist.insert(iter, ch);
	}
	return 0;
}