class MpiGuard
{
 public:
  MpiGuard(int& argc, char**& argv)
  {
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_);
  }
  ~MpiGuard()
  {
    MPI_Finalize();
  }

  int32_t GetSize() const
  {
    return size_;
  }

 private:
  int32_t size_{};
};

class MpiNode
{
 public:
  MpiNode(int32_t message_tag)
      : name_(MPI_MAX_PROCESSOR_NAME, '\0'), message_tag_{message_tag}
  {
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_);

    int32_t length{};
    MPI_Get_processor_name(name_.data(), &length);
    name_.shrink_to_fit();
  }

  int32_t const& GetRank() const
  {
    return rank_;
  }
  int32_t GetTag() const
  {
    return message_tag_;
  }

 private:
  std::string name_{};
  MPI_Status status_{};
  int32_t rank_{};
  int32_t message_tag_{};
};
