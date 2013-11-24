#include <iostream>
#include <string>
using namespace std;

class TreeRecovery {
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
void TreeRecovery::reconstruct(string pre, string in) {
	int sz = pre.size();
	if (sz == 0) return;
	int p = in.find(pre[0]);
	reconstruct(pre.substr(1, p), in.substr(0, p));
	reconstruct(pre.substr(p+1, sz-p-1), in.substr(p+1, sz-p-1));
	postorder.push_back(pre[0]);
}

int main() {
	TreeRecovery tr;
	string pre, in;
	while (cin >> pre >> in) {
		tr.initial(pre, in);
		tr.work();
		tr.output();
	}
	return 0;
}
