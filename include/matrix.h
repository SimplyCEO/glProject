#ifndef MATRIX_HEADER_FILE
#define MATRIX_HEADER_FILE

#include "types.h"

/* 2D */

/* Matrix */

struct Matrix2i
{
  i32 x;
  i32 y;
};

struct Matrix2u
{
  u32 x;
  u32 y;
};

struct Matrix2f
{
  float x;
  float y;
};

struct Matrix2d
{
  double x;
  double y;
};

/* Rotation */

struct Rotation2i
{
  float deg;
  struct Matrix2i face;
};

struct Rotation2u
{
  float deg;
  struct Matrix2u face;
};

struct Rotation2f
{
  float deg;
  struct Matrix2f face;
};

struct Rotation2d
{
  float deg;
  struct Matrix2d face;
};

/* Acceleration */

struct Acceleration2i
{
  i32 fw;
  i32 bw;
  i32 up;
  i32 dn;
};

struct Acceleration2u
{
  u32 fw;
  u32 bw;
  u32 up;
  u32 dn;
};

struct Acceleration2f
{
  float fw;
  float bw;
  float up;
  float dn;
};

struct Acceleration2d
{
  double fw;
  double bw;
  double up;
  double dn;
};

/* Vector */

struct Vector2i
{
  struct Matrix2i pos;
  struct Acceleration2i vel;
  struct Rotation2i rot;
};

struct Vector2u
{
  struct Matrix2u pos;
  struct Acceleration2u vel;
  struct Rotation2u rot;
};

struct Vector2f
{
  struct Matrix2f pos;
  struct Acceleration2f vel;
  struct Rotation2f rot;
};

struct Vector2d
{
  struct Matrix2d pos;
  struct Acceleration2d vel;
  struct Rotation2d rot;
};

/* 3D */

/* Matrix */

struct Matrix3i
{
  i32 x;
  i32 y;
  i32 z;
};

struct Matrix3u
{
  u32 x;
  u32 y;
  u32 z;
};

struct Matrix3f
{
  float x;
  float y;
  float z;
};

struct Matrix3d
{
  double x;
  double y;
  double z;
};

/* Rotation */

struct Rotation3i
{
  i32 deg;
  struct Matrix3i face;
};

struct Rotation3u
{
  u32 deg;
  struct Matrix3u face;
};

struct Rotation3f
{
  float deg;
  struct Matrix3f face;
};

struct Rotation3d
{
  double deg;
  struct Matrix3d face;
};

/* Acceleration */

struct Acceleration3i
{
  i32 fw;
  i32 bw;
  i32 lt;
  i32 rt;
};

struct Acceleration3u
{
  u32 fw;
  u32 bw;
  u32 lt;
  u32 rt;
};

struct Acceleration3f
{
  float fw;
  float bw;
  float lt;
  float rt;
};

struct Acceleration3d
{
  double fw;
  double bw;
  double lt;
  double rt;
};

/* Vector */

struct Vector3i
{
  struct Matrix3i pos;
  struct Acceleration3i vel;
  struct Rotation3i rot;
};

struct Vector3u
{
  struct Matrix3u pos;
  struct Acceleration3u vel;
  struct Rotation3u rot;
};

struct Vector3f
{
  struct Matrix3f pos;
  struct Acceleration3f vel;
  struct Rotation3f rot;
};

struct Vector3d
{
  struct Matrix3d pos;
  struct Acceleration3d vel;
  struct Rotation3d rot;
};

#endif

