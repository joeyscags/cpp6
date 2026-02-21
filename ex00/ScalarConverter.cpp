/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:04:56 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/21 14:29:45 by joeyscags        ###   ########.fr       */
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

// ─── Print Helpers ───────────────────────────────────────────────────────────

void ScalarConverter::printChar(double value, bool impossible)
{
	if (impossible || std::isnan(value) || std::isinf(value)
		|| value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible)
{
	if (impossible || std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(INT_MIN)
		|| value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool isPseudo)
{
	float f = static_cast<float>(value);
	std::cout << "float: ";
	if (isPseudo || std::isnan(f) || std::isinf(f))
		std::cout << f << "f" << std::endl;
	else if (f == static_cast<float>(static_cast<int>(f))
		&& !std::isinf(f) && std::abs(f) < 1e6)
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value, bool isPseudo)
{
	std::cout << "double: ";
	if (isPseudo || std::isnan(value) || std::isinf(value))
		std::cout << value << std::endl;
	else if (value == static_cast<double>(static_cast<int>(value))
		&& !std::isinf(value) && std::abs(value) < 1e6)
		std::cout << value << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}

// ─── Public Static Method ────────────────────────────────────────────────────

void ScalarConverter::convert(const std::string &literal)
{
	(void)literal;
	std::cout << "convert() called" << std::endl;
}
