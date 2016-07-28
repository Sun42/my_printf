/*
** my_printf.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:42:53 2008 christophe sundas
** Last update Thu Nov 27 21:03:17 2008 christophe sundas
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int		my_printf(char *format, ...)
{
  va_list	vlist;
  int		ret;

  va_start(vlist, format);
  ret = parse_format(format, vlist);
  va_end(vlist);
  return (ret);
}
