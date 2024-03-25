/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:02:08 by wacista           #+#    #+#             */
/*   Updated: 2024/03/25 08:04:11 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0 || !((str[i - 1] >= 'a' && str[i - 1] <= 'z') || \
			(str[i - 1] >= 'A' && str[i - 1] <= 'Z') || \
			(str[i - 1] >= '0' && str[i - 1] <= '9')))
				str[i] -= 32;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (((str[i - 1] >= 'a' && str[i - 1] <= 'z') || \
			(str[i - 1] >= 'A' && str[i - 1] <= 'Z') || \
			(str[i - 1] >= '0' && str[i - 1] <= '9')))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
