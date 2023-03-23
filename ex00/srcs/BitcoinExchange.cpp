/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:52 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/23 01:35:17 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string database) {

	std::cout << BLUE "Parameterised constructor BitcoinExchange!\n" RESET;
	
	std::ifstream	file(database.c_str());

	if (!file.is_open()) {
		std::cerr << YELLOW "Error: " RESET "btc: can't open data.csv";
		return;
	}

	std::string		line;
	std::string		key;

	std::getline(file, line);
	while (std::getline(file, line)) {	
		
		std::stringstream	ss(line);
	
		std::getline(ss, key, ',');
		float exchgRate;
		ss >> exchgRate;
		dataCSV[key] = exchgRate;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) : dataCSV(rhs.dataCSV) {
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {

	this->dataCSV = rhs.dataCSV;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED "Destructor BitcoinExchange!\n" RESET;
}

void	BitcoinExchange::ApplyXCHRate(std::string date, std::string nbBTC) {

	std::map<std::string, float>::const_iterator	ite = dataCSV.find(date);

	if (ite == dataCSV.end()) {
		ite = dataCSV.lower_bound(date);
		--ite;
	}

	float	rate = ite->second;
	float	bitcoins = atof(nbBTC.c_str());
	float	cost = bitcoins * rate;

	std::cout << date << " => " << nbBTC << " = " << cost << std::endl;
}
