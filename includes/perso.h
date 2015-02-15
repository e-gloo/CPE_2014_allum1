/*
** perso.h for perso in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 15:13:58 2015 Dylan Coodien
** Last update Sun Feb 15 15:56:31 2015 Dylan Coodien
*/

#ifndef PERSO_H_
# define PERSO_H_

# define SIZE	1024
# define ROB	"\nDo you want to choose only the number of row, or matches as well ?\n"
# define WHAT	"\nType 'row only' or 'both' to choose :"
# define ONLY	"row only\n"
# define BOTH	"both\n"
# define HM	"\nHow many matches do you want in the row "
# define POS	"\nChoose between 1 and 50\n"
# define STOP	"stop\n"
# define ROW	"\nChoose the number of row between 1 and 25 :"
# define MODE	"\nAgainst whom do you want to play ?\n"
# define VSIA	"IA\n"
# define OVO	"1v1\n"
# define WMODE	"\nType 'IA' to play against IA or '1v1' to play against someone :"
# define LEVEL	"\nChoose the level of the IA\n"
# define SELECT	"\nType type 'easy' or 'hard' to choose :"
# define EASY	"easy\n"
# define HARD	"hard\n"
# define FIRST	"\nWho start, player1 or player2 ?\n"
# define ONE	"player1\n"
# define TWO	"player2\n"
# define PLAYER	"\nType 'player1' or 'player2' to choose :"
# define WHO	"\nWho start, you or the IA ?\n"
# define ME	"me\n"
# define IA	"IA\n"
# define IAORME	"\nType 'me' or 'IA' to choose :"
# define TIPS	"cheat\n"
# define LOOSER	"\nTake what you want, you already lost\n"

#include "alum1.h"

typedef struct	s_info
{
  int		nb_row;
  int		num;
  int		mode;
  int		level;
  int		first;
  int		tips;
  int		keep;
}		t_info;

int		choose_display(t_info *info, t_list *list);
int		choose_mode(t_info *info);
int		choose_first(t_info *info, t_list *list);
int		put_matches_in_row(t_info *info, t_list *list);
int		put_all_row(t_info *info, t_list *list);
int		one_versus_one(t_list *list, t_info *info);
int		easy(t_list *list, t_info *info, t_algo *al, t_vars *vars);
int		hard(t_list *list, t_algo *algo, t_info *info, t_vars *vars);
int		turn(t_list *list, t_info *info);
int		IA_turn(t_list *list, t_info *info, t_vars *vars);

#endif /* !PERSO_H_ */
