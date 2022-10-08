#include <util.h>
// #ifndef UTIL_H
// #define UTIL_H

// #include <string_view>
// #include <vector>
// #include <string>
// namespace cstr {
//     ssize_t index_of(const char * in, const char * delim);
//     size_t substr(const char * in, size_t start, size_t end);
//     size_t shift(char * in, size_t amount, char * out);
// }

// namespace string {
//     void split(const std::string_view in, const char delim, std::vector<std::string> out);
// }

// #endif

bool has(const char * in, const char * delim) {
    for(size_t i = 0; delim[i] != '\0'; i ++) {
        if(in[i] == '\0') {
            return false;
        }
        if(in[i] != delim[i]) {
            return false;
        }
    }
    return true;
}

size_t cstr::index_of(const char * in, const char * delim) {
    for(size_t i = 0; in[i] != '\0'; i++) {
        if(has(in + i, delim)) {
            return i;
        }
    }
    return -1;
}

size_t cstr::substr(const char * in, size_t start, size_t end) {

}
void cstr::shift(char * in, size_t amount, char * out) {
    size_t i = 0;
    for(i = 0; i < amount; i ++) {
        out[i] = in[i];
    }
    out[amount] = '\0';
    for(i = 0; in[i + amount] != '\0'; i ++) {
        in[i] = in[i + amount];
    }
    in[i] = '\0';
}