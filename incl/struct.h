
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_data
{
	t_map	*map;
}	t_data;

#endif
