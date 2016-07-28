/*
** print_strings.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:46:17 2008 christophe sundas
** Last update Sat Nov 29 16:53:25 2008 christophe sundas
*/

#include <stdlib.h> 
#include <stdarg.h>
#include "my_printf.h"

/*
** %c
*/
char		*print_char(va_list *vlist)
{
  unsigned char	c;
  char		*tabstr;

  c = (unsigned char)va_arg(*vlist, int);
  if ((tabstr = malloc(sizeof(*tabstr) * 2)) == NULL)
    exit(-1);
  tabstr[0] = c;
  tabstr[1] = '\0';
  return (tabstr);
}

/*
** %s
*/
char	*print_string(va_list *vlist)
{
  char	*str;
  char	*tabstr;

  str = va_arg(*vlist, char *);
  if (str != NULL)
    tabstr = my_strdup(str);
  else
    tabstr = my_strdup("(null)");
  return (tabstr);
}

/*
** %P 
*/
char		*print_pointer(va_list *vlist)
{
  unsigned int	nb;
  char		*tabstr;
  int		k;
  int		lenstr;

  k = 2;
  nb = va_arg(*vlist, unsigned int);
  lenstr = my_putnbr_base_cptu(nb, "0123456789abcdef");
  if ((tabstr = malloc (sizeof(*tabstr) * (lenstr + 3))) == NULL)
    exit(-1);
  tabstr[0] = '0';
  tabstr[1] = 'x';
  my_putnbr_base2u(nb, "0123456789abcdef", tabstr, &k);
  tabstr[lenstr + 2] = '\0';
  return (tabstr);
}

/*
** %%
*/
char	*print_percent()
{
  char	*tabstr;

  if ((tabstr = malloc(sizeof(*tabstr)* 2)) == NULL)
    exit(-1);
  tabstr[0] = '%';
  tabstr[1] = '\0';
  return (tabstr);
}
