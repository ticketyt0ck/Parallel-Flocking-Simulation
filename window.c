#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/Xos.h>
#include<stdio.h>
#include<stdlib.h>
#include"window.h"
#include<time.h>


int window_width;
int window_height;
int screen;

Window window;
Display *display;
GC gc;
Pixmap pixmap;


/*
 * create_window: *  creates window with given width and height *  CALL ONCE
 *  width is the width of the window
 *  height is the height of the window
 *  name is the name of the window
 */
void create_window(int width, int height, char *name) {
    int xpos, ypos;
    int border_width;
    XWindowAttributes wa;

    xpos = ypos = 0;    /* window is at 0,0 */
    border_width = 5;   /* 5px border */

    window_width = width;
    window_height = height;

    if (!XInitThreads()) {
        fprintf(stderr, "Error initializing Xlib\n");
    }

    if ((display = XOpenDisplay(NULL)) == NULL) {
        fprintf(stderr, "Error connecting to X server.\n");
        exit(-1);
    }

    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, screen),
            xpos, ypos, width, height, border_width, 
            BlackPixel(display, screen), WhitePixel(display, screen));

    XStoreName(display, window, name);

    gc = XCreateGC(display, window, 0, NULL);
    
    XMapWindow(display, window);

    XSelectInput(display, window, KeyPressMask);

    XGetWindowAttributes(display, window, &wa);

    pixmap = XCreatePixmap(display, window, wa.width,
            wa.height, wa.depth);
    
     XSync(display, 0);

}

/*
 * plot_point:
 *  plots a point in the current foreground color
 *  (default is black)
 *  x is the x coordinate to plot
 *  y is the y coordinate to plot
 */
void plot_point(int x, int y) {
    XDrawPoint(display, pixmap, gc, x, y);
}

/*
 * update_window:
 *  updates the window
 */
void update_window() {
    XCopyArea(display, pixmap, window, gc, 0, 0, 
            window_width, window_height, 0, 0);
    XFlush(display);
    XSetForeground(display, gc, 0);
    XFillRectangle(display, pixmap, gc, 0, 0, window_width, window_height);
}

/*
 * close_window:
 *  returns window resources
 */
void close_window() {
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

/*
 * wait_until_keypress:
 *  waits until a key is pressed.
 */
void wait_until_keypress() {
    XEvent event;
    while(1) {
        XNextEvent(display, &event);
        if (event.type == KeyPress) break;
    } } 
/*
 * set_color:
 *  sets the drawing color to the color specified in packed RGB
 */
void set_color(int color) {
    XSetForeground(display, gc, color);
}

/*
 * set_background:
 *  sets backgroundcolor in rgb
 */
void set_background(int color) {
    XSetBackground(display, gc, color);
}

// Try and run the given file as a visual simulation
void run_sim(Agent **agent_list, long num_steps, long num_agents){
	
	wait_until_keypress();
		
	int x_coord, y_coord, type;
	
	int i, j;
	for(i=0; i<num_steps; i++){
		for(j=0; j<num_agents; j++){
			x_coord = agent_list[i][j].position.x;	
			y_coord = agent_list[i][j].position.y;
			type = agent_list[i][j].type;	
			
			
			
			if(type == 0){
				set_color(41550);
			}
			else{
				set_color(WHITE);
			}
			
			plot_point(x_coord, y_coord);
		
		}
		update_window();
		//wait_until_keypress();
		usleep(50000);
	}
	
	
}
	
	
// add a point to a given file with an x y and type and the file to write to
void add_point_to_file(int x, int y, int type, char* file){
	

	FILE* the_file = fopen(file, "a");

	fprintf(the_file, "%d %d %d\n", x, y, type);
	
	fclose(the_file);
		
		
}

// add the given terminator to the given file
void add_terminator_to_file(int term, char* file){
	FILE* the_file = fopen(file, "a");

	fprintf(the_file, "%d\n", term);
	
	fclose(the_file);
		
		
	}
		



void test() {
    int i, j;


    for (i = 0; i < window_height; i++) {
        set_color(255<<16 | 128 << 8 | i);
        for (j = 0; j < window_width; j++) {
            plot_point(j, i);
        }
    }

    update_window();

    wait_until_keypress();

    for (i = 0; i < window_height; i++) {
        set_color(255<<16 | 255 << 8 | i);
        for (j = 0; j < window_width; j++) {
            plot_point(j, i);
        }
    }

    update_window();

    wait_until_keypress();
}

