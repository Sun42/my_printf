/*
**  my_printf.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf 
**
**  Made by christophe sundas
**  Login   <sundas_c@epitech.net> 
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas
** Last update Thu Nov 27 20:46:37 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

char	*mk_sharp_flag(t_spec *spec)
{
  int	cas;

  cas = need_mk_sharp(spec);
  if (cas == 0)
    {
      return (NULL);
    }
  if (cas == 1)
    return (my_strdup("0"));
  if (cas == 2)
    return (my_strdup("0x"));
  if (cas == 3)
    return (my_strdup("0X"));
  return (NULL);
}

int	need_mk_sharp(t_spec *spec)
{
  if (spec->flag.sharp != '#')
    return (0);
  if (spec->converter == 'o')
    return (1);
  if (spec->converter == 'x')
    return (2);
  if (spec->converter == 'X')
    return (3);
  else
    return (0);
}
