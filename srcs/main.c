#include "cub3d.h"
#include "libft.h"

int main(int ac, char **av)
{
	t_all *all;
	(void)ac;

	all = new_all();
	read_file(all, av[1]);
	return (0);
}
