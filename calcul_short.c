/*
** calcul_short.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:30:23 2008 christophe sundas
** Last update Thu Nov 27 20:42:10 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

void			my_putnbr_base2h(short int n, char *base, char tabstr[], int *i)
{
  short signed int	deb;
  short signed int	fin;
  short signed int	len;

  len = my_strlen(base);
  if (n < 0)
    {
      tabstr[*i] = '-';
      *i = *i + 1;
      my_putnbr_base2h(-n, base, tabstr, i);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
	my_putnbr_base2h(deb, base, tabstr, i);
      tabstr[*i] = base[fin];
      *i = *i + 1;
    }
}

int			my_putnbr_base_cpth(short int n, char *base)
{
  short signed int	deb;
  short signed int	fin;
  short signed int	len;
  short signed int	cpt;

  cpt = 0;
  len = my_strlen(base);
  if (n < 0)
    {
      cpt++;
      cpt += my_putnbr_base_cpth(-n, base);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        cpt += my_putnbr_base_cpth(deb, base);
      cpt++;
    }
  return (cpt);
}

void			my_putnbr_base2hu(short unsigned int n, char *base, char tabstr[], int *i)
{
  short	unsigned int	deb;
  short	unsigned int	fin;
  short	unsigned int	len;

  len = my_strlen(base);
  fin = n % len;
  deb = (n - fin) / len;
  if (deb != 0)
    my_putnbr_base2hu(deb, base, tabstr, i);
  tabstr[*i] = base[fin];
  *i = *i + 1;
}

int			my_putnbr_base_cpthu(short unsigned int n, char *base)
{
  short	unsigned int	deb;
  short	unsigned int	fin;
  short	unsigned int	len;
  short unsigned int	cpt;

  cpt = 0;
  len = my_strlen(base);
  fin = n % len;
  deb = (n - fin) / len;
  if (deb != 0)
    cpt += my_putnbr_base_cpthu(deb, base);
  cpt++;
  return (cpt);
}
