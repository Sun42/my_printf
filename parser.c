/*
** parser.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:43:44 2008 christophe sundas
** Last update Sat Nov 29 16:50:23 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Parse la string
*/
int		parse_format(char *format, va_list vlist)
{
  int		cpt;
  t_spec	spec;

  cpt = 0;
  while (*format)
    {
      if (!(is_regular(*format)))
        {
	  format++;
	  format += fill_spec(format, &spec, &vlist);
	  cpt += print_converter(&spec, &vlist);
	}
      else
        {
          cpt++;
          my_putchar(*format);
          format++;
        }
    }
  return (cpt);
}

/*
**  Retourne vrai si le char est de type regulier
*/
int	is_regular(char c)
{
  if (c != '%')
    return (1);
  else
    return (0);
}
