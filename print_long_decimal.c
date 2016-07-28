/*
** print_long_decimal.c for my_printf in u/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:44:19 2008 christophe sundas
** Last update Thu Nov 27 20:45:10 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

/*
** %ld %li
*/
char			*print_l_signed_decimal(va_list *vlist)
{
  long signed int	nb;
  char			*tabstr;
  long signed int	lenstr;
  int			k;

  nb = (long signed int)va_arg(*vlist,long signed int);
  lenstr = my_putnbr_base_cptl(nb, "0123456789");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  tabstr[lenstr] = '\0';
  k = 0;
  my_putnbr_base2l(nb, "0123456789", tabstr, &k);
  return (tabstr);
}

/*
** %lu
*/
char			*print_l_unsigned_decimal(va_list *vlist)
{
  long unsigned int	nb;
  char			*tabstr;
  long unsigned int	lenstr;
  int			k;

  nb = (long unsigned int)va_arg(*vlist,long unsigned int);
  lenstr = my_putnbr_base_cptlu(nb, "0123456789");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  tabstr[lenstr] = '\0';
  k = 0;
  my_putnbr_base2lu(nb, "0123456789", tabstr, &k);
  return (tabstr);
}
