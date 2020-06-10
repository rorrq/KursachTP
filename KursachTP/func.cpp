#include "func.h"


int get_dec(std::string&& str) {
	int tmp;
	std::cout << str;
	std::cin >> tmp;
	std::cin.get();
	return tmp;
}
int menu(std::string invite, int amount, const std::string* str) {
	int i = 0;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << std::endl;
	std::cout.setf(std::ios::left);
	for (i = 0; i < amount; ++i) {
		if (!((i + 1) % 5)) std::cout << std::endl;
		std::cout << i + 1 << ". ";
		std::cout.width(30);
		std::cout << str[i];
	}
	std::cout.unsetf(std::ios::left);
	std::cout << std::endl << std::endl;
	std::cout << invite;
	std::cin >> i;
	std::cin.get();
	if (i < 1 || i > amount)
		throw exceptions("Пункт меню выбран неверно");
	return i;
}
void print_exp(const exceptions& e) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, ((WORD)15 << 4) | (WORD)4);
	std::cout << "Ошибка: " << e.what() << std::endl;
	SetConsoleTextAttribute(hStdout, ((WORD)15 << 4) | (WORD)0);
}
