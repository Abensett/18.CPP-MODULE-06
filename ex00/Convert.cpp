/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 03:20:44 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <stdlib.h>

using std::cout;
using std::endl;

// Default Constructor
Convert::Convert(void) {
}
// Destructor
Convert::~Convert(void) {
}
// Copy Constructor
Convert::Convert(const Convert &Convert) {
    *this = Convert;
}
// Overload assignation
Convert &Convert::operator=(const Convert &Convert) {
	_to_convert = Convert._to_convert;
    return *this;
}
// Constructor with type
Convert::Convert(char * to_convert) : _nan(0),_to_convert(to_convert), _char('0'), _integer(0), _float(0.0), _double(0)
{
	return;
}

// GETTERS
string Convert::getChar(void) const
{
	string returned;
	returned  += _char;
	if (_nan)
		return "impossible";
	if (_integer >= 32 && _integer <= 126)
		return "'"+returned+"'";
	return "Non displayable";
}
string  Convert::getInteger(void) const
{
	string returned;

	std::stringstream ss;
	ss << _integer;
	ss >> returned;
	if (_nan || _double > INT_MAX || _double < INT_MIN)
		return "impossible";
	return returned;
}
string  Convert::getFloat(void) const
{
	string returned;

	std::stringstream ss;
	ss << _float;
	ss >> returned;
	if (_to_convert == "+inff" || _to_convert == "+inf" || _float == FLT_MAX)
		return "+inff";
	if ( _to_convert == "-inff"|| _to_convert == "-inf" || _float == -FLT_MAX)
		return "-inff";
	if (_nan)
		return "nanf";
	if (_integer == _float)
		return returned+ ".0f";;
	return returned+"f";
}
string  Convert::getDouble(void) const
{
	string returned;
	std::stringstream ss;
	ss << _float;
	ss >> returned;
	if (_to_convert == "+inff" || _to_convert == "+inf" || _float == FLT_MAX)
		return "+inf";
	if ( _to_convert == "-inff"|| _to_convert == "-inf" || _float == -FLT_MAX )
		return "-inf";
	if (_nan)
		return "nan";
	if (_integer == _double)
		return returned + ".0";
	return returned;
}

// return TRUE if char
static int isChar(string to_convert)
{
	if (to_convert.length() == 1 && to_convert[0] > 32 && to_convert[0] < 126 )		// check printable
		if (to_convert[0] < 48 || to_convert[0] > 57 )								// check if not between 0 et 9 table ASCII
			return 1;
	return 0;
}
static int isInt(string to_convert)
{
	for (unsigned int i = 0; i < to_convert.length(); i++)
	{
		if ((to_convert[0] == '-' || to_convert[0] == '+') && i == 0)
			i++;
		if (to_convert[i] < '0' || to_convert[i] > '9')
			return 0;
	}
	return 1;
}
static int isFloat(string to_convert)
{
	int haspoint = 0;

	for (unsigned int i = 0; i < to_convert.length(); i++)
	{
		if ((to_convert[0] == '-' || to_convert[0] == '+') && i == 0)
			i++;
		if ( to_convert[i] == '.' && i != 0 && i != to_convert.length() - 2)
		{
			haspoint++;
			i++;
		}
		if ((to_convert[i] < '0' || to_convert[i] > '9') && i != to_convert.length() - 1)
			return 0;
	}
	if (haspoint == 1 && to_convert[to_convert.length() - 1] == 'f')
		return 1;
	return (0);
}

static int isDouble(string to_convert)
{
	int haspoint = 0;

	for (unsigned int i = 0; i < to_convert.length(); i++)
	{
		if ((to_convert[0] == '-' || to_convert[0] == '+') && i == 0)
			i++;
		if ( to_convert[i] == '.' && i != 0 && i != to_convert.length() - 1)
		{
			haspoint++;
			i++;
		}
		if ((to_convert[i] < '0' || to_convert[i] > '9') && i != to_convert.length() - 1)
			return 0;
	}
	if (haspoint == 1)
		return 1;
	return (0);
}

// Finds the type of the arg and return "char" "int" "float"  or  "double"
string Convert::guess_type(void)
{
	if(isChar(_to_convert))
		return "char";
	else if (isInt(_to_convert))
		return "int";
	else if (isFloat(_to_convert))
		return "float";
	else if (isDouble(_to_convert))
		return "double";
	_nan = 1;
	return "NaN";
}

// convert in every other types
void Convert::convert_to_others(string to_convert_type)
{
	if(to_convert_type == "char")
	{
		_char	 = _to_convert[0];
		_integer =  static_cast<int>(_char);
		_float   =  static_cast<float>(_integer);
		_double  =  static_cast<double>(_char);
	}
	if(to_convert_type == "int")
	{
		long int tmp;
		std::stringstream ss;
    	ss << _to_convert;
		ss >> tmp;
		if (tmp < INT_MIN || tmp > INT_MAX)
			_nan = 1;
		_char	 = static_cast<char>(tmp);
		_integer = tmp;
		_float   =  static_cast<float>(tmp);
		_double  =  static_cast<double>(tmp);
	}
	if(to_convert_type == "float")
	{
		float tmp;
		std::stringstream ss;
    	ss << _to_convert;
		ss >> tmp;

		_char	 = static_cast<char>(tmp);
		_integer = static_cast<int>(tmp);
		_float   =  tmp;
		_double  =  static_cast<double>(tmp);
	}
	if(to_convert_type == "double")
	{
		double tmp;
		std::stringstream ss;
    	ss << _to_convert;
		ss >> tmp;
		_char	 = static_cast<char>(tmp);
		_integer = static_cast<int>(tmp);
		_float   =  static_cast<float>(tmp);
		_double  =  tmp;
	}


}
// surchage operateur d'insertion pour afficher le Convert trqlement
ostream &operator<<(ostream &o, const Convert &Convert) {
        o << "char: " << Convert.getChar()   <<endl;
        o << "int: " << Convert.getInteger()  <<endl;
        o << "float: " << Convert.getFloat()  <<endl;
        o << "double: " << Convert.getDouble()  <<endl;

    return o;
}
