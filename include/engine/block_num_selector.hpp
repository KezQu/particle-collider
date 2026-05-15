#ifndef BLOCK_NUM_SELECTOR_HPP_
#define BLOCK_NUM_SELECTOR_HPP_

#include "i_node.hpp"
#include "logger.hpp"

namespace collider
{
class BlockNumSelector : public graphics::INode
{
 public:
  BlockNumSelector() noexcept;

  void Generate() override;

 private:
  int32_t number_of_blocks_{};
};
}  // namespace collider

#endif
