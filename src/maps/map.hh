#ifndef MAP_HH
# define MAP_HH

# include <vector>
# include "type.hh"

class Map
{
    public:
        Map(int width, int height);
    private:
        std::vector<std::vector<Type>> map_;
};

#endif /* MAP_HH */
