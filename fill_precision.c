/*
** fill_precision.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:41:17 2008 christophe sundas
** Last update Thu Nov 27 20:44:01 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Rempli le champs precision a rajouter : fill_precision star
*/
int	fill_precision(char *format, t_spec *spec, va_list *vlist)
{
  int	cpt;
  char	*strprec;

  cpt = 0;
  if (*format != '.')
    {
      spec->precis.precision = 0;
      return (0);
    }
  else
    {
      format++;
      if (*format == '*')
	return (fill_precision_star(spec, vlist));
      while (my_char_is_num(format[cpt]))
	cpt++;
      if ((strprec = malloc(sizeof(*strprec) * (cpt + 1))) == NULL)
	exit(-1);
      strprec[0] = '\0';
      my_strncat(strprec, format, cpt);
      spec->precis.precision = my_getnbr(strprec);
      free(strprec);
    }
  return (cpt + 1);
}

int	fill_precision_star(t_spec *spec, va_list *vlist)
{
  spec->precis.precision = va_arg(*vlist, int);
  return (2);
}
