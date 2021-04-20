/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:04:59 by vmelkony          #+#    #+#             */
/*   Updated: 2021/04/20 19:05:51 by vmelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
int					has_return(char *str);

size_t				ft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);

#endif
