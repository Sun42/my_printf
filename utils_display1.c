/*
** my_printf.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_print
**
**  Made by christophe sundas 
** Login   <sundas_c@epitech.net>  
**
**  Started on  Wed Nov 26 22:43:16 2008 christophe sundas
** Last update Thu Nov 27 20:46:45 2008 christophe sundas
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

/*
** prefixe +str ou precision +str
*/
char	*add_to_str(char *add, char *str)
{
  char	*new_str;
  int	len;

  len = my_strlen(str) + my_strlen(add) + 1;
  if ((new_str = malloc(sizeof(*new_str) * len)) == NULL)
    exit(-1);
  my_strcpy(new_str, add);
  my_strcat(new_str, str);
  return (new_str);
}

/*
***cree  prefixe + precision + str
*/
char	*add_to_str2(char *prefixe, char *prec, char *str)
{
  char	*new_str;
  int	len;

  len = my_strlen(prefixe) + my_strlen(prec) + my_strlen(str) + 1;
  if ((new_str = malloc(sizeof(*new_str) * len)) == NULL)
    exit(-1);
  my_strcpy(new_str, prefixe);
  my_strcat(new_str, prec);
  my_strcat(new_str, str);
  return (new_str);
}

/*
** retourne chaine avec prefixe + precision + str 
*/
char	*mk_precision_unsigned(char *str, t_spec *spec)
{
  char	*prec;
  char	*prefixe;
  char	*new_str;
  int	nbprec;
  int	lenstr;

  nbprec = spec->precis.precision - my_strlen(str);
  prefixe = mk_sharp_flag(spec);
  prec = mk_precis(nbprec);
  lenstr = my_strlen(str);
  if ((prefixe == NULL) && (prec == NULL))
    new_str = my_strdup(str);
  if ((prefixe != NULL) && (prec != NULL))
    new_str =  add_to_str2(prefixe, prec, str);
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

void	display_spaces(int lenstr, int final_width, t_spec *spec)
{
  int	nb;

  nb = final_width - lenstr;
  while (nb > 0)
    {
      my_putchar(spec->flag.add);
      nb--;
    }
}

void	display_spaces_nan(int lenstr, int final_width)
{
  int	nb;

  nb = final_width - lenstr;
  while (nb > 0)
    {
      my_putchar(' ');
      nb--;
    }
}
