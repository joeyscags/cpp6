/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:00:00 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/24 16:48:06 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base::~Base() {}

Base* generate(void)
{
	return nullptr;
}

void identify(Base* p)
{
	std::cout << "identify(Base*) called" << std::endl;
}

void identify(Base& p)
{
	std::cout << "identify(Base&) called" << std::endl;
}
