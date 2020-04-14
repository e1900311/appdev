// usually in a header file we have 2 parts:
// 1. function declaration
// 2. constant defintions

// constant definitions
#define ESC 0x1B    // or 27
// make enumeration for fg colors
enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10) // this is called macro definition

#define UNICODE
#define BAR "\u2590"

#define DEBUG

// the following is the information of cursor position
// decoded by escape sequnce ESC[6n, and quesy should be a string
// consisting row an col numbers of the cursor
typedef struct {
    int row;
    int col;
} Position;

// making a constant in a name will make your program more meaningful/readable
// now we can use color names in functon setfgcolor()

// function declarations
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void clearscreen(void);
void gotoXY(int, int);
void drawbar(int, int);
Position getscreensize(void);

