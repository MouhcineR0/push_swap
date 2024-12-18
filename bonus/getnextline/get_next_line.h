/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:33:02 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 11:55:51 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2024
# endif

char	*get_next_line(int fd);

#endif