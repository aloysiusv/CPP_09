/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:52 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/22 21:27:26 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

	std::cout << BLUE "Default constructor BitcoinExchange " END << std::endl;
	
	std::ifstream	file("data.csv");
	if (!file.is_open()) {
		std::cerr << RED "btc: can't open data.csv" END << std::endl;
		return;
	}

	std::string			line;
	std::string			key;

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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : dataCSV(cpy.dataCSV) {
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& asgn) {

	this->dataCSV = asgn.dataCSV;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED "💥 Destructor BitcoinExchange " << std::endl;
}

void	BitcoinExchange::ApplyXCHRate(std::string date, std::string nbBTC) {

	std::map<std::string, float>::const_iterator	ite = dataCSV.find(date);

	if (ite == dataCSV.end()) {
		ite = dataCSV.lower_bound(date);
		--ite;
	}

	float											rate = ite->second;
	float											bitcoins = std::atof(nbBTC.c_str());
	float											cost = bitcoins * rate;

	std::cout << date << " => " << nbBTC << " = " << cost << std::endl;
}
