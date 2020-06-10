#include "car.h"

using std::cout;

car::car() :
	year(0), airbags(0), capacity(0.0),
	power(0.0), fuelTank(0.0), fuelCons(0.0),
	rdrHeat(false), gearBox(false), ABS(false),
	EDS(false), sysNav(false), computer(false),
	seatHead(false), roofRack(false), x(0.0),
	y(0.0), z(0.0) {}

car& car::operator=(const car& Obj) {
	model = Obj.model;
	color = Obj.color;
	year = Obj.year;
	airbags = Obj.airbags;
	capacity = Obj.capacity;
	power = Obj.power;
	fuelTank = Obj.fuelTank;
	fuelCons = Obj.fuelCons;
	rdrHeat = Obj.rdrHeat;
	gearBox = Obj.gearBox;
	ABS = Obj.ABS;
	EDS = Obj.EDS;
	sysNav = Obj.sysNav;
	computer = Obj.computer;
	seatHead = Obj.seatHead;
	roofRack = Obj.roofRack;
	x = Obj.x;
	y = Obj.y;
	z = Obj.z;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const car& Obj) {
	int width_one = 37;
	int width_two = 10;


	os.width(width_one);
	os << "������: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.model;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "����: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.color;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "����� ���������(� ������): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.capacity;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "���-�� ������� ������������: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.airbags;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "��� �������: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.year;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "�������� ��������� � ���: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.power;
	os.unsetf(std::ios::left);
	os << std::endl;


	os.width(width_one);
	os << "����� ���������� ����(� ������): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.fuelTank;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "������ ������� �� 100��: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.fuelCons;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "�������� ����: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.rdrHeat ? "����" : "���");
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "���� ��� ����: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.gearBox ? "����" : "����");
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "ABS: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.ABS ? "����" : "���");
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "EDS: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.EDS ? "����" : "���");
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "������� ���������: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.sysNav ? "����" : "���");
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "�������� ���������: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.computer ? "����" : "���");
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "�������� �������: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.seatHead ? "����" : "���");
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "�������� �� �����: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << (Obj.roofRack ? "����" : "���");
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "�����(� ������): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.x;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "������(� ������): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.y;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "������(� ������): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << Obj.z;
	os.unsetf(std::ios::left);
	os << std::endl;

	os << std::endl;

	return os;
}
std::ofstream& operator<<(std::ofstream& ofs, const car& Obj) {
	ofs << Obj.model << ';';
	ofs << Obj.color << ';';
	ofs << Obj.year << ';';
	ofs << Obj.airbags << ';';
	ofs << Obj.capacity << ';';
	ofs << Obj.power << ';';
	ofs << Obj.fuelTank << ';';
	ofs << Obj.fuelCons << ';';
	ofs << Obj.rdrHeat << ';';
	ofs << Obj.gearBox << ';';
	ofs << Obj.ABS << ';';
	ofs << Obj.EDS << ';';
	ofs << Obj.sysNav << ';';
	ofs << Obj.computer << ';';
	ofs << Obj.seatHead << ';';
	ofs << Obj.roofRack << ';';
	ofs << Obj.x << ';';
	ofs << Obj.y << ';';
	ofs << Obj.z << ';';

	return  ofs;
}

std::istream& operator>>(std::istream& is, car& Obj) {

	cout << "������� ������: ";
	is >> Obj.model;

	cout << "������� ����: ";
	is >> Obj.color;

	cout << "������� ��� �������: ";
	is >> Obj.year;

	if (Obj.year < 1885)
		throw exceptions("��� ������� �� ����� ���� ������ ���� �������� ������ ������!");

	cout << "������� ���-�� ������� ������������: ";
	is >> Obj.airbags;

	if (Obj.airbags > 12)
		throw exceptions("���-�� ������� ��������� ������������ ������������!");

	cout << "������� ����� ��������� � ������: ";
	is >> Obj.capacity;

	if (Obj.capacity > 8.4)
		throw exceptions("����� ��������� ��������� ����������� ���������!");

	cout << "������� �������� ��������� � ���: ";
	is >> Obj.power;

	cout << "������� ����� ���������� ����(� ������): ";
	is >> Obj.fuelTank;

	cout << "������� ������ ������� �� 100��(� ������): ";
	is >> Obj.fuelCons;

	cout << "�������� ����(1 - yes/0 - no): ";
	is >> Obj.rdrHeat;

	cout << "���� ��� ����(1 - ����/0 - ����): ";
	is >> Obj.gearBox;

	cout << "ABS(1 - yes/0 - no): ";
	is >> Obj.ABS;

	cout << "EDS(1 - yes/0 - no): ";
	is >> Obj.EDS;

	cout << "������� ���������(1 - yes/0 - no): ";
	is >> Obj.sysNav;

	cout << "�������� ���������(1 - yes/0 - no): ";
	is >> Obj.computer;

	cout << "�������� �������(1 - yes/0 - no): ";
	is >> Obj.seatHead;

	cout << "�������� �� �����(1 - yes/0 - no): ";
	is >> Obj.roofRack;

	cout << "������� ����� � ������: ";
	is >> Obj.x;

	cout << "������� ������ � ������: ";
	is >> Obj.y;

	cout << "������� ������ � ������: ";
	is >> Obj.z;

	cout << std::endl;

	return is;
}
std::ifstream& operator>>(std::ifstream& ifs, car& Obj) {
	std::string tmp;
	std::getline(ifs, Obj.model, ';');

	std::getline(ifs, Obj.color, ';');

	std::getline(ifs, tmp, ';');
	Obj.year = atoi(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.airbags = atoi(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.capacity = atof(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.power = atof(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.fuelTank = atof(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.fuelCons = atof(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.rdrHeat = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.gearBox = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.ABS = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.EDS = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.sysNav = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.computer = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.seatHead = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.roofRack = static_cast<bool>(atoi(tmp.c_str()));

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.x = atof(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.y = atof(tmp.c_str());

	tmp.clear();
	std::getline(ifs, tmp, ';');
	Obj.z = atof(tmp.c_str());


	return  ifs;
}

bool operator==(const car& Obj1, const car& Obj2) {
	if (Obj1.model != Obj2.model) return false;
	if (Obj1.color != Obj2.color) return false;
	if (Obj1.year != Obj2.year) return false;
	if (Obj1.airbags != Obj2.airbags) return false;
	if (Obj1.capacity != Obj2.capacity) return false;
	if (Obj1.power != Obj2.power) return false;
	if (Obj1.fuelTank != Obj2.fuelTank) return false;
	if (Obj1.fuelCons != Obj2.fuelCons) return false;
	if (Obj1.rdrHeat != Obj2.rdrHeat) return false;
	if (Obj1.gearBox != Obj2.gearBox) return false;
	if (Obj1.ABS != Obj2.ABS) return false;
	if (Obj1.EDS != Obj2.EDS) return false;
	if (Obj1.sysNav != Obj2.sysNav) return false;
	if (Obj1.computer != Obj2.computer) return false;
	if (Obj1.seatHead != Obj2.seatHead) return false;
	if (Obj1.roofRack != Obj2.roofRack) return false;
	if (Obj1.x != Obj2.x) return false;
	if (Obj1.y != Obj2.y) return false;
	if (Obj1.z != Obj2.z) return false;

	return true;
}
bool car::check(const std::string& model) const {
	return this->model == model;
}

void move(car& Obj1, car& Obj2) {
	Obj1.model = std::move(Obj2.model);
	Obj1.color = std::move(Obj2.color);
	Obj1.year = std::move(Obj2.year);
	Obj1.airbags = std::move(Obj2.airbags);
	Obj1.capacity = std::move(Obj2.capacity);
	Obj1.power = std::move(Obj2.power);
	Obj1.fuelTank = std::move(Obj2.fuelTank);
	Obj1.fuelCons = std::move(Obj2.fuelCons);
	Obj1.rdrHeat = std::move(Obj2.rdrHeat);
	Obj1.gearBox = std::move(Obj2.gearBox);
	Obj1.ABS = std::move(Obj2.ABS);
	Obj1.EDS = std::move(Obj2.EDS);
	Obj1.sysNav = std::move(Obj2.sysNav);
	Obj1.computer = std::move(Obj2.computer);
	Obj1.seatHead = std::move(Obj2.seatHead);
	Obj1.roofRack = std::move(Obj2.roofRack);
	Obj1.x = std::move(Obj2.x);
	Obj1.y = std::move(Obj2.y);
	Obj1.z = std::move(Obj2.z);
}

const std::string& car::get_model() const {
	return model;
}
const std::string& car::get_color() const {
	return color;
}

void car::set_model(const std::string model) {
	this->model = model;
}


bool car::is_pattern() const {
	return !year;
}
