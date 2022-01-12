#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return -1;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return -1;
	lst->content = "a";
	new->content = "b";
	printf("before	lst->content : %s\n", lst->content);
	printf("before	new->content : %s\n", new->content);
	ft_lstadd_front(&lst, new);
	printf("after	lst->content : %s\n", lst->content);
	printf("after	new->content : %s\n", new->content);
	return (0);
}
