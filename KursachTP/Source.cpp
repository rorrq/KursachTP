#include "Chain_of_Responsibility.h"

using std::cout;
using std::cin;
using std::endl;


void handler_db(KeeperCar& Obj);


int main() {
	int ch;
	bool FLAG = true;
	KeeperCar salonCar, dbCar, prdCar;

	system("color f1");

	handlerSalon salon(&salonCar);
	handlerBase dataBase(&dbCar);
	handlerProduction prdctn(&prdCar);

	salon.add(&dataBase);
	dataBase.add(&prdctn);

	try {
		salonCar.load("C:/Users/Public/TP/salon.txt");
		dbCar.load("C:/Users/Public/TP/dealer.txt");
		prdCar.load("C:/Users/Public/TP/manufacture.txt");
	}
	catch (exceptions& e) {
		print_exp(e);
		return 0;
	}

	setlocale(LC_ALL, "Russian");

	std::string mode[] = {
		"������ � ��",
		"������ � �������������",
		"�����"
	};

	std::string db[] = {
		"������ � �������",
		"������ � �� ������",
		"������ � �������������",
		"�������"
	};

	std::string model;

	while (FLAG) {

		try {
			ch = menu("�������� �����: ", 3, mode);
		}
		catch (exceptions& e) {
			print_exp(e);
			continue;
		}

		switch (ch) {
		case 1:
			while (FLAG) {

				try {
					ch = menu("������� � ��� ����� ����������� ������: ", 4, db);
				}
				catch (exceptions& e) {
					print_exp(e);
					continue;
				}

				switch (ch) {
				case 1:
					handler_db(salonCar);
					break;
				case 2:
					handler_db(dbCar);
					break;
				case 3:
					handler_db(prdCar);
					break;
				case 4:
					FLAG = false;
					break;
				default:
					cout << "�������� �����." << endl;
				}
			}
			FLAG = true;
			break;
		case 2: {
			car tmpObj;
			int count;

			cout << "������� ������ ����: ";
			cin >> model;
			cout << "������� ������ ���-��: ";
			cin >> count;


			tmpObj.set_model(model);

			switch (salon.handle(tmpObj, count)) {
			case -2:
				cout << "��������, ��� �� �� ������ ������� ��� ������ ���-�� ����." << endl;
				break;
			case -1:
				cout << "��������, ��� �� �� ������ ��������� ��� ������ ����." << endl;
				break;
			case 0:
				cout << "����������� � �������� ��������!" << endl;
				break;
			case 1:
				cout << "���������� �������� �� �������..." << endl;
				break;
			}

			model.clear();
		}
			  break;
		case 3:
			FLAG = false;
			try {
				salonCar.save("C:/misha/salon.txt");
				dbCar.save("C:/misha/dealer.txt");
				prdCar.save("C:/misha/manufacture.txt");
			}
			catch (exceptions& e) {
				print_exp(e);
				FLAG = true;
			}

			break;
		default:
			cout << "�������� �����" << endl;
		}
	}





	int xxccvv;
	cin >> xxccvv;

	return 0;
}

void handler_db(KeeperCar& Obj) {
	int ch;
	bool FLAG = true;
	car carObj;
	std::string list[] = {
		"������� �� ����� ����������",
		"�������� ����",
		"������� ����",
		"�������"
	};

	while (FLAG) {

		try {
			ch = menu("�������� ����� ����: ", 4, list);
		}
		catch (exceptions& e) {
			print_exp(e);
			continue;
		}

		switch (ch) {
		case 1:
			cout << Obj;

			break;
		case 2:
			try {
				cin >> carObj;
			}
			catch (exceptions& e) {
				print_exp(e);
				break;
			}

			ch = get_dec("������� ������ ���-��: ");

			Obj.add_car(carObj, ch);

			break;
		case 3:
			try {
				cin >> carObj;
			}
			catch (exceptions& e) {
				print_exp(e);
				break;
			}

			ch = get_dec("������� ��������� ���-��(������� ���: -1): ");
			if (ch < 0) {
				ch = Obj.find_car(carObj);
				if (ch < Obj.get_size()) ch = Obj.get_amount(ch);
				else ch = 0;
			}
			try {
				Obj.sub_car(carObj, ch);
			}
			catch (exceptions& e) {
				print_exp(e);
			}
			break;
		case 4:
			FLAG = false;
			break;
		default:
			cout << "�������� �����." << endl;
		}
	}
}
