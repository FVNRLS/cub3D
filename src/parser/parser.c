#include "../../incl/cub3D.h"

static bool check_extension(char *s)
{
	int len;

	len = ft_strlen(s);
	s += len - 4;
	if (ft_strncmp(s, ".cub", 5) == 0)
		return (true);
	return (false);
}

void	parse_input(t_data *data, char **argv)
{
	int 	fd;
	bool	ext_valid;

	ext_valid = check_extension(argv[1]);
	if (ext_valid == false)
		return(print_error(INVALID_EXTENSION));
	fd = open(argv[1], O_RDONLY, RIGHTS);
	if (fd < 0)
		return (print_error(OPEN_ERROR));
}


