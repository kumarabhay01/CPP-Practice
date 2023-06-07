#include <iostream>
#include "Math.h"

int main() {
	int x, y;
	std::cin >> x >> y;
	//int result = x + y;
	//std::cout << "Result is: " << result << std::endl;

	int result = Add(x, y);
}

//int Add(int x, int y) {
//	int sum = x + y;
//	std::cout << "Sum is : " << sum << std::endl;
//	return sum;
//}