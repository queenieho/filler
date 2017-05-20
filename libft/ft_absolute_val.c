/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 11:25:53 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 14:00:25 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_absolute_val(int n)
{
	if (n < 0)
		n = (unsigned int)-n;
	return ((unsigned int)n);
}
