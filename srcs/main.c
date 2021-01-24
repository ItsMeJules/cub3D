#include "../mlx_linux/mlx.h"
#include "../LIBFT/includes/libft.h"

int main()
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
	ft_putstr_fd("fe", 1);
	mlx_loop(mlx);
}
