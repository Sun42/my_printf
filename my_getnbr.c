/*
** my_getnbr.c for my_getnbr in /u/all/duplei_m/cu/rendu/piscine/Jour_04
** 
** Made by mathieu dupleix
** Login   <duplei_m@epitech.net>
** 
** Started on  Thu Oct  9 10:55:52 2008 mathieu dupleix
** Last update Thu Nov 27 21:01:49 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

int	my_getnbr(char *str)
{
  int	i;
  int	numb_find;
  int	ten;
  int	neg;

  i = 0;
  numb_find = 0;
  ten = 1;
  neg = 1;
  while (str[i] != '\0' && str[i] >= '+' && str[i] <= '9')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  if (i > 0)
	    numb_find = numb_find * 10;
	  ten = str[i] - '0';
	  numb_find = numb_find + ten;
	}
      if (str[i] == '-')
	neg = -neg;
      i = i + 1;
    }
  numb_find = (numb_find * neg);
  return (numb_find);
}
