#include "Drivetrain.h"

Drivetrain *Drivetrain::m_instance = 0;  						//Global static pointer

using namespace std;

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	cout << "info: Drivetrain constructor" << endl;

	//CANTalons
	m_LeftMotor1 = new CANTalon(DRIVE_LEFT_1);
	m_LeftMotor2 = new CANTalon(DRIVE_LEFT_2);
	m_RightMotor1 = new CANTalon(DRIVE_RIGHT_1);
	m_RightMotor2 = new CANTalon(DRIVE_RIGHT_2);

	//TODO: Set CANTalon Ramp Rate to 6.0V per second
	//m_LeftMotor1->SetVoltageRampRate(6.0);
	//m_LeftMotor2->SetVoltageRampRate(6.0);
	//m_RightMotor1->SetVoltageRampRate(6.0);
	//m_RightMotor2->SetVoltageRampRate(6.0);

	m_drive = new RobotDrive(m_LeftMotor1, m_RightMotor1, m_LeftMotor2, m_RightMotor2);

	//Pneumatics
	m_comp = new Compressor(0); //TODO: add Constant
	m_compSpike = new Relay(COMPRESSOR_RELAY);
	m_comp->SetClosedLoopControl(true);

	//Encoders
	m_rEncoder = new Encoder(DRIVETRAIN_ENCODER_RIGHT_A,DRIVETRAIN_ENCODER_RIGHT_B,true, CounterBase::k4X);
	m_lEncoder = new Encoder(DRIVETRAIN_ENCODER_LEFT_A,DRIVETRAIN_ENCODER_LEFT_B,true, CounterBase::k4X);

	//gyro
	m_gyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);

	//PDP
	pdp = new PowerDistributionPanel();
}


Drivetrain* Drivetrain::GetInstance() {
	if (m_instance ==  0) {
		cout << "info: GetInstance Creating Drivetrain Class" << endl;
		m_instance = new Drivetrain();
	}
	return m_instance;
}


void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());

}


void Drivetrain::Arcade(float ystick, float xstick) {
	m_drive->ArcadeDrive(ystick,xstick);
}


//void Drivetrain::Arcade(Joystick joy) {
//	m_drive->ArcadeDrive(joy, false);
//}
