/*
** minishell.c for mini in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:33:55 2016
** Last update Sun Jan 24 22:51:17 2016 Clement Peau
*/

#ifndef _MINISHELL_
# define _MINISHELL_

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

typedef struct	s_data
{
  char		*get_next;
  char		**args;
  char		**envcpy;
  char		**path;
}		t_data;

void	actualise(t_data *);
int	get_envnbr(char *, char **);
void	free_it(t_data *);
char	*read_it(t_data *);
char	*seek_env(char **, char *);
int	check_name(char *, char *, int);
int	env_length(char *);
int	minishell(int, char **, char **);
void	my_strcpy(char *, char *);
char	*get_next_line(int );
int	count_words(char *, char);
char	**my_wordtab(char *, char);
char	*epur_str(char *);
char	*main_calc(t_data *);
char	**get_env(char **);
int	my_arrlen(char **);
int	my_strlen(char *);
void	get_path(t_data *);
int	main_fork(t_data *);
void	my_cd(t_data *);
void	my_setenv(t_data *);
void	my_env(t_data *);
void	my_unsetenv(t_data *);
void	my_exit(t_data *);
int	my_strcmp(char *, char *);
int	arrlen(char **);
int	getnbr(char *);
void	showtab(char **);
void	my_strcat(char *, char *);
char	*get_name(char *);
int	is_builtin(t_data *);
void	change_path(t_data *);
int	my_strlen(char *);
void	free_args(t_data *);

#endif /* _MINISHELL_ */
