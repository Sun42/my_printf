/*
** print_undecimal.c for my_printf in /sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:46:32 2008 christophe sundas
** Last update Thu Nov 27 20:46:23 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** %o
*/
char		*print_octal(va_list *vlist)
{
  unsigned int	nb;
  char		*tabstr;
  int		lenstr;
  int		k;

  nb = va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cptu(nb, "01234567");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2u(nb, "01234567", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}

/*
** %X
*/
char		*print_hexa_up(va_list *vlist)
{
  unsigned int	nb;
  char		*tabstr;
  int		lenstr;
  int		k;

  nb = va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cptu(nb, "0123456789ABCDEF");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2u(nb, "0123456789ABCDEF", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}

/*
** %x
*/
char		*print_hexa_low(va_list *vlist)
{
  unsigned int	nb;
  char		*tabstr;
  int		lenstr;
  int		k;

  nb = va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cptu(nb, "0123456789abcdef");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2u(nb, "0123456789abcdef", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}

/*
** %b
*/
char		*print_binary(va_list *vlist)
{
  unsigned int	nb;
  char		*tabstr;
  int		lenstr;
  int		k;

  nb = va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cptu(nb, "01");
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  k = 0;
  my_putnbr_base2u(nb, "01", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}
