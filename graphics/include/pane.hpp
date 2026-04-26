#ifndef PANE_HPP_
#define PANE_HPP_

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "i_node.hpp"
#include "i_pane.hpp"
#include "imgui.h"
#include "logger.hpp"

namespace graphics
{

class Pane : public IPane
{
 public:
  Pane(std::string_view name,
       ImGuiWindowFlags settings = ImGuiWindowFlags_None);

  void AddNode(std::reference_wrapper<INode> node) override;
  void Generate() override;

 private:
  common::Logger logger_{};
  std::vector<std::reference_wrapper<INode>> children_{};
  std::string_view name_;
  ImGuiWindowFlags settings_;
};

}  // namespace graphics

#endif
