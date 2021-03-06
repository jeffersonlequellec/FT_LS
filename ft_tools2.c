/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:20:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/10 13:49:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_treeclr(t_tree *node)
{
	CHK_CV(node);
	ft_treeclr(node->left);
	ft_treeclr(node->right);
	free(node->name);
	if (node->path)
		free(node->path);
	node->name = NULL;
	node->path = NULL;
	free(node);
	node = NULL;
}

void		ft_info(t_info *var, char *name, char *directory)
{
	var->name = ft_strdup(name);
	if (directory)
		var->path = ft_path(directory, name);
	else
		var->path = NULL;
}

t_tree		*ft_treenew(t_info var, time_t sec, long nsec)
{
	t_tree	*node;

	node = (t_tree*)malloc(sizeof(t_tree));
	node->name = ft_strdup(var.name);
	if (var.path)
		node->path = ft_strdup(var.path);
	else
		node->path = NULL;
	node->sec = sec;
	node->nsec = nsec;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_tree		*ft_treeinsert_as(t_tree *node, t_info var, time_t sec, long nsec)
{
	if (node == NULL)
		return (ft_treenew(var, sec, nsec));
	else if (ft_strcmp(var.name, node->name) <= 0)
		node->left = ft_treeinsert_as(node->left, var, sec, nsec);
	else if (ft_strcmp(var.name, node->name) > 0)
		node->right = ft_treeinsert_as(node->right, var, sec, nsec);
	return (node);
}

t_tree		*ft_treeinsert_ti(t_tree *node, t_info var, time_t sec, long nsec)
{
	if (node == NULL)
		return (ft_treenew(var, sec, nsec));
	else if (sec < node->sec)
		node->right = ft_treeinsert_ti(node->right, var, sec, nsec);
	else if (sec == node->sec && nsec == node->nsec && ft_strcmp(var.name,
																node->name) > 0)
		node->right = ft_treeinsert_ti(node->right, var, sec, nsec);
	else
		node->left = ft_treeinsert_ti(node->left, var, sec, nsec);
	return (node);
}
