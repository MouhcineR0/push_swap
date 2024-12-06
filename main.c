#include "push_swap.h"

int isNumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int *fill(char **a,int *stack_a,int length) // fill in the stack a
{
	int	i;
	int	j;
	char **split;
 
	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i],' ');
		while (*split)
		{
			if (!isNumber(*split))
				return (0);
			(split)++;
			j++;
		}
		i++;
	}
	return (stack_a);
}

int verify_args(char **a, int length) // verifying and calculates the length of stack a
{
	int	i;
	int	j;
	char **split;
 
	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i],' ');
		while (*split)
		{
			if (!isNumber(*split))
				return (0);
			(split)++;
			j++;
		}
		i++;
	}
	return (j);
}

int RaiseError()
{
	ft_putstr_fd("Error",2);
	return 0;
}

int main(int argc, char const *argv[])
{
	int *stack_a;
	int *stack_b;
	int	arr_len;

	arr_len = verify_args((char **)argv,argc);
	ft_printf("%d",arr_len);
	if (arr_len)
	{
		stack_a = (int *)malloc(sizeof(int) * arr_len);
		stack_b = (int *)malloc(sizeof(int) * arr_len);
		if (!stack_a || !stack_b)
			return RaiseError();
		Sort(fill(argv,stack_a,argc),stack_b,arr_len);
		free(stack_a);
	}
	else
		return RaiseError();
	return 0;
}
