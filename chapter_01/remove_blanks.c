#include <stdio.h>

main() 
{
  int c, lc;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      if (lc != ' ') {
        putchar(' ');
      }      
    } else {
      putchar(c);
    }
    lc = c;
  }
}