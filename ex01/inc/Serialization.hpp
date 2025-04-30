/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialization.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/04/10 11:31:53 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <cstdint>
# include "Data.hpp"

# define RESET          "\033[0m"
# define BLACK          "\033[30m"
# define WHITE          "\033[37m"
# define BRIGHT_WHITE   "\033[97m"
# define RED            "\033[31m"
# define BRIGHT_RED     "\033[91m"
# define YELLOW         "\033[33m"
# define BRIGHT_YELLOW  "\033[93m"
# define BLUE           "\033[34m"
# define LIGHT_BLUE     "\033[38;5;123m"
# define BRIGHT_BLUE    "\033[94m"
# define MAGENTA        "\033[35m"
# define BRIGHT_MAGENTA "\033[95m"
# define CYAN           "\033[36m"
# define BRIGHT_CYAN    "\033[96m"
# define GREEN          "\033[32m"
# define BRIGHT_GREEN   "\033[92m"
# define GRAY           "\033[90m"
# define LIGHT_GRAY     "\033[37m"
# define DARK_GRAY      "\033[90m"
# define ORANGE         "\033[38;5;208m"
# define PINK           "\033[38;5;213m"
# define PURPLE         "\033[38;5;129m"
# define BOLD           "\033[1m"
# define UNDERLINE      "\033[4m"

class Serialization{
private:
	Serialization();
	~Serialization();
	Serialization(const Serialization &toCopy);
	Serialization& operator=(const Serialization &other);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZATION_HPP