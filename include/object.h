#ifndef OBJECT_HEADER_FILE
#define OBJECT_HEADER_FILE

#include "config.h"
#include "matrix.h"

enum ObjectType
{
  /* BUFFER = 0 */
  TRIANGLE  = 1,
  CUBE      = 2,
  CIRCLE    = 3
};

/* 2D */

/* Nodes/Vertices */

struct Node2i
{
  struct Matrix2i pos[3];
};

struct Node2u
{
  struct Matrix2u pos[3];
};

struct Node2f
{
  struct Matrix2f pos[3];
};

struct Node2d
{
  struct Matrix2d pos[3];
};

/* Texture */

struct Texture2i
{
  char name[256];
  struct Matrix2i size;
};

struct Texture2u
{
  char name[256];
  struct Matrix2u size;
};

struct Texture2f
{
  char name[256];
  struct Matrix2f size;
};

struct Texture2d
{
  char name[256];
  struct Matrix2d size;
};

/* Mesh */

struct Mesh2i
{
  struct Node2i node[MAX_NODE2_SIZE];
};

struct Mesh2u
{
  struct Node2u node[MAX_NODE2_SIZE];
};

struct Mesh2f
{
  struct Node2f node[MAX_NODE2_SIZE];
};

struct Mesh2d
{
  struct Node2d node[MAX_NODE2_SIZE];
};

/* Object */

struct Object2i
{
  enum ObjectType type;
  u32 id;
  struct Mesh2i mesh;
  struct Vector2i vec;
  i32 size;
  i8 colour[3];
  u8 alpha;
  struct Texture2i texture;
};

struct Object2u
{
  enum ObjectType type;
  u32 id;
  struct Mesh2u mesh;
  struct Vector2u vec;
  u32 size;
  u8 colour[3];
  u8 alpha;
  struct Texture2u texture;
};

struct Object2f
{
  enum ObjectType type;
  u32 id;
  struct Mesh2f mesh;
  struct Vector2f vec;
  float size;
  float colour[3];
  float alpha;
  struct Texture2f texture;
};

struct Object2d
{
  enum ObjectType type;
  u32 id;
  struct Mesh2d mesh;
  struct Vector2d vec;
  double size;
  double colour[3];
  double alpha;
  struct Texture2d texture;
};

/* 3D */

/* Nodes/Vertices */

struct Node3i
{
  struct Matrix3i pos[3];
};

struct Node3u
{
  struct Matrix3u pos[3];
};

struct Node3f
{
  struct Matrix3f pos[3];
};

struct Node3d
{
  struct Matrix3d pos[3];
};

/* Texture */

struct Texture3i
{
  char name[256];
  struct Matrix3i size;
};

struct Texture3u
{
  char name[256];
  struct Matrix3u size;
};

struct Texture3f
{
  char name[256];
  struct Matrix3f size;
};

struct Texture3d
{
  char name[256];
  struct Matrix3d size;
};

/* Mesh */

struct Mesh3i
{
  struct Node3i node[MAX_NODE3_SIZE];
};

struct Mesh3u
{
  struct Node3u node[MAX_NODE3_SIZE];
};

struct Mesh3f
{
  struct Node3f node[MAX_NODE3_SIZE];
};

struct Mesh3d
{
  struct Node3d node[MAX_NODE3_SIZE];
};

/* Object */

struct Object3i
{
  enum ObjectType type;
  u32 id;
  struct Mesh3i mesh;
  struct Vector3i vec;
  i32 size;
  i8 colour[3];
  i8 alpha;
  struct Texture3i texture;
};

struct Object3u
{
  enum ObjectType type;
  u32 id;
  struct Mesh3u mesh;
  struct Vector3u vec;
  u32 size;
  u8 colour[3];
  u8 alpha;
  struct Texture3u texture;
};

struct Object3f
{
  enum ObjectType type;
  u32 id;
  struct Mesh3f mesh;
  struct Vector3f vec;
  float size;
  float colour[3];
  float alpha;
  struct Texture3f texture;
};

struct Object3d
{
  enum ObjectType type;
  u32 id;
  struct Mesh3d mesh;
  struct Vector3d vec;
  double size;
  double colour[3];
  double alpha;
  struct Texture3d texture;
};

void registerObjects(enum ObjectType type);
int returnObject(enum ObjectType type, u32 id);
u8 addObjectData(struct Object3f object);
struct Object3f getObjectData(enum ObjectType type, u32 id);
void setObjectData(struct Object3f object);

#endif

