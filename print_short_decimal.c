/*
** print_short_decimal.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:45:00 2008 christophe sundas
** Last update Thu Nov 27 20:45:36 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

/*
** %hd %hi
*/
char			*print_h_signed_decimal(va_list *vlist)
{
  short signed int	nb;
  char			*tabstr;
  short signed int	lenstr;
  int	k;

  nb = (short signed int)va_arg(*vlist, signed int);
  lenstr = my_putnbr_base_cpth(nb, "0123456789");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  tabstr[lenstr] = '\0';
  k = 0;
  my_putnbr_base2h(nb, "0123456789", tabstr, &k);
  return (tabstr);
}

/*
** %hu 
*/
char			*print_h_unsigned_decimal(va_list *vlist)
{
  short unsigned int	nb;
  char			*tabstr;
  short unsigned int	lenstr;
  int	k;

  nb = (short unsigned int)va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cpthu(nb, "0123456789");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  tabstr[lenstr] = '\0';
  k = 0;
  my_putnbr_base2hu(nb, "0123456789", tabstr, &k);
  return (tabstr);
}
