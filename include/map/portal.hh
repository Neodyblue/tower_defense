#ifndef PORTAL_HH
# define PORTAL_HH

# include <vector>

# include "type.hh"
# include "point.hh"

struct Portal
{
  Type type;
  std::vector<Point> path;
};

#endif /* !PORTAL_HH */
