#include "../libft/libft.h"
#include "push_swap.h"

int		counter(struct p_l *head)
{
	int	counter;
	struct	p_l *curr;

	counter = 0;
	if (head)
	{
		curr = head;
		while (curr)
		{
			counter++;
			curr = curr->next;
		}
	}
	return (counter);
}

void		quarter_list(struct p_l **stack_a, struct p_l **max,
		struct p_l **quar, struct p_l **min, int count)
{
	int		max_num;
	struct p_l	*curr;
	struct p_l	*curr_q;
	struct p_l	*new_;

	if ((*stack_a) && (*max))
	{
		max_num = (*max)->elem;
		if (!((*quar) = (struct p_l *)malloc(sizeof(struct p_l))))
			return ;
		curr_q = (*quar);
		curr_q->elem = max_num;
		max_num--;
		while (count > 1 && max_num >= (*min)->elem)
		{
			curr = (*stack_a);
			while (curr)
			{
				if (curr->elem == max_num)
				{
					new_ = (struct p_l *)malloc(sizeof(struct p_l ));
					curr_q->next = new_;
					new_->prev = curr_q;
					curr_q = curr_q->next;
					curr_q->elem = max_num;
					curr_q->next = NULL;
					count--;
				}
				curr = curr->next;
			}
			max_num--;
		}
	}
}

int		compare(struct p_l **stack_a, struct p_l **quar)
{
	struct p_l	*curr;
	struct p_l	*curr_q;

	if ((*stack_a) && (*quar))
	{
		curr = (*stack_a);
		while (curr)
		{
			curr_q = (*quar);
			while (curr_q)
			{
				if (curr->elem == curr_q->elem)
					return (1);
				curr_q = curr_q->next;
			}
			curr = curr->next;
		}
	}
	return (0);
}
