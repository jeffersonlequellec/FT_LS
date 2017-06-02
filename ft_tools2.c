/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:20:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 16:24:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_path(char *directory, char *var)
{
	char	*path;

	path = ft_memalloc(ft_strlen(directory) + 1 + ft_strlen(var) + 1);
	ft_strcpy(path, directory);
	ft_strcat(path, "/");
	ft_strcat(path, var);
	return (path);
}
