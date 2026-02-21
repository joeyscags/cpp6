/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:04:56 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/21 19:10:02 by joeyscags        ###   ########.fr       */
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

// ─── Conversion From Detected Types ─────────────────────────────────────────

void ScalarConverter::convertFromChar(const std::string &literal)
{
	char c = literal[0];
	double value = static_cast<double>(c);
	printChar(value, false);
	printInt(value, false);
	printFloat(value, false);
	printDouble(value, false);
}

void ScalarConverter::convertFromInt(const std::string &literal)
{
	long long ll;
	bool overflow = false;
	try
	{
		ll = std::stoll(literal);
		if (ll < INT_MIN || ll > INT_MAX)
			overflow = true;
	}
	catch (...)
	{
		overflow = true;
		ll = 0;
	}

	double value = static_cast<double>(ll);
	printChar(value, overflow);
	if (overflow)
		std::cout << "int: impossible" << std::endl;
	else
		printInt(value, false);
	printFloat(value, overflow);
	printDouble(value, overflow);
}

void ScalarConverter::convertFromFloat(const std::string &literal)
{
	std::string trimmed = literal.substr(0, literal.length() - 1);
	float f;
	try
	{
		f = std::stof(trimmed);
	}
	catch (...)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	double value = static_cast<double>(f);
	printChar(value, false);
	printInt(value, false);
	printFloat(value, false);
	printDouble(value, false);
}

void ScalarConverter::convertFromDouble(const std::string &literal)
{
	double d;
	try
	{
		d = std::stod(literal);
	}
	catch (...)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	printChar(d, false);
	printInt(d, false);
	printFloat(d, false);
	printDouble(d, false);
}

void ScalarConverter::convertFromPseudo(const std::string &literal)
{
	double value;

	if (literal == "nanf" || literal == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inff" || literal == "+inf"
		|| literal == "inff" || literal == "inf")
		value = std::numeric_limits<double>::infinity();
	else
		value = -std::numeric_limits<double>::infinity();

	printChar(value, true);
	printInt(value, true);
	printFloat(value, true);
	printDouble(value, true);
}

// ─── Public Static Method ────────────────────────────────────────────────────

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Error: empty literal" << std::endl;
		return;
	}

	LiteralType type = detectType(literal);

	switch (type)
	{
		case CHAR:
			convertFromChar(literal);
			break;
		case INT:
			convertFromInt(literal);
			break;
		case FLOAT:
			convertFromFloat(literal);
			break;
		case DOUBLE:
			convertFromDouble(literal);
			break;
		case PSEUDO:
			convertFromPseudo(literal);
			break;
		default:
			std::cout << "Error: invalid literal" << std::endl;
			break;
	}
}
