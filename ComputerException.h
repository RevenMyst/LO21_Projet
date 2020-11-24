#pragma once
#include <string>
class ComputerException {
private:
	std::string err;
public:
	ComputerException(std::string err) :err(err) {}
	const std::string& getInfo() const { return err; }
};


