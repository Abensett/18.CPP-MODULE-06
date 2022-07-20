/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                       :+:      :+:    :+:   	  */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 02:02:26 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP_
#define DATA_HPP_
#include <iostream>
#include <string>

class Data
{
 	public:
		Data(void);
		~Data(void);
		Data(const Data &Data);
		Data &operator=(const Data &Data);

		int		getDataValue(void) const;

	private :
		int 	_value;
};


#endif
