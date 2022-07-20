/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 02:02:26 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP_
#define CONVERT_HPP_

#include <iostream>
#include <string>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <iomanip>

using std::string;
using std::ostream;

class Convert
{
 	public:
		Convert(void);
		~Convert(void);
		Convert(char * to_convert);
		Convert(const Convert &Convert);
		Convert &operator=(const Convert &Convert);

		string	guess_type(void) ;
		void	convert_to_others(string to_convert_type);

		string	getChar(void) const;
		string	getInteger(void) const;
		string	getFloat(void) const;
		string	getDouble(void) const;


	private :
		int 	_nan;
		string	_to_convert;
		char	_char;
		int		_integer;
		float	_float;
		double	_double;
};

ostream &operator<<(ostream &o, const Convert &Convert);

#endif
