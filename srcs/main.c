#include "cub3d.h"
#include "libft.h"

int main(int ac, char **av)
{
	t_map *map;
	(void)ac;

	map = new_map();
	read_map(map, av[1]);
	return (0);
}
