/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:10:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/17 22:46:03 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int nb, int *lenght)
{
	int	c;

	c = 0;
	if (nb <= 9)
	{
		c = '0' + nb;
		ft_putchar_lenght(c, lenght);
	}
	else if (nb > 9)
		ft_print_putnbr((nb / 10), lenght);
	ft_print_putnbr(nb % 10, lenght);
}
