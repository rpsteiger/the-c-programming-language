#include <stdio.h>

#define    MAXWORDLEN  10
#define    IN_WORD      1
#define    NOT_IN_WORD  2

int terminates_word(int c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == EOF);
}


int main(void)
{
  int c;
  int state = 0;
  long word_lengths[MAXWORDLEN+1];
  int word_length = 0;

  for(int i=0; i<MAXWORDLEN; ++i)
    word_lengths[i] = 0;

  state = NOT_IN_WORD;
  while((c = getchar()) != EOF) {
    if(terminates_word(c)) {
      if(state == IN_WORD) {
        if(word_length >= MAXWORDLEN) {
          ++word_lengths[MAXWORDLEN];
        } else {
          if (word_length >= 0) {
            word_lengths[word_length-1];
          }
        }
      }
    } else {
      if(state == NOT_IN_WORD) {
        word_length = 0;
        state = IN_WORD;
      }
      ++word_length;
    }
  }
}