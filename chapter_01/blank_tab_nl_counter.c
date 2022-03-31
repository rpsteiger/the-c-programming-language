#include <stdio.h>

main() 
{
  long special_chars_counter = 0;
  int c;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t') {
      ++special_chars_counter;
    }
  }
  printf("%ld\n", special_chars_counter);
}