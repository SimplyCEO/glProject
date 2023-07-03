#ifndef MATRIX_HEADER_FILE
#define MATRIX_HEADER_FILE

/* struct Matrix2 matrixPos2 = { 0.0f, 0.0f }; */
struct Matrix2
{
  float x;
  float y;
};

/* struct Matrix3 matrixPos3 = { 0.0f, 0.0f, 0.0f }; */
struct Matrix3
{
  float x;
  float y;
  float z;
};

/* struct Rotation2 matrixRot2 = { 0.0f, matrixPos2 }; */
struct Rotation2
{
  float deg;
  struct Matrix2 face;
};

/* struct Rotation3 matrixRot3 = { 0.0f, matrixPos3 }; */
struct Rotation3
{
  float deg;
  struct Matrix3 face;
};

/* struct Vector2 matrixVec2 = { matrixPos2, matrixRot2 }; */
struct Vector2
{
  struct Matrix2 pos;
  struct Rotation2 rot;
};

/* struct Vector3 matrixVec3 = { matrixPos3, matrixRot3 }; */
struct Vector3
{
  struct Matrix3 pos;
  struct Rotation3 rot;
};

#endif

