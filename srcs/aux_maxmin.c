#include "ft_printf.h"

int min(int args, ...)
{
    int i;
	int	min_value;
	int	current;
    va_list valist;
    va_start(valist, args);

	i = -1;
	min_value = INT_MIN;
	while (++i < args)
    {
        current = va_arg(valist, int);
        if (min_value > current || min_value == INT_MIN)
            min_value = current;
    }
    va_end(valist);
    return min_value;
}

int max(int args, ...)
{
	int i;
	int	max_value;
	int	current;
	va_list valist;
	va_start(valist, args);

	i = -1;
	max_value = INT_MAX;
	while (++i < args)
	{
		current = va_arg(valist, int);
		if (max_value < current || max_value == INT_MAX)
		max_value = current;
	}
	va_end(valist);
	return max_value;
}
