#include <iostream>
#include "Mutantstack.hpp"

int main() {

	MutantStack<int> mstack;
	std::stack<int> stack;

	mstack.push(5);
	mstack.push(17);

	stack.push(5);
	stack.push(17);

	std::cout << mstack.top() << " | " << stack.top() << std::endl;

	mstack.pop();
	stack.pop(); // deleting '17'

	std::cout << mstack.size() << " | " << stack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator iter = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	++iter;
	--iter;

	while (iter != end)
	{
		std::cout << *iter << std::endl;
		++iter;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	MutantStack<int> newStack(mstack);
	iter = newStack.begin();
	end = newStack.end();

	++iter;
	--iter;

	while (iter != end)
	{
		std::cout << *iter << std::endl;
		++iter;
	}
	return 0;
}