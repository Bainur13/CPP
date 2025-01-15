#ifndef ITER_HPP
#define ITER_HPP

template <typename A, typename F>

void iter(A &tab, int len, F func)
{
    if (tab == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(tab[i]);
}

#endif
