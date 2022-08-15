#include <timer.h>
#include <logger.h>
#include <unistd.h>
#include <chrono>

int i = 0;
static auto dt;

auto then = std::chrono::steady_clock::now();
auto start = then;
auto now = std::chrono::steady_clock::now();

void test() {
    double dt = std::chrono::duration_cast<std::chrono::nanoseconds> (now - then).count() * 0.000000001;
    int t_since = std::chrono::duration_cast<std::chrono::nanoseconds> (now - start).count();
    logger::info("i: {:10d} {:10f} ", i, dt);
    i++;
}

int main() {
    timer t(test, 1000);
    while(true) {
        usleep(10000);
    }
}