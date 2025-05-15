/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialization.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/05/15 17:43:23 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialization.hpp"

Serialization::Serialization() {}

Serialization::~Serialization() {}

Serialization::Serialization(const Serialization &toCopy) {
	*this = toCopy;
}

Serialization& Serialization::operator=(const Serialization &other) {
	if (this != &other) {
	}
	return *this;
}

uintptr_t Serialization::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}