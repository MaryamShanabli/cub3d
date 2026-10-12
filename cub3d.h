#ifndef CUB3D_H
# define CUB3D_H

typedef enum e_side		/* BOTH: index for tex_path[] and tex[] */
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_side;

typedef struct s_map	/* Hamdan writes it, Maryam reads it */
{
	char	**grid;		/* padded to a rectangle, spaces kept */
	int		width;
	int		height;
}	t_map;

typedef struct s_scene	/* HANDOFF: Hamdan fills it, Maryam only reads it */
{
	char	*tex_path[4];	/* Hamdan fills, Maryam loads images from it */
	int		floor_color;	/* Hamdan fills, Maryam draws with it */
	int		ceil_color;
	t_map	map;
	int		spawn_x;		/* Hamdan fills, Maryam builds player from it */
	int		spawn_y;
	char	spawn_dir;		/* N, S, E or W */
}	t_scene;

typedef struct s_img	/* Maryam only: one MLX image */
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player	/* Maryam only */
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;	/* camera plane, sets the field of view */
	double	plane_y;
}	t_player;

typedef struct s_game	/* BOTH: one instance, zeroed at start of main */
{
	t_scene	scene;	/* Hamdan's part */
	void	*mlx;	/* below: Maryam's part */
	void	*win;
	t_img	frame;
	t_img	tex[4];
	t_player	player;
}	t_game;

#endif
