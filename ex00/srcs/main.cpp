/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:13:04 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/22 14:46:01 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/stdc++.h>

static int err(int ret, char **av) {

	if (ret == 1) {
		std::cerr << "Arguments must be : ./btc <filename>.txt\n";
		return (ret);
	}
	if (ret == 2) {
		std::cerr << RED << "Error: " << END << "Unable to open file " << av[1] << std::endl;
		return (ret);
	}
	if (ret == 3) {
		std::cerr << RED << "Error: " << END << "file " << av[1] << " is empty or is a directory\n";
		return (ret);
	}
	if (ret == 4) {
		std::cerr << RED << "Error: " << END << "Bad input in file " << av[1] << " is incorrect\n";
		return (ret);
	}
	if (ret == 5) {
		std::cerr << RED << "Error: " << END << "Invalid date.\n";
		return (ret);
	}
	if (ret == 6) {
		std::cerr << RED << "Error: " << END << "The amount of btc isn't specified or has a bad input.\n";
		return (ret);
	}
	return (EXIT_SUCCESS);
}

static int date_err(String date, char** av) {

	if (date.length() != 10)
			return err(4, av);
	if (date[4] != '-' || date[7] != '-')
		return err(4, av);
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == false)
			return err(4, av);
	}

	String		day = date.substr(8, 2);
	String		month = date.substr(5, 2);
	String		year = date.substr(0, 4);

	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
		return err(5, NULL);
	
	if ((atoi(month.c_str()) == 1 || atoi(month.c_str()) == 3 || atoi(month.c_str()) == 5
		|| atoi(month.c_str()) == 7 || atoi(month.c_str()) == 8 || atoi(month.c_str()) == 10
		|| atoi(month.c_str()) == 12) && (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31))
		return err(5, NULL);
	
	if ((atoi(month.c_str()) == 4 || atoi(month.c_str()) == 6 || atoi(month.c_str()) == 9
		|| atoi(month.c_str()) == 11) && (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 30))
		return err(5, NULL);

	if (atoi(month.c_str()) == 2 && (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 29))
		return err(5, NULL);

	if (atoi(year.c_str()) < 2009 || atoi(year.c_str()) > 2022)
		return err(5, NULL);
	
	return (EXIT_SUCCESS);
}

static size_t countOccur(char c, String &str)
{
	size_t		count = 0;

	for (size_t i = 0; i < str.length(); ++i)
		if (str[i] == c)
			++count;
	return (count);
}

static int nbBTC_err(String nbBTC) {

	if (nbBTC.length() < 1 || nbBTC.length() > 4)
		return err(6, NULL);
	if (countOccur('.', nbBTC) > 1)
		return err(6, NULL);
	if (atof(nbBTC.c_str()) < 0 || atof(nbBTC.c_str()) > 1000)
		return err(6, NULL);
	return 0;
}

int main(int ac, char **av) {

	if (ac != 2)
		return err(1, NULL);
	
	std::ifstream		file;
	String				filename;
	String				buff;
	size_t				delim;

	filename = av[1];
	file.open(filename.c_str());
	if (!file.is_open())
		return err(2, av);
	if (file.peek() == std::ifstream::traits_type::eof())
		return err(3, av);
	
	BitcoinExchange		myBTC;
	String				date;
	String 				nbBTC;
	int					hasErr;

	// DISPLAY MAP
	// std::map<String, float>::iterator it;
	// for (it = myBTC.dataCSV.begin(); it != myBTC.dataCSV.end(); ++it)
	// 	std::cout << "Key: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
	
	getline(file, buff);
	if (buff != "date | value")
		return err (4, av);
	while (file.eof() == false) {
		getline(file, buff);
		if (buff.empty())
			continue;
		delim = buff.find("|");
		date = buff.substr(0, (delim - 1));
		hasErr = date_err(date, av);
		nbBTC = buff.substr((delim + 1), buff.length());
		hasErr = nbBTC_err(nbBTC);
		if (hasErr == 0)
			myBTC.ApplyXCHRate(date, nbBTC);
	}
	file.close();
	return (EXIT_SUCCESS);
}