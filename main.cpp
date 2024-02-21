#include <iostream>
#include <cstring>

bool all_hex(char*);

int main(int argc, char* argv[]) {
  int valid_colors = 0;

  for(int i=1; i < argc; i++) {
    int length = std::strlen(argv[i]);
    if( (length == 3 || length == 6) && all_hex(argv[i]) ) {
      std::cout << "#" << argv[i] << std::endl;
    }  
  }
  return 0;
}

bool all_hex(char* word) {
  for(int i=0; i<strlen(word); i++) {
    if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'f')
      || (word[i] >= 'A' && word[i] <='F')) {
      continue;
    }
    else {
      return false;
    }
  }

  //no non-hex characters found
  return true;
}