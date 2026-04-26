#ifndef I_NODE_HPP_
#define I_NODE_HPP_

namespace graphics
{
class INode
{
 public:
  virtual ~INode() = default;
  virtual void Generate() = 0;
};
}  // namespace graphics

#endif
