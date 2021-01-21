#include "mlx.h"
#include "libft.h"

int	key_handle(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	return (0);
}

int main()
{
	void	*mlx_p;
	void	*win_p;

	mlx_p = mlx_init();

	win_p = mlx_new_window(mlx_p, 500, 500, "window");
	mlx_pixel_put(mlx_p, win_p, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_p, key_handle, (void *) 0);
	mlx_loop(mlx_p);
}
