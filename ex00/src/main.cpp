/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/04/09 20:23:57 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << BRIGHT_RED << BOLD << "Error: " << RESET << "Invalid number of arguments." << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	// Automatic tests:
	// {
	// 	std::cout << BRIGHT_GREEN << BOLD << "\tTesting Special: \n" << RESET;
	// 	std::cout << BOLD << "\t-inf\n" << RESET;
	// 	ScalarConverter::convert("-inf");
	// 	std::cout << BOLD << "\t+inf\n" << RESET;
	// 	ScalarConverter::convert("+inf");
	// 	std::cout << BOLD << "\tnan\n" << RESET;
	// 	ScalarConverter::convert("nan");
	// 	std::cout << BOLD << "\t-inff\n" << RESET;
	// 	ScalarConverter::convert("-inff");
	// 	std::cout << BOLD << "\t+inff\n" << RESET;
	// 	ScalarConverter::convert("+inff");
	// 	std::cout << BOLD << "\tnanf\n" << RESET;
	// 	ScalarConverter::convert("nanf");
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	std::cout << BRIGHT_GREEN << BOLD << "\tTesting Char: \n" << RESET;
	// 	std::cout << BOLD << "\t'" << "a" << "'\n" << RESET;
	// 	ScalarConverter::convert("'a'");
	// 	std::cout << BOLD << "\t'" << "c" << "'\n" << RESET;
	// 	ScalarConverter::convert("'c'");
	// 	std::cout << BOLD << "\t'" << "z" << "'\n" << RESET;
	// 	ScalarConverter::convert("'z'");
	// 	std::cout << BOLD << "\t'" << "A" << "'\n" << RESET;
	// 	ScalarConverter::convert("'A'");
	// 	std::cout << BOLD << "\t'" << "C" << "'\n" << RESET;
	// 	ScalarConverter::convert("'C'");
	// 	std::cout << BOLD << "\t'" << "Z" << "'\n" << RESET;
	// 	ScalarConverter::convert("'Z'");
	// 	std::cout << BOLD << "\t'" << "0" << "'\n" << RESET;
	// 	ScalarConverter::convert("'0'");
	// 	std::cout << BOLD << "\t'" << "1" << "'\n" << RESET;
	// 	ScalarConverter::convert("'1'");
	// 	std::cout << BOLD << "\t'" << "9" << "'\n" << RESET;
	// 	ScalarConverter::convert("'9'");
	// 	std::cout << BOLD << "\t'" << "!" << "'\n" << RESET;
	// 	ScalarConverter::convert("'!'");
	// 	std::cout << BOLD << "\t'" << "@" << "'\n" << RESET;
	// 	ScalarConverter::convert("'@'");
	// 	std::cout << BOLD << "\t'" << "#" << "'\n" << RESET;
	// 	ScalarConverter::convert("'#'");
	// 	std::cout << BOLD << "\t'" << "$" << "'\n" << RESET;
	// 	ScalarConverter::convert("'$'");
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << BRIGHT_GREEN << BOLD << "\tTesting Int: \n" << RESET;
	// 	std::cout << BOLD << "\t42\n" << RESET;
	// 	ScalarConverter::convert("42");
	// 	std::cout << BOLD << "\t0\n" << RESET;
	// 	ScalarConverter::convert("0");
	// 	std::cout << BOLD << "\t-0\n" << RESET;
	// 	ScalarConverter::convert("-0");
	// 	std::cout << BOLD << "\t-1\n" << RESET;
	// 	ScalarConverter::convert("-1");
	// 	std::cout << BOLD << "\t2147483647\n" << RESET;
	// 	ScalarConverter::convert("2147483647");
	// 	std::cout << BOLD << "\t-2147483648\n" << RESET;
	// 	ScalarConverter::convert("-2147483648");
	// 	std::cout << BOLD << "\t2147483648\n" << RESET;
	// 	ScalarConverter::convert("2147483648");
	// 	std::cout << BOLD << "\t-2147483649\n" << RESET;
	// 	ScalarConverter::convert("-2147483649");
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << BRIGHT_GREEN << BOLD << "\tTesting Float: \n" << RESET;
	// 	std::cout << BOLD << "\t42.0f\n" << RESET;
	// 	ScalarConverter::convert("42.0f");
	// 	std::cout << BOLD << "\t0.0f\n" << RESET;
	// 	ScalarConverter::convert("0.0f");
	// 	std::cout << BOLD << "\t-0.0f\n" << RESET;
	// 	ScalarConverter::convert("-0.0f");
	// 	std::cout << BOLD << "\t-1.0f\n" << RESET;
	// 	ScalarConverter::convert("-1.0f");
	// 	std::string float_max = std::to_string(std::numeric_limits<float>::max());
	// 	std::cout << BOLD << "\t" << float_max << "\n" << RESET;
	// 	ScalarConverter::convert(float_max);
	// 	std::string float_min = std::to_string(std::numeric_limits<float>::lowest());
	// 	std::cout << BOLD << "\t" << float_min << "\n" << RESET;
	// 	ScalarConverter::convert(float_min);
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << BRIGHT_GREEN << BOLD << "\tTesting Double: \n" << RESET;
	// 	std::cout << BOLD << "\t0.0\n" << RESET;
	// 	ScalarConverter::convert("0.0");
	// 	std::cout << BOLD << "\t-1.0\n"  << RESET;
	// 	ScalarConverter::convert("-1.0");
	// 	std::cout << BOLD << "\t42.0\n"  << RESET;
	// 	ScalarConverter::convert("42.0");
	// 	std::string double_max = std::to_string(std::numeric_limits<double>::max());
	// 	std::cout << BOLD << "\t" << double_max << "\n" << RESET;
	// 	ScalarConverter::convert(double_max);
	// 	std::string double_min = std::to_string(std::numeric_limits<double>::lowest());
	// 	std::cout << BOLD << "\t" << double_min << "\n" << RESET;
	// 	ScalarConverter::convert(double_min);
	// }
	return (0);
}
