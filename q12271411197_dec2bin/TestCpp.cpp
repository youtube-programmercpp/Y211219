#include <iostream>
int main()
{
	std::cout << "�����l����͂��Ă��������B\n";
	std::cout << "�����l: ";
	int n;
	if (std::cin >> n) {
		std::cout << "���͂��ꂽ�l�� " << n << " �ł����B\n";
	}
	else {
		std::cout << "���������͂���܂���ł����B\n";
	}
	return 0;
}
