/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:52 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/30 16:33:53 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

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
		_dataCSV[key] = exchgRate;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) : _dataCSV(rhs._dataCSV) {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {

	this->_dataCSV = rhs._dataCSV;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED "Destructor BitcoinExchange!\n" RESET;
}

void	BitcoinExchange::ApplyXCHRate(std::string date, std::string nbBTC) {

	std::map<std::string, float>::const_iterator	ite = _dataCSV.find(date);

	if (ite == _dataCSV.end()) {
		ite = _dataCSV.lower_bound(date);
		--ite;
	}

	float	rate = ite->second;
	float	bitcoins = atof(nbBTC.c_str());
	float	cost = bitcoins * rate;

	std::cout << date << " => " << nbBTC << " = " << cost << std::endl;
}
