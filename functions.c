/*  The Snake Game (v 0.11) on Linux Console!
 *  Copyright ©2011 - @uthor #Utroz(RsC)#.
 *  File: functions.c
 *  Blog: http://Gcoders.wordpress.com/ (Access it)!
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "global.h"

extern void goto_apple(void);
extern char map[ROW][COLUMN];
extern void move_modules(void);
extern void set_key(void);

void game_start(void);
void player_data(void);
int game_modules(void);
void clean_body(void);
void delay_time(int seconds);
void clean_console(void);
void show_game(void);
void clean_console(void);
void remove_garbage(void);
void game_exit(void);

const char game_name[] = ("The Snake Game (v0.11) on Linux Console!"),
author[] = (":: By Utroz(RSC)::");

/* Game Start */
void game_start(void)
{
	clean_console();
	player_data();
	printf("\n\t\t%s\n\t\t\t%s\n", game_name, author);
	delay_time(2);

	while(1)
	{
		/* Check if snake is dead */
		if(config.snake_status == 1) game_exit();

		game_modules();
		printf("\n");
	}
}

/* Reset Player Data */
void player_data(void)
{
	config.snake_status = LIVE;
	snake_pos[HEAD][POS_X] = DEFAULT_X;
	snake_pos[HEAD][POS_Y] = DEFAULT_Y;
	create_apple();
	clean_body();
	config.count = 0;
	config.points_user = 0;
	config.snake_direction = WE;
	config.game_level = N3;
}	

/* Run all modules of game */
game_modules(void)
{
	clean_console();
	goto_apple();
	move_modules();
	show_game();
	//set_key();

	delay_time(config.game_level); // Nivel.

	return (0);
}

void clean_body(void)
{
	int i;
	
	for(i = 1; i <= config.count; i++)
	{
		snake_pos[i][POS_X] = 0;
		snake_pos[i][POS_Y] = 0;
	}
}

void delay_time(int seconds)
{
	// sleep(seconds); 
	usleep(seconds * 1000000);
}

void clean_console(void)
{
	printf("\e[H\e[2J");
}

char *direct_msg(void)
{
	if(config.snake_direction == 0) return "West";
	else if(config.snake_direction == 1) return "East";
	else if(config.snake_direction == 2) return "North";
	else return "South";
	
	return NULL;
}
		

/* Show Screen of Game. */
void show_game(void)
{
	int level;
	register int i, j;
	char direction[2];

	printf("\n\t\t%s\n\t\t\t%s\n", game_name, author);

	//if(config.snake_direction == 0) direction

	if(config.game_level == N3) level = 3;
	else if(config.game_level == N2) level = 2;
	else level = 1;

	printf("\n\t\t\tLevel: %d | Points: %d\n\n", level, config.points_user);
	for(i = 0; i < ROW; i++) 
	{
		printf("\t\t%c%c%c%c%c", M, M, M, M, M);
		for(j = 0; j < COLUMN; j++) printf(" %c",map[i][j]);

		printf("\n");
	}
	msg_log(config.log);
	printf("\t\tApple Count: %d  / Snake Direction: %s\n", config.count, direct_msg());	
	printf("\n\t\tPlease access: http://GCoders.wordpress.com\n");
}  

/* Remove Garbage by the map */
void remove_garbage(void)
{
	register int i, j;
	for(i = 1; i < ROW-1; i++) 
	{
		for(j = 1; j < COLUMN-1; j++)
		{ 
			if(map[i][j] != M) map[i][j] = M;
		}
	}		
} 

void game_exit(void)
{
	char choose;

	printf("\t\t\t:::::::::::::::::::\n");
	printf("\t\t\t:: You are dead! ::\n");
	printf("\t\t\t:::::::::::::::::::\n");
	delay_time(1);		

	while(1)
	{
		printf("\n\t\tYou wanna play other time? (y/n):");
		scanf("%c", &choose);
		fflush(stdin);

		switch(choose)
		{
			case 'y': 
				remove_garbage();
				player_data();
				game_start(); 
				break;
			case 'n': 
				printf("\n\t\tThanks for play the game!\n"); 
				delay_time(1);	
				clean_console();
				exit(1); 

				break;
			default: 
				printf("\n\t\tPlease input a valid option! (y/n)\n");
				break;
		}
	}
}

