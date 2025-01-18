/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/01/17 17:17:59 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << BOLD << CYAN << "\n\tTest 1 (Construction)"<< RESET << std::endl;
		Bureaucrat defaultBureaucrat;
		std::cout << "Announcing: " << defaultBureaucrat << RESET;
		Bureaucrat nameBureaucrat("NAME");
		std::cout << "Announcing: " << nameBureaucrat << RESET;
		Bureaucrat gradeBureaucrat(10);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		Bureaucrat nameGradeBureaucrat("ME", 55);
		std::cout << "Announcing: " << nameGradeBureaucrat << RESET;
		Bureaucrat copyBureaucrat(gradeBureaucrat);
		std::cout << "Announcing: " << copyBureaucrat << RESET;
		copyBureaucrat = nameGradeBureaucrat;
		std::cout << "Announcing: " << copyBureaucrat << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 2 (Exception)"<< RESET << std::endl;
		try
		{
			Bureaucrat gradeTooHighBureaucrat("TOO HIGH", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat gradeTooLowBureaucrat("TOO LOW", 151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 3 (increment/decrement)"<< RESET << std::endl;
		Bureaucrat gradeBureaucrat("SomeGuy", 88);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.incrementGrade();
			std::cout << "Announcing: " << gradeBureaucrat << RESET;
			gradeBureaucrat.decrementGrade();
			std::cout << "Announcing: " << gradeBureaucrat << RESET;
			gradeBureaucrat.decrementGrade();
			std::cout << "Announcing: " << gradeBureaucrat << RESET;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 4 (setGrade)"<< RESET << std::endl;
		Bureaucrat gradeBureaucrat("LameGuy", 66);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.setGrade(0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.setGrade(151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.setGrade(1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 5 (getters)"<< RESET << std::endl;
		Bureaucrat gradeBureaucrat("CoolGuy", 1);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		std::cout << "Name: " << gradeBureaucrat.getName() << std::endl;
		std::cout << "Grade: " << gradeBureaucrat.getGrade() << std::endl;
	}
}
