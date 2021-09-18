SRCS:=${wildcard src/*.cpp}

OPTS:= -Iinclude -pthread -lpthread -L../lib -li2c -std=c++11

.PHONY: drone arm calibration low_speed high_speed pressure accel servo

all: drone

rampup: ${SRCS} tools/rampup.cpp
	mkdir -p bin
	g++ tools/rampup.cpp ${SRCS} -o bin/rampup ${OPTS}

high_speed: ${SRCS} tools/high_speed.cpp
	mkdir -p bin
	g++ tools/high_speed.cpp ${SRCS} -o bin/high_speed ${OPTS}

low_speed: ${SRCS} tools/low_speed_test.cpp
	mkdir -p bin
	g++ tools/low_speed_test.cpp ${SRCS} -o bin/low_speed ${OPTS}

arm: ${SRCS} tools/arm.cpp
	mkdir -p bin
	g++ tools/arm.cpp ${SRCS} -o bin/arm ${OPTS}

calibration: ${SRCS} tools/calibrate.cpp
	mkdir -p bin
	g++ tools/calibrate.cpp ${SRCS} -o bin/calibrate ${OPTS}

pulse: ${SRCS} tools/pulse.cpp
	mkdir -p bin
	g++ tools/pulse.cpp ${SRCS} -o bin/pulse ${OPTS}

pressure: ${SRCS} tools/pressure.cpp
	mkdir -p bin
	g++ tools/pressure.cpp ${SRCS} -o bin/pressure ${OPTS}

accel: ${SRCS} tools/accl_test.cpp
	mkdir -p bin
	g++ tools/accl_test.cpp ${SRCS} -o bin/accel ${OPTS}

setmotors: ${SRCS} tools/set_motors.cpp
	mkdir -p bin
	g++ tools/set_motors.cpp ${SRCS} -o bin/setmotors ${OPTS}

servo: ${SRCS} tools/servo.cpp
	mkdir -p bin
	g++ tools/servo.cpp ${SRCS} -o bin/servo ${OPTS}

logger: ${SRCS} tools/logger.cpp
	mkdir -p bin
	g++ tools/logger.cpp ${SRCS} -o bin/logger ${OPTS}

drone_spd_ctl: ${SRCS} tools/drone_spd_ctl.cpp
	mkdir -p bin
	g++ tools/drone_spd_ctl.cpp ${SRCS} -o bin/spd ${OPTS}

gamepad:  ${SRCS} tools/gamepad_test.cpp
	mkdir -p bin
	g++ tools/gamepad_test.cpp ${SRCS} -o bin/game ${OPTS}

drone: 
	mkdir -p bin
	g++ main/main.cpp ${SRCS} -o bin/drone ${OPTS}