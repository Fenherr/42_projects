#include "push_swap.h"

void sort(t_stack *a, t_stack *b)
{
    t_stack *next_elm;
    t_stack *last;
    (void)b;

    next_elm = a->next;
    last = lastelm(a);
    if (a->content > next_elm->content)
    {
        lst_swap(a);
        ft_printf("sa\n");
    }
    else if (a->content > next_elm->content && a->content < last->content)
    {
        reverse_rotate(a);
        ft_printf("rra\n");
    }
}