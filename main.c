#include <stdlib.h>
#include <stdio.h>
#include "agent.h"
#include "vector.h"
#include <sys/time.h>
// Main class for running the parallel flocking sim

#define WINDOWSIZE 500

int main(int argc, char **argv) {
	
	long num_agents;
	long num_steps;
	char* filename;
	long timestep;

	if (argc != 4) {
        printf("Usage: num_agents num_steps filename\n");
        exit(1);
        }
        
        num_agents = atol(argv[1]);
        num_steps = atol(argv[2]);
        filename = argv[3];
        
        
        
        printf("Running a simulation with %lu agents for %lu steps and saving the data to the file %s\n", 
        	num_agents, num_steps, filename);
        
        // here's the simulation skeleton
        
        
        // create the agents, with random headings, maybe random locations or all in a bunch
        int i;
        Agent agent_list[num_agents];
        
        struct timeval tv;
        gettimeofday(&tv, NULL);
        
        srand(tv.tv_usec);
        for(i = 0; i < num_agents - 1; i++){
        	Vector2D heading = init_vector((rand_r(i) % 5), (rand_r(i) % 5));
        	Point2D start_loc = init_point((rand_r(i) % WINDOWSIZE), (rand_r(i) % WINDOWSIZE));
        	double speed = 5;
        	agent_list[i] = init_agent(heading, start_loc, speed, Agent_Type prey);
        	
        	
        }
        Vector2D heading = init_vector((rand_r(i) % 5), (rand_r(i) % 5));
        Point2D start_loc = init_point((rand_r(i) % WINDOWSIZE), (rand_r(i) % WINDOWSIZE));
        double speed = 5;
        agent_list[i] = init_agent(heading, start_loc, speed, Agent_Type predator);
        
        
        
        // for each numstep
        for(timestep = 0; i < num_steps; i++){
        	
        
        //	for each agent
        //		do cohesion, alignment, and seperation
        //		update new heading
        // 	
        // 	for each agent
        //		update the agent location
        //		check their position within boundaries, fix it with mod	
        //		update old heading by setting it = to new heading
        //		write position of agent to file
        //
        //	(if it's not the last step)
        //	write -2 to file
        
        }
        //
        // write -1 to file
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        return 0;
        
}
