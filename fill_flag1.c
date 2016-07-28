/*
** fill_flag1.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:38:41 2008 christophe sundas
** Last update Thu Nov 27 20:43:34 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

/*
** rempli la structure flag
*/
int	fill_flag(char *format, t_spec *spec)
{
  int	cpt;

  cpt = 0;
  while (is_flag(format[cpt]))
    cpt++;
  fill_align(format, cpt , spec);
  fill_add(format, cpt, spec);
  fill_force_sign(format, cpt, spec);
  fill_force_space(format, cpt, spec);
  fill_sharp(format, cpt, spec);
  return (cpt);
}

int	is_flag(char c)
{
  if ((c == ' ') || (c == '#') || (c == '+') || (c == '-') || c == '0')
    return (1);
  return (0);
}
