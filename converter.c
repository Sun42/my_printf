/*
** converter.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:31:11 2008 christophe sundas
** Last update Thu Nov 27 20:42:20 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

t_converter	tabmod[] =
  {
    {'c', print_char},
    {'b', print_binary},
    {'d', print_signed_decimal},
    {'i', print_signed_decimal},
    {'u', print_unsigned_decimal},
    {'o', print_octal},
    {'x', print_hexa_low},
    {'X', print_hexa_up},
    {'s', print_string},
    {'S', print_string_special},
    {'p', print_pointer},
    {'%', print_percent},
    {0, 0},
  };

/*
** Verifie si le char est dans le tableau de modifiers
*/
int	is_converter(char c)
{
  int	i;

  i = 0;
  while (tabmod[i].converter)
    {
      if (tabmod[i].converter == c)
        return (1);
      i++;
    }
  return (0);
}

/*
** Appel la fonction correspondante au converter (cdiXx etc..)
*/
int	print_converter(t_spec *spec, va_list *vlist)
{
  int	i;
  char	*res;
  int	ret;
  
  if (spec->modifier == 'h')
    return (print_h_converter(spec, vlist));
  if (spec->modifier == 'l')
    return (print_l_converter(spec, vlist));
  i = 0;
  while (tabmod[i].converter)
    {
      if (tabmod[i].converter == spec->converter)
        {
	  res = tabmod[i].f(vlist, spec);
	  ret = display_converted(res, spec);
	  free(res);
	  return (ret);
	}
      i++;
    }
  return (0);
}
