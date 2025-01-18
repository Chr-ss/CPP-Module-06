/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/18 17:28:29 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter(std::string input) : _input(input){
	_int = 0;
	_float = 0;
	_double = 0;
	_char = 0;
}

// Destructor
ScalarConverter::~ScalarConverter()
{

}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &toCopy) : _input(toCopy._input), _int(toCopy._int), _float(toCopy._float), _double(toCopy._double), _char(toCopy._char)
{

}

// Copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
	if (this != &other){
		_input = other._input;
		_int = other._int;
		_float = other._float;
		_double = other._double;
		_char = other._char;
	}
	return *this;
}

// Private functions
void ScalarConverter::_convertToChar(){
	if (_input.length() == 1 && !std::isdigit(_input[0])){
		_char = _input[0];
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (_input.length() == 3 && _input[0] == '\'' && _input[2] == '\''){
		_char = _input[1];
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (_input.length() == 3 && _input[0] == '\'' && _input[1] == '\\' && _input[2] == '0'){
		_char = '\0';
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else{
		_int = std::stoi(_input);
		if (_int < 0 || _int > 127)
			throw ScalarConverter::ImpossibleException();
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
}

void ScalarConverter::_convertToInt(){
	try{
		_int = std::stoi(_input);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	catch (std::exception &e){
		throw ScalarConverter::ImpossibleException();
	}
}

void ScalarConverter::_convertToFloat(){
	try{
		_float = std::stof(_input);
		_int = static_cast<int>(_float);
		_char = static_cast<char>(_int);
		_double = static_cast<double>(_float);
	}
	catch (std::exception &e){
		throw ScalarConverter::ImpossibleException();
	}
}

void ScalarConverter::_convertToDouble(){
	try{
		_double = std::stod(_input);
		_int = static_cast<int>(_double);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_double);
	}
	catch (std::exception &e){
		throw ScalarConverter::ImpossibleException();
	}
}

// Public functions
void ScalarConverter::convert(){
	try{
		_convertToChar();
	}
	catch (std::exception &e){
		try{
			_convertToInt();
		}
		catch (std::exception &e){
			try{
				_convertToFloat();
			}
			catch (std::exception &e){
				try{
					_convertToDouble();
				}
				catch (std::exception &e){
					throw ScalarConverter::ImpossibleException();
				}
			}
		}
	}
}

void ScalarConverter::print(){
	std::cout << BRIGHT_WHITE << "char: ";
	if (std::isprint(_char))
		std::cout << "'" << _char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}


