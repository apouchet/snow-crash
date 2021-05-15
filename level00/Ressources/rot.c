#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_rot(char *str, int rot)
{
	int		i;
	int		tmp;

	i = 0;
	rot = rot % 26;
	while (str[i])
	{
		tmp = str[i] + rot;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = tmp - (tmp > 'z' ? 26 : 0);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = tmp - (tmp > 'Z' ? 26 : 0);
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int		rot;

	if (argc == 1)
		printf("./rot \"string\" [rot value]\n");
	else if (argc == 2)
	{
		rot = 0;
		while (rot++ < 25)
			printf("rot: %.2d - %s\n", rot, ft_rot(argv[1], 1));
	}
	else
		printf("rot: %d - %s\n", atoi(argv[2]) % 26, ft_rot(argv[1], atoi(argv[2]) % 26));
	return (0);
}
