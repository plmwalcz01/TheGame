#pragma once
#include <functional>
#include <unordered_map>
#include <map>
#include <memory>
#include "location.hpp"
#include "hero.hpp"


template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
  template<typename S, typename T> struct hash<pair<S, T>>
  {
    inline size_t operator()(const pair<S, T> & v) const
    {
      size_t seed = 0;
      ::hash_combine(seed, v.first);
      ::hash_combine(seed, v.second);
      return seed;
    }
  };
}

class Game
{
private:

public:
    Hero hero;
    std::map<std::pair<int, int>, std::shared_ptr<Location> > map;
    std::map< std::pair<int, int>, std::shared_ptr<Location> >::iterator map_ith;
    int item_transfer(Hero*, Item *);
    int fight();
    int insert_location(std::pair<int, int>, std::shared_ptr<Location>);
    int insert_location(std::shared_ptr<Location>);
    int initialize_hero(Hero*);

    std::shared_ptr<Location> generate_location(std::pair<int, int>);
    std::shared_ptr<Location> generate_location();
};
