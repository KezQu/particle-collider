#include "engine_factory.hpp"

namespace collider
{

EngineFactory::EngineFactory() noexcept {}

EngineFactory::UINodes EngineFactory::GetUserInterfaceNodes()
{
  return {std::ref(backend_selector_), std::ref(block_num_selector_)};
}

}  // namespace collider
