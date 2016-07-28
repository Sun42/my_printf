/*
** print_special_string.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:46:01 2008 christophe sundas
** Last update Sat Nov 29 16:59:17 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

char			*print_string_special(va_list *vlist)
{
  char			*str;
  char			*tabstr;
  int			lenstr;
  char			*octalstr;

  str = va_arg(*vlist, char *);
  if (str == NULL)
    return (my_strdup("(null)"));
  lenstr = cpt_special_str(str);
  if ((tabstr = malloc(sizeof(*tabstr) * (lenstr + 1))) == NULL)
    exit(-1);
  my_strcpy(tabstr, "");
  tabstr[lenstr] = '\0';
  while (*str)
    {
      if ((*str < 32) || (*str >= 127))
        {
	  octalstr = print_char_asoctal(*str);
	  my_strcat(tabstr, octalstr);
	  free(octalstr);
        }
      else
	my_strncat(tabstr, str, 1);
      str++;
    }
  return (tabstr);
}

/*
** retourne longueur totale d'une  chaine %S en vue dun malloc
*/
int	cpt_special_str(char *str)
{
  int	cpt;

  cpt = 0;
  while (*str)
    {
      if ((*str < 32) || (*str >= 127))
        {
          cpt += cpt_char_asoctal(*str);
        }
      else
        {
	  cpt++;
        }
      str++;
    }
  return (cpt);
}

/*
** retourn longueur d'une sous chaine speciale en octal
*/
int	cpt_char_asoctal(unsigned char c)
{
  int	cpt;

  cpt = my_putnbr_base_cptu(c, "01234567") + 1;
  return (cpt);
}

/*
** retourne la sous chaine special en octal
*/
char	*print_char_asoctal(unsigned char c)
{
  int	lenstr;
  int	k;
  char	*tabstr;

  k = 1;
  lenstr = my_putnbr_base_cptu(c, "01234567");
  if ((tabstr = malloc (sizeof(*tabstr) * (lenstr + 2))) == NULL)
    exit(-1);
  tabstr[0] = '\\';
  my_putnbr_base2u(c, "01234567", tabstr, &k);
  tabstr[lenstr] = '\0';
  return (tabstr);
}
