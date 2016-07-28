/*
** fill_flag2.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:38:53 2008 christophe sundas
** Last update Thu Nov 27 20:43:41 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

/*
** rempli le champs sharp '#' ou '?'
*/
void	fill_sharp(char *format, int cpt, t_spec *spec)
{
  int	i;

  i = 0;
  while (i < cpt)
    {
      if (format[i] == '#')
        {
          spec->flag.sharp = '#';
          return ;
        }
      i++;
    }
  spec->flag.sharp = '?';
}

/*
** rempli le champ force space 1 ou 0
*/
void	fill_force_space(char *format, int cpt, t_spec *spec)
{
  int	i;

  i = 0;
  while (i < cpt)
    {
      if (format[i] == ' ')
        {
          spec->flag.force_space = 1;
          return ;
        }
      i++;
    }
  spec->flag.force_space = 0;
}

/*
** rempli le champ force sign 1 ou 0
*/
void	fill_force_sign(char *format, int cpt, t_spec *spec)
{
  int	i;

  i = 0;
  while (i < cpt)
    {
      if (format[i] == '+')
        {
          spec->flag.force_sign = 1;
          return ;
        }
      i++;
    }
  spec->flag.force_sign = 0;
}

/*
** rempli le champs add ' ' ou '0'
*/
void	fill_add(char *format, int cpt, t_spec *spec)
{
  int	i;

  i = 0;
  while (i < cpt)
    {
      if (format[i] == '0')
        {
          spec->flag.add = '0';
          return ;
        }
      i++;
    }
  spec->flag.add = ' ';
}

/*
** rempli le champs align 'L' ou 'R'
*/
void	fill_align(char *format, int cpt, t_spec *spec)
{
  int	i;
 
  i = 0;
  while (i < cpt)
    {
      if (format[i] == '-')
        {
          spec->flag.align = 'L';
          return ;
        }
      i++;
    }
  spec->flag.align = 'R';
}
