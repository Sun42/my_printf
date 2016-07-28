/*
** fill_spec.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:41:48 2008 christophe sundas
** Last update Thu Nov 27 20:44:12 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Rempli la structure de specifications et retourne le nb de char des spec 
*/
int	fill_spec(char *format, t_spec *spec, va_list *vlist)
{
  int	cpt;
  int	nb;
  
  cpt = 0;
  nb = fill_flag(format, spec);
  format += nb;
  cpt += nb;
  nb = fill_largeur(format, spec, vlist);
  format += nb;
  cpt += nb;
  nb = fill_precision(format, spec, vlist);
  format += nb;
  cpt += nb;
  nb = fill_modifier(format, spec);
  format += nb;
  cpt += nb;
  nb = fill_converter(format, spec);
  format += nb;
  cpt += nb;
  return (cpt);
}

/*
** fill modifier
*/
int	fill_modifier(char *format, t_spec *spec)
{
  int	cpt;

  cpt = 0;
  if ((*format == 'l') || (*format == 'h') || (*format == 'L'))
    {
      spec->modifier = *format;
      cpt++;
    }
  else
    {
      spec->modifier = '?';
    }
  return (cpt);
}

/*
** Rempli le cham spec converter
*/
int	fill_converter(char *format, t_spec *spec)
{
  int	cpt;

  cpt = 0;
  if (is_converter(*format))
    {
      spec->converter = *format;
      cpt++;
    }
  else
    {
      spec->converter = '?';
      my_putstr("\nConverter missing");
      my_putstr(" or not ISO 99 conform\n");
      exit(-1);
    }
  return (cpt);
}

int	my_char_is_num(char c)
{
  if ((c >= '0') && (c <= '9'))
    return (1);
  return (0);
}
