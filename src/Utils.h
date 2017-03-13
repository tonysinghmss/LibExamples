#ifndef GAURD_Utils
#define GAURD_Utils
#include <string>
#include <vector>
bool not_url_char(char);
std::string::const_iterator url_end(std::string::const_iterator, std::const_iterator);
std::string::const_iterator url_beg(std::string::const_iterator, std::const_iterator);
vector<string> find_urls(const std::string&);
#endif
