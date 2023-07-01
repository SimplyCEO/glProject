#ifndef REGISTER_HEADER_FILE
#define REGISTER_HEADER_FILE

enum ObjectType
{
  CUBE  = 1
};

struct Object
{
  enum ObjectType type;
  u8 id;
  float size;
  float colour[3];
  char texture[128];
};

void registerObjects(void);
int returnObject(u8 id);
u8 addObjectData(struct Object object[]);
struct Object getObjectData(u8 type, u8 id);

#endif

