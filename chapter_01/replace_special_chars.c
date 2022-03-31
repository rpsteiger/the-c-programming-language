#include <stdio.h>

main() 
{
  int c;
  while((c = getchar()) != EOF) {
    if(c == '\t' || c == '\n' || c == '\b') {
      putchar('\\');
      if (c == '\t') {
        putchar('t');        
      } else if(c == '\b') {
        putchar('b');
      } else if(c == '\n') {
        putchar('n');
      }
    } else {
      putchar(c);
    }  
  }
}