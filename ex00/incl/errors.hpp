/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:59:53 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 17:39:16 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum ErrorCode {
    E_BAD_USE = 1,
    E_BAD_INPUT,
    E_CANT_OPEN,
    E_BAD_FILE,
    E_BAD_DATE,
	E_BAD_DELIM,
    E_BAD_BTC,
};

int		err(ErrorCode code, const std::string &filename);
int		date_err(const std::string& line);
int		delim_err(const std::string& line);
int		nbBTC_err(const std::string& nbBTC);
