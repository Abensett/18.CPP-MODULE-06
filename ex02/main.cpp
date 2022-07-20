/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:25:41 by abensett          #+#    #+#             */
/*   Updated: 2022/07/20 19:26:50 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************
	This exo is meant to understand dynamic_cast.
	Unlike other casts, dynamic_cast involves a run-time type check. 
	If the object bound to the pointer is not an object of the target type, 
	it fails and the value is 0. 
	If it's a reference type when it fails, then an exception of type bad_cast
	is thrown.   
 ******************************************************************************/

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdint.h>
#include <time.h>
#define RED "\e[0;31m"

using std::cout;
using std::endl;

Base  *generate(void)
{
	srand (time(NULL));				

	int random;
	random = rand() % 3 ;
	if (random == 0)
		return new A();
	if (random == 1)
		return new B();
	return new C();
}


void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)		// pointer so if the case fails it returns NULL
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);			// reference so if the case fails it throws an exception bad cast
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}


int	main(void)
{
	srand(time(NULL));		/* initialize random seed to get a random number*/ 
	Base	*p;

	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}