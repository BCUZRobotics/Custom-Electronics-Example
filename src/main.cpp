#include "main.h"

//Custom Electonics Ports
int ce_write = 13;
int ce_read = 14;

//Comm variables
pros::Serial *ce_port_w = nullptr;
pros::Serial *ce_port_r = nullptr;

void init_comm(){
  //Setup the ports
  ce_port_w = new pros::Serial(ce_write);
  ce_port_r = new pros::Serial(ce_read);
}

//flush the comm ports
void flush(){
  ce_port_w->flush();
  pros::delay(100);
  ce_port_r->flush();
}

//set the port baud rate
void setBaud(){
  ce_port_w->set_baudrate(115200);
  ce_port_r->set_baudrate(115200);
}

//read byte from port and print to cout
void recv_print(){
  //Read byte command
  int32_t r = ce_port_r->read_byte();
  //Check if error
  if(r == PROS_ERR){
    std::cout << pros::millis() << " Error read " << r << std::endl;
  } else {
    //Print recieved byte
    std::cout << pros::millis() << " Pass read " << r << std::endl;
  }
}

void send_print(char value){
	//Send the value byte
  int32_t w = ce_port_w->write_byte(value);
	std::cout << "Sent Value " << value << std::endl;
  pros::delay(3);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//Set up the communication. Takes about 1/8th of a second
	init_comm();
	pros::delay(10);
	flush();
	pros::delay(10);
	setBaud();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//Send and recieve alphabet as a test
	for(int i = 65; i <= 90; i++){
		send_print(i);
		recv_print();
		pros::delay(97);
	}
	while (true) {
		pros::delay(20);
	}
}
