// === Debug macro starts here ===

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x)                                                                                                                                        \
  {                                                                                                                                                   \
    ++recur_depth;                                                                                                                                    \
    auto x_ = x;                                                                                                                                      \
    --recur_depth;                                                                                                                                    \
    std::cerr << std::string(recur_depth, '\t') << "\033[91m" << __func__ << ":" << __LINE__ << "\t" << #x << " = " << x_ << "\033[39m" << std::endl; \
  }
#else
#define dbg(x)
#endif
template <typename Ostream, typename Cont>
typename std::enable_if<std::is_same<Ostream, std::ostream>::value, Ostream&>::type operator<<(Ostream& os, const Cont& v) {
  os << "[";
  for (auto& x : v) {
    os << x << ", ";
  }
  return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const std::pair<Ts...>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}

// === Debug macro ends here ===

