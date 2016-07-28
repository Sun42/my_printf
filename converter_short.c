/*
** converter_short.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:38:03 2008 christophe sundas
** Last update Thu Nov 27 20:42:39 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

t_converter	tabmod_short[] =
  {
    {'c', print_char},
    {'b', print_binary},
    {'d', print_h_signed_decimal},
    {'i', print_h_signed_decimal},
    {'u', print_h_unsigned_decimal},
    {'o', print_h_octal},
    {'x', print_h_hexa_low},
    {'X', print_h_hexa_up},
    {'s', print_string},
    {'S', print_string_special},
    {'p', print_pointer},
    {'%', print_percent},
    {0, 0},
  };

/*
** converti Appel la fonction correspondante au converter (cdiXx etc..)
** retourne le nb de char imprime
*/
int	print_h_converter(t_spec *spec, va_list *vlist)
{
  int	i;
  char	*res;
  int	ret;

  i = 0;
  while (tabmod_short[i].converter)
    {
      if (tabmod_short[i].converter == spec->converter)
        {
          res = tabmod_short[i].f(vlist, spec);
          ret = display_converted(res, spec);
          free(res);
          return (ret);
        }
      i++;
    }
  return (0);
}
