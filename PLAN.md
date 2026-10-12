# cub3D plan

## Hamdan: parsing

<label><input type="checkbox"> `main`: exactly one argument, `.cub` extension</label><br>
<label><input type="checkbox"> Read the file</label><br>
<label><input type="checkbox"> Parse `NO SO WE EA` texture paths: any order, empty lines allowed, one or more spaces, bad path is an error</label><br>
<label><input type="checkbox"> Reject missing or duplicated texture identifiers</label><br>
<label><input type="checkbox"> Reject unknown identifiers before the map starts</label><br>
<label><input type="checkbox"> Parse `F` and `C` colors: `R,G,B` in `[0,255]`</label><br>
<label><input type="checkbox"> Reject missing, duplicated, malformed, negative, or out-of-range colors</label><br>
<label><input type="checkbox"> Parse the map, always last: only `0 1 N S E W` and spaces, exactly one player, read as it looks in the file</label><br>
<label><input type="checkbox"> Reject empty lines inside or after the map if they break the "map is last" rule</label><br>
<label><input type="checkbox"> Pad map rows safely so spaces can be checked like real map content</label><br>
<label><input type="checkbox"> Check the map is closed by walls</label><br>
<label><input type="checkbox"> Treat spaces and out-of-bounds neighbors around `0` or player spawn as map closure errors</label><br>
<label><input type="checkbox"> Print `Error\n` followed by an explicit message for every file misconfiguration</label><br>
<label><input type="checkbox"> `void free_scene(t_scene *s)`: free texture paths and map grid</label><br>
<label><input type="checkbox"> `void free_all(t_game *g)`: call `free_scene` and `free_engine`</label><br>
<label><input type="checkbox"> Stub `free_engine` as empty until Maryam's real version exists</label><br>
<label><input type="checkbox"> `void exit_error(t_game *g, char *msg)`: call `free_all`, print `Error\n` + msg, exit</label><br>
<label><input type="checkbox"> No leaks on any error path</label><br>

## Maryam: engine

<label><input type="checkbox"> MLX init, window, image buffer</label><br>
<label><input type="checkbox"> Use a temporary `exit_error` that prints and exits until Hamdan's version exists</label><br>
<label><input type="checkbox"> Display the rendered image in the window using an MLX image buffer</label><br>
<label><input type="checkbox"> Hooks: ESC and red cross close cleanly</label><br>
<label><input type="checkbox"> Window stays smooth on minimize and focus change</label><br>
<label><input type="checkbox"> Use a temporary `free_all` stub until Hamdan's version exists</label><br>
<label><input type="checkbox"> Floor and ceiling colors</label><br>
<label><input type="checkbox"> Hardcode `floor_color` and `ceil_color` until parser values exist</label><br>
<label><input type="checkbox"> Load the 4 textures</label><br>
<label><input type="checkbox"> Hardcode texture paths until `tex_path[]` exists</label><br>
<label><input type="checkbox"> Raycasting with DDA</label><br>
<label><input type="checkbox"> Hardcode a map until `map.grid` exists</label><br>
<label><input type="checkbox"> Pick texture by wall side: N/S/E/W</label><br>
<label><input type="checkbox"> Player start position and direction from the spawn</label><br>
<label><input type="checkbox"> Hardcode spawn until `spawn_x`, `spawn_y`, and `spawn_dir` exist</label><br>
<label><input type="checkbox"> W/A/S/D move, left/right arrows rotate, never leaving the map</label><br>
<label><input type="checkbox"> Use `map.grid` and size for bounds checks once parser data exists</label><br>
<label><input type="checkbox"> `void free_engine(t_game *g)`: destroy images, window, display, free mlx, only what exists</label><br>
<label><input type="checkbox"> Handle MLX init, window, image, and texture load failures cleanly</label><br>
<label><input type="checkbox"> No leaks, clean exit</label><br>

## Integration (together)

<label><input type="checkbox"> Plug the real parser into the engine</label><br>
<label><input type="checkbox"> Test good maps and broken maps, no crash, no unexpected quit</label><br>
<label><input type="checkbox"> Test invalid arguments, wrong extensions, missing files, missing elements, duplicates, bad colors, bad texture paths, invalid characters, multiple players, open maps, and maps with spaces</label><br>
<label><input type="checkbox"> Leak check including ESC and red cross exit</label><br>
<label><input type="checkbox"> Norminette</label><br>
<label><input type="checkbox"> Makefile doesn't relink</label><br>
<label><input type="checkbox"> Makefile builds with `cc -Wall -Wextra -Werror` and has at least `$(NAME)`, `all`, `clean`, `fclean`, `re`</label><br>
<label><input type="checkbox"> README</label><br>
<label><input type="checkbox"> Be ready for a small evaluation modification request</label><br>
<label><input type="checkbox"> Both can explain the whole project for eval</label><br>
<label><input type="checkbox"> Optional: test suite</label><br>
