/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/05/15 18:30:24 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

int main()
{
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tbasic test: \n" << RESET;
		Base *base = generate();
		std::cout << "base ptr: " << base << std::endl;
		identify(base);
		identify(*base);
		delete base;
		base = NULL;
	}
	return (0);
}
