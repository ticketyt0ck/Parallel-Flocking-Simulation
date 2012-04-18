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
        
        return 0;
        
}
