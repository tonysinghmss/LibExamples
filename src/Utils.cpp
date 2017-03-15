#include <string>
#include <vector>
#include <cctype>// isalnum
#include <algorithm>
#include "Utils.h"
  bool not_url_char(char c){
    // characters that appear in a url in addition to alphanumeric
    static const std::string url_ch = "~;/?:@=&$-_.+!*'()";
    // check whether c can appear in a URL and return the negative
    return !(isalnum(c) ||
	   find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
  }

std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e){
    return find_if(b,e,not_url_char);
  }

  std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e){
    static const std::string sep = "://";
    typedef std::string::const_iterator iter;
    // i marks where the separator was found
    iter i=b;
    while((i = search(i,e,sep.begin(),sep.end()))!=e){
      if(i != b && i+sep.size() != e){
	//beg marks beginning of protocol-name
	iter beg = i;
	while(beg != b && isalpha(beg[-1]))//beg[-1] is equivalent of *(beg -1)
	  --beg;

	// Is there at least one appropriate character before and after the separator?
	// In real world, here will check if protocol name belongs to any of the fixed set of protocol-names.
	
	if(beg != i && !not_url_char(i[sep.size()]))//i[sep.size()] is equivalent of *(i+sep.size())
	   return beg;
      }

      // the separator we found wasnt part of a URL advance i past this separator
      i += sep.size();
   }
   return e;
  }

  std::vector<std::string> find_urls(const std::string& s){
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    // look through the entire input
    while(b!=e){
      //look for one or more letters followed by ://
      b = url_beg(b,e);
      //if we found it
      if(b != e){
	// get the rest of the URL
	iter after = url_end(b,e);
	ret.push_back(std::string(b,after));
	// advance b and check for more URLs on this line
	b = after;
      }
    }
    return ret;
  }

 std::vector<std::string> split(const std::string& s){
    std::vector<std:string> ret;
    typedef std::string::size_type string_size;
    string_size i = 0;
    
    while(i != s.size()){
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while(i != s.size() && isspace(s[i]))
            ++i;
        
        // find end of next word
        string_size j = i;
        // invariant: none of  the characters in range [original j, current j) is a space
        while(j != s.size() && !isspace(s[j]))
            ++j;
        // if we found some nonwhitespace characters
        if( i != j){
            // copy from s starting  at i and taking j - i chars
            ret.push_back(s.substr(i,j-i));
            i = j;
        }
    }
    return ret;
}
