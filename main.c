#include <stdlib.h>
#include <stdio.h>
// Main class for running the parallel flocking sim

int main(int argc, char **argv) {
	
	long num_agents;
	long num_steps;
	char* filename;

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
        
        // for each numstep
        
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
        //
        // write -1 to file
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        return 0;
        
}
