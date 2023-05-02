/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printContainer.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:46:49 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/02 18:28:05 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "PmergeMe.hpp"

template<typename T>
void	printContainer(const T container, std::string name) {

	typename T::const_iterator it;
	
	std::cout << "\n" << name << "=> [ ";
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]\n";
}
