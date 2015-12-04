#include <boost/regex.hpp>
#include <string>
int main()
{
    string text = "alpha beta";
  string::const_iterator begin = text.begin();
  string::const_iterator end = text.end();
  boost::match_results<string::const_iterator> what;
  while (regex_search(begin, end, what, boost::regex("([a-z]+)"))) {
      cout << string(what[1].first, what[2].second-1);
      begin = what[0].second;
  }
return 0;
}
