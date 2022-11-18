#pragma once
#include <string>
#include <list>

class Calculator
{
private:
	double result = 0.0;
	std::list<double> nums;
	std::list<char> oper;
	std::string fullNum = "";

private:
	void SeparateString(std::string prompt);
	void SetNumber();

public:
	double Calculate(std::string prompt);
};