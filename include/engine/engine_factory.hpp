#ifndef ENGINE_FACTORY_HPP_
#define ENGINE_FACTORY_HPP_

#include <memory>
#include <string_view>
#include <vector>

#include "backend_selector.hpp"
#include "block_num_selector.hpp"
#include "i_node.hpp"
#include "logger.hpp"

namespace collider
{

class EngineFactory
{
 public:
  using UINodes = std::vector<std::reference_wrapper<graphics::INode>>;

  EngineFactory() noexcept;

  UINodes GetUserInterfaceNodes();

 private:
  common::Logger logger_{};

  BackendSelector backend_selector_{};
  BlockNumSelector block_num_selector_{};
};

}  // namespace collider

#endif
