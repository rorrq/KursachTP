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
			std::cout << "�� ������ ������ � ������ ����������� ��������� �����: " << std::endl;
			std::cout << tmpCar;

			num = get_dec("������� �����(0 - ���� �� ���� ���� �� ��������): ") - 1;

			if (num < 0) {
				std::cout << "������������� � ���� ������ ������..." << std::endl;
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
				std::cout << "����� ������� �������, ������������� � ���� ������ ������..." << std::endl;
				ret = handlerInterface::handle(tmpCar[num], count - tmpCount);
				count = tmpCount;
			}

			kCar->sub_car(tmpCar[num], count);

			std::cout << "������� " << count << " ���� �� ������." << std::endl;

			return ret;
		}
		else {
			std::cout << "� ������ �� ������� ������� �����������, ������������� � ���� ������ ������..." << std::endl;
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
				std::cout << "� ������ ������ �� ������ ����������� ��������� �����: " << std::endl;
				std::cout << tmpCar;

				int num = get_dec("������� �����(0 - ���� �� ���� ���� �� ��������): ") - 1;

				if (num < 0) {
					std::cout << "������������� �� ������������..." << std::endl;
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
					std::cout << "����� ������� �������, ������������� �� ������������..." << std::endl;
					ret = handlerInterface::handle(tmpCar[num], count - tmpCount);
					count = tmpCount;
				}

				kCar->sub_car(tmpCar[num], count);

				std::cout << "������� " << count << " ���� �� ������." << std::endl;

				if (ret) return ret;

			}
			else {
				std::cout << "� ���� ������ ������ �� ������� ������� �����������, ������������� �� ������������... " << std::endl;
				return handlerInterface::handle(ObjCar, count);
			}
		}
		else {
			int num = kCar->find_car(ObjCar);
			if (num == kCar->get_size()) {
				std::cout << "� ���� ������ ������ �� ������� ������ �����������, ������������� �� ������������... " << std::endl;
				return handlerInterface::handle(ObjCar, count);
			}
			else {
				tmpCount = kCar->get_amount(num);

				int ret = 0;

				if (count > tmpCount) {
					std::cout << "����� ������� �������, ������������� �� ������������..." << std::endl;
					ret = handlerInterface::handle((*kCar)[num], count - tmpCount);
					count = tmpCount;
				}

				kCar->sub_car((*kCar)[num], count);

				std::cout << "������� " << count << " ���� �� ������." << std::endl;

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
				std::cout << "� ������ ������ ����� ����� ������� ��������� �����: " << std::endl;

				std::cout << tmpCar;

				int num = get_dec("������� �����(0 - ���� �� ���� ���� �� ��������): ") - 1;

				if (num < 0) return -1;

				try {
					tmpCount = kCar->get_amount(num);
				}
				catch (exceptions& e) {
					print_exp(e);
					return 1;
				}

				if (count > tmpCount) {
					std::cout << "����� ������� �������." << std::endl;
					count = tmpCount;
				}

				kCar->sub_car(tmpCar[num], count);

				std::cout << "������� " << count << " ���� c ������������." << std::endl;

			}
			else {
				std::cout << "����� �� ����� ���������� ���� ������ ������ � �����." << std::endl;
				return -1;
			}
		}
		else {
			int num = kCar->find_car(ObjCar);
			if (num == kCar->get_size()) {
				std::cout << "����� �� ����� ���������� ����� �� ����������." << std::endl;
				return -2;
			}
			else {
				tmpCount = kCar->get_amount(num);

				bool flag = 0;

				if (count > tmpCount) {
					std::cout << "����� ������� �������." << std::endl;
					count = tmpCount;
					flag = true;
				}
				kCar->sub_car((*kCar)[num], count);

				std::cout << "������� " << tmpCount << " ���� � ������������." << std::endl;

				if (flag) return -2;
			}
		}
		return 0;
	}
};
