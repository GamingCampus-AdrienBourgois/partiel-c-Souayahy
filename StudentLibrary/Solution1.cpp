#include "Solution1.h"
#include <iostream>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
	std::cout << "Choose your value : " << std::endl;
	std::cin >> _value;

	std::cout << "Type the ID of the unit you want to convert from :  " << std::endl;
	std::cout << "1 CELSIUS - 2 FAHRENHEIT - 3 KELVIN " << std::endl;
	int fromID;
	std::cin >> fromID;
	

	switch(fromID) 
	{
		case 1 :
			_from = TemperatureUnits::CELSIUS;
			break;
		case 2 :
			_from = TemperatureUnits::FAHRENHEIT;
			break;
		case 3 :
			_from = TemperatureUnits::KELVIN;
			break;
	}

	std::cout << "Choose the unit you want to convert to : " << std::endl;
	std::cout << "1 CELSIUS - 2 FAHRENHEIT - 3 KELVIN " << std::endl;
	int toID;
	std::cin >> toID;

	switch(toID)
	{
		case 1:
			_to = TemperatureUnits::CELSIUS;
			break;
		case 2:
			_to = TemperatureUnits::FAHRENHEIT;
			break;
		case 3:
			_to = TemperatureUnits::KELVIN;
			break;
	}

	if ((_from == TemperatureUnits::CELSIUS) && (_to == TemperatureUnits::FAHRENHEIT))
	{
		_value = (9.0 / 5.0) * _value + 32;
	}

	else if ((_from == TemperatureUnits::KELVIN) && (_to == TemperatureUnits::FAHRENHEIT))
	{
		_value = (9.0 / 5.0) * (_value - 273.15) + 32;
	}

	else if ((_from == TemperatureUnits::FAHRENHEIT) && (_to == TemperatureUnits::CELSIUS))
	{
		_value = (5.0 / 9.0) * (_value - 32);
	}

	else if ((_from == TemperatureUnits::CELSIUS) && (_to == TemperatureUnits::KELVIN))
	{
		_value = _value + 273.15;
	}

	else if ((_from == TemperatureUnits::KELVIN) && (_to == TemperatureUnits::CELSIUS))
	{
		_value = _value - 273.15;
	}

	else if ((_from == TemperatureUnits::FAHRENHEIT) && (_to == TemperatureUnits::KELVIN))
	{
		_value = (5.0 / 9.0) * (_value - 32) + 273.15;
	}

	return _value;
}

#endif
