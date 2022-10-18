#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# include "struct.h"
# include "errors.h"
# include "tools.h"

# define RIGHTS	0644

void	parse_input(t_data *data, char **argv);


#endif
