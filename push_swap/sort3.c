#include "push_swap.h"

static void case1(t_stack *lst)
{
    t_stack *next_elm;
    t_stack *last;

    next_elm = lst->next;
    last = lastelm(lst);
    if ((lst->content > next_elm->content && lst->content < last->content) || (next_elm == last && lst->content > next_elm->content))
    {
        lst_swap(lst);
        ft_printf("sa\n");
    }
    else if (lst->content > next_elm->content && lst->content > last->content && next_elm->content < last->content)
    {
        rotate(lst);
        ft_printf("ra\n");
    }
    else if (lst->content < next_elm->content && lst->content > last->content)
    {
        reverse_rotate(lst);
        ft_printf("rra\n");
    }
}

static void case2(t_stack *lst)
{
    t_stack *next_elm;
    t_stack *last;

    next_elm = lst->next;
    last = lastelm(lst);
    if (lst->content > next_elm->content && lst->content > last->content && next_elm->content > last->content)
    {
        lst_swap(lst);
        reverse_rotate(lst);
        ft_printf("sa\nrra\n");
    }
    else if (lst->content < next_elm->content && lst->content < last->content && next_elm->content > last->content)
    {
        lst_swap(lst);
        rotate(lst);
        ft_printf("sa\nra\n");
    }
}

void sort3(t_stack *lst)
{
    case1(lst);
    case2(lst);
}
