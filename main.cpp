#include <iostream>
#include <cstring>

using namespace std;

bool all_hex(char*);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "ERR_MISSING: One or more RGB values should be provided as arguments, separated by spaces" << endl;
        return 1;
    }

    for(int i = 1; i < argc; i++) {
        int length = strlen(argv[i]);
        bool isHex = all_hex(argv[i]);

        if ((length == 3 || length == 6) && isHex) {
            cout << "#" << argv[i] << endl;
        } else {
            if (length != 3 && length != 6) {
                cout << argv[i] << " ERR_LENGTH: RGB values must be either 3 or 6 characters long" << endl;
            }
            if (!isHex) {
                cout << argv[i] << " ERR_VALUE: RGB values must be in 0-F range" << endl;
            }
        }
    }
    return 0;
}

bool all_hex(char* word) {
    for(int i = 0; i < strlen(word); i++) {
        if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'f') || (word[i] >= 'A' && word[i] <= 'F')) {
            continue;
        } else {
            return false;
        }
    }
    // No non-hex characters found
    return true;
}
