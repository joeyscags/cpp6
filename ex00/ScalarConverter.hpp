/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:04:40 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/21 14:29:45 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <climits>
# include <cmath>

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		enum LiteralType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			INVALID
		};

		static LiteralType	detectType(const std::string &literal);
		static bool			isChar(const std::string &literal);
		static bool			isInt(const std::string &literal);
		static bool			isFloat(const std::string &literal);
		static bool			isDouble(const std::string &literal);
		static bool			isPseudo(const std::string &literal);

	static void			printChar(double value, bool impossible);
	static void			printInt(double value, bool impossible);
	static void			printFloat(double value, bool isPseudo);
	static void			printDouble(double value, bool isPseudo);
};

#endif
