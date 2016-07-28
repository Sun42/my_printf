/*
** for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
**
**  Made by christophe sundas 
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:28:59 2008 christophe sundas
** Last update Thu Nov 27 20:43:23 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

/*
**  x X o b u
*/
int	display_unsigned_num(char *str, t_spec *spec)
{
  char	*new_str;
  int	final_width;

  new_str = mk_precision_unsigned(str, spec);
  final_width = r_max2(my_strlen(new_str), spec->largeur);
  if (spec->flag.align == 'R')
    display_spaces_nan(my_strlen(new_str), final_width);
  my_putstr(new_str);
  if (spec->flag.align == 'L')
    display_spaces_nan(my_strlen(new_str), final_width);
  free(new_str);
  return (final_width);
}
