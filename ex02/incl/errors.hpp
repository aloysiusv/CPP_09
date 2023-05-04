/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:07:54 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 17:44:46 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum ErrorCode {
	E_BAD_USE = 1,
	E_EMPTY,
	E_NOT_DIGIT,
	E_NO_NEG,
	E_BAD_INT,
	E_TWIN,
	E_SORTED
};

int err(ErrorCode code);