/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:13:04 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/29 17:55:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "errors.h"

static int err(ErrorCode code, const std::string &filename) {
	switch (code) {
		case (E_BAD_USE):
			std::cerr << YELLOW "Error: " RESET "[usage]: ./btc <filename>.txt.\n";
			break;
		case (E_BAD_INPUT):
			std::cerr << YELLOW "Error: " RESET "something is wrong with the input.\n";
			break;
		case (E_CANT_OPEN):
			std::cerr << YELLOW "Error: " RESET "unable to open file " << filename << std::endl;
			break;
		case (E_BAD_FILE):
			std::cerr << YELLOW "Error: " RESET "file " << filename << " is empty or is a directory.\n";
			break;
		case (E_BAD_SEP):
			std::cerr << GREEN << filename << RESET << "\n" << YELLOW "Error: " RESET "no \"|\"? Really?.\n";
			break;
		case (E_BAD_DATE):
			std::cerr << YELLOW "Error: " RESET "invalid date.\n";
			break;
		case (E_BAD_BTC):
			std::cerr << YELLOW "Error: " RESET "invalid amount of bitcoins.\n";
			break;
		default:
			return EXIT_SUCCESS;
	}
	return static_cast<int>(code);
}

static size_t countOccur(char c, std::string &str) {

	size_t		count = 0;

	for (size_t i = 0; i < str.length(); ++i)
		if (str[i] == c)
			++count;
	return (count);
}

static int date_err(const std::string &date, const std::string &filename) {
	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	}

	std::string day_str		= date.substr(8, 2);
	std::string month_str	= date.substr(5, 2);
	std::string year_str	= date.substr(0, 4);

	int day					= atoi(day_str.c_str());
	int month				= atoi(month_str.c_str());
	int year				= atoi(year_str.c_str());

	static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static const int MIN_YEAR = 2009;
	static const int MAX_YEAR = 2022;

	if (month < 1 || month > 12)
		return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	else if (day < 2 && month == 1 && year == MIN_YEAR)
		return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	else if (day < 1 || day > daysInMonth[month])
		return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	else if (month == 2 && day == 29 && (!(year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	else if (year < MIN_YEAR || year > MAX_YEAR)
		return (std::cout << GREEN << date << RESET << std::endl, err(E_BAD_DATE, filename));
	return (EXIT_SUCCESS);
}

static int nbBTC_err(std::string& nbBTC) {

	if (nbBTC.length() < 1)
		return (std::cout << GREEN << nbBTC << RESET << std::endl, err(E_BAD_BTC, "default"));
	else if (countOccur('.', nbBTC) > 1)
		return (std::cout << GREEN << nbBTC << RESET << std::endl, err(E_BAD_BTC, "default"));
	else if (atof(nbBTC.c_str()) < 0 || atof(nbBTC.c_str()) > 1000)
		return (std::cout << GREEN << nbBTC << RESET << std::endl, err(E_BAD_BTC, "default"));
	return (EXIT_SUCCESS);
}

static int	rohJessica(std::string line) {
	return err(E_BAD_SEP, line);
}

int main(int ac, char **av) {

	if (ac != 2)
		return err(E_BAD_USE, "default");
	
	std::ifstream		infile;
	std::string			filename;

	filename = av[1];
	infile.open(filename.c_str());
	if (!infile.is_open())
		return err(E_CANT_OPEN, filename);
	if (infile.peek() == std::ifstream::traits_type::eof())
		return err(E_BAD_FILE, filename);
	
	BitcoinExchange		myBTC("data.csv");
	
	std::string			line;
	std::string			date;
	std::string 		nbBTC;
	size_t				delim;

	getline(infile, line);
	if (line != "date | value")
		return (std::cout << GREEN << line << RESET << std::endl, err(E_BAD_INPUT, filename));

	while (infile.eof() == false) {
		
		int				hasErr = 0;
		
		getline(infile, line);
		if (line.empty())
			continue;
		date = line.substr(0, 10);
		hasErr += date_err(date, filename);
		delim = line.find("|");
		if (delim == std::string::npos)
			if (hasErr == 0)
				hasErr += rohJessica(line);
		nbBTC = line.substr((delim + 1), line.length());
		if (hasErr == 0)
			hasErr += nbBTC_err(nbBTC);
		if (hasErr == 0)
			myBTC.ApplyXCHRate(date, nbBTC);
	}
	infile.close();
	return (EXIT_SUCCESS);
}
