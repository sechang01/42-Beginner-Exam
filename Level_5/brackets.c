#include <unistd.h>
#include <stdio.h>

int	isopen(char c)
{
	if (c == '(' || c == '{' || c == '[')
		return (1);
	else
		return (0);
}

int	isclose(char c)
{
	if (c == ')' || c == '}' || c == ']')
		return (1);
	else
		return (0);
}

int	notbrk(char c)
{
	if (c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']')
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	br[4096];
	i = 0;
	j = 0;
	k = 0;
	while (i < 4096)
	{
		br[i++] = '\0';
	}
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (isopen(argv[i][j]))
			{
				br[k] = argv[i][j];
				k++;
			}
			if (isclose(argv[i][j]))
			{
				if (argv[i][j] == ')')
				{
					if ((br[k-1]) && br[k-1] == '(')
					{
						br[k - 1] = '\0';
						k--;
					}
					else
					{
						write(1, "Error\n", 6);
						//	return (0);
					}
				}
				else if (argv[i][j] == '}')
				{
					if ((br[k-1]) && br[k-1] == '{')
					{
						br[k] = '\0';
						k--;
					}
					else
					{
						write(1, "Error\n", 6);
						//	return (0);
					}
				}
				else if (argv[i][j] == ']')
				{
					if ((br[k-1]) && br[k-1] == '[')
					{
						br[k] = '\0';
						k--;
					}
					else
					{
						write(1, "Error\n", 6);
						//	return (0);
					}
				}

			}
			if (notbrk(argv[i][j]))
			{

			}
			j++;
		}
		i++;
		if (!br[0])
		{
			write (1, "OK\n", 3);
			while (i < 4096)
			{
				br[i++] = '\0';
			}
			i =0;
		}
	}

	i = 0;
	while (i < 12)
		printf("%c", br[i++]);
	write(1, "end\n", 4);
	return (0);
}