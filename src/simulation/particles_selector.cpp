#include "particles_selector.hpp"

#include "imgui.h"

namespace collider
{
ParticlesSelector::ParticlesSelector() noexcept
    : INode("##SelectNumOfParticles")
{
}

void ParticlesSelector::Generate()
{
  ImGui::SeparatorText("Number of particles");
  ImGui::SliderInt("##ParticlesNum", &number_of_particles_, 2, 100);
}

int32_t ParticlesSelector::GetNumberOfParticles() const
{
  return number_of_particles_;
}

}  // namespace collider
