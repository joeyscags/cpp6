/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:00:00 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/24 20:04:35 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"

int main(void)
{
	std::cout << "=== Base class type identification test ===" << std::endl;
	std::cout << std::endl;

	// Test 1: Generate and identify with pointer
	std::cout << "--- Test 1: Pointer identification ---" << std::endl;
	Base* obj1 = generate();
	std::cout << "Identified via pointer: ";
	identify(obj1);
	std::cout << std::endl;

	// Test 2: Identify with reference
	std::cout << "--- Test 2: Reference identification ---" << std::endl;
	std::cout << "Identified via reference: ";
	identify(*obj1);
	std::cout << std::endl;
	delete obj1;

	// Test 3: Multiple random objects
	std::cout << "--- Test 3: Multiple random objects ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\nObject " << i + 1 << ": ";
		Base* obj = generate();
		std::cout << "Pointer: ";
		identify(obj);
		std::cout << "Reference: ";
		identify(*obj);
		delete obj;
	}

	return 0;
}
