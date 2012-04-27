#include<stdio.h>
#include<stdlib.h>

#include "agent.h"

Vector2D separation(Agent* a, int index, Agent *agentarray, int num_agents);
Vector2D cohesion(Agent* a, int index, Agent *agentarray, int num_agents);
Vector2D alignment(Agent* a, int index, Agent *agentarray, int num_agents);
int find_closest(Agent* a, int index, Agent *agentarray, int num_agents);
Vector2D seek(Agent* a, Agent* b);
