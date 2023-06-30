#include "Stack.h"
#include <iostream>

int main()
{
	Stack<int> stack{};
	stack.clear();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.clear();

	stack.push(4);
	stack.push(5);
	stack.push(6);
	
	std::cout << "Empty: " << stack.empty() << '\n';
	std::cout << "Size: " << stack.size() << '\n';

	std::cout << '\n';

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();

	stack.clear();
	std::cout << "Empty: " << stack.empty() << '\n';
	std::cout << "Size: " << stack.size() << '\n';

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.clear();

	std::cout << "Empty: " << stack.empty() << '\n';
	std::cout << "Size: " << stack.size() << '\n';

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.clear();

	std::cout << "Empty: " << stack.empty() << '\n';
	std::cout << "Size: " << stack.size() << '\n';

	stack.clear();


	return 0;
}