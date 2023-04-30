/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:13:04 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/30 18:23:38 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
