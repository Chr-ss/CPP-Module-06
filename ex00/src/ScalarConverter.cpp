/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/04/09 20:19:19 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy) {
	*this = toCopy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other) {
	}
	return *this;
}

bool	ifSpecial(const std::string &input) {
	if (input == "-inf" || input == "+inf" || input == "nan") {
		std::cout << "char: out-of-range" << std::endl;
		std::cout << "int: out-of-range" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return (true);
	} else if (input == "-inff" || input == "+inff" || input == "nanf") {
		std::string doubleInput = input.substr(0, input.length() - 1);
		std::cout << "char: out-of-range" << std::endl;
		std::cout << "int: out-of-range" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input << std::endl;
		return (true);
	}
	return (false);
}

bool	isChar(const std::string &input) {
	if (input.length() == 3 && input.at(0) == '\'' && input.back() == '\'' && std::isprint(input.at(1))) {
		return (true);
	}
	return (false);
}

bool	isInt(const std::string &input) {
	size_t i = 0;
	if (input[0] == '-') {
		i++;
	}
	if (input.find_first_not_of("0123456789", i) == std::string::npos) {
		try {
			std::stoi(input);
			return (true);
		  } catch (...) {
			return (false);
		  }
	}
	return (false);
}

bool	isFloat(const std::string &input) {
	bool decimal = false;
	bool f = false;
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '-' && i != 0) {
			return (false);
		}
		if (input[i] == '.' ) {
			if (decimal || i == 0 || i == input.length() - 1) {
				return (false);
			}
			decimal = true;
		}
		if (input[i] == 'f') {
			if (f || i != input.length() - 1) {
				return (false);
			}
			f = true;
		}
	}
	if (!decimal) {
		return (false);
	}
	if (decimal && !f) {
		return (false);
	}
	if (decimal && f) {
		try {
			std::stof(input);
			return (true);
		} catch (...) {
			return (false);
		}
	}
	return (false);
}


bool	isDouble(const std::string &input) {
	bool decimal = false;
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '-' && i != 0) {
			return (false);
		}
		if (input[i] == '.') {
			if (decimal || i == 0 || i == input.length() - 1) {
				return (false);
			}
			decimal = true;
		}
	}
	try {
		std::stod(input);
		return (true);
	} catch (...) {
		return (false);
	}
	return (false);
}


int	getLiteralType(const std::string &input) {
	if (input.empty()) {
		return (INVALID_TYPE);
	}
	if (isChar(input)) {
		return (CHAR_TYPE);
	}
	if (isInt(input)) {
		return (INT_TYPE);
	}
	if (isFloat(input)) {
		return (FLOAT_TYPE);
	}
	if (isDouble(input)) {
		return (DOUBLE_TYPE);
	}
	return (INVALID_TYPE);
}


void ScalarConverter::convert(const std::string &input) {
	if (ifSpecial(input)) {
		return ;
	}
	
	int type = getLiteralType(input);

	char	c = 0;
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	bool	overflow[3] = {false, false, false};

	switch (type) {
		case CHAR_TYPE:
			c = input.at(1);
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT_TYPE:
			i = std::stoi(input);
			if (i < std::numeric_limits<char>::lowest() || i > std::numeric_limits<char>::max()) {
				c = 0;
				overflow[0] = true;
			} else {
				c = static_cast<char>(i);
			}
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT_TYPE:
			f = std::stof(input);
			if (f < std::numeric_limits<char>::lowest() || f > std::numeric_limits<char>::max()) {
				c = 0;
				overflow[0] = true;
			} else {
				c = static_cast<char>(f);
			}
			if (f < std::numeric_limits<int>::lowest() || f > std::numeric_limits<int>::max()) {
				i = 0;
				overflow[1] = true;
			} else {
				i = static_cast<int>(f);
			}
			d = static_cast<double>(f);
			break;
		case DOUBLE_TYPE:
			d = std::stod(input);
			if (d < std::numeric_limits<char>::lowest() || d > std::numeric_limits<char>::max()) {
				c = 0;
				overflow[0] = true;
			} else {
				c = static_cast<char>(d);
			}
			if (d < std::numeric_limits<int>::lowest() || d > std::numeric_limits<int>::max()) {
				i = 0;
				overflow[1] = true;
			} else {
				i = static_cast<int>(d);
			}
			if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max()) {
				f = 0.0f;
				overflow[2] = true;
			} else {
				f = static_cast<float>(d);
			}
			break;
		case INVALID_TYPE:
			std::cerr << BRIGHT_RED << BOLD << "Invalid input" << RESET << std::endl;
			return ;
		default:
			std::cerr << BRIGHT_RED << BOLD << "Invalid input" << RESET << std::endl;
			break;
	}


	std::cout << "char: ";
	if (overflow[0]) {
		std::cout << "out-of-range" << std::endl;
	} else if (std::isprint(c)) {
		std::cout << "'" << c << "'" << std::endl;
	} else {
		std::cout << "non-displayable" << std::endl;
	}
	std::cout << "int: ";
	if (overflow[1]) {
		std::cout << "out-of-range" << std::endl;
	} else {
		std::cout << i << std::endl;
	}
	std::cout << "float: ";
	if (overflow[2]) {
		std::cout << "out-of-range" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	std::cout << std::endl;
}