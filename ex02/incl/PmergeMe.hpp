/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:31 by vagrant           #+#    #+#             */
/*   Updated: 2023/04/01 20:12:03 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <utility>

# include <vector>
# include <list>

# include "errors.h"
# include "colours.h"

template<typename T>
void	printContainer(const T container, std::string name);

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &rhs);
		~PmergeMe();

		std::vector<int>	mergeInsertVec(std::vector<int> &unsorted);
		std::list<int>		mergeInsertList(std::list<int> &unsorted);
};

# include "printContainer.tpp"
