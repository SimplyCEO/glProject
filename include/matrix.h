#ifndef MATRIX_HEADER_FILE
#define MATRIX_HEADER_FILE

struct Matrix2
{
  float x;
  float y;
};

struct Matrix3
{
  float x;
  float y;
  float z;
};

struct Rotation2
{
  float deg;
  struct Matrix2 face;
};

struct Rotation3
{
  float deg;
  struct Matrix3 face;
};

struct Acceleration2
{
  float fw;
  float bw;
  float up;
  float dn;
};

struct Acceleration3
{
  float fw;
  float bw;
  float lt;
  float rt;
};

struct Vector2
{
  struct Matrix2 pos;
  struct Rotation2 rot;
};

struct Vector3
{
  struct Matrix3 pos;
  struct Rotation3 rot;
};

#endif

