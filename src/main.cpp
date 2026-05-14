#include <memory>

#include "context.hpp"
#include "mediator_process.hpp"
#include "mpi_guard.hpp"
#include "process.hpp"

graphics::Context context{};

int main(int32_t argc, char** argv)
{
  mpi::MpiGuard const mpi_guard{argc, argv};

  std::unique_ptr<mpi::Process> worker{std::make_unique<mpi::Process>()};

  if (worker->GetRank() == mpi::Process::kMediatorProcess)
  {
    worker = std::make_unique<mpi::MediatorProcess>();
  }
  worker->ProcessTasks();
}
