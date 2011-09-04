/*  The Snake Game (v 0.11) on Linux Console!
 *  Copyright ©2011 - @uthor #Utroz(RsC)#.
 *  File: ia.c
 *  Blog: http://Gcoders.wordpress.com/ (Access it)!
*/

#include "global.h"
#include <stdlib.h>

extern char map[ROW][COLUMN];

/* Snake Head Pos */
int h_pos_x, h_pos_y;


void head_pos(void)
{
	h_pos_x = snake_pos[HEAD][POS_X];
	h_pos_y = snake_pos[HEAD][POS_Y];
}

/* Make a function to don't found body! */
int goto_apple(void)
{
	head_pos();

	if(config.body_found == 1)
	{
		srand(time(NULL));

		/* Select a random direction */
		config.snake_direction = rand() % 4;

		config.body_found = 0;
		return 0;

	}

	/* Snake pos is below line of Apple Pos */ 
	if(h_pos_x > apple_pos[POS_X])
	{
		if(map[(h_pos_x) -1][h_pos_y] != M && map[(h_pos_x) -1][h_pos_y] != A) 
	
			if(h_pos_y > apple_pos[POS_Y])	
				config.snake_direction = WE;
			else 
				config.snake_direction = EA;
		 
		else config.snake_direction = NO;
	}	

	/* Snake pos is above line of Apple Pos */ 
	else if (h_pos_x < apple_pos[POS_X])
	{
		if(map[(h_pos_x) +1][h_pos_y] != M && map[(h_pos_x) +1][h_pos_y] != A) 
			
			if(h_pos_y > apple_pos[POS_Y])	
				config.snake_direction = WE;
			else 
				config.snake_direction = EA;

		else config.snake_direction = SO;
	}

	/* Snake pos is equals line of Apple Pos */ 
	else if (h_pos_x == apple_pos[POS_X])
	{
		/* Apple pos are to left from Snake. */
		if(h_pos_y > apple_pos[POS_Y])
		{
			if(map[h_pos_x][(h_pos_y) -1] != M && map[h_pos_x][(h_pos_y) -1] != A)

				if(map[(h_pos_x) -1][h_pos_y] == V || map[(h_pos_x) -1][h_pos_y] == H)	
					config.snake_direction = SO;
				else 
					config.snake_direction = NO;

			else config.snake_direction = WE;
		}

		/* Apple pos are to right from Snake. */
		else if(h_pos_y < apple_pos[POS_Y])
		{
			if(map[h_pos_x][(h_pos_y) +1] != M && map[h_pos_x][(h_pos_y) +1] != A) 			
				if(map[(h_pos_x) -1][h_pos_y] == V || map[(h_pos_x) -1][h_pos_y] == H)	
					config.snake_direction = SO;
				else 
					config.snake_direction = NO;

			else config.snake_direction = EA;
		}
	}
	return 0;
}


