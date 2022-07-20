/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                       :+:      :+:    :+:   	  */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 03:20:44 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <string>
#include <iostream>

// Default Constructor
Data::Data(void) : _value(42){
}
// Destructor
Data::~Data(void) {
}
// Copy Constructor
Data::Data(const Data &Data) {
    *this = Data;
}
// Overload assignation
Data &Data::operator=(const Data &Data) {
	_value = Data._value;
    return *this;
}

// GETTERS
int Data::getDataValue(void) const
{
	return _value;
}
