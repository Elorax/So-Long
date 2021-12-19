
#include "../so_long_bonus.h"

void	open_doors(t_vars *vars)
{

	int	i;
	int	j;

	i = 0;
	j = 0;
	while(vars->map.map[++i])
	{
		while(vars->map.map[i][++j])
			if (vars->map.map[i][j] == 'D')
				vars->map.map[i][j] = 'd';
		j = 0;
	}
}

void	close_doors(t_vars *vars)
{

	int	i;
	int	j;

	i = 0;
	j = 0;
	while(vars->map.map[++i])
	{
		while(vars->map.map[i][++j])
			if (vars->map.map[i][j] == 'd')
				vars->map.map[i][j] = 'D';
		j = 0;
	}
}

void	check_doors(t_vars *vars)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while(vars->map.map[++i])
	{
		while(vars->map.map[i][++j])
		{
			if (ft_strchr("pB", vars->map.map[i][j]))
				tmp = 1;
		}
		j = 0;
	}
	if (!tmp)
		open_doors(vars);
	else if (tmp == 1)
		close_doors(vars);
	ft_update_full_map(vars);
}
