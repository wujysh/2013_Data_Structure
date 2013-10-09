#include <iostream>
#include <string>
using namespace std;

class PreInandPost {
private:
	string preorder, inorder, postorder;
public:
	void initial(string pre, string in) {
		preorder = pre;
		inorder = in;
		postorder.clear();
	}
	void work() {reconstruct(preorder, inorder);}
	void output() {cout << postorder << endl;}
	void reconstruct(string pre, string in);
};
void PreInandPost::reconstruct(string pre, string in) {
	int sz = pre.size();
	if (sz == 0) return;
	int p = in.find(pre[0]);
	reconstruct(pre.substr(1, p), in.substr(0, p));
	reconstruct(pre.substr(p+1, sz-p-1), in.substr(p+1, sz-p-1));
	postorder.push_back(pre[0]);
}

int main() {
	PreInandPost pip;
	string pre, in;
	int n, c;
	cin >> n;
	while (n--) {
		cin >> c >> pre >> in;
		pip.initial(pre, in);
		pip.work();
		pip.output();
	}
	return 0;
}
