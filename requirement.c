/**
 * This file contains utility functions used throughout the shell
 * Implements string comparison, number conversion, and comment handling
 */

#include "main.h"

/**
 * _strcmp - performs string comparison
 * Used for command matching and string equality checks
 * Case-sensitive comparison of two strings
 *
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: 0 if equal, positive if s1 > s2, negative if s1 < s2
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
 * _atoi - converts string to integer
 * Handles positive and negative numbers
 * Implements overflow protection for INT_MAX/MIN
 *
 * @s: string to convert
 * Return: converted integer value
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
 * set_null - handles comment removal in command strings
 * Terminates string at first '#' character
 * Essential for implementing comment functionality
 *
 * @s: command string to process
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
