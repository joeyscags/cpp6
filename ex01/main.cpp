/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:00:00 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/24 13:55:04 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;
	
	data.id = 42;
	data.name = "Test";
	data.value = 3.14;

	std::cout << "Original Data:" << std::endl;
	std::cout << "  Address: " << &data << std::endl;
	std::cout << "  id: " << data.id << std::endl;
	std::cout << "  name: " << data.name << std::endl;
	std::cout << "  value: " << data.value << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized: 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "  Address: " << ptr << std::endl;
	std::cout << "  id: " << ptr->id << std::endl;
	std::cout << "  name: " << ptr->name << std::endl;
	std::cout << "  value: " << ptr->value << std::endl;
	std::cout << std::endl;

	if (ptr == &data)
		std::cout << "✓ Success: Pointers match!" << std::endl;
	else
		std::cout << "✗ Error: Pointers don't match!" << std::endl;

	return 0;
}
