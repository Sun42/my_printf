/*
** calcul_long.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:29:59 2008 christophe sundas
** Last update Thu Nov 27 20:42:01 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

void			my_putnbr_base2l(long int n, char *base, char tabstr[], int *i)
{
  long signed int	deb;
  long signed int	fin;
  long signed int	len;

  len = my_strlen(base);
  if (n < 0)
    {
      tabstr[*i] = '-';
      *i = *i + 1;
      my_putnbr_base2l(-n, base, tabstr, i);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        my_putnbr_base2l(deb, base, tabstr, i);
      tabstr[*i] = base[fin];
      *i = *i + 1;
    }
}

int			my_putnbr_base_cptl(long int n, char *base)
{
  long signed int	deb;
  long signed int	fin;
  long signed int	len;
  long signed int	cpt;

  cpt = 0;
  len = my_strlen(base);
  if (n < 0)
    {
      cpt++;
      cpt += my_putnbr_base_cptl(-n, base);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        cpt += my_putnbr_base_cptl(deb, base);
      cpt++;
    }
  return (cpt);
}

void			my_putnbr_base2lu(long unsigned int n, char *base, char tabstr[], int *i)
{
  long unsigned int	deb;
  long unsigned int	fin;
  long unsigned int	len;

  len = my_strlen(base);
  fin = n % len;
  deb = (n - fin) / len;
  if (deb != 0)
    my_putnbr_base2lu(deb, base, tabstr, i);
  tabstr[*i] = base[fin];
  *i = *i + 1;
}

int			my_putnbr_base_cptlu(long unsigned int n, char *base)
{
  long unsigned int	deb;
  long unsigned int	fin;
  long unsigned int	len;
  long unsigned int	cpt;

  cpt = 0;
  len = my_strlen(base);
  fin = n % len;
  deb = (n - fin) / len;
  if (deb != 0)
    cpt += my_putnbr_base_cptlu(deb, base);
  cpt++;
  return (cpt);
}
