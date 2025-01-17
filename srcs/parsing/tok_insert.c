#include "libft.h"
#include "token.h"

void	insert_tok_end(t_tok_list *list, t_tok *tok)
{
	t_tok	*temp;

	if (list == NULL || tok == NULL)
		return ;
	if (list->head == NULL)
	{
		list->head = tok;
		list->tail = tok;
		tok->prev = list->tail;
		tok->next = list->head;
	}
	else
	{
		temp = list->tail;
		list->tail = tok;
		tok->prev = temp;
		tok->next = list->head;
		temp->next = tok;
	}
	++(list->size);
}

// void	insert_tok_next(t_tok_list	*list, t_tok *target, t_tok *node)
// {
// 	t_tok	*temp;

// 	if (list == NULL || node == NULL)
// 		return ;
// 	if (list->head == )
// }
