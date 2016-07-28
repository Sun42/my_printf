/*
** print_decimal.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:44:04 2008 christophe sundas
** Last update Thu Nov 27 20:44:50 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

/*
** %d %i
*/
char		*print_signed_decimal(va_list *vlist)
{
  signed int	nb;
  char		*tabstr;
  int		lenstr;
  int		k;

  nb = va_arg(*vlist, signed int);
  lenstr = my_putnbr_base_cpt(nb, "0123456789");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  tabstr[lenstr] = '\0';
  k = 0;
  my_putnbr_base2(nb, "0123456789", tabstr, &k);
  return (tabstr);
}

/*
** %u
*/
char		*print_unsigned_decimal(va_list *vlist)
{
  unsigned int	nb;
  char		*tabstr;
  int		lenstr;
  int		k;

  nb = va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cptu(nb, "0123456789");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  tabstr[lenstr] = '\0';
  k = 0;
  my_putnbr_base2u(nb, "0123456789", tabstr, &k);
  return (tabstr);
}
