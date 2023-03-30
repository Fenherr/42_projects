/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:49:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/30 11:53:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t *raw;
	
	raw = reinterpret_cast<uintptr_t *>(ptr);
	return *raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr;
	
	ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}