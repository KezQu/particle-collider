#ifndef ENGINE_FACTORY_NODE_IMPL_HPP_
#define ENGINE_FACTORY_NODE_IMPL_HPP_

#include <string>

#include "i_node.hpp"

namespace collider
{

class EngineFactoryNodeImpl : public graphics::INode
{
 public:
  void Generate() override;

 private:
  size_t selected_backend_{};
  std::string_view name_{"##SelectBackend"};
};

}  // namespace collider

#endif
