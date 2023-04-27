/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:56:03 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/27 18:59:55 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
