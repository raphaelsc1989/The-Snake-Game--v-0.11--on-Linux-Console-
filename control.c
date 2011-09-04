/*  The Snake Game (v 0.11) on Linux Console!
 *  Copyright ©2011 - @uthor #Utroz(RsC)#.
 *  File: control.c
 *  Blog: http://Gcoders.wordpress.com/ (Access it)!
*/

#include <stdio.h>
#include "global.h"

/* Choose a snake direction */
void set_key(void)
{
	char key, ch;
	ch = getchar();
	key = ch;
	fflush(stdin);

	switch(key)
	{
		case KEY_UP:
			config.snake_direction = NO;
			break;
		case KEY_DOWN:
			config.snake_direction = SO;
			break;
		case KEY_LEFT:
			config.snake_direction = WE;
			break;
		case KEY_RIGHT:
			config.snake_direction = EA;
			break;

	} 

	if(key != KEY_UP && key != KEY_DOWN && key != KEY_LEFT && key != KEY_RIGHT) set_key();

	key = 0;
}
			
