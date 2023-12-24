#include <string>

template <typename Out = std::vector<std::string>>
Out split(const std::string_view s, const char delim, const size_t maxFields = 0)
{
  Out elems;
  size_t start{};
  size_t end{};
  size_t numFieldsParsed{};

  do
  {
    end = s.find_first_of(delim, start);
    elems.emplace_back(s.substr(start, end - start));
    start = end + 1;
  } while (end != std::string::npos && (maxFields == 0 || ++numFieldsParsed < maxFields));
  return elems;
};
