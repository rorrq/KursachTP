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
		"Работа с БД",
		"Работа с пользователем",
		"Выход"
	};

	std::string db[] = {
		"Работа с Салоном",
		"Работа с БД дилера",
		"Работа с Производством",
		"Возврат"
	};

	std::string model;

	while (FLAG) {

		try {
			ch = menu("Выберите режим: ", 3, mode);
		}
		catch (exceptions& e) {
			print_exp(e);
			continue;
		}

		switch (ch) {
		case 1:
			while (FLAG) {

				try {
					ch = menu("Введите с чем будет происходить работа: ", 4, db);
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
					cout << "Неверный выбор." << endl;
				}
			}
			FLAG = true;
			break;
		case 2: {
			car tmpObj;
			int count;

			cout << "Введите модель авто: ";
			cin >> model;
			cout << "Введите нужное кол-во: ";
			cin >> count;


			tmpObj.set_model(model);

			switch (salon.handle(tmpObj, count)) {
			case -2:
				cout << "Сожелеем, что вы не смогли продать вам нужное кол-во авто." << endl;
				break;
			case -1:
				cout << "Сожелеем, что вы не смогли подобрать вам нужное авто." << endl;
				break;
			case 0:
				cout << "Поздравляем с успешной покупкой!" << endl;
				break;
			case 1:
				cout << "Прерывание операции по продаже..." << endl;
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
			cout << "Неверный выбор" << endl;
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
		"Вывести на экран содержимое",
		"Добавить авто",
		"Удалить авто",
		"Возврат"
	};

	while (FLAG) {

		try {
			ch = menu("Выберите пункт меню: ", 4, list);
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

			ch = get_dec("Введите нужное кол-во: ");

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

			ch = get_dec("Введите удаляемое кол-во(удалить все: -1): ");
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
			cout << "Неверный выбор." << endl;
		}
	}
}
