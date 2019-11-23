/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgupta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:42:16 by mgupta            #+#    #+#             */
/*   Updated: 2019/11/10 21:42:19 by mgupta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_h
#define GET_NEXT_LINE_h

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include<stdio.h> 
#include<stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <string.h>

int	get_next_line(int fd, char **line);
#endif