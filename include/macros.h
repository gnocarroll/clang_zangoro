#ifndef MACROS_H
#define MACROS_H

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

// will not work if number of args is zero, but as of right now that is not
// used in this codebase

#define NARGS(...) (sizeof((int[]){__VA_ARGS__}) / sizeof(int))

#endif // MACROS_H
