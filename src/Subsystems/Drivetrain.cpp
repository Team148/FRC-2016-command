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

	m_LeftMotor1->ConfigNominalOutputVoltage(0.0,0.0);
	m_LeftMotor1->ConfigPeakOutputVoltage(+12.0,-12.0);
	m_LeftMotor1->SetFeedbackDevice(CANTalon::QuadEncoder);
	m_LeftMotor1->ConfigEncoderCodesPerRev(256);
	m_RightMotor1->ConfigNominalOutputVoltage(0.0,0.0);
	m_RightMotor1->ConfigPeakOutputVoltage(+12.0,-12.0);
	m_RightMotor1->SetFeedbackDevice(CANTalon::QuadEncoder);
	m_RightMotor1->ConfigEncoderCodesPerRev(256);

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
	pdp = new PowerDistributionPanel();

	m_posX = 0;
	m_posY = 0;
	m_prevDistance = 0;
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

void Drivetrain::SetVelocityMode(){
	m_LeftMotor1->SetControlMode(CANSpeedController::kSpeed);
	m_LeftMotor1->Set(0);
	m_LeftMotor1->SetF(0.496);// Feed forward in Native Units
//	m_LeftMotor1->SetP(0.1); //Made up
//	m_LeftMotor1->SetI(0.0);
//	m_LeftMotor1->SetD(1.0);
	m_LeftMotor2->SetControlMode(CANSpeedController::kFollower);
	m_LeftMotor2->Set(DRIVE_LEFT_1);
	m_RightMotor1->SetControlMode(CANSpeedController::kSpeed);
	m_RightMotor1->Set(0);
	m_RightMotor1->SetF(0.496);	// Feed forward in Native Units
//	m_RightMotor1->SetP(0.1); //Made up
//	m_RightMotor1->SetI(0.0);
//	m_RightMotor1->SetD(1.0);
	m_RightMotor2->SetControlMode(CANSpeedController::kFollower);
	m_RightMotor2->Set(DRIVE_RIGHT_1);
}

void Drivetrain::SetVBusMode(){
	m_LeftMotor1->SetControlMode(CANSpeedController::kPercentVbus);
	m_LeftMotor1->Set(0);
	m_LeftMotor2->SetControlMode(CANSpeedController::kPercentVbus);
	m_LeftMotor2->Set(0);
	m_RightMotor1->SetControlMode(CANSpeedController::kPercentVbus);
	m_RightMotor1->Set(0);
	m_RightMotor2->SetControlMode(CANSpeedController::kPercentVbus);
	m_RightMotor2->Set(0);
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
/** Set in Inches Per Second **/
void Drivetrain::SetLeftSpeed(double speed){
	double m_RPM = 60.0*speed / WheelCircumference;
	m_LeftMotor1->Set(m_RPM);
}
/** Set in Inches Per Second **/
void Drivetrain::SetRightSpeed(double speed){
	double m_RPM = 60.0*speed / WheelCircumference;
	m_RightMotor1->Set(m_RPM);
}

Encoder* Drivetrain::GetLEncoder() {
	return m_lEncoder;
}


Encoder* Drivetrain::GetREncoder() {
	return m_rEncoder;
}
// this is inverted because the 'front' is inverted, needs cleanup
double Drivetrain::GetLDistance() {
//	return m_lEncoder->GetDistance();
	return m_RightMotor1->GetPosition();	//returns rotations
}

double Drivetrain::GetRDistance() {
	//return m_lEncoder->GetDistance();
	return m_LeftMotor1->GetPosition();		//returns rotations
}

double Drivetrain::GetAvgDistance(){
	return ((this->GetLDistance() + this->GetRDistance()) / 2.0);
}

double Drivetrain::GetAvgDistanceInInches(){
	return this->GetAvgDistance() * WheelCircumference;
}

double Drivetrain::GetLEncSpeed(){
	return m_RightMotor1->GetSpeed() * WheelCircumference / 60.0;
}

double Drivetrain::GetREncSpeed(){
	return m_LeftMotor1->GetSpeed() * WheelCircumference / 60.0;
}

double Drivetrain::GetAvgEncSpeed(){
	return ((GetLEncSpeed() + GetREncSpeed())/2.0);
}

Gyro* Drivetrain::GetGyro() {
	return m_gyro;
}

float Drivetrain::GetGyroAngle() {
	return m_gyro->GetAngle();
}
//Position Tracking
double Drivetrain::GetPositionX(){
	return m_posX;
}
double Drivetrain::GetPositionY(){
	return m_posY;
}

void Drivetrain::SetPositionX(double posX){
	m_posX = posX;
}

void Drivetrain::SetPositionY(double posY){
	m_posY = posY;
}

void Drivetrain::SetDeltaX(double deltaX){
	m_posX = m_posX + deltaX;
}

void Drivetrain::SetDeltaY(double deltaY){
	m_posY = m_posY + deltaY;
}

void Drivetrain::UpdatePosition(){
	if (m_prevDistance == 0)
		m_prevDistance = this->GetAvgDistance();

	m_deltaDistance = this->GetAvgDistance() - m_prevDistance;	//Checks for change since last cycle

	//converts Gyro to Rads takes sin or cos value and multiplies it by distance scalar
	this->SetDeltaX(m_deltaDistance*sin((this->GetGyroAngle())*PI/180.0));
	this->SetDeltaY(m_deltaDistance*cos((this->GetGyroAngle())*PI/180.0));

	std::cout<<"current x:"<<this->GetPositionX()<<" y:"<<this->GetPositionY()<<std::endl;

	m_prevDistance = this->GetAvgDistance(); //Sets current distance moved to previous for next cycle
}

//void Drivetrain::Arcade(Joystick joy) {
//	m_drive->ArcadeDrive(joy, false);
//}
