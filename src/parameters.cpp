#include <parameters.h>
#include <vector>
#include <logger.h>
#include <unordered_map>

static std::vector<const char *> readonly_names;
static std::vector<void *> readonly_bindings;

static std::vector<const char *> writable_names;
static std::vector<void *> writable_bindings;

// 0 - bool
// 1 - int
// 2 - dbl
// 3 - str
static std::vector<char> readonly_types;
static std::vector<char> writable_types;

// static std::unordered_map<const char *, 

static std::string

void parameters::bind_bool(const char * name, bool * value, bool readonly){
    if(readonly) {
        readonly_names.push_back(name);
        readonly_bindings.push_back((void*) value);
        readonly_types.push_back(0);
    }else {
        writable_names.push_back(name);
        writable_bindings.push_back((void*) value);
        writable_types.push_back(0);
    }
}


void parameters::bind_int(const char * name, int * value, bool readonly){
    if(readonly) {
        readonly_names.push_back(name);
        readonly_bindings.push_back((void*) value);
        readonly_types.push_back(1);
    }else {
        writable_names.push_back(name);
        writable_bindings.push_back((void*) value);
        writable_types.push_back(1);
    }
}


void parameters::bind_dbl(const char * name, double * value, bool readonly){
    if(readonly) {
        readonly_names.push_back(name);
        readonly_bindings.push_back((void*) value);
        readonly_types.push_back(2);
    }else {
        writable_names.push_back(name);
        writable_bindings.push_back((void*) value);
        writable_types.push_back(2);
    }
}


void parameters::bind_str(const char * name, std::string * value, bool readonly){
    if(readonly) {
        readonly_names.push_back(name);
        readonly_bindings.push_back((void*) value);
        readonly_types.push_back(3);
    }else {
        writable_names.push_back(name);
        writable_bindings.push_back((void*) value);
        writable_types.push_back(3);
    }
}

void parameters::post_bind_setup() {
    std::string out = "{";
    int k = writable_.size();
    for(int i = 0; i < k; i ++){
        std::string name(names[i]);
        out+="\""+name+"\":"+i;
        if(i != k-1) {
            out += ",";
        }
    }
    return out+"}";
}

static std::string json_helper(std::vector<const char *> & names, std::vector<void *> & bindings, std::vector<char> & types){
    std::string out = "{";
    int k = names.size();
    for(int i = 0; i < k; i ++){
        std::string name(names[i]);
        out+="\""+name+"\":";
        switch(types[i]){
            case 0:
                out += std::to_string(*((bool *) (bindings[i])));
                break;
            case 1:
                out += std::to_string(*((int *) (bindings[i])));
                break;
            case 2:
                out += std::to_string(*((double *) (bindings[i])));
                break;
            case 3:
                out += '"'+*((std::string *) bindings[i])+'"';
                break;
            default:
                out += "null";
                break;
        }
        if(i != k-1) {
            out += ",";
        }
    }
    return out+"}";
}

std::string parameters::get_json_report(){
    return "{writable:"+json_helper(writable_names, writable_bindings, writable_types)+",readable:{"+json_helper(readonly_names, readonly_bindings, readonly_types)+",writable_i:"++"}";
}

// for string delimiter
static std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


void parameters::chg(const char * str) {
    std::string bruh(str);
    std::vector<std::string> splitted = split(bruh, " ");
    int type = std::atoi(splitted[0]); // 0 - normal, 1 - axis input
    int id = std::atoi(splitted[1]);
    // int value;

    if(type == 0) {
        switch(readonly_types[id]){
        case 0:
            (*((bool *) writable_bindings[id])) = splitted[2] == '1';
            break;
        case 1:
            (*((int *) writable_bindings[id]))  = std::atoi(splitted[2]);
            break;
        case 2:
            (*((double *) writable_bindings[id]))  = std::atof(splitted[2]);
            break;
        case 3:
            break;
        default:
            break;
        }
    }else if(type == 1){
        
    }


}