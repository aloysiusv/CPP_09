/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:36 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/22 21:26:11 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------- C O L O R S ---------*/

#define GREY "\033[0;30m"
#define RORED "\033[0;31m"
#define RED "\033[0;91m"
#define GREEN "\033[0;32m"
#define YELW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PINK "\033[0;35m"
#define TURQ "\033[0;36m"
#define WHITE "\033[0;97m"
#define BWHITE "\033[1;97m"
#define LWHITE "\033[4;97m"
#define END "\e[0m"

/*------ L I B R A R I E S ------*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>


/*------ T Y P E D E F S ------*/

typedef	unsigned int	uint;

/*-------- C L A S S E S --------*/

class BitcoinExchange {

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		BitcoinExchange& operator=(const BitcoinExchange& asgn);
		~BitcoinExchange();

		void	ApplyXCHRate(std::string date, std::string nbBTC);

		std::map<std::string, float>	dataCSV;
};

/*---------- O T H E R ----------*/


