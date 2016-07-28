/*
** my_printf.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf 
**
** Made by christophe sundas
** Login   <sundas_c@epitech.net>   
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas 
** Last update Thu Nov 27 20:46:54 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** retourne une string de 000 pour le precision
*/
char	*mk_precis(int nb)
{
  char	*prec;

  if (nb <= 0)
    return (NULL);
  if ((prec = malloc(sizeof(*prec) * nb + 1)) == NULL)
    exit(-1);
  prec[nb] = '\0';
  while (nb > 0)
    {
      my_strcat(prec, "0");
      nb--;
    }
  return (prec);
}
