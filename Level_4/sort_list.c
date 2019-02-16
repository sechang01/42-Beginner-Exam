#include "list.h"

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp;
	int		buf;	

	buf = 0;
	tmp = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			buf = lst->data;
			lst->data = lst->next->data;
			lst->next->data = buf;
			lst = tmp;
		}
		else
		{
			lst = lst->next;
		}
	}
	lst = tmp;
	return (tmp);
}