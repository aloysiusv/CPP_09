/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:56:03 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 17:39:56 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum ErrorCode {
    E_BAD_USE = 1,
	E_EMPTY,
    E_BAD_START,
    E_INVALID_CHAR,
    E_NO_SPACE,
	E_INSUFFICIENT_OP,
	E_DIV_BY_ZERO,
	E_TOO_MANY
};

int		err(ErrorCode code);
bool	isop(int c);
