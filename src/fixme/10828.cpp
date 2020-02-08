#include <iostream>
#include <stack>
#include <string>

void process(std::string command, std::stack<int> &stack) {
	if ("push" == command) {
		int input;
		std::cin >> input;
		stack.push(input);
	} else if ("pop" == command) {
		if (stack.size() == 0) {
			std::cout << "-1\n";
		} else {
			std::cout << stack.top() << "\n";
			stack.pop();
		}
	} else if ("size" == command) {
		std::cout << stack.size() << "\n";
	} else if ("empty" == command) {
		std::cout << ((stack.size() == 0) ? "1" : "0") << "\n";
	} else if ("top" == command) {
		if (stack.size() == 0) {
			std::cout << "-1";
		} else {
			std::cout << stack.top();
		}
		std::cout << "\n";
	}
}

int main(void)
{
	std::stack<int> stack;
	int count = 0;

	std::cin >> count;

	std::string command;
	for (int i = 0; i < count; i++) {
		std::cin >> command;
		process(command, stack);
	}
	
	return 0;
}