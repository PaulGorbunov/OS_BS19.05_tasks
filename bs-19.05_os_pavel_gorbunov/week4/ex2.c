#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int number = 5;
    for (int u = 0; u < number; u++) {
        fork();
        system("sleep 5");
    }
    return 0;
}



/*  pstree: 
 * 
 * As "sleep 5" is used, some processes are asleep during pstree command executed, 
 * so the trees below are not showing the final forking state.
 * 
 * int number = 5;
 * 
 * gnome-terminal-─┬─bash───a.out─┬─a.out─┬─a.out───sh───sleep
 *                 │              │       └─sh───sleep
 *                 │              ├─a.out───sh───sleep
 *                 │              └─sh───sleep
 *                 ├─bash───pstree
 * 
 *
 * int number = 3;
 * 
 * gnome-terminal-─┬─bash───a.out─┬─a.out───sh───sleep
 *                 │              └─sh───sleep
 *                 ├─bash───pstree
 *
 *
 *As the int number is growing, the bash process tree is getting bigger.
 * 
*/
