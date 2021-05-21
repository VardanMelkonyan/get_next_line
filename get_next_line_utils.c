/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:30:24 by vmelkony          #+#    #+#             */
/*   Updated: 2021/05/21 14:41:11 by vmelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int                    ft_strchr(const char *s, int c)
{
    size_t    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

unsigned long        ft_strlen(const char *s)
{
    unsigned long i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char                *ft_strjoin(char *memory, char *buffer)
{
    char    *join;
    int        i;
    int        j;

    if (!(join = malloc(sizeof(char) *
                    (ft_strlen(memory) + ft_strlen(buffer) + 1))))
        return (NULL);
    i = 0;
    j = 0;
    if (memory)
        while (memory[i] != '\0')
            join[j++] = memory[i++];
    i = 0;
    if (buffer)
        while (buffer[i] != '\0')
            join[j++] = buffer[i++];
    join[j] = '\0';
    return (join);
}
