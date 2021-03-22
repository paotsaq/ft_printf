#include "ft_printf.h"

int min(int args, int init, ...)
{
    int i;
	int	min;
	int	current;
    va_list valist;
    va_start(valist, init);

	i = -1;
	min = init;
	while (++i < args)
    {
        current = va_arg(valist, int);
        if(min > current || min == INT_MIN)
            min = current;
    }
    va_end(valist);
    return min;
}

int max(int args, int init, ...)
{
	int i;
	int	max;
	int	current;
	va_list valist;
	va_start(valist, init);

	i = -1;
	max = init;
	while (++i < args)
	{
		current = va_arg(valist, int);
		if (max < current || max == INT_MAX)
		max = current;
	}
	va_end(valist);
	return max;
}
