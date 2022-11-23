#include <iostream>
int main()
{
	std::cout << "整数値を入力してください。\n";
	std::cout << "整数値: ";
	int n;
	if (std::cin >> n) {
		std::cout << "入力された値は " << n << " でした。\n";
	}
	else {
		std::cout << "正しく入力されませんでした。\n";
	}
	return 0;
}
