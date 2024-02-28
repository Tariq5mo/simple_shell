#include "main.h"

/**
 * _strcmp - compare between two strings
 *
 * @s1: first string
 * @s2: second string
 * Return: 0 are equals, 1 s1 > s2, -1 s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
		;
	j = s1[i] - s2[i];
	return (j);
}
/**
 * _atoi - Convert string to number
 *
 * @s: the string
 * Return: the number
 */
int _atoi(char *s)
{
	int i, num, sign;

	sign = 1;
	num = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (num >= INT_MAX)
			return (INT_MAX);
		if (num <= INT_MIN)
			return (INT_MIN);
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			if ((num % 10) == 0 && s[i] == 0)
				num = num * 10;
			else
				num = num * 10 + s[i] - '0';
			if (s[i + 1] < '0' || s[i + 1] > '9')
				return (num * sign);
		}
	}
	if (num == INT_MAX)
		return (INT_MAX);
	if (num == 0)
		return (0);
	return (num * sign);
}
/**
 * set_null - set first '#' to '\0'
 *
 * @s: the string
 */
void set_null(char *s)
{
	for (; *s; s++)
		if (*s == '#')
		{
			*s = '\0';
			return;
		}
}
