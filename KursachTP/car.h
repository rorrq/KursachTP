#pragma once

#include <iostream>
#include <fstream>
#include "exceptions.h"

class car {
public:
	car();
	car& operator=(const car& Obj);
	friend std::ostream& operator<<(std::ostream& os, const car& Obj);
	friend std::istream& operator>>(std::istream& is, car& Obj);
	friend std::ofstream& operator<<(std::ofstream& ofs, const car& Obj);
	friend std::ifstream& operator>>(std::ifstream& ifs, car& Obj);
	friend bool operator==(const car& Obj1, const car& Obj2);
	bool check(const std::string& model) const;
	friend void move(car& Obj1, car& Obj2);

	const std::string& get_model() const;
	const std::string& get_color() const;

	void set_model(const std::string model);

	bool is_pattern() const;

private:

	std::string model;		//Модель
	std::string color;		//Цвет
	int year;				//Год выпуска
	int airbags;			//Кол-во подушек безопасности
	double capacity;		//объем двигателя в литрах
	double power;			//Мощность двигателя в кВТ
	double fuelTank;		//Объем топливного бака в литрах
	double fuelCons;		//Расход топлива на 100км
	bool rdrHeat;			//Подогрев руля 		
	bool gearBox;			//АКПП или МКПП
	bool ABS;				//ABS
	bool EDS;				//EDS
	bool sysNav;			//Система навигации
	bool computer;			//Бортовой компьютер
	bool seatHead;			//Подогрев сидений
	bool roofRack;			//Багажник на крышу
	double x;				//Длина
	double y;				//Ширина
	double z;				//Высота
};
