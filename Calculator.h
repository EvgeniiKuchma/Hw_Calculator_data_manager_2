#pragma once
#include <iostream>
template <typename T, typename U>
class Calculator
{
public:
	Calculator(T x, T y) : _x(x), _y(y) {};
	T getSum()
	{
		return _x + _y;
	}
	T getSub()
	{
		return _x - _y;
	}
	T getMul()
	{
		return _x * _y;
	}
	T getDiv()
	{
		if (_y == 0)
		{
			std::cout << "Error\n";
			return false;
		}
		return _x / _y;
	}
private:
	T _x = 0;
	T _y = 0;
};