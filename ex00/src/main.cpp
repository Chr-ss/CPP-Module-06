/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/05/13 15:07:40 by crasche       ########   odam.nl         */
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
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tTesting Special: \n" << RESET;
		std::cout << BOLD << "\n\t-inf\n" << RESET;
		ScalarConverter::convert("-inf");
		std::cout << BOLD << "\n\t+inf\n" << RESET;
		ScalarConverter::convert("+inf");
		std::cout << BOLD << "\n\tnan\n" << RESET;
		ScalarConverter::convert("nan");
		std::cout << BOLD << "\n\t-inff\n" << RESET;
		ScalarConverter::convert("-inff");
		std::cout << BOLD << "\n\t+inff\n" << RESET;
		ScalarConverter::convert("+inff");
		std::cout << BOLD << "\n\tnanf\n" << RESET;
		ScalarConverter::convert("nanf");
		std::cout << RESET << std::endl;
	}
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tTesting Char: \n" << RESET;
		std::cout << BOLD << "\n\t'" << "a" << "'\n" << RESET;
		ScalarConverter::convert("'a'");
		std::cout << BOLD << "\n\t'" << "c" << "'\n" << RESET;
		ScalarConverter::convert("'c'");
		std::cout << BOLD << "\n\t'" << "z" << "'\n" << RESET;
		ScalarConverter::convert("'z'");
		std::cout << BOLD << "\n\t'" << "A" << "'\n" << RESET;
		ScalarConverter::convert("'A'");
		std::cout << BOLD << "\n\t'" << "C" << "'\n" << RESET;
		ScalarConverter::convert("'C'");
		std::cout << BOLD << "\n\t'" << "Z" << "'\n" << RESET;
		ScalarConverter::convert("'Z'");
		std::cout << BOLD << "\n\t'" << "0" << "'\n" << RESET;
		ScalarConverter::convert("'0'");
		std::cout << BOLD << "\n\t'" << "1" << "'\n" << RESET;
		ScalarConverter::convert("'1'");
		std::cout << BOLD << "\n\t'" << "9" << "'\n" << RESET;
		ScalarConverter::convert("'9'");
		std::cout << BOLD << "\n\t'" << "!" << "'\n" << RESET;
		ScalarConverter::convert("'!'");
		std::cout << BOLD << "\n\t'" << "@" << "'\n" << RESET;
		ScalarConverter::convert("'@'");
		std::cout << BOLD << "\n\t'" << "#" << "'\n" << RESET;
		ScalarConverter::convert("'#'");
		std::cout << BOLD << "\n\t'" << "$" << "'\n" << RESET;
		ScalarConverter::convert("'$'");
		std::cout << std::endl;
	}
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tTesting Int: \n" << RESET;
		std::cout << BOLD << "\n\t42\n" << RESET;
		ScalarConverter::convert("42");
		std::cout << BOLD << "\n\t0\n" << RESET;
		ScalarConverter::convert("0");
		std::cout << BOLD << "\n\t-0\n" << RESET;
		ScalarConverter::convert("-0");
		std::cout << BOLD << "\n\t-1\n" << RESET;
		ScalarConverter::convert("-1");

		// A 32-bit float only has 23 bits of precision in the
		// mantissa (plus 1 implicit bit). That gives you about
		// 6 to 7 decimal digits of precision.
		// But 2147483647 has 10 decimal digits, so the float cannot
		// represent it exactly. It rounds to the nearest representable
		// float, which is slightly off.
		std::cout << BOLD << "\n\t2147483647\n" << RESET;
		ScalarConverter::convert("2147483647");
		std::cout << BOLD << "\n\t-2147483648\n" << RESET;
		ScalarConverter::convert("-2147483648");
		std::cout << BOLD << "\n\t2147483648\n" << RESET;
		ScalarConverter::convert("2147483648");

		// A 32-bit float only has 23 bits of precision in the
		// mantissa (plus 1 implicit bit). That gives you about
		// 6 to 7 decimal digits of precision.
		std::cout << BOLD << "\n\t-2147483649\n" << RESET;
		ScalarConverter::convert("-2147483649");
		std::cout << std::endl;
	}
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tTesting Float: \n" << RESET;
		std::cout << BOLD << "\n\t42.0f\n" << RESET;
		ScalarConverter::convert("42.0f");
		std::cout << BOLD << "\n\t0.0f\n" << RESET;
		ScalarConverter::convert("0.0f");
		std::cout << BOLD << "\n\t-0.0f\n" << RESET;
		ScalarConverter::convert("-0.0f");
		std::cout << BOLD << "\n\t-1.0f\n" << RESET;
		ScalarConverter::convert("-1.0f");
		std::cout << BOLD << "\n\t2147483647.0f\n" << RESET;
		ScalarConverter::convert("2147483647.0f");
		std::cout << BOLD << "\n\t-2147483648.0f\n" << RESET;
		ScalarConverter::convert("-2147483648.0f");
		std::cout << BOLD << "\n\t2147483648.0f\n" << RESET;
		ScalarConverter::convert("2147483648.0f");
		std::cout << BOLD << "\n\t-2147483649.0f\n" << RESET;
		ScalarConverter::convert("-2147483649.0f");
		// std::string float_max = std::to_string(std::numeric_limits<float>::max());
		std::string float_max = "340282346638528859811704183484516925440.0f";
		std::cout << BOLD << "\n\t" << float_max << "\n" << RESET;
		ScalarConverter::convert(float_max);
		// std::string float_min = std::to_string(std::numeric_limits<float>::lowest());
		std::string float_min = "-340282346638528859811704183484516925440.0f";
		std::cout << BOLD << "\n\t" << float_min << "\n" << RESET;
		ScalarConverter::convert(float_min);
		std::cout << std::endl;
	}
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tTesting Double: \n" << RESET;
		std::cout << BOLD << "\n\t0.0\n" << RESET;
		ScalarConverter::convert("0.0");
		std::cout << BOLD << "\n\t-1.0\n"  << RESET;
		ScalarConverter::convert("-1.0");
		std::cout << BOLD << "\n\t42.0\n"  << RESET;
		ScalarConverter::convert("42.0");
		std::string double_max = std::to_string(std::numeric_limits<double>::max());
		std::cout << BOLD << "\n\t" << double_max << "\n" << RESET;
		ScalarConverter::convert(double_max);
		std::string double_min = std::to_string(std::numeric_limits<double>::lowest());
		std::cout << BOLD << "\n\t" << double_min << "\n" << RESET;
		ScalarConverter::convert(double_min);
	}
	return (0);
}
