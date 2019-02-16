int		is_power_of_2(unsigned int n)
{
	while (n > 0)
	{
		if (n == 1)
			return (1);
		if (n % 2 == 1)
			return (0);
		n /= 2;
	}
	return (0);
}

int	main()
{
	int		i;

	i = 0;
	while (i < 257)
	{
		printf("i: %d, power: %d\n ", i, is_power_of_2(i));
		i++;
	}
	return (0);
}

// ./a.out > test.txt
// compare values
// 0 - not a power of 2
// 1 - power of 2
// 2, 4, 8, 16, 32, 64, 128, 256... etc. - power of 2