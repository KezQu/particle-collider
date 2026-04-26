#ifndef I_PANE_HPP_
#define I_PANE_HPP_

#include <functional>
#include <memory>

#include "i_node.hpp"

namespace graphics
{
class IPane
{
 public:
  virtual ~IPane() = default;

  virtual void AddNode(std::reference_wrapper<INode> node) = 0;
  virtual void Generate() = 0;
};
}  // namespace graphics

#endif
