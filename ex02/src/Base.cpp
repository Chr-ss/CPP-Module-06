/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/05/15 17:43:23 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void) {
	srand(time(0));
	switch (rand() % 3) {
		case 0:
			std::cout << "A" << std::endl;
			return new A();
		case 1:
			std::cout << "B" << std::endl;
			return new B();
		case 2:
			std::cout << "C" << std::endl;
			return new C();
		default:
			std::cout << "Unknown type" << std::endl;
			return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (const std::bad_cast &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		} catch (const std::bad_cast &e) {
			std::cout << "C" << std::endl;
		}
	}
}