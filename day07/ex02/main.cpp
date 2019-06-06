#include "Array.hpp"
#include <ctime>

int main() {

	srand(time(NULL));

	try {
		Array<int> arr(5);
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = rand() % 100;
			std::cout << ' ' << arr.operator[](i);
		}
		std::cout << std::endl;

		Array<char> arrChar(8);
		for (int i = 0; i < arrChar.size(); i++) {
			arrChar[i] = (rand() % 100 + 26);
			std::cout << ' ' << arrChar.operator[](i);
		}
		std::cout << std::endl;

		Array <int> arrCopy(500);
		arrCopy = arr;
		for (int i = 0; i < arr.size(); i++) {
			std::cout << ' ' << arr.operator[](i);
		}
	}
	catch (std::exception &e)
	{
		std::cout << " Error: bad access: " << e.what() << std::endl;
	}
	return 0;
}
