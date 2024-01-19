#include "Solution1.h"
#include <iostream>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
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
