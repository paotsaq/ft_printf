## So I had to recode ft_printf... 👨‍💻

...and this is my very naive attempt at doing it.

### I'm having a weird bug! 

It can be reproduced by
- cloning this repo;
- <code>git checkout another_bug</code>;
- running <git submodule init>, followed by <git submodule update> (this will clone the libft dependency;
- running <code> gcc srcs/*.c main.c libft/*.c -Iincludes </code>
