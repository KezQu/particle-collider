#ifndef I_NODE_HPP_
#define I_NODE_HPP_

#include <string_view>

namespace graphics
{
class INode
{
 public:
  explicit INode(std::string_view name) noexcept : name_{name} {}

  virtual ~INode() = default;
  virtual void Generate() = 0;

 protected:
  std::string_view name_;
};
}  // namespace graphics

#endif
