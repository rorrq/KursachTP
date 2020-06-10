#pragma once

#include "exceptions.h"
#include <iostream>
#include <windows.h>

int get_dec(std::string&& str);
int menu(std::string invite, int amount, const std::string* str);
void print_exp(const exceptions& e);
