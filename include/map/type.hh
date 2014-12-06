#ifndef TYPE_HH
# define TYPE_HH

enum class Type
{
  BEACH = 0x10,
  PLAIN = 0x11,
  FOREST = 0x20,
  PROFONDFOREST = 0x21,
  MOUNTAIN = 0x40,
  HIGHMOUNTAIN = 0x41,
  PROFONDSEA = 0x80,
  SEA = 0x81,
  NONE = 0xF0,
  FINAL = 0xF1,
  PORTAL = 0xF2,
  ROAD = 0xF3,
  TOWER = 0xF4,
};

inline int operator&(Type t1, Type t2)
{
      return static_cast<int>(t1) & static_cast<int>(t2);
}

#endif /* !TYPE_HH */
