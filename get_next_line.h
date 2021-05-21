/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:04:59 by vmelkony          #+#    #+#             */
/*   Updated: 2021/04/23 20:16:54 by vmelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int					get_next_line(int fd, char **line);
int					has_new_line(char *str);
int                   ft_strchr(const char *s, int c);
unsigned long        ft_strlen(const char *s);
char                *ft_strjoin(char *memory, char *buffer);

#endif
