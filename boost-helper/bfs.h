#pragma once

#include <boost/filesystem.hpp>

template <typename stringType>
inline size_t num_of_same_chars_at_start(const stringType& s1, const stringType& s2)
{
  if (s1.length() > s2.length()) return num_of_same_chars_at_start(s2, s1);
  if (s1.empty()) return 0;
  typename stringType::size_type i = 0;
  for (; i < s1.length(); ++i)
    if (s1[i] != s2[i]) break;
  return i;
}

/**
* Makes sure \a path uses preferred slash and it ends with slash
*/
inline void make_preferred_dir_format(boost::filesystem::path& path)
{
  path.make_preferred();
  if (path.native().back() != path.preferred_separator)
    path = path.native() + path.preferred_separator;
}
