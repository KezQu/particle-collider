#include <memory>

#include "base_process.hpp"
#include "context.hpp"
#include "mediator_process.hpp"
#include "mpi_guard.hpp"
#include "worker_process.hpp"

graphics::Context context{};

int main(int32_t argc, char** argv)
{
  mpi::MpiGuard const mpi_guard{argc, argv};

  std::unique_ptr<mpi::BaseProcess> worker{
      std::make_unique<mpi::BaseProcess>()};

  if (worker->GetRank() == mpi::BaseProcess::kMediatorProcess)
  {
    worker = std::make_unique<mpi::MediatorProcess>();
  }
  else
  {
    worker = std::make_unique<mpi::WorkerProcess>();
  }
  worker->ProcessTask();
}
