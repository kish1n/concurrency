export module concurrency:spsc_queue;

import std;

export namespace concurrency {

template <typename T> class spsc_queue {
public:
  explicit spsc_queue(std::size_t capacity) { m_buffer.reserve(capacity); }
  ~spsc_queue() = default;

  spsc_queue(const spsc_queue &) = delete;
  spsc_queue &operator=(const spsc_queue &) = delete;
  spsc_queue(spsc_queue &&) = delete;
  spsc_queue &operator=(spsc_queue &&) = delete;

  bool push(const T &value) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (full()) {
      return false;
    }
    m_buffer.push(value);
    return true;
  }
  bool push(T &&value);

  bool pop(T &value);

  [[nodiscard]] bool empty() const;
  [[nodiscard]] bool full() const { return false; }
  [[nodiscard]] std::size_t size() const;
  [[nodiscard]] std::size_t capacity() const;

private:
  std::queue<T> m_buffer;
  std::mutex m_mutex;
};

} // namespace concurrency
