/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/05/15 18:03:18 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialization.hpp"

int main()
{
	{
		std::cout << BRIGHT_GREEN << BOLD << "\n\tInit Data: \n" << RESET;
		Data *data = new Data;
		data->i = 42;
		data->c = 'a';
		std::cout << "data: " << data << std::endl;
		std::cout << "data->i: " << data->i << std::endl;
		std::cout << "data->c: " << data->c << std::endl;
		std::cout << BRIGHT_GREEN << BOLD << "\n\tserialize: \n" << RESET;
		uintptr_t data_raw = Serialization::serialize(data);

		std::cout << "data_raw: " << data_raw << std::endl;

		std::cout << BRIGHT_GREEN << BOLD << "\n\tdeserialize: \n" << RESET;
		Data *data2 = Serialization::deserialize(data_raw);

		std::cout << "data2: " << data2 << std::endl;
		std::cout << "data2->i: " << data2->i << std::endl;
		std::cout << "data2->c: " << data2->c << std::endl;

		std::cout << BRIGHT_GREEN << BOLD << "\n\tDeleting over deserialize ptr: \n" << RESET;
		data = NULL;
		delete data2;
		data2 = NULL;
	}
	return (0);
}
