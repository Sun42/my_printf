/*
** ill_largeur.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
**
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
**
** Started on  Wed Nov 26 22:40:26 2008 christophe sundas 
** Last update Thu Nov 27 20:43:10 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

/*
**  display %d %i
*/
int	display_signed_num(char *str,t_spec *spec)
{
  char	*new_str;
  int	final_width;

  new_str = mk_precision_signed_r(str, spec);
  final_width = r_max2(my_strlen(new_str), spec->largeur);
  if (spec->flag.align == 'R')
    display_spaces(my_strlen(new_str), final_width, spec);
  my_putstr(new_str);
  if (spec->flag.align == 'L')
    display_spaces_nan(my_strlen(new_str), final_width);
  free(new_str);
  return (final_width);
}

char	*mk_signed_prefix(char	*str, t_spec *spec)
{
  if ((spec->flag.force_sign == 1) && (str[0] != '-'))
    return (my_strdup("+"));
  if ((spec->flag.force_space == 1) && (str[0] != '-'))
  return (my_strdup(" "));
  else 
    return (NULL);
}

char	*mk_precision_signed_r(char *str, t_spec *spec)
{
  char	*prec;
  char	*prefixe;
  char	*new_str;
  int	nbprec;
  int	lenstr;

  nbprec = spec->precis.precision - my_strlen(str);
  prefixe = mk_signed_prefix(str, spec);
  prec = mk_precis(nbprec);
  lenstr = my_strlen(str);
  if ((prefixe == NULL) && (prec == NULL))
    new_str = my_strdup(str);
  if ((prefixe != NULL) && (prec != NULL))
    new_str = add_to_str2(prefixe, prec, str);
  if ((prec == NULL) && (prefixe != NULL))
    new_str = add_to_str(prefixe, str);
  if ((prefixe == NULL) && (prec != NULL))
    new_str = add_to_str(prec, str);
  if (prefixe != NULL)
    free(prefixe);
  if (prec != NULL)
    free(prec);
  return (new_str);
}
