/*
** converter_long.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:36:56 2008 christophe sundas
** Last update Thu Nov 27 20:42:30 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

t_converter	tabmod_long[] =
  {
    {'c', print_char},
    {'b', print_binary},
    {'d', print_l_signed_decimal},
    {'i', print_l_signed_decimal},
    {'u', print_l_unsigned_decimal},
    {'o', print_l_octal},
    {'x', print_l_hexa_low},
    {'X', print_l_hexa_up},
    {'s', print_string},
    {'S', print_string_special},
    {'p', print_pointer},
    {'%', print_percent},
    {0, 0},
  };

int	print_l_converter(t_spec *spec, va_list *vlist)
{
  int	i;
  char	*res;
  int	ret;

  i = 0;
  while (tabmod_long[i].converter)
    {
      if (tabmod_long[i].converter == spec->converter)
        {
          res = tabmod_long[i].f(vlist, spec);
          ret = display_converted(res, spec);
          free(res);
          return (ret);
        }
      i++;
    }
  return (0);
}
