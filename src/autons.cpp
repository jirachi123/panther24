#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 120;
const int DRIVE_SPEED_SLOW = 40; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;

const int SWING_SPEED = 90;


///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 15, 0, 25, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.25, 0.05, 2, 15); // D=0
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 10, 5, 15);
  chassis.set_pid_constants(&chassis.turnPID, 6, 0.003, 30, 15);
  chassis.set_pid_constants(&chassis.swingPID, 6, 0.003, 22.5, 15);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0, 20, 0);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
} 
void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void match_load() {
  pros::Motor catapult(1);
  pros::Motor vision(7);
  pros::Motor intake(19); 

  intake.set_brake_mode(MOTOR_BRAKE_HOLD);
  pros::ADIDigitalOut piston ('B');
  pros::ADIDigitalOut wing1 ('E');
  pros::ADIDigitalOut wing2 ('F');

  
  //catapult=-110;

  chassis.set_drive_pid(-16, DRIVE_SPEED, true);
  chassis.wait_until(-10);
  // chassis.set_swing_pid(ez::LEFT_SWING, 45, TURN_SPEED);
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_until(45);
  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_until(-18);
  chassis.set_drive_pid(17, DRIVE_SPEED, true);
  chassis.wait_until(12);
  chassis.wait_drive();
  chassis.set_turn_pid(120, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(1, 50, false);
  chassis.wait_drive();

  catapult=-110;
}

void comp_auton() {
  pros::Motor catapult(1);
  pros::Motor vision(7);
  pros::Motor intake(19); 
  pros::Controller master (CONTROLLER_MASTER);
  

  pros::Optical optical_sensor(17);
  pros::c::optical_rgb_s_t rgb_value;

  intake.set_brake_mode(MOTOR_BRAKE_HOLD);
  pros::ADIDigitalOut piston ('B');
  pros::ADIDigitalOut wing1 ('E');
  pros::ADIDigitalOut wing2 ('F');

  chassis.set_drive_pid(54, DRIVE_SPEED, true);
  
  chassis.wait_drive();

  master.set_text(0, 0, "2");

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  intake=-127;


  chassis.set_drive_pid(8, DRIVE_SPEED, true);
  chassis.wait_drive();
  intake=0;

  chassis.set_drive_pid(-6, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();



  intake = 127;
  chassis.set_drive_pid(12, DRIVE_SPEED_SLOW, true);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  intake=-127;

  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();
  intake=0;

  chassis.set_drive_pid(-6, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  intake = 127;
  chassis.set_drive_pid(32, DRIVE_SPEED_SLOW, true);
  chassis.wait_drive();
  intake=0;
  chassis.reset_gyro();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  
  chassis.set_drive_pid(24, DRIVE_SPEED_SLOW, true);
  chassis.wait_drive();
  intake = -127;
  chassis.set_drive_pid(12, DRIVE_SPEED_SLOW, true);
  chassis.wait_drive();
  intake = 0;
  chassis.set_drive_pid(-30, DRIVE_SPEED_SLOW, true);
  chassis.wait_drive();
  



}


void skills_auton() {
  pros::Motor catapult(1);
  pros::Motor vision(7);
  pros::Motor intake(19); 
  intake.set_brake_mode(MOTOR_BRAKE_HOLD);
  pros::ADIDigitalOut piston ('B');
  pros::ADIDigitalOut wing1 ('E');
  pros::ADIDigitalOut wing2 ('F');

  
  //catapult=-110;

  chassis.set_drive_pid(-16, DRIVE_SPEED, true);
  chassis.wait_until(-10);
  // chassis.set_swing_pid(ez::LEFT_SWING, 45, TURN_SPEED);
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_until(45);
  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_until(-18);
  chassis.set_drive_pid(17, DRIVE_SPEED, true);
  chassis.wait_until(12);
  chassis.wait_drive();
  chassis.set_turn_pid(120, TURN_SPEED);
   chassis.wait_drive();
  chassis.set_drive_pid(1, 50, true);
  chassis.wait_drive();
  //catapult = -127; 
  pros::delay(1000);
  chassis.reset_gyro();
  chassis.set_swing_pid(ez::RIGHT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();
  chassis.reset_gyro();
  chassis.set_swing_pid(ez::LEFT_SWING, -35, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.reset_gyro();
  chassis.set_swing_pid(ez::LEFT_SWING, -30, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-62, DRIVE_SPEED, true); // Big movement
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_swing_pid(ez::LEFT_SWING, -65, TURN_SPEED);
  chassis.wait_drive();


  chassis.set_drive_pid(-30, DRIVE_SPEED, false);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_swing_pid(ez::LEFT_SWING, -15, SWING_SPEED);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_swing_pid(ez::LEFT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(35, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_turn_pid(-55, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, SWING_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  

}


///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches
  pros::Imu imu_sensor(11);
  pros::Controller master (CONTROLLER_MASTER);
  string val = std::to_string(imu_sensor.get_heading());
  
  chassis.set_drive_pid(48, DRIVE_SPEED, true);
  chassis.wait_drive();

  string val2 = std::to_string(imu_sensor.get_heading());

  master.set_text(0, 0, val + " " + val2);
  // chassis.set_drive_pid(-12, DRIVE_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-12, DRIVE_SPEED);
  // chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at
  pros::Imu imu_sensor(11);
  pros::Controller master (CONTROLLER_MASTER);
  string val = std::to_string(imu_sensor.get_heading());
  
  //printf();
  //printf("IMU get heading: %f degrees\n", imu_sensor.get_heading());
  chassis.set_turn_pid(270, TURN_SPEED);
  chassis.wait_drive();
  string val2 = std::to_string(imu_sensor.get_heading());

  master.set_text(0, 0, val + " " + val2);


  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .