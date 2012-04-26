#ifndef agent_head
	#define agent_head

#include<stdio.h>
#include<stdlib.h>
#include "point.h"

typedef enum { 
	prey, 
	predator 
} Agent_Type;

typedef struct {
	Vector2D heading;
	Point2D position;
	double speed;
	Agent_Type type;
	
	
} Agent;




Agent init_agent(Vector2D* heading, Point2D* position, double speed, Agent_Type type);
void agent_update(Agent* a, double delta);

#endif
