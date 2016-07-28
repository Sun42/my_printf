/*
** print_long_undecimal.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:45:28 2008 christophe sundas
** Last update Thu Nov 27 20:45:23 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

char			*print_l_octal(va_list *vlist)
{
  long unsigned int	nb;
  char			*tabstr;
  long unsigned int	lenstr;
  int			k;

  nb = (long unsigned int)va_arg(*vlist,long unsigned int);
  lenstr = my_putnbr_base_cptlu(nb, "01234567");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2lu(nb, "01234567", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}

char			*print_l_hexa_up(va_list *vlist)
{
  long unsigned int	nb;
  char			*tabstr;
  long unsigned int	lenstr;
  int			k;

  nb = (long unsigned int)va_arg(*vlist, long unsigned int);
  lenstr = my_putnbr_base_cptlu(nb, "0123456789ABCDEF");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2lu(nb, "0123456789ABCDEF", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}

char			*print_l_hexa_low(va_list *vlist)
{
  long unsigned int	nb;
  char			*tabstr;
  long unsigned int	lenstr;
  int			k;

  nb = (long unsigned int)va_arg(*vlist, long unsigned int);
  lenstr = my_putnbr_base_cptlu(nb, "0123456789abcdef");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2lu(nb, "0123456789abcdef", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}
