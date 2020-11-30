/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrxy <mrxy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:21:21 by ysarsar           #+#    #+#             */
/*   Updated: 2020/11/30 15:30:59 by mrxy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		braces_checker(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == '{' && str[i + 1] == ' ')
	{
		i = 2;
		while (str[i] && str[i] != '}')
		{
			if (str[i] == '{' || str[i] == '(' || str[i] == ')')
				return (0);
			i++;
		}
		if (str[i--] == '}')
		{
			while ((str[i] == ' ' || str[i] == '\t') && i > 0)
				i--;
			return (str[i] == ';' ? 1 : 0);
		}
		return (0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	i = braces_checker(av[1]);
	if (i > 0)
		printf("checker SUCCESS\n");
	else if (i == 0)
		printf("checker ERROR\n");
	else
		printf("checker not complete!!\n");
	return (0);
}