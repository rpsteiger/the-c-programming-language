#include <stdio.h>

#define    LOWER  0
#define    UPPER  300
#define    STEP  20

float convert_to_celsius(float f);

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 3000 */
main()
{
  int fahr;
  printf("fahr | C\n");
  printf("----------\n");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    printf("%3d %6.1f\n", fahr, convert_to_celsius(fahr));
}

float convert_to_celsius(float f) {
  return (5.0/9.0) * (f-32.0);
}