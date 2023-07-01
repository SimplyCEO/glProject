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
struct Object getObjectData(u8 type, u8 id);

#endif

