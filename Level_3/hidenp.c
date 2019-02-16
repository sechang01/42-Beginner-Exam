#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i, j;
	int		yn;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			yn = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					yn = 1;
					j++;
					break ;
				}
				j++;
			}
			if (!yn)
			{
				write(1, "0\n", 2);
				return (0);
			}
			i++;
		}
		if (yn)
		{
			write(1, "1", 1);
		}
		else
		{
			write(1, "0", 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}