#include "main.h"

pros::Controller master(CONTROLLER_MASTER);

void initialize() {
	arms::init();
}

void disabled() {
}

void competition_initialize() {
}

void autonomous() {
	using namespace arms::chassis;
	printf("Running autonomous\n");
	move({{24, 0}}, 50, arms::THRU);
	move({{0, 0}}, 50, arms::THRU | arms::BACKWARDS);
	
	printf("Finished autonomous\n");
}

void opcontrol() {

	while (true) {
		if (master.get_digital(DIGITAL_LEFT) && !competition::is_connected())
			autonomous();

		arms::chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                      master.get_analog(ANALOG_RIGHT_X) * (double)100 /
		                          127);

		pros::delay(10);
	}
}
