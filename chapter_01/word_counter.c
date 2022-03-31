#include <stdio.h>

#define    IN   1
#define    OUT  0

main()
{
  int nl, nw, nc, c, state;
  nl = nw = nc = 0;
  state = OUT;  
  while((c = getchar()) != EOF) {
    ++nc;
    if(c == '\n')
      ++nl;
    if( c == '\n' || c == ' ' || c == '\t')
      state = OUT;
    else if(state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("line count: %d, word count: %d, char count: %d\n", nl, nw, nc);
}