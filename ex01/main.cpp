/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:25:41 by abensett          #+#    #+#             */
/*   Updated: 2022/07/20 16:23:57 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**************************************************************************
  uintptr_t =
  Integer type capable of holding a value converted from a void 
  pointer and then be converted back to that type with a value that compares
  equal to the original pointer.

  = int de la meme taille qu'un pointeur void 
  -> useful to do intoperations on a pointer


  This exo is meant to understand reinterpretations with *reinterpret_cast*
 ***************************************************************************/

#include "Data.hpp"
#include <stdint.h>
#define RED "\e[0;31m"

using std::cout;
using std::endl;

uintptr_t	serialize(Data *ptr)			
{
	return (reinterpret_cast<uintptr_t>(ptr));		// does not change the bits, only the type
}

Data		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data		*mydata;
	Data		*deserialized;
	uintptr_t	serialized;

	mydata = new Data();
	std::cout << "data ptr = " << mydata << std::endl;
	std::cout << "value = " << mydata->getDataValue() << std::endl;

	serialized = serialize(mydata);
	std::cout << "serialize(data ptr) = " << serialized << std::endl;

	deserialized = deserialize(serialized);
	std::cout << "deserialize(serialize(data ptr)) = " << deserialized << std::endl;
	std::cout << "value = " << deserialized->getDataValue() << std::endl;

	return 0;
}
