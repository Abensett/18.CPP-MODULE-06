/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:25:41 by abensett          #+#    #+#             */
/*   Updated: 2022/07/20 14:24:49 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***********************************************************************************************

	Vous devez premièrement détecter le type du littéral passé en paramètre, le convertir
	de sa représentation sous forme de chaîne de caractères vers son véritable type, et ensuite
	le convertir explicitement vers les trois autres types de données.

*************************************************************************************************/
#include "Convert.hpp"

using std::cout;
using std::endl;

#define RED "\e[0;31m"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << RED "You need to give an argument" << endl;
		return 1;
	}
	Convert Converter = Convert(av[1]);
	string to_convert_type = Converter.guess_type();
	Converter.convert_to_others(to_convert_type);
	cout << Converter;

	return 0;
}
