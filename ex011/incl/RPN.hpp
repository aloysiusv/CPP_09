/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:54:20 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/23 01:55:01 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <bits/stdc++.h>

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

# include <stack>

# include "colours.h"

class RPN {

	public:
		RPN();
		RPN(const RPN &rhs);
		RPN& operator=(const RPN &rhs);
		~RPN();
};
