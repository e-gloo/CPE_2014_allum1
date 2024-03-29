/*
** alum1.h for alum1 in /home/coodie_d/rendu/C_Prog/B2/Allum1/includes
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb  6 13:08:16 2015 Dylan Coodien
** Last update Sun Feb 22 18:36:55 2015 Dylan Coodien
*/

#ifndef ALUM1_H_
# define ALUM1_H_

# define SIZE	1024
# define BASE	"01"
# define OPTION	"\nIf you retry with the game with '-h' or '--help', you'll find the the way to play with much more fun !\n"
# define VALIDE	"\nPlease choose a valid row\n"
# define MATCH	"\nPlease, take at least one match\n"
# define CHOOSE	"\nType 'yes' or 'no' to choose\n"
# define NUM	"\nYou must enter 2 numbers: row and numbers\n"
# define TRY	"\nTry again ?\n"
# define YES	"yes\n"
# define NO	"no\n"
# define MANY	"\nToo many matches to take in this row\n"
# define TURN	"\nYour turn : "
# define BUG	"\nSegmentation fau... Haha, got ya !\n"
# define WON	"\nYOU WOOOOOON !!!\n"
# define LOST	"\nYOU LOOOOOOST !!!\n"
# define GU	"give up\n"
# define EXIT	"exit\n"

typedef	struct	s_list
{
  int		num;
  int		row;
  int		save;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_vars
{
  int		row;
  int		num;
  char		buffer[SIZE];
  char		**tab;
}		t_vars;

typedef struct	s_algo
{
  int		n;
  int		count;
  int		len;
}		t_algo;

void		my_free(char **tab);
void		free_list(t_list *list);
char		**my_str_to_word_tab(char *str);
int		my_put_in_list(t_list *list);
int		begin_game(void);
void		my_show_list(t_list *list, int space);
int		check_arg(int ac, char **av);
int		action(t_list *list);
int		perso(void);
int		help(void);
int		check_longer(t_list *list);
void		change_buffer(t_vars *vars);
int		players_turn(t_list *list, t_vars *vars);
int		after_turn(t_vars *vars, t_list *list);
t_vars		*init(void);
void		display_IA_move(t_list *tmp);
int		my_putnbr_base_rev_i(int nb, char *base, int i);
int		check_game(t_list *list, t_vars *vars);
char		*algo(t_list *list, t_vars *vars);

#endif /* !ALUM1_H_ */
