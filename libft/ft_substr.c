/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:45:36 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/27 12:45:37 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[a] = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (a < len)
	{
		str[a] = s[start + a];
		a++;
	}
		str[a] = '\0';
	return (str);
}

/*int main()
{
  char c[] = "183-55-4899-1368-445";
  char *str;
  str = ft_substr(c, 7, 4);
  printf("%s\n", str);
  return 0;
}*/
