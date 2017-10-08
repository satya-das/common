#pragma once

#include <boost/filesystem.hpp>

template <typename stringType>
inline size_t num_of_same_chars_at_start(const stringType& s1, const stringType& s2)
{
  if (s1.length() > s2.length()) return num_of_same_chars_at_start(s2, s1);
  if (s1.empty()) return 0;
  stringType::size_type i = 0;
  for (; i < s1.length(); ++i)
    if (s1[i] != s2[i]) break;
  return i;
}
/**
* Assumes both paths uses preferred slashes.
* \warning If the relative path cannot be computed then it returns empty path.
*/
inline boost::filesystem::path relative_path(const boost::filesystem::path& from, const boost::filesystem::path& to)
{
  if (from.is_relative() && !to.is_relative()) return relative_path(boost::filesystem::absolute(from), to);
  if (to.is_relative() && !from.is_relative()) return relative_path(from, boost::filesystem::absolute(to));
  if (boost::filesystem::is_regular_file(from)) return relative_path(from.parent_path(), to);
  typedef boost::filesystem::path::string_type bfs_string;
  bfs_string::size_type n = num_of_same_chars_at_start(from.native(), to.native());
  if (n == 0) return boost::filesystem::path();
  bfs_string f = from.native().substr(n);
  bfs_string::size_type nUp = std::count(f.begin(), f.end(), from.preferred_separator);
  boost::filesystem::path relPath;
  for (bfs_string::size_type i = 0; i < nUp; ++i)
  {
    relPath /= "..";
  }
  relPath /= to.native().substr(n);
  return relPath;
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
