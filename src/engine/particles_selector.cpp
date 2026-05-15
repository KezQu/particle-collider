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
  ImGui::SliderInt("##ParticlesNum", &number_of_particles, 2, 100);
}
}  // namespace collider
