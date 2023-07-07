#include <math.h>

int findRangei(int target, int final)
{
  int range = (target*100)*final;
  return range;
}

float findRangef(float target, float final)
{
  float range = (target*100.0f)*final;
  return range;
}

