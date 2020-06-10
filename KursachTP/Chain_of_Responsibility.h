#pragma once

#include "KeeperCar.h"
#include "func.h"

class handlerInterface {
public:
	handlerInterface(KeeperCar* kCar) : kCar(kCar), next(nullptr) {}
	void add(handlerInterface* b) {
		if (next)
			next->add(b);
		else
			next = b;
	}
	virtual int handle(const car& ObjCar, int count) {
		return next->handle(ObjCar, count);
	}
protected:
	KeeperCar* kCar;
private:
	handlerInterface* next;
};

class handlerSalon : public handlerInterface {
public:
	handlerSalon(KeeperCar* kCar) : handlerInterface(kCar) {};
	int handle(const car& ObjCar, int count) override {
		KeeperCar tmpCar(kCar->sim_car(ObjCar));
		if (tmpCar.get_size()) {
			int num, tmpCount;
			std::cout << "На данный момент в салоне присутсвует следующий набор: " << std::endl;
			std::cout << tmpCar;

			num = get_dec("Введите номер(0 - если ни одно авто не подходит): ") - 1;

			if (num < 0) {
				std::cout << "Переадресация в базу данных склада..." << std::endl;
				return handlerInterface::handle(ObjCar, count);
			}

			try {
				tmpCount = kCar->get_amount(num);
			}
			catch (exceptions& e) {
				print_exp(e);
				return 0;
			}

			int ret = 0;

			if (count > tmpCount) {
				std::cout << "Заказ слишком большой, переадресация в базу данных склада..." << std::endl;
				ret = handlerInterface::handle(tmpCar[num], count - tmpCount);
				count = tmpCount;
			}

			kCar->sub_car(tmpCar[num], count);

			std::cout << "Продано " << count << " авто из салона." << std::endl;

			return ret;
		}
		else {
			std::cout << "В салоне не имеется похожих экземпляров, переадресация в базу данных склада..." << std::endl;
			return handlerInterface::handle(ObjCar, count);
		}
		return 0;
	}
};

class handlerBase : public handlerInterface {
public:
	handlerBase(KeeperCar* kCar) : handlerInterface(kCar) {};
	int handle(const car& ObjCar, int count) override {
		int tmpCount;

		if (ObjCar.is_pattern()) {
			KeeperCar tmpCar(kCar->sim_car(ObjCar));
			if (tmpCar.get_size()) {
				std::cout << "В данный момент на складе присутсвует следующий набор: " << std::endl;
				std::cout << tmpCar;

				int num = get_dec("Введите номер(0 - если ни одно авто не подходит): ") - 1;

				if (num < 0) {
					std::cout << "Переадресация на производство..." << std::endl;
					return handlerInterface::handle(ObjCar, count);;
				}

				try {
					tmpCount = kCar->get_amount(num);
				}
				catch (exceptions& e) {
					print_exp(e);
					return 0;
				}

				int ret = 0;

				if (count > tmpCount) {
					std::cout << "Заказ слишком большой, переадресация на производство..." << std::endl;
					ret = handlerInterface::handle(tmpCar[num], count - tmpCount);
					count = tmpCount;
				}

				kCar->sub_car(tmpCar[num], count);

				std::cout << "Продано " << count << " авто со склада." << std::endl;

				if (ret) return ret;

			}
			else {
				std::cout << "В базе данных склада не имеется похожих экземпляров, переадресация на производство... " << std::endl;
				return handlerInterface::handle(ObjCar, count);
			}
		}
		else {
			int num = kCar->find_car(ObjCar);
			if (num == kCar->get_size()) {
				std::cout << "В базе данных склада не имеется данных экземпляров, переадресация на производство... " << std::endl;
				return handlerInterface::handle(ObjCar, count);
			}
			else {
				tmpCount = kCar->get_amount(num);

				int ret = 0;

				if (count > tmpCount) {
					std::cout << "Заказ слишком большой, переадресация на производство..." << std::endl;
					ret = handlerInterface::handle((*kCar)[num], count - tmpCount);
					count = tmpCount;
				}

				kCar->sub_car((*kCar)[num], count);

				std::cout << "Продано " << count << " авто со склада." << std::endl;

				if (ret) return ret;

			}
		}
		return 0;
	}
};

class handlerProduction : public handlerInterface {
public:
	handlerProduction(KeeperCar* kCar) : handlerInterface(kCar) {};
	int handle(const car& ObjCar, int count) override {
		int tmpCount;

		if (ObjCar.is_pattern()) {
			KeeperCar tmpCar(kCar->sim_car(ObjCar));
			if (tmpCar.get_size()) {
				std::cout << "В данный момент завод может создать следующий набор: " << std::endl;

				std::cout << tmpCar;

				int num = get_dec("Введите номер(0 - если ни одно авто не подходит): ") - 1;

				if (num < 0) return -1;

				try {
					tmpCount = kCar->get_amount(num);
				}
				catch (exceptions& e) {
					print_exp(e);
					return 1;
				}

				if (count > tmpCount) {
					std::cout << "Заказ слишком большой." << std::endl;
					count = tmpCount;
				}

				kCar->sub_car(tmpCar[num], count);

				std::cout << "Продано " << count << " авто c производства." << std::endl;

			}
			else {
				std::cout << "Завод не может изготовить авто данной модели и цвета." << std::endl;
				return -1;
			}
		}
		else {
			int num = kCar->find_car(ObjCar);
			if (num == kCar->get_size()) {
				std::cout << "Завод не может изготовить такие же экземпляры." << std::endl;
				return -2;
			}
			else {
				tmpCount = kCar->get_amount(num);

				bool flag = 0;

				if (count > tmpCount) {
					std::cout << "Заказ слишком большой." << std::endl;
					count = tmpCount;
					flag = true;
				}
				kCar->sub_car((*kCar)[num], count);

				std::cout << "Продано " << tmpCount << " авто с производства." << std::endl;

				if (flag) return -2;
			}
		}
		return 0;
	}
};
