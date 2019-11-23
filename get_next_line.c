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

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i != len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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
	if (fd == -1 || line == NULL || fd > 10 || BUFFER_SIZE<1)
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

int check_newl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
//			printf("\t\t NEline found!!\n");
			return (1);
		}
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
//		printf("\tBuff:|%s| and str:|%s| and ret |%d|\n", buff, str,ret);
	}
	
	if (check_newl(str))
		return (str);
	else if(ret == 0)
	{
		*i = 0;
		return(str);
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
	int ret;
	if (checkerror(fd, &str, line) == -1)
		return (-1);
	i = 0;
	ret = 1;
	str = readline(str, fd, &ret);
/*	printf("Debug-----------Start----------------\n");
	printf("Value of S: #%s#\n",str);
	printf("Debug*********************************\n");
*/	while (str[i] != '\n' && str[i])
		i++;
	if (i == 0)
		(*line) = strdup("");
	else
		(*line) = ft_strsub(str, 0, i);
	str = &str[i + 1];
	//printf("value of ret: %d", ret);
	return (ret);
}
/*
int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;

	if (!(fd = open("./t.txt", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s|\n", line);
	}
	printf("|%s|\n", line);
}*/