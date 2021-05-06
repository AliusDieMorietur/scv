#include "headers/utils.h"

namespace utils {
  vector<string> split_string(string s) {
    vector<string> v;
    string tmp = "";
    for(int i = 0;i < s.length(); i++) {
      if(s[i] == '\n') {
        v.push_back(tmp);
        tmp = "";
      } else {
        tmp.push_back(s[i]);
      }
    }
    v.push_back(tmp);
    return v;
  }
}