/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/04/10 11:31:26 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP6_DATA_HPP
# define CPP6_DATA_HPP

# include <cstdint>

class Data{
private:
	Data(const Data &toCopy) = delete;
	Data& operator=(const Data &other) = delete;
public:
	Data() = delete;
	~Data() = delete;
	int i;
};

#endif // CPP6_DATA_HPP