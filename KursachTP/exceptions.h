#pragma once

#include <string>

class exceptions {
public:
	exceptions(const std::string& str);
	exceptions(std::string&& str);
	exceptions(const exceptions& e);
	exceptions(exceptions&& e);
	const std::string& what() const;
private:
	std::string mesg;
};
