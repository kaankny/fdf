/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <kkanyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:18:21 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/25 11:25:03 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstring(char *str);
int		ft_putpointer(unsigned long int ptr, int i);
int		ft_putnumber(long int nbr);
int		ft_putunsignedint(unsigned int nbr);
int		ft_puthex(unsigned int nbr, char type);
char	*ft_itoa(long int number);

#endif
