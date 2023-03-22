/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:12:52 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/22 15:21:36 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

	std::cout << BLUE "Default constructor BitcoinExchange " << std::endl;
	
	std::ifstream	file("data.csv");
	if (!file.is_open()) {
    	std::cerr << RED "btc: can't open data.csv" << std::endl;
   		return;
	}

	String			line;
	String			key;
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

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {};

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& asgn) {
// 	return *this;
// }

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED "💥 Destructor BitcoinExchange " << std::endl;
}

void	BitcoinExchange::ApplyXCHRate(String date, String nbBTC) {

	std::map<std::string, float>::const_iterator	ite = dataCSV.find(date);

	if (ite == dataCSV.end()) {
		ite = dataCSV.lower_bound(date);
		--ite;
	}

	float											rate = ite->second;
	float											bitcoins = std::strtof(nbBTC.c_str(), NULL);
	float											cost = bitcoins * rate;

	std::cout << date << " => " << nbBTC << " = " << cost << std::endl;
}
