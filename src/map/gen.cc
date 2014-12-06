#include <ctime>
#include <cstdlib>
#include <tuple>

#include "gen.hh"

Gen::Gen(int width, int height)
    : width_(width), height_(height)
{
    tab_ = std::make_shared<std::vector<std::vector<unsigned>>>();
    tab_->resize(width);
    for (int x = 0; x < width; x++)
        (*tab_)[x].resize(height);
}

void Gen::init_()
{
    for (int x = 0; x < width_; x++)
        for (int y = 0; y < height_; y++)
        {
            (*tab_)[x][y] = std::rand() % 255;
        }
}

void Gen::split_()
{
    auto new_tab = std::make_shared<std::vector<std::vector<unsigned>>>();
    new_tab->resize(2 * width_);
    for (int x = 0; x < 2 * width_; x++)
        (*new_tab)[x].resize(2 * height_);
    for (int x = 0; x < width_; x++)
        for (int y = 0; y < height_; y++)
        {
            (*new_tab)[2 * x][2 * y] = (*tab_)[x][y];
            (*new_tab)[2 * x + 1][2 * y] = (*tab_)[x][y];
            (*new_tab)[2 * x][2 * y + 1] = (*tab_)[x][y];
            (*new_tab)[2 * x + 1][2 * y + 1] = (*tab_)[x][y];
        }
    width_ *= 2;
    height_ *= 2;
    tab_ = new_tab;
}

void Gen::merge_()
{
    auto new_tab = std::make_shared<std::vector<std::vector<unsigned>>>();
    new_tab->resize(width_);
    for (int x = 0; x < width_; x++)
        (*new_tab)[x].resize(height_);
    for (int x = 0; x < width_; x++)
        for (int y = 0; y < height_; y++)
        {
            std::vector<int> l;
            int div = 1;
            unsigned value = (*tab_)[x][y];
            l.push_back((*tab_)[x][y]);
            if (check_(x + 1, y))
            {
                div++;
                value += (*tab_)[x + 1][y];
                l.push_back((*tab_)[x + 1][y]);
            }
            if (check_(x - 1, y))
            {
                div++;
                value += (*tab_)[x - 1][y];
                l.push_back((*tab_)[x - 1][y]);
            }
            if (check_(x, y + 1))
            {
                div++;
                value += (*tab_)[x][y + 1];
                l.push_back((*tab_)[x][y + 1]);
            }
            if (check_(x, y - 1))
            {
                div++;
                value += (*tab_)[x][y - 1];
                l.push_back((*tab_)[x][y - 1]);
            }
            (*new_tab)[x][y] = (value / div + l[std::rand() % l.size()]) / 2;
        }
    tab_ = new_tab;
}


std::shared_ptr<std::vector<std::vector<unsigned>>> Gen::Generate(int witdh,
                                                                  int height,
                                                                  int iter)
{
    Gen g(witdh, height);
    g.init_();
    for (int i = 0; i < iter; i++)
    {
        g.split_();
        g.merge_();
    }
    return g.tab_;
}
