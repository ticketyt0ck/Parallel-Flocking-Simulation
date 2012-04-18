
// Main class for running the parallel flocking sim

int main(int argc, char **argv) {
	
	long num_agents;
	long num_steps;
	char* filename;
	
	if (argc != 3) {
        printf("Usage: num_agents num_steps filename\n");
        exit(1);
        }
        
        num_agents = atol(argv[1]);
        num_steps = atol(argv[2]);
        
        
        
        //printf("Running a simulation 
