#include<stdio.h>
#include<stdlib.h>
#include "steering_behaviors.h"



Vector2D separation(Agent* a, int index, Agent *agentarray, int num_agents) {
	Vector2D steering_force = init_vector(0.0, 0.0);
	
	int i;
	
	for(i = 0; i < num_agents; i++) {
		if (i != index) {
			
			Vector2D toAgent = point_minus(&a->position, &agentarray[i].position);
			
						
			
			//printf("X and Y before mag %f %f\n", toAgent.x, toAgent.y);
			double mag = magnitude(&toAgent);
			//printf("Magnitude of toagent is %.2f\n", mag);
			normalize(&toAgent);
			divide_equals(&toAgent, mag);
			
			plus_equals(&steering_force, &toAgent);
			//printf("steering force is %f %f\n", steering_force.x, steering_force.y);

		}
	}
	
	
	return steering_force;
	
}


Vector2D cohesion(Agent* a, int index, Agent *agentarray, int num_agents) {
	Vector2D steering_force = init_vector(0.0, 0.0);
	Point2D center_point_mass = init_point(0.0, 0.0);
	Vector2D v;
	
	
	
	
	int neighborcount = 0;
	int i;
	double xavg = 0;
	double yavg = 0;
	double mag;
	for(i = 0; i < num_agents; i++) {
		Vector2D v = point_minus(&a->position, &agentarray[i].position);
		mag = magnitude(&v);
		if (i != index && mag < 200) {
			xavg += agentarray[i].position.x;
			yavg += agentarray[i].position.y;
			++neighborcount;
		}
	}
	
	if (neighborcount > 0) {
		
		steering_force.x = xavg / neighborcount;
		steering_force.y = yavg / neighborcount;
		
		center_point_mass.x = steering_force.x;
		center_point_mass.y = steering_force.y;
				
		v = point_minus(&center_point_mass, &a->position);
		normalize(&v);
		v = times(&v, a->speed);
		steering_force = minus(&v, &a->heading);
	}
	
	return steering_force;
}

Vector2D alignment(Agent* a, int index, Agent *agentarray, int num_agents) {
	Vector2D average_heading = init_vector(0.0, 0.0);
	Vector2D steering_force = init_vector(0.0, 0.0);	
	
	int neighborcount = 0;
	int i;
	double mag;
	for(i = 0; i < num_agents; i++) {
		Vector2D v = point_minus(&a->position, &agentarray[i].position);
		mag = magnitude(&v);
		if (i != index && mag < 200) {
			plus_equals(&average_heading, &agentarray[i].heading);
			++neighborcount;
			
		}
		
		
		
	}
	if (neighborcount > 0) {
		steering_force = divide(neighborcount, &average_heading);
			
		steering_force = minus(&steering_force, &a->heading);
				
			
	}
	
	return steering_force;
	
	
}
