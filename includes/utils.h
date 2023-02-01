/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:38:06 by smuradya          #+#    #+#             */
/*   Updated: 2023/01/22 18:53:04 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// utils1.c

long double	ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strchr(const char *s, int c);

// utils2.c
void		ft_putstr_fd(char *str, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
int			ft_strlen(const char *str);

// utils3.h
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

#endif // UTILS_H
