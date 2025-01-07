static int	verifier(unsigned long result, int sign, char x)
{
	if (((result == 922337203685477580 && x > '7')
			|| result > 922337203685477580) && sign == 1)
		return (-1);
	if (((result == 922337203685477580 && x > '8')
			|| result > 922337203685477580) && sign == -1)
		return (0);
	return (5);
}

int	ft_atoi(const char *nptr)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if (verifier(result, sign, nptr[i]) != 5)
			return (verifier(result, sign, nptr[i]));
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}