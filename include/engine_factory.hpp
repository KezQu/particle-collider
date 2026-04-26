#ifndef ENGINE_FACTORY_HPP_
#define ENGINE_FACTORY_HPP_

#include <memory>
#include <string>
#include <vector>

#include "i_node.hpp"
#include "logger.hpp"

namespace collider
{

class EngineFactory : public graphics::INode
{
 public:
  EngineFactory();
  void Generate() override;

 private:
  common::Logger logger_{};
  std::unique_ptr<graphics::INode> node_impl_{};
};

}  // namespace collider

#endif
