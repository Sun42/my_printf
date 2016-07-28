/*
** calcul.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:28:59 2008 christophe sundas
** Last update Thu Nov 27 20:41:46 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_putnbr_base(int n, char *base)
{
  int	deb;
  int	fin;
  int	len;

  len = my_strlen(base);
  if (n < 0)
    {
      my_putchar('-');
      my_putnbr_base(-n, base);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        my_putnbr_base(deb, base);
      my_putchar(base[fin]);
    }
}

void	my_putnbr_base2(int n, char *base, char tabstr[], int *indice)
{
  int	deb;
  int	fin;
  int	len;
  
  len = my_strlen(base);
  if (n < 0)
    {
      tabstr[*indice] = '-';
      *indice = *indice + 1;
      my_putnbr_base2(-n, base, tabstr, indice);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
      	  my_putnbr_base2(deb, base, tabstr, indice);
      tabstr[*indice] = base[fin];
      *indice = *indice + 1 ;
    }
}
	
int	my_putnbr_base_cpt(int n, char *base)
{
  int	deb;
  int	fin;
  int	len;
  int	cpt;

  cpt = 0;
  len = my_strlen(base);
  if (n < 0)
    {
      cpt++;
      cpt += my_putnbr_base_cpt(-n, base);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        cpt += my_putnbr_base_cpt(deb, base);
      cpt++;
    }
  return (cpt);
}

void		my_putnbr_base2u(unsigned int n, char *base, char tabstr[], int *indice)
{
  unsigned int	deb;
  unsigned int	fin;
  unsigned int	len;

  len = my_strlen(base);
  fin = n % len;
  deb = (n - fin) / len;
  if (deb != 0)
    my_putnbr_base2(deb, base, tabstr, indice);
  tabstr[*indice] = base[fin];
  *indice = *indice + 1 ;
}

int		my_putnbr_base_cptu(unsigned int n, char *base)
{
  unsigned int	deb;
  unsigned int	fin;
  unsigned int	len;
  unsigned int	cpt;

  cpt = 0;
  len = my_strlen(base);
  fin = n % len;
  deb = (n - fin) / len;
  if (deb != 0)
    cpt += my_putnbr_base_cpt(deb, base);
  cpt++;
  return (cpt);
}
