#ifndef _WINDOW_H_
#define _WINDOW_H_

#define WHITE (255<<16 | 255<<8 | 255)
#define BLACK 0

/* creates a window with given dimensions */
void create_window(int, int, char*);
/* flushes the window */
void update_window(void);
/* sets the drawing color to the given color */
void set_color(int);
/* plots a point at the given coordinate */
void plot_point(int, int);
/* busy waits until a key is pressed */
void wait_until_keypress(void);
/* frees a windows resources */
void close_window(void);
void add_point_to_file(int x, int y, int type, char* file);
void add_terminator_to_file(int term, char* file);
void run_file(const char* file);

void test(void);

#endif

