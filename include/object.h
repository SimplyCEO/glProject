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

/* struct Vertex2 vertex2.pos = { {0.0f, 0.0f}^3 }; */
struct Vertex2
{
  struct Matrix2 pos[3];
};

/* struct Vertex3 vertex3.pos = { {0.0f, 0.0f, 0.0f}^3 }; */
struct Vertex3
{
  struct Matrix3 pos[3];
};

/* struct Mesh2 mesh2.vertex.pos = {{0.0f, 0.0f}^3}^8; */
struct Mesh2
{
  struct Vertex2 vertex[MAX_VERTEX2_SIZE];
};

/* struct Mesh3 mesh3.vertex.pos = {{0.0f, 0.0f, 0.0f}^3}^512; */
struct Mesh3
{
  struct Vertex3 vertex[MAX_VERTEX3_SIZE];
};

struct Object2
{
  u8 type;
  u16 id;
  struct Mesh2 mesh;
  struct Vector2 vec;
  float size;
  float alpha;
  char texture[128];
};

struct Object3
{
  u8 type;
  u16 id;
  struct Mesh3 mesh;
  struct Vector3 vec;
  float size;
  float colour[3];
  float alpha;
  char texture[128];
};

void registerObjects(u8 type);
int returnObject(u8 type, u8 id);
u8 addObjectData(struct Object3 object);
struct Object3 getObjectData(u8 type, u8 id);

#endif

