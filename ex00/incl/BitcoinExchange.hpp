/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:36 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 23:20:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "colours.h"
# include <bits/stdc++.h> // atof

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

# include <map>


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
