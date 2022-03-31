#include <stdio.h>

float convert_to_fahrenheit(float c);

/* print Celsius-Fahrenheit table for celsius = 0, 20, ..., 3000 */
main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("cels.| F.\n");
  printf("----------\n");
  while (celsius <= upper) {
    fahr = convert_to_fahrenheit(celsius);
    printf("%6.0f %3.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

float convert_to_fahrenheit(float c) {
  return c * (9.0/5.0) + 32.0;
}