/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:34:51 by yihssan           #+#    #+#             */
/*   Updated: 2020/12/12 23:54:06 by yihssan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_error(char *s)
{
	int i;

	i = 0;
	write(1, "Error\n", 7);
	while (s[i] != '\0' && s[i] > 31 && s[i] < 127)
	{
		write(1, s + i, 1);
		i++;
	}
	if (i != 0)
		write(1, "\n", 2);
	exit(EXIT_FAILURE);
}

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list *tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
