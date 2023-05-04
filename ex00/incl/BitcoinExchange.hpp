/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:36 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 18:59:36 by lrandria         ###   ########.fr       */
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

# include <map>

# include "colours.h"

class BitcoinExchange {

	private:
		BitcoinExchange();
		
		std::map<std::string, float>	_dataCSV;

	public:
		BitcoinExchange(std::string database);
		BitcoinExchange(const BitcoinExchange &rhs);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		void	ApplyXCHRate(std::string date, std::string nbBTC);

};
