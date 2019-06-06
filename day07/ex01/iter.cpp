#include <iostream>

template < typename T >
void	iter ( T *a, int len, void (*func)(T &)) {

	for (int i = 0; i < len; i++)
		func(a[i]);
}
template < typename C >
void	putChar(C & c) {
	std::cout << c << ' ';
}

int main() {

	char arr[] = {'H', 'e', 'l', 'l', 'o'};

	::iter(arr, sizeof(arr), putChar);
	std::cout << std::endl;

	int arr2[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
	::iter(arr2, 13, putChar);
	std::cout << std::endl;

	return 0;
}