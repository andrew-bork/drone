#include <config.h>
#include <logger.h>

int main(){
    config::load_file("config/test.json");
    config::get_config_int("a.b.c.d", 1);
    config::write_to_file("config/test.json");
}