/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:40:33 by aboiarin          #+#    #+#             */
/*   Updated: 2023/06/20 15:17:08 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
int		ft_newline(const char *s);
void	ft_free_str(char **s1, char **s2, char **s3);
void	*ft_memzero(size_t len, size_t size);
char	*ft_strdup(const char *src);
char	*ft_join(const char *s1, const char *s2);

#endif
