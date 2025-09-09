#include <iostream>
#include <string.h>
#include "../include/mylib/cryptography.h"
using namespace std;

int main() {
    const char* test_message = "password";
    unsigned char* digest = nullptr;
    unsigned int digest_len;
    
    cout << "Testing digest_message with: \"" << test_message << "\"" << endl;
    
    // Compute digest
    digest_message((const unsigned char*)test_message, strlen(test_message), &digest, &digest_len);
    
    if(digest != nullptr && digest_len == 32) {
        cout << "✓ Test passed - digest created successfully" << endl;
        OPENSSL_free(digest);
        return 0;
    } else {
        cout << "✗ Test failed - digest creation failed" << endl;
        return 1;
    }
}