#include "cub3d.h"

int main()
{
	t_mlx	*vars;
	t_img	*img;
	

	vars = malloc(sizeof(t_mlx));
	vars->mlx = mlx_init();
	vars->length = 800;
	vars->width = 1000;
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->length, "test");
	img = new_image(vars);
	handle_destroy_win(vars);

	set_pixel(img, 100, 100, 0x00FF00FF);
	draw_square(img, 100, 100, 100, 0x00FF00FF);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
}
