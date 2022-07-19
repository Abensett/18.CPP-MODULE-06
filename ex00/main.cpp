/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:25:41 by abensett          #+#    #+#             */
/*   Updated: 2022/07/19 22:33:05 by abensett         ###   ########.fr       */
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

#define BLUE "\e[0;36m"

int main(int ac, char **av)
{
	Convert Converter = Convert(av[1]);
	string to_convert_type = Converter.guess_type();

	cout << to_convert_type << endl;

	(void)ac;
	return 0;
}
