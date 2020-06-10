#pragma once

#include "car.h"
#include "realloc.h"

#define PH 16

class KeeperCar {
public:
	KeeperCar();
	KeeperCar(const KeeperCar& Obj);
	KeeperCar(KeeperCar&& Obj);
	~KeeperCar();
	void add_car(const car& Obj, int count);
	int find_car(const car& Obj);
	void sub_car(const car& Obj, int count);
	void load(const std::string&& str);
	void save(const std::string&& str);
	car& operator[](int i) const;
	KeeperCar sim_car(const car& ObjCar) const;
	friend std::ostream& operator<<(std::ostream& os, const KeeperCar& Obj);
	int get_size() const;
	int get_amount(int num) const;
private:

	void add_reserve();

	car* mas;
	int* amount;
	int size;
	int reserve;
};
