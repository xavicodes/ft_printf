/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:29:21 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/05/02 17:35:48 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_putnbr(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 12);
			return(ft_dividenbr(n));
		}
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr((n / 10));
		digit = (n % 10) + '0';
		ft_putchar(digit);
	}
        return(ft_dividenbr(n));
}