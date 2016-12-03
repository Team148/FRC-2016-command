#include "Drivetrain.h"

Drivetrain *Drivetrain::m_instance = 0;  						//Global static pointer
extern Logger *logger;

using namespace std;

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	cout << "info: Drivetrain constructor" << endl;

	//CANTalons
	m_LeftMotor1 = new CANTalon(DRIVE_LEFT_1);
	m_LeftMotor2 = new CANTalon(DRIVE_LEFT_2);
	m_RightMotor1 = new CANTalon(DRIVE_RIGHT_1);
	m_RightMotor2 = new CANTalon(DRIVE_RIGHT_2);

	SetBrakeMode(0);

	m_drive = new RobotDrive(m_LeftMotor1, m_LeftMotor2, m_RightMotor1, m_RightMotor2);

	//Shifter
	m_shifter = new Solenoid(0,0);

	//Encoders
	m_rEncoder = new Encoder(DRIVETRAIN_ENCODER_RIGHT_A,DRIVETRAIN_ENCODER_RIGHT_B,true, CounterBase::k4X);
	m_lEncoder = new Encoder(DRIVETRAIN_ENCODER_LEFT_A,DRIVETRAIN_ENCODER_LEFT_B,true, CounterBase::k4X);

	//gyro
	m_gyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);

	//PDP
	m_pdp = new PowerDistributionPanel();

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


//select drivetrain gear.  lowgear=true highgear=false
void Drivetrain::SetGear(bool gear) {
	m_gear = gear;
	m_shifter->Set(m_gear);
}

//TODO: TEST SwitchGear
void Drivetrain::SwitchGear() {
	m_gear = ~m_gear;
	m_shifter->Set(m_gear);

}
// lowgear=true highgear=false
bool Drivetrain::GetGear() {
	return m_gear;
}

//TODO: Test SetBrakeMode
void Drivetrain::SetBrakeMode(bool on) {
	if(on) {
		m_LeftMotor1->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
		m_LeftMotor2->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
		m_RightMotor1->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
		m_RightMotor2->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	}
	else {
		m_LeftMotor1->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		m_LeftMotor2->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		m_RightMotor1->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		m_RightMotor2->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	}
}

//TODO: Test SetLeftDrive
void Drivetrain::SetLeftDrive(float power) {
	if(power>1.0)
		power=1.0;

	m_LeftMotor1->Set(power);
	m_LeftMotor2->Set(power);
}

//TODO: TestRightDrive
void Drivetrain::SetRightDrive(float power) {
	if(power>1.0)
		power=1.0;

	m_RightMotor1->Set(power);
	m_RightMotor2->Set(power);
}

Encoder* Drivetrain::GetLEncoder() {
	return m_lEncoder;
}


Encoder* Drivetrain::GetREncoder() {
	return m_rEncoder;
}

float Drivetrain::GetGyroAngle() {
	return m_gyro->GetAngle();
}

void Drivetrain::Log() {
	LogPDP();
}


void Drivetrain::LogPDP() {
	string name;
	for(int i=0;i<=15;i++) {
		name = "Channel " + i + string(" Current");
		logger->AddtoBuffer(name, m_pdp->GetCurrent(i));
	}

}
