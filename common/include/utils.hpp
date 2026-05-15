#include <limits>
#include <random>

namespace common
{
template <typename T>
T GetRandomValue(T min = std::numeric_limits<T>::lowest(),
                 T max = std::numeric_limits<T>::max())
{
  std::random_device rd;
  std::uniform_int_distribution<int> dist(min, max);
  return dist(rd);
}

}  // namespace common
