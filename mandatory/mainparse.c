/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:54:07 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/22 22:13:21 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;
	int res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	res = ft_atoi(str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	if (res == 0 && str[0] != '0')
		return (0);
	return(1);
}
#include <stdio.h>

int main()
{
    const char *valid = "1 2 3";
    const char *overflow = "21474836488888888";
    const char *garbage = "one";

    printf("%s is %s\n", valid, is_valid_number(valid) ? "valid" : "invalid");
    printf("%s is %s\n", overflow, is_valid_number(overflow) ? "valid" : "invalid");
    printf("%s is %s\n", garbage, is_valid_number(garbage) ? "valid" : "invalid");

    return 0;
}
