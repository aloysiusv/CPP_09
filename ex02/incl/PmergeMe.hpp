/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:31 by vagrant           #+#    #+#             */
/*   Updated: 2023/05/05 16:53:58 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <ctime>   // clock for elapsed time
# include <climits> // INT macros

# include <vector>
# include <list>

# include "colours.h"

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(const std::vector<int>);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &rhs);
		~PmergeMe();

		std::vector<int>	mergeInsertVec(std::vector<int> &unsorted);
		std::list<int>		mergeInsertLst(std::list<int> &unsorted);

		template<typename T>
		void				printContainer(const T container, std::string name) {
			typename T::const_iterator it;
			std::cout << "\n" << name << "=> [ ";
			for (it = container.begin(); it != container.end(); ++it) 
				std::cout << *it << " ";
			std::cout << "]\n";
		}
};
