/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:29 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/10 14:25:08 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>

# define SEC buf.st_mtime
# define NSEC buf.st_mtimespec.tv_nsec
# define NORM perror(ft_strjoin("./ft_ls: ", directory))
# define CHK_DIR(a) if (!a) { NORM; return ; }

typedef struct		s_tree
{
	char			*name;
	char			*path;
	time_t			sec;
	long			nsec;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_info
{
	char			*name;
	char			*path;
}					t_info;

typedef struct		s_norm
{
	DIR				*dirp;
	blkcnt_t		blocks;
}					t_norm;

typedef struct		s_ret
{
	int				error;
}					t_ret;

/*
** MAIN
*/
t_tree				*ft_options(char **argv, t_tree *node);
t_tree				*ft_directories(char **argv, t_tree *options, t_tree *node);
t_tree				*ft_files(char **argv, t_tree *option, t_ret *ret,
					t_tree *node);

/*
** FT_TOOLS1.C
*/
size_t				ft_treelen(t_tree *directories);
char				*ft_path(char *directory, char *var);
int					ft_treesearch(t_tree *options, char c);
size_t				ft_index(char **argv);

/*
** FT_TOOLS2.C
*/
void				ft_treeclr(t_tree *node);
void				ft_info(t_info *var, char *name, char *directory);
t_tree				*ft_treenew(t_info var, time_t sec, long nsec);
t_tree				*ft_treeinsert_as(t_tree *node, t_info var, time_t sec,
					long nsec);
t_tree				*ft_treeinsert_ti(t_tree *node, t_info var, time_t sec,
					long nsec);

/*
** FT_TOOLS3.C
*/
void				ft_printowner(struct stat buf, t_tree *options);
void				ft_printtime(time_t ti);
void				ft_error(t_ret *ret, char *str);

/*
** PRINTING
*/
void				ft_print_in(t_tree *files, int flag, t_tree *options);
void				ft_print_or(t_tree *files, int flag, t_tree *options);
void				ft_printfiles(t_tree *files, t_tree *options,
					t_tree *directories);
void				ft_printlong(char *str, char *path, t_tree *options);
void				ft_display(t_tree *options, t_tree *node, blkcnt_t blocks);

/*
** READING
*/
void				ft_read(t_tree *options, char *directory);
void				ft_handle_directions(t_tree *node, t_tree *options);

/*
** LAUNCHER
*/
void				ft_launcher1(t_tree *options, t_tree *directories,
					int display);
void				ft_launcher2(t_tree *options, t_tree *directories,
					int display);

#endif
