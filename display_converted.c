/*
** display_converted.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:38:17 2008 christophe sundas
** Last update Sat Nov 29 16:46:25 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
**
*/
int	display_converted(char *str, t_spec *spec)
{
  int	ret;

  ret = 0;
  if (is_num_converter(spec->converter) == 1)
    ret = display_signed_num(str, spec);
  if (is_num_converter(spec->converter) == 2)
    ret = display_unsigned_num(str, spec);
  if (is_num_converter(spec->converter) == 0)
    ret = display_nan_converted(str, spec);
  return (ret);
}

int	is_num_converter(char c)
{
  if ((c == 'd') || (c == 'i'))
    return (1);
  if (c == 'b' || c == 'o' || c == 'x' || c == 'X' || c == 'u')
    return (2);
  if (c == 'c' || c == 'p' || c == 's' || c == 'S' || c == '%')
    return (0);
  return (0);
}

/*
** c, p s S %
*/
int	display_nan_converted(char *str, t_spec *spec)
{
  int	final_width;

  final_width = r_max2(my_strlen(str), spec->largeur);
  if (spec->flag.align == 'R')
    display_spaces(my_strlen(str), final_width, spec);
  my_putstr(str);
  if (spec->flag.align == 'L')
    display_spaces_nan(my_strlen(str), final_width);
  return (final_width);
}

int	r_max2(int a, int b)
{
  int	max;
  
  max = a > b ? (a) : (b);
  return (max);
}
