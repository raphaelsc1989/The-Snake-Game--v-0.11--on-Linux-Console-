/*  The Snake Game (v 0.11) on Linux Console!
 *  Copyright ©2011 - @uthor #Utroz(RsC)#.
 *  File: game.c
 *  Blog: http://Gcoders.wordpress.com/ (Access it)!
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

extern int game_modules(void);

void move_modules(void);
void msg_log(char *args);
int snake_move(void);
void set_pos(void);
void remove_pos(void);
void remake_body(void);
void create_body(void);
int check_status(void);
int check_body(void);
int check_wall(void);
int check_apple(void);
int create_apple(void);

int snake_check = 0;

/* Game Map */
char map[ROW][COLUMN] = { //Column |
		     	{ H, H, H, H, H, H, H, H, H, H, H, H }, //Row -
			{ V, M, M, M, M, M, M, M, M, M, M, V },
			{ V, M, M, M, M, M, M, M, M, M, M, V },
			{ V, M, M, M, M, M, M, M, M, M, M, V },
			{ V, M, M, M, M, M, M, M, M, M, M, V },
			{ V, M, M, M, M, M, M, M, M, M, M, V },
			{ V, M, M, M, M, M, M, M, M, M, M, V },
		     	{ H, H, H, H, H, H, H, H, H, H, H, H },
			};

/* Snake Move Modules */
void move_modules()
{
	/* Remove all Snake IDS on map */
	remove_pos();	

	/* If snake head are in body don't walk */
	if(snake_check == 0) remake_body();
	
	/* Return snake condition */
	snake_check = snake_move();

	/* If snake head are in wall don't walk! */
	if(check_status())
		set_pos();
}

void msg_log(char *args)
{
	printf("\t\t\t:: Last Log: %s ::\n", args);
	strcpy(config.log, "-");

}

/* Snake Move */
snake_move(void)
{
	int i;

	/* Increment snake position. */
	switch(config.snake_direction)
	{

		case WE: // West.
			snake_pos[HEAD][POS_Y]--;
			if(check_body() == 1)
			{
				snake_pos[HEAD][POS_Y]++;
				return 1;
			}
			break;

		case EA: // East.
			snake_pos[HEAD][POS_Y]++; 
			if(check_body() == 1)
			{
				snake_pos[HEAD][POS_Y]--;
				return 1;
			}
			break; 

		case NO: // North.
			snake_pos[HEAD][POS_X]--;
			if(check_body() == 1)
			{
				snake_pos[HEAD][POS_X]++;
				return 1;
			}	
			break; 

		case SO: // South.
			snake_pos[HEAD][POS_X]++;
			if(check_body() == 1)
			{
				snake_pos[HEAD][POS_X]--;
				return 1;
			}
			break; 
		case '1': exit(0);
	}

	return 0;	
}

/* Set Pos on map. */
void set_pos(void)
{
	int i;

	for(i = config.count; i >= 0; i--)	
		map[snake_pos[i][POS_X]][snake_pos[i][POS_Y]] = S; // Snake ID
}

/* Remove pos on map */
void remove_pos(void)
{
	int i;

	for(i = config.count; i >= 0; i--)	
		map[snake_pos[i][POS_X]][snake_pos[i][POS_Y]] = M; // Map ID
}

/* Remake all body parts */
void remake_body(void)
{
	int i;

	for(i = config.count; i > 0; i--)
	{
		snake_pos[i][POS_X] = snake_pos[i-1][POS_X];
		snake_pos[i][POS_Y] = snake_pos[i-1][POS_Y]; 

	}
}

/* Create a Body */
void create_body(void)
{
	++config.count;

	snake_pos[config.count][POS_X] = snake_pos[config.count-1][POS_X];
	snake_pos[config.count][POS_Y] = snake_pos[config.count-1][POS_Y]; 		
}

/* Check Snake Status */
check_status(void)
{
	if(check_apple() == 1)
	{ 
		config.points_user += POINT;
		strcpy(config.log, "Apple eat!");
		create_apple();
		create_body(); 
		return 1;
	}

	if(check_wall() == 1)
	{
		strcpy(config.log, "You are dead!");
		config.snake_status = DEAD;
		return 0;
	}
	return 1;
}

check_body(void)
{
	int i;

	for(i = config.count; i > 0; i--)
	{
		if (snake_pos[HEAD][POS_X] == snake_pos[i][POS_X])
			if(snake_pos[HEAD][POS_Y] == snake_pos[i][POS_Y])
			{
				config.body_found = 1;
				strcpy(config.log, "Body Found!");
				return 1;
			}
	}
	return 0;
}

check_wall(void)
{ 
	// Check if snake are in wall.
	return map[snake_pos[HEAD][POS_X]][snake_pos[HEAD][POS_Y]] != M ? 1 : 0;
}

check_apple(void)
{
	// Check if snake apple eat.
	return map[snake_pos[HEAD][POS_X]][snake_pos[HEAD][POS_Y]] == A ? 1 : 0;
}

/* Create Apple on Map */
create_apple(void)
{
	srand(time(NULL));
	apple_pos[POS_X] = rand() % (ROW-2) + 1;
	apple_pos[POS_Y] = rand() % (COLUMN-2) + 1;

	// Check if apple position is equals to snake.
	int i;

	for(i = 0; i <= config.count; i++)
	{
		if(apple_pos[POS_X] == snake_pos[i][POS_X] && apple_pos[POS_Y] == snake_pos[i][POS_Y]) return create_apple();
	}

	map[apple_pos[POS_X]][apple_pos[POS_Y]] = A; // Set Apple ID on map.

	return (0);
}

