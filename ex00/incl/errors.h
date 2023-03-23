/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:56:03 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/23 01:15:52 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum ErrorCode {
    E_BAD_USE = 1,
    E_BAD_INPUT,
    E_CANT_OPEN,
    E_BAD_FILE,
    E_BAD_DATE,
    E_BAD_BTC
};

static const int MIN_YEAR = 2009;
static const int MAX_YEAR = 2022;
