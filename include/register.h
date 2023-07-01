#ifndef REGISTER_HEADER_FILE
#define REGISTER_HEADER_FILE

enum ObjectType
{
  CUBE  = 1
};

struct Vector2
{
  float x;
  float y;
};

struct Vector3
{
  float x;
  float y;
  float z;
};

struct Object
{
  enum ObjectType type;
  u8 id;
  struct Vector3 pos;
  float size;
  float colour[3];
  float alpha;
  char texture[128];
};

void registerObjects(void);
int returnObject(u8 id);
u8 addObjectData(struct Object object[]);
struct Object getObjectData(u8 type, u8 id);

#endif

