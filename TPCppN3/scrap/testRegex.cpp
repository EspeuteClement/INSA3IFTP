#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main () {    
  std::string url = "http://mydomain.com/randompage.php";
  boost::regex exp("^https?://([^/]*?)/");
  boost::smatch match;
  if (boost::regex_search(url, match, exp))
  {
    std::cout << std::string(match[1].first, match[1].second);
  }    
}