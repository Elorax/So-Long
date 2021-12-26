#include "string_constructor.h"

//Compiler version gcc  6.3.0


int max(int a, int b)
{
	return (a > b ? a : b);
}

int min(int a, int b)
{
	return (a > b ? b : a);
}

int ft_strlen(char *s)
{
	int  i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char  *ft_strndup(char *s, int n)
{
	int  i;
	char  *dest;
	int size;

	i = 0;
	size = min(n, ft_strlen(s));
	dest = malloc(size + 1);
	if (!dest)
		return (NULL);
	if (!s)
		return (NULL);
	if (!n)
		return (NULL);
	while (i < size)
	{
		dest[i] = s[i];
		i++; 
	}
	dest[i] = 0;
	return (dest);
}


char *ft_strjoin(char *s1, char *s2, int a, int b)
{
	int  i;
	int  j;
	char  *dest;

	i = 0;
	j = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	if (s1)
		while (s1 && s1[j])
			dest[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			dest[i++] = s2[j++];
	if (a)
		free(s1);
	if (b)
		free(s2);
	dest[i] = 0;
	return(dest);
}

char  *ft_itoa(int nb)
{
	unsigned int cpy;
	char *dest;
	int i;

	i = (nb < 0);
	cpy = nb < 0 ? -nb : nb;
	while (cpy > 9)
	{
		cpy /= 10;
		i++;
	}
	dest = malloc(i + 2);
	if (!dest)
		return (NULL);
	dest[0] = nb == 0 ? 48 : 45;
	dest[i + 1] = 0;
	cpy = nb < 0 ? -nb : nb;
	while (cpy)
	{
		dest[i--] = (cpy % 10) + 48;
		cpy /= 10;
	}
	return (dest);
}

char *ft_string_creator(const char *str, ...)
{
	va_list  list;
	char  *dest;
	char  *cpy;
	int  i;

	dest = NULL;
	cpy = str;
	if (!str)
		return(NULL);
	va_start(list, str);
	while (*str)

	{
		cpy = str;
		i = 0;
		while (*str && *str != '%')
		{
			str++;
			i++;
		}
		dest = ft_strjoin(dest, ft_strndup(cpy, i), 1, 1);
		if (*str && *(++str) && *str == 'd')
			dest = ft_strjoin(dest, ft_itoa(va_arg(list, int)), 1, 1);
		else if (*str == 's')
			dest = ft_strjoin(dest, va_arg(list, char*), 1, 0);
		if (*str)
			str++;
	}
	va_end(list);
	return(dest);
}
int main()
{
	int nb = 42;
	char *str = ft_string_creator("Nombre 42 : %d, %d\n%s<--", 42, 2021, "Quelle belle fonction !");

	printf("Hello, Dcoder!\n%s", str);
	free(str);
	return 0;
}
