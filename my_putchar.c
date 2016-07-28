/*
** my_putchar.c for my_putchar in /u/epitech_2011s/sundas_c/cu/rendu/lib/my
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 18:38:49 2008 christophe sundas
** Last update Thu Nov 27 21:01:40 2008 christophe sundas
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
