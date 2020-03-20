#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	char data;
	Node *left;
	Node *right;
};
vector<Node *> nodeList(256);

void dlr(Node *node) {
	cout << node->data;
	if (node->left != nullptr) {
		dlr(node->left);
	}
	if (node->right != nullptr) {
		dlr(node->right);
	}
}

void ldr(Node *node) {
	if (node->left != nullptr) {
		ldr(node->left);
	}
	cout << node->data;
	if (node->right != nullptr) {
		ldr(node->right);
	}
}

void lrd(Node *node) {
	if (node->left != nullptr) {
		lrd(node->left);
	}
	if (node->right != nullptr) {
		lrd(node->right);
	}
	cout << node->data;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int lineCount;
	cin >> lineCount;
	for (int i = 0; i < lineCount; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;

		if (nodeList[parent - 'A'] == nullptr) {
			nodeList[parent - 'A'] = new Node();
			nodeList[parent - 'A']->data = parent;
		}

		if (left != '.' && nodeList[left - 'A'] == nullptr) {
			nodeList[left - 'A'] = new Node();
			nodeList[left - 'A']->data = left;
			nodeList[parent - 'A']->left = nodeList[left - 'A'];
		}

		if (right != '.' && nodeList[right - 'A'] == nullptr) {
			nodeList[right - 'A'] = new Node();
			nodeList[right - 'A']->data = right;
			nodeList[parent - 'A']->right = nodeList[right - 'A'];
		}
	}

	dlr(nodeList[0]);
	cout << "\n";
	ldr(nodeList[0]);
	cout << "\n";
	lrd(nodeList[0]);

	return 0;
}
