#include "stack0.0.1.hpp"
#include <stdlib.h>
#include <string>

int main()
{
	stack<int> stack_;
	std::string str;
	unsigned int i = 0;

	std::cout << "Add an element: +<Element>\nShow the last element: ?\nPop the last element: -\nShow the stack: =\n\n";
	std::getline(std::cin, str);

	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '+':
		{
					if (str[i + 1] == ' ' || str[i + 1] == '\0')
						std::cout << "An error has occurred while reading arguments\n";
					else
					{
						stack_.push(stoi(str.substr(i + 1)));
					}
					break;
		}
		case '?':
		{
					std::cout << stack_.last();
					std::cout << std::endl;
					break;
		}
		case '-':
		{
					stack_.pop();
					break;
		}
		case '=':
		{
					stack_.print();
					break;
		}
		defoult: break;
		}
		i++;
	}
  
	return 0;
}
