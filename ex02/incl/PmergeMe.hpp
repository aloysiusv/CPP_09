/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagrant <vagrant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:31 by vagrant           #+#    #+#             */
/*   Updated: 2023/03/24 16:15:21 by vagrant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>

# include <vector>
# include <list>

# include "errors.h"
# include "colours.h"

class PmergeMe {

	public:
		PmergeMe(const char** av);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe    &operator=(const PmergeMe &rhs);    
		~PmergeMe();

		void				mergeInsert();
		void				printSorted();

		std::vector<int>	myVec;
		std::list<int>		myLst;
}
