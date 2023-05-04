/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:13:04 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 18:49:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

enum ErrorCode {
    E_BAD_USE = 1,
    E_BAD_INPUT,
    E_CANT_OPEN,
    E_BAD_FILE,
    E_BAD_DATE,
	E_BAD_DELIM,
    E_BAD_BTC,
};

int err(ErrorCode code, const std::string &element) {
	switch (code) {
		case (E_BAD_USE):
			std::cerr << YELLOW "Error: " RESET "[usage]: ./btc <filename>.txt.\n";
			break;
		case (E_BAD_INPUT):
			std::cerr << YELLOW "Error: " RESET "something is wrong with the input: "
					  << ORANGE << element << RESET << std::endl;
			break;
		case (E_CANT_OPEN):
			std::cerr << YELLOW "Error: " RESET "unable to open file " 
					  << ORANGE << element << RESET << std::endl;
			break;
		case (E_BAD_FILE):
			std::cerr << YELLOW "Error: " RESET "file " 
					  << ORANGE << element << " is empty or is a directory.\n";
			break;
		case (E_BAD_DATE):
			std::cerr << YELLOW "Error: " RESET "invalid date => "
					  << ORANGE << element << RESET << std::endl;
			break;
		case (E_BAD_DELIM):
			std::cerr << YELLOW "Error: " RESET "no proper \"|\"? Really? "
					  << ORANGE << element << RESET << std::endl;
			break;
		case (E_BAD_BTC):
			std::cerr << YELLOW "Error: " RESET "invalid amount of bitcoins => "
					  << ORANGE << element << RESET << std::endl;
			break;
		default:
			return EXIT_SUCCESS;
	}
	return static_cast<int>(code);
}

static int date_err(const std::string &line) {
	
	if (line.length() < 10 || line[4] != '-' || line[7] != '-')
		return err(E_BAD_DATE, line);
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(line[i]))
			return err(E_BAD_DATE, line);
	}

	std::string			day_str = line.substr(8, 2);
	std::string			month_str = line.substr(5, 2);
	std::string			year_str = line.substr(0, 4);

	int 				day = atoi(day_str.c_str());
	int 				month = atoi(month_str.c_str());
	int 				year = atoi(year_str.c_str());

	static const int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static const int	MIN_YEAR = 2009;
	static const int	MAX_YEAR = 2022;

	if (month < 1 || month > 12)
		return err(E_BAD_DATE, line);
	else if (day < 2 && month == 1 && year == MIN_YEAR)
		return err(E_BAD_DATE, line);
	else if (day < 1 || day > daysInMonth[month])
		return err(E_BAD_DATE, line);
	else if (month == 2 && day == 29 && (!(year % 4 == 0 && year % 100 == 0 && year % 400 == 0)))
		return err(E_BAD_DATE, line);
	else if (year < MIN_YEAR || year > MAX_YEAR)
		return err(E_BAD_DATE, line);
	return EXIT_SUCCESS;
}

static size_t countOccur(char c, const std::string &str) {

	size_t	count = 0;

	for (size_t i = 0; i < str.length(); ++i)
		if (str[i] == c)
			++count;
	return count;
}

static int	delim_err(const std::string& line) {

	if (countOccur('|', line) != 1)
		return err(E_BAD_DELIM, line);
	return EXIT_SUCCESS;
}

static int nbBTC_err(const std::string& nbBTC) {

	if (nbBTC.length() < 1)
		return err(E_BAD_BTC, ":'(");
	else if (countOccur('.', nbBTC) > 1)
		return err(E_BAD_BTC, nbBTC);
	else if (atof(nbBTC.c_str()) < 0 || atof(nbBTC.c_str()) > 1000)
		return err(E_BAD_BTC, nbBTC);
	return EXIT_SUCCESS;
}

static int launchXchange(std::ifstream &infile) {

	BitcoinExchange		myBTC("data.csv");
	
	std::string			line;
	std::string			date;
	std::string 		nbBTC;
	size_t				delim;

	getline(infile, line);
	if (line != "date | value")
		return err(E_BAD_INPUT, line);
	while (infile.eof() == false) {
	
		int				mistake = 0;
	
		getline(infile, line);
		if (line.empty())
			continue;
		mistake += date_err(line);
		if (!mistake) {
			date = line.substr(0, 10);
			mistake += delim_err(line);
		}
		if (!mistake) {
			delim = line.find("|");
			nbBTC = line.substr((delim + 1), line.length());
			mistake += nbBTC_err(nbBTC);
		}
		if (!mistake)
			myBTC.ApplyXCHRate(date, nbBTC);			
	}
	return EXIT_SUCCESS;
}

int main(int ac, char **av) {

	if (ac != 2)
		return err(E_BAD_USE, ":'(");

	std::ifstream		infile;
	std::string			filename;
	int					exitCode;

	filename = av[1];
	
	infile.open(filename.c_str());
	if (!infile.is_open())
		return err(E_CANT_OPEN, filename);
	if (infile.peek() == std::ifstream::traits_type::eof())
		return err(E_BAD_FILE, filename);
	exitCode = launchXchange(infile);
	infile.close();
	
	if (exitCode != EXIT_SUCCESS)
		return exitCode;
	return EXIT_SUCCESS;
}
