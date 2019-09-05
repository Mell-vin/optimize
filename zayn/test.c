#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int start;
	int end;
	int *nbr;
	int size;
} p_l;

void		display_list(p_l *list, int size)
{
	int i;

	i = list->start;
	if (!list->nbr[0])
		return ;
	while (i < size)
	{
		printf("number: %d --> %d\n", i + 1, list->nbr[i]);
		i++;
	}
	printf("%d\n\n", list->size);
}

void		tester(p_l *pile)
{
	pile->end = pile->size;
	pile->start += 1;
	printf("new start: \n\n\n");
	display_list(pile, pile->size);
}
int		main(int ac, char **av)
{
	int i;
	p_l new;
	int *tmp;

	if (ac > 2)
	{
		i = 0;
		while (av[i])
			i++;
		new.nbr = (int *)malloc(sizeof(int) * i);
		tmp = new.nbr;
		new.start = 0;
		if (!tmp)
			return (1);
		i = 1;
		while (av[i])
		{
			*tmp = atoi(av[i]);
			i++;
			*tmp++;
		}
	}
	new.size = i - 1;
	i = 0;
	display_list(&new, new.size);
	while (i < new.size)
	{
		tester(&new);
		i++;
	}
	return (0);
}
