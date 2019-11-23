/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgupta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:41:26 by mgupta            #+#    #+#             */
/*   Updated: 2019/11/10 21:41:28 by mgupta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ans = (char *)malloc(len + 1)))
		return (NULL);
	while (*s1)
		*ans++ = *s1++;
	while (*s2)
		*ans++ = *s2++;
	*ans = '\0';
	return (ans - len);
}

int		checkerror(int fd, char **str, char **line)
{
	if (fd <= -1 || line == NULL || fd > 10 || BUFFER_SIZE < 1)
	{
		return (-1);
	}
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

int		check_newl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*readline(char *str, int fd, int *i)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	char	*temp;

	ret = read(fd, buff, BUFFER_SIZE);
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	if (check_newl(str))
		return (str);
	else if (ret == 0)
	{
		*i = 0;
		return (str);
	}
	else
	{
		temp = str;
		str = readline(str, fd, i);
		free(temp);
	}
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str;
	int			i;
	int			ret;

	if (checkerror(fd, &str, line) == -1)
		return (-1);
	i = 0;
	ret = 1;
	str = readline(str, fd, &ret);
	while (str[i] != '\n' && str[i])
		i++;
	if (i == 0)
		(*line) = ft_strdup("");
	else
		(*line) = ft_strsub(str, 0, i);
	str = &str[i + 1];
	return (ret);
}
/*
int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;

	if (!(fd = open("./t.txt", O_RDWR | O_CREAT)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	printf("%s\n", line);
}*/