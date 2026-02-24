/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:00:00 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/22 18:49:20 by joeyscags        ###   ########.fr       */
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

	std::cout << "Original pointer: " << &data << std::endl;

	return 0;
}
