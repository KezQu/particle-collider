#ifndef BACKEND_SELECTOR_HPP_
#define BACKEND_SELECTOR_HPP_

#include "i_node.hpp"
#include "logger.hpp"

namespace collider
{

class BackendSelector : public graphics::INode
{
 public:
  BackendSelector() noexcept;

  void Generate() override;

  int8_t GetSelectedBackend() const;

 private:
  common::Logger logger_{};

  int8_t selected_backend_{};
};
}  // namespace collider

#endif
