#include <stdio.h>

#define    IN   1
#define    OUT  0

main()
{
  int nc, c, state;
  nc = 0;
  state = OUT;  
  while((c = getchar()) != EOF) {
    ++nc;
    if( c == '\n' || c == ' ' || c == '\t')
      state = OUT;
    else if(state == OUT) {
      state = IN;      
      if(nc > 1)
        putchar('\n');
    }
    putchar(c);
  }
}