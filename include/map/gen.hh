#ifndef GEN_HH
# define GEN_HH

# include <vector>
# include <memory>

# include "map.hh"

class Gen
{
  public:
    static std::shared_ptr<std::vector<std::vector<unsigned>>> Generate(
        int witdh,
        int height,
        int iter);
  private:
    Gen(int witdh, int height);
    std::shared_ptr<std::vector<std::vector<unsigned>>> tab_;
    void init_();
    void load_map_();
    void split_();
    void merge_();
    inline bool check_(int x, int y) const
    {
      return x >= 0 && y >= 0 && x < width_ && y < height_;
    }

    int width_;
    int height_;

};

#endif /* GEN_HH */
