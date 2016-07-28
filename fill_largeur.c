/*
** fill_largeur.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:40:26 2008 christophe sundas
** Last update Thu Nov 27 20:43:50 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Rempli le champ spec largeur et retourne le nb de char de la spec largeur
*/

int	fill_largeur(char *format, t_spec *spec, va_list *vlist)
{
  int	cpt;
  char	*slargeur;

  cpt = 0;
  if (*format == '*')
    return (fill_largeur_star(spec, vlist));
  while (my_char_is_num(format[cpt]))
    cpt++;
  if (cpt != 0)
    {
      if ((slargeur = malloc(sizeof(char) * (cpt + 1))) == NULL)
        exit(-1);
      slargeur[0] = '\0';
      my_strcat(slargeur, "");
      my_strncat(slargeur, format, cpt);
      spec->largeur = my_getnbr(slargeur);
      free(slargeur);
    }
  else
    spec->largeur = 0;
  return (cpt);
}

/*
** Cas '*'
*/
int	fill_largeur_star(t_spec *spec, va_list *vlist)
{
  spec->largeur = va_arg(*vlist, int);
  return (1);
}
