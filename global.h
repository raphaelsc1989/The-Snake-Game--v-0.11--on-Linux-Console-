/*  The Snake Game (v 0.11) on Linux Console!
 *  Copyright ©2011 - @uthor #Utroz(RsC)#.
 *  File: global.h
 *  Blog: http://Gcoders.wordpress.com/ (Access it)!
*/ 

/* Key Cordenates */
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

/* Map Cordenates */
#define POS_X 0
#define POS_Y 1

/* Map Size */
#define ROW 8
#define COLUMN	12 

/* Map IDS */
#define M 32	//Map ID
#define S 42	//Snake ID
#define A 64	//Apple ID

/* Graphics */
#define V 124	//Vertical Graphic
#define H 126	//Horizontal Graphic

/* Directions */
#define WE 0	// West
#define EA 1	// East
#define NO 2	// North
#define SO 3	// South

/* Snake Status */
#define LIVE 0;	// Live
#define DEAD 1; // Dead

/* ID's Position
   Row: [0] / Column: [1] */
int snake_pos[99][2];
int apple_pos[2];
#define DEFAULT_X 3
#define DEFAULT_Y 5

/* Snake ID's */
#define HEAD 0

/* Data Config */
struct {

	/* Snake Body Count */
	int count; // (Start on: 0)

	/* Snake Status */
	int snake_status, body_found;

	/* Log Snake */
	char log[40];

	/* Snake Direction */
	int snake_direction;

	/* Data User */
	int game_level, points_user;
} config;

/* Game Level : Delay */
#define N1 1.4
#define N2 1.2
#define N3 1.0

/* Apple Points */
#define POINT 10


