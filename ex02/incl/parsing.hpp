/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:33:48 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/12 17:41:44 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"

bool	g_isOdd = false;

bool	hasTwin(std::vector<int> dummy);
bool	isSorted(std::vector<int> dummy);
bool	notValid(char **av);

