#include "KeeperCar.h"


KeeperCar::KeeperCar() {
	mas = new car[PH];
	amount = new int[PH]();
	size = 0;
	reserve = PH;
}
KeeperCar::KeeperCar(const KeeperCar& Obj) {
	reserve = Obj.reserve;
	mas = new car[reserve];
	amount = new int[reserve]();
	for (size = 0; size < Obj.size; ++size) {
		mas[size] = Obj.mas[size];
		amount[size] = Obj.amount[size];
	}
}
KeeperCar::KeeperCar(KeeperCar&& Obj) {
	reserve = Obj.reserve;
	mas = new car[reserve];
	amount = new int[reserve]();
	for (size = 0; size < Obj.size; ++size) {
		move(mas[size], Obj.mas[size]);
		amount[size] = std::move(Obj.amount[size]);
	}
}
car& KeeperCar::operator[](int i) const {
	if (i >= size)
		throw exceptions("Выход за пределы!");
	return mas[i];
}
int KeeperCar::get_size() const {
	return size;
}
int KeeperCar::get_amount(int num) const {
	if (num >= size)
		throw exceptions("Выход за пределы!");
	return amount[num];
}
void KeeperCar::add_car(const car& Obj, int count) {
	int tmp;
	if ((tmp = find_car(Obj)) == size) {
		if (size == reserve)
			add_reserve();
		mas[size] = Obj;
		amount[size++] += count;
	}
	else amount[tmp] += count;
}
void KeeperCar::sub_car(const car& Obj, int count) {
	int tmp;
	if ((tmp = find_car(Obj)) < size) {
		if (count > amount[tmp])
			throw exceptions("Выход за пределы!");
		amount[tmp] -= count;
		if (!amount[tmp]) {
			--size;
			for (int i = tmp; i < size; ++i) {
				amount[i] = amount[i + 1];
				move(mas[i], mas[i + 1]);
			}
		}
	}
	else
		throw exceptions("Авто не найдено!");
}
int KeeperCar::find_car(const car& Obj) {
	int i;
	for (i = 0; i < size; ++i) {
		if (Obj == mas[i])
			break;
	}
	return i;
}
void KeeperCar::load(const std::string&& str) {
	std::ifstream in(str);
	car tmpCar;
	std::string tmpStr;

	if (!in.is_open())
		throw exceptions("Файл \"" + str + "\" не был открыт!");

	while (in.get() != EOF) {
		in.unget();
		in >> tmpCar;
		std::getline(in, tmpStr, ';');
		amount[size] = atoi(tmpStr.c_str());
		in.get();
		move(mas[size++], tmpCar);
		if (size == reserve)
			add_reserve();
	}

	in.close();
}
void KeeperCar::save(const std::string&& str) {
	std::ofstream out(str);

	if (!out.is_open())
		throw exceptions("Файл \"" + str + "\" не был открыт!");

	for (int i = 0; i < size; ++i) {
		out << mas[i] << amount[i] << ';';
		out << std::endl;
	}
	out.close();
}
void KeeperCar::add_reserve() {
	reserve += PH;
	mas = realloc(mas, size, reserve);
	amount = realloc(amount, size, reserve);
}
KeeperCar KeeperCar::sim_car(const car& ObjCar) const {
	int i;
	KeeperCar tmp;
	for (i = 0; i < size; ++i)
		if (mas[i].check(ObjCar.get_model())) {
			tmp.add_car(mas[i], amount[i]);
		}
	return tmp;
}
std::ostream& operator<<(std::ostream& os, const KeeperCar& Obj) {
	for (int i = 0; i < Obj.size; ++i) {
		os << '|' << i + 1 << '|' << "\tКол-во: " << Obj.amount[i];
		os << std::endl;
		os << Obj.mas[i];
		os << std::endl;
	}
	return os;
}
KeeperCar::~KeeperCar() {
	delete[] mas;
	delete[] amount;
}
