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
Convert::Convert(char * to_convert) : _to_convert(to_convert), _char('0'), _integer(0), _float(0.0), _double(0)
{
	return;
}


// GETTERS
char Convert::getChar(void) const
{
	return _char;
}
int  Convert::getInteger(void) const
{
	return _integer;
}
float  Convert::getFloat(void) const
{
	return _float;
}
double  Convert::getDouble(void) const
{
	return _double;
}


// return TRUE if char
static int isChar(string to_convert)
{
	if (to_convert.length() == 1 && to_convert[0] > 32 && to_convert[0] < 123 )
		return 1;
	return 0;
}

// Function that finds the type from the arg
string Convert::guess_type(void)  {
	if(isChar(_to_convert))
		return "char";
	return "NaN";
}

// surchage operateur d'insertion pour afficher le Convert trqlement
ostream &operator<<(ostream &o, const Convert &Convert) {
        o << "char : " << Convert.getChar()  << "." <<endl;
        o << "int : " << Convert.getInteger()  << "." <<endl;
        o << "float : " << Convert.getFloat()  << "." <<endl;
        o << "double : " << Convert.getDouble()  << "." <<endl;

    return o;
}
