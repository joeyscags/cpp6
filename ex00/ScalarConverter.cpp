/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:04:56 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/20 22:42:00 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}


bool ScalarConverter::isChar(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isPseudo(const std::string &literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf"
		|| literal == "-inf" || literal == "+inf" || literal == "nan"
		|| literal == "inff" || literal == "inf");
}

bool ScalarConverter::isInt(const std::string &literal)
{
	size_t i = 0;
	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal.empty() || literal.back() != 'f')
		return false;
	std::string trimmed = literal.substr(0, literal.length() - 1);
	size_t i = 0;
	bool hasDot = false;
	if (trimmed.empty())
		return false;
	if (trimmed[i] == '+' || trimmed[i] == '-')
		i++;
	if (i == trimmed.length())
		return false;
	while (i < trimmed.length())
	{
		if (trimmed[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(trimmed[i]))
			return false;
		i++;
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	size_t i = 0;
	bool hasDot = false;
	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return hasDot;
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string &literal)
{
	if (isPseudo(literal))
		return PSEUDO;
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return INVALID;
}

// ─── Public Static Method ────────────────────────────────────────────────────

void ScalarConverter::convert(const std::string &literal)
{
	(void)literal;
	std::cout << "convert() called" << std::endl;
}
