/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:29:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 18:30:02 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void 	ft_inspect_rights(mode_t nb)
{
	!S_ISBLK(nb) ? : ft_putchar('b');
	!S_ISCHR(nb) ? : ft_putchar('c');
	!S_ISLNK(nb) ? : ft_putchar('l');
	!S_ISDIR(nb) ? : ft_putchar('d');
	!S_ISREG(nb) ? : ft_putchar('-');
	!S_ISSOCK(nb) ? : ft_putchar('s');
	!S_ISFIFO(nb) ? : ft_putchar('p');
	nb & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	nb & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	nb & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	nb & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	nb & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	nb & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	nb & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	nb & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	nb & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}

static void 	ft_printtime(char *str)
{
	size_t	index;

	index = 4;
	while (index < 16)
		ft_putchar(str[index++]);
}

static void		ft_print_name(char *str, char *path, mode_t nb)
{
	size_t			len;
	char			link[1024];

	if (S_ISLNK(nb))
	{
		ft_putstr(str);
		ft_putstr(" -> ");
		if ((len = readlink(str, link, sizeof(link))) == (size_t)-1 &&
			(len = readlink(path, link, sizeof(link))) == (size_t)-1 )
		{
			perror(str);
			ft_putendl("lol");
			return ;
		}
		link[len] = '\0';
		ft_putendl(link);
	}
	else
		ft_putendl(str);
}

static void		ft_printinfo(struct stat buf, struct passwd *id, struct group *gid)
{
	ft_putstr("\t");
	ft_putnbr(buf.st_nlink);
	ft_putstr("\t");
	ft_putstr(id->pw_name);
	ft_putstr("\t");
	ft_putstr(gid->gr_name);
	ft_putstr("\t");
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		ft_putnbr(major(buf.st_rdev));
		ft_putstr(",  ");
		ft_putnbr(minor(buf.st_rdev));
	}
	else
		ft_putnbr(buf.st_size);
	ft_putstr("\t");
	ft_printtime(ctime(&buf.st_mtime));
	ft_putstr("\t");
}

void			ft_printlong(char *str, char *path)
{
	struct stat		buf;
	struct passwd 	*id;
	struct group	*gid;

	if (lstat(path, &buf) == -1 && lstat(str , &buf) == -1)
	{
		ft_putstr("./ft_ls: ");
		perror(str);
		return ;
	}
	id = getpwuid(buf.st_uid);
	gid = getgrgid(buf.st_gid);
	ft_inspect_rights(buf.st_mode);
	ft_printinfo(buf, id, gid);
	ft_print_name(str, path, buf.st_mode);
}