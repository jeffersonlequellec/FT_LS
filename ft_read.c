/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:14:40 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/07 15:20:03 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_read1(t_tree *options, char *directory)
{
	t_tree			*node;
	t_info			var;
	t_norm			norm;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	norm.blocks = 0;
	CHK_DIR((norm.dirp = opendir(directory)))
	while ((sd = readdir(norm.dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0)
		{
			node == NULL
			? node = ft_treeinsert_ti(node, var, SEC, NSEC)
			: ft_treeinsert_ti(node, var, SEC, NSEC);
			norm.blocks += buf.st_blocks;
		}
	}
	closedir(norm.dirp);
	ft_treesearch(options, 'R') == 1
	? ft_handle_directions(node, options, norm.blocks)
	: ft_display(options, node, norm.blocks);
}

void 	ft_read2(t_tree *options, char *directory)
{
	t_tree			*node;
	t_info			var;
	t_norm			norm;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	norm.blocks = 0;
	CHK_DIR((norm.dirp = opendir(directory)))
	while ((sd = readdir(norm.dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0 && *sd->d_name != '.')
		{
			node == NULL
			? node = ft_treeinsert_ti(node, var, SEC, NSEC)
			: ft_treeinsert_ti(node, var, SEC, NSEC);
			norm.blocks += buf.st_blocks;
		}
	}
	closedir(norm.dirp);
	ft_treesearch(options, 'R') == 1
	? ft_handle_directions(node, options, norm.blocks)
	: ft_display(options, node, norm.blocks);
}

void 	ft_read3(t_tree *options, char *directory)
{
	t_tree			*node;
	t_info			var;
	t_norm			norm;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	norm.blocks = 0;
	CHK_DIR((norm.dirp = opendir(directory)))
	while ((sd = readdir(norm.dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0)
		{
			node == NULL
			? node = ft_treeinsert_as(node, var, SEC, NSEC)
			: ft_treeinsert_as(node, var, SEC, NSEC);
			norm.blocks += buf.st_blocks;
		}
	}
	closedir(norm.dirp);
	ft_treesearch(options, 'R') == 1
	? ft_handle_directions(node, options, norm.blocks)
	: ft_display(options, node, norm.blocks);
}

void 	ft_read4(t_tree *options, char *directory)
{
	t_tree			*node;
	t_info			var;
	t_norm			norm;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	norm.blocks = 0;
	CHK_DIR((norm.dirp = opendir(directory)))
	while ((sd = readdir(norm.dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0 && *sd->d_name != '.')
		{
			node == NULL
			? node = ft_treeinsert_as(node, var, SEC, NSEC)
			: ft_treeinsert_as(node, var, SEC, NSEC);
			norm.blocks += buf.st_blocks;
		}
	}
	closedir(norm.dirp);
	ft_treesearch(options, 'R') == 1
	? ft_handle_directions(node, options, norm.blocks)
	: ft_display(options, node, norm.blocks);
}

void	ft_read(t_tree *options, char *directory)
{
	if (ft_treesearch(options, 't') == 1)
	{
		ft_treesearch(options, 'a') == 1
		? ft_read1(options, directory)
		: ft_read2(options, directory);
	}
	else
	{
		ft_treesearch(options, 'a') == 1
		? ft_read3(options, directory)
		: ft_read4(options, directory);
	}
}
