#include "WPILib.h"
#include <vector>
#include <cmath>
#include "USBCamera.h"


//justinchange
//morechanges
//~~~~~~~~~~~~~~~~~~~~~~~~~ AUTON SUB-ROUTINES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~1st get through the defense ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int Portculis(unsigned int &Drive, float &yStick, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp);
unsigned int Chevy(unsigned int &Drive, float &yStick, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP);
unsigned int RoughTerrian(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp);
unsigned int LowBar(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, bool &Action);
unsigned int RockWall(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp);
unsigned int Ramparts(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp);
unsigned int Moat(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp);

//~~~~~~~~~~~~~~~~~~~~~~~~~2nd get to the shooting position ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int PositionOne(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);
unsigned int PositionTwo(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);
unsigned int PositionThree(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);
unsigned int PositionFour(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);
unsigned int PositionFive(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);
unsigned int PositionSix(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp);
unsigned int PositionSeven(unsigned int &Drive, bool &OneTrack, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp, float &Destination, int &TrueCounter,bool &camSwitch, float &IntakeMotor, float &Beam);
unsigned int PositionSevenThree(unsigned int &Drive, bool &OneTrack, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp, float &Destination, int &TrueCounter,bool &camSwitch, float &IntakeMotor, float &Beam);
unsigned int PositionEight(unsigned int &Drive, bool &OneTrack, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp, float &Destination, int &TrueCounter,bool &camSwitch, float &IntakeMotor, float &Beam, bool &Action, bool &ActionSTP);

//~~~~~~~~~~~~~~~~~~~~~~~~~AIM and SHOOT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AutoAim(unsigned int &Drive, bool &OneTrack, float &Destination, int &TrueCounter,bool &camSwitch, float &xStick, float &gyro, bool &AirSwitch, bool &Clamp);

//~~~~~~~~~~~~~~~~~~~~~~~~~GO BACK SUB-ROUTINES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int GoBackPosOne(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);
unsigned int GoBackPosTwo(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);
unsigned int GoBackPosThree(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);
unsigned int GoBackPosFour(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);
unsigned int GoBackPosFive(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~SALLY + DRAWBRIDGE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int GoBackONEToTWO(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);

unsigned int GoBackTWOToTHREE(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);

unsigned int GoBackTHREEToTWO(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);
unsigned int GoBackTHREEToFOUR(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);

unsigned int GoBackFOURToTHREE(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);
unsigned int GoBackFOURToFIVE(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);

unsigned int GoBackFIVEToFOUR(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear);

//~~~~~~~~~~~~~~~~~~~~~~~~~misc~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int PosTwoLong(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);
unsigned int PosFiveLong(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot);

//#define AXISCAMERA
#define USBCAMERA
#define CAMERA
#define CALIBRATECAMERA
#define DOMORETHANCAMERA
#define SPIGYRO
#define SPIACCEL
#define NEWBRICK
#define CAM0

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

#ifdef AXISCAMERA
	IMAQdxSession session;
	Image *frame;
	Image *binaryFrame;
	int imaqError;
	//	IMAQdxError imaqError;
	std::unique_ptr<AxisCamera> camera;
#endif

#ifdef USBCAMERA
	IMAQdxSession session;
	Image *frame;
	Image *binaryFrame;
	int imaqError;
	USBCamera *cam0;
	CameraServer *server;
#endif

	//A structure to hold measurements of a particle
	struct ParticleReport {
		double PercentAreaToImageArea;
		double Area;
		double BoundingRectLeft;
		double BoundingRectTop;
		double BoundingRectRight;
		double BoundingRectBottom;
	};

	//Structure to represent the scores for the various tests used for target identification
	struct Scores {
		double Area;
		double Aspect;
	};

	//Constants // duo ring light
//	Range RING_HUE_RANGE = {85, 120};	//Default hue range for ring light
//	Range RING_SAT_RANGE = {67, 255};	//Default saturation range for ring light
//	Range RING_VAL_RANGE = {100, 255};	//Default value range for ring light

//	---UNO RING LIGHT
	Range RING_HUE_RANGE = {81, 146};	//Default hue range for ring light
	Range RING_SAT_RANGE = {29, 255};	//Default saturation range for ring light
	Range RING_VAL_RANGE = {60, 241};	//Default value range for ring light
	//Coverage Area = Bounding box area / strip area.  240/80  in^2.
	//Aspect Ratio = Particle Width / Particle Height - 12"W x 20"H => 1.6.
	//Moment = 0.28 from Moment of Inertia
	//Coordinates (0,0) is top left of screen.  (0,  0) -> (0  ,320)
	//..........................................(0,240) -> (320,240)
	//Aim(x,y) = (P(x,y) - (resolution(x,y)/2) / (resolution(x,y) / 2)
	//Distance
	double AREA_MINIMUM = 0.33; //Default Area minimum for particle as a percentage of total image area
	double AREA_RATIO = (240.0/75.0); //Area of bounding box / area of the tape.
	double RATIO = 0.5; //W/H => 12"/20" -> 0.6.
	double SCORE_MIN = 58.0;  //Minimum score to be considered a target/was 75 /was72 for comp
#ifdef AXISCAMERA
	double VIEW_ANGLE = 64; //View angle fo camera, set to Axis m1011 by default, 64 for m1013, 51.7 for 206, 52 for HD3000 square, 60 for HD3000 640x480
	//using 49 for view angle to correct distance calculation.
#endif
#ifdef USBCAMERA
	double VIEW_ANGLE = 52; //View angle fo camera, set to Axis m1011 by default, 64 for m1013, 51.7 for 206, 52 for HD3000 square, 60 for HD3000 640x480
	//using 49 for view angle to correct distance calculation.
#endif
	ParticleFilterCriteria2 criteria[1];
	ParticleFilterOptions2 filterOptions = {0,0,1,1};
	Scores scores;
	int numParticles = 0;
	float areaMin = 0;
	float bright = 15;
	bool isTarget = 0;
	bool seebinary = 0;
	double TargetAngle = 0.0;

#ifdef DOMORETHANCAMERA
	float gyro = 0.0;
	float Spyro = 0.0;
	float Spyro2 = 0.0;
	float Spyro3 = 0.0;

	bool button1; // Brick/Defense Buttons
	bool button2; // Brick/Defense Buttons
	bool button3; // Brick/Defense Buttons
	bool button4; // Brick/Teleop Button
	bool button5; // Brick/Teleop Button

	bool pos1; // Position Buttons
	bool pos2;
	bool pos3;
	bool pos4;
	bool pos5;
	bool pos6;
	bool pos7;
	bool pos8;

	bool def1; // defense buttons
	bool def2;
	bool def3;
	bool def4;
	bool def5;
	bool def6;
	bool def7;
	bool def8;

	bool aimIsReady;
	bool goBackAfter;
	bool teleOpAirSwitch;
	bool globNoName;

	int AADest;

	//	bool box1; // Button Box Buttons
	//	bool box2;
	//	bool box3;
	//	bool box4;
	//	bool box5;
	//	bool box6;

	/*	CANTalon *pTalon0;
	CANTalon *pTalon1;
	CANTalon *pTalon2;
	CANTalon *pTalon3;
	CANTalon *IntakeMotor7;
	CANTalon *ArmMotor0;
	CANTalon *HangerMotor6;
	CANTalon *SpareTalon1;
	 */
	CANTalon *ArmMotor0;
	//CANTalon *SpareTalon1;
	CANTalon *DriveTalon2;
	CANTalon *DriveTalon3;
	CANTalon *DriveTalon4;
	CANTalon *DriveTalon5;
	CANTalon *HangerMotor6;
	CANTalon *IntakeMotor7;

	Joystick *DrvStick;
	Joystick *OpStick;
	Joystick *Brick;  //side B inputs of brick - the side we have been using for switches
	Joystick *BrickA; //side A inputs of brick - this side currently has rotary selector switch
	//	Joystick *ButtonBox;

	RobotDrive *myRobot;

	Encoder *DriveEncoderR;
	Encoder *DriveEncoderL;
	Encoder *ArmEncoder;

	Compressor *c;

	DigitalOutput *pSonicOutput;

	DigitalInput *FrontFlashLight;
	DigitalInput *BackFlashLight;
	DigitalInput *RingLight;
	DigitalInput *ArmUpHE;
	DigitalInput *ArmDownHE;


	AnalogInput *BeamBreak;
	AnalogInput *Pressure;
	//	AnalogInput *pRightSonic;
	//	AnalogInput *pLeftSonic;


	Relay *CameraLedSpike;
	Relay *FrontFlashSpike;
	Relay *Compressor2;

	Solenoid *Shifter;
	DoubleSolenoid *DeployHanger;
	Solenoid *ShortShot;
	Solenoid *BallClamp;
	Solenoid *Sole0;
	Solenoid *ActionArm;
	Solenoid *ActionArmStop;
	Solenoid *Sole6;
	Solenoid *Sole7;
	Solenoid *Sole8;
	Solenoid *Sole9;

	Timer *timer1;


#ifdef SPIGYRO
	Gyro *pGyro;
	double angle = 0.0;
#endif

#ifdef SPIACCEL
	Accelerometer *pAccel;
	double accelerationX = 0.0;
	double accelerationY = 0.0;
	double accelerationZ = 0.0;
#endif
	PowerDistributionPanel *pdp;

	unsigned int Drive;
	unsigned int State;
	unsigned int SubRoute;
	unsigned int TBDrive;
	unsigned int TBFunc;
	unsigned int OTBDrive;
	unsigned int OTBFunc;

	bool deployOnce = 0;

	enum DriveX
	{
		DRIVESTRAIGHT = 1,
		NOSTRAIGHT,
		STRAIGHTENCODER,
		STRAIGHTAFTERAA
	};

	enum Statex
	{
		DRIVEFORWARD = 20,
		TURN,
		DRIVETOGOAL,
		AUTOAIM,
		SHOOT
	};

	enum SubRoutex
	{
		SUB1 = 40,
		SUB2,
		SUB3,
		GOBACK,
		GOBACKLEFT,
		GOBACKRIGHT,
	};

	enum TBFuncx
	{
		DROPNSNATCH = 60,
		TURNTOAUTOAIM,
		BALLGRABTWO,
		TURNTOAUTOAIMTWO,
		NOTHINGNESS
	};

	enum TBDrivex
	{
		TURNTOLOWBAR = 80,
		GOINGBACK,
		GOINGBACKWBALL,
		NOTHINGDRIVE

	};

	enum OTBDrivex
	{
		ROADTOAIM = 100,
		ROADTOBALL,
		LASTROAD,
		NOTHING
	};

	enum OTBFuncx
	{
		PREPARETOAIM = 120,
		OTBAUTOAIM,
		PREPARETOCROSS,
		GRABBALL,
		NOTHINGFUNC
	};



public:
	Robot()
{
		session = 0;
		frame = (NULL);
		binaryFrame = (NULL);
		imaqError = 0;
		chooser = (NULL);

		ArmMotor0 = new CANTalon(0);
		//SpareTalon1 = new CANTalon(1);
		DriveTalon2 = new CANTalon(2);
		DriveTalon3 = new CANTalon(3);
		DriveTalon4 = new CANTalon(4);
		DriveTalon5 = new CANTalon(5);
		HangerMotor6 = new CANTalon(6);
		IntakeMotor7 = new CANTalon(7);

		DrvStick = new Joystick(0);
		OpStick = new Joystick(1);
		Brick = new Joystick(2);
		BrickA = new Joystick(3);
		//	ButtonBox = new Joystick(5);

		myRobot = new RobotDrive(DriveTalon2, DriveTalon3, DriveTalon5, DriveTalon4); //FL,FR,RL,RR

		DriveEncoderR = new Encoder(1,2,true, CounterBase::k4X);
		DriveEncoderL = new Encoder(3,4,true, CounterBase::k4X);
		ArmEncoder = new Encoder(7,8,true, CounterBase::k1X);

		pSonicOutput = new DigitalOutput(0);
		ArmUpHE = new DigitalInput(5);
		ArmDownHE = new DigitalInput(6);


		Pressure = new AnalogInput(0);
		BeamBreak = new	AnalogInput(1);


		//PCM0
		c = new Compressor(0);

		Shifter = new Solenoid(0,0);
		DeployHanger = new DoubleSolenoid(0,1,5);
		ShortShot = new Solenoid(0,2);
		BallClamp = new Solenoid(0,3);
		ActionArm = new Solenoid(0,4);
		ActionArmStop = new Solenoid(0,6);
		//PCM1 Shooter
		Sole0 = new Solenoid(1,0);
		Sole6 = new Solenoid(1,1);
		Sole7 = new Solenoid(1,2);
		Sole8 = new Solenoid(1,3);

		timer1 = new Timer();


		CameraLedSpike = new Relay(2);
		FrontFlashSpike = new Relay(1);
		Compressor2 = new Relay(0);

		//CameraLedSpike = new Relay(5, Relay::kBothDirections);
		//FrontFlashSpike = new Relay(6, Relay::kBothDirections);
		//BackFlashSpike = new Relay(7, Relay::kBothDirections);


#ifdef SPIGYRO
		pGyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
		//pAccel = new ADXL362(SPI::Port::kOnboardCS1, Accelerometer::Range::kRange_2G);
#endif

		pdp = new PowerDistributionPanel();

		c->SetClosedLoopControl(true);
}
#endif //Do More Than Camera

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);

		// create an image
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		binaryFrame = imaqCreateImage(IMAQ_IMAGE_U8, 0);

		//Put default values to SmartDashboard so fields will appear
		SmartDashboard::PutNumber("Tote hue min", RING_HUE_RANGE.minValue);
		SmartDashboard::PutNumber("Tote hue max", RING_HUE_RANGE.maxValue);
		SmartDashboard::PutNumber("Tote sat min", RING_SAT_RANGE.minValue);
		SmartDashboard::PutNumber("Tote sat max", RING_SAT_RANGE.maxValue);
		SmartDashboard::PutNumber("Tote val min", RING_VAL_RANGE.minValue);
		SmartDashboard::PutNumber("Tote val max", RING_VAL_RANGE.maxValue);
		SmartDashboard::PutNumber("Area min %", AREA_MINIMUM);
		SmartDashboard::PutNumber("See Binary", seebinary);
		SmartDashboard::PutNumber("CamBrighness", bright);
		SmartDashboard::PutNumber("RightSonic", 0);
		SmartDashboard::PutNumber("LeftSonic", 0);
		SmartDashboard::PutNumber("XSTICK", 0);
		SmartDashboard::PutNumber("SonicTime", 0);

#ifdef SPIGYRO
		pGyro->Reset();
#endif

#ifdef AXISCAMERA		// open the camera at the IP address assigned. This is the IP address that the camera
		// can be accessed through the web interface.
		camera.reset(new AxisCamera("axis-camera.local"));
		Wait(4.0);
		camera->WriteResolution(AxisCamera::kResolution_320x240);
		//		camera->WriteExposureControl(AxisCamera::kExposureControl_Hold);
		camera->WriteCompression(30);
		camera->WriteBrightness(0.1);
		camera->WriteWhiteBalance(AxisCamera::kWhiteBalance_FixedFluorescent1);
		camera->WriteMaxFPS(10);
		camera->WriteExposureControl(AxisCamera::kExposureControl_Hold);

#endif
#ifdef USBCAMERA
#ifdef CAM0
		cam0 = new USBCamera("cam0",1);
#else
		cam0 = new USBCamera("cam1",1);
#endif
		//instance of camera server
		server = CameraServer::GetInstance();
		//sets camera server quality
		server->SetQuality(50);
		// create an image
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		binaryFrame = imaqCreateImage(IMAQ_IMAGE_U8, 0);
		// create an image
		// open the camera USB
		cam0->OpenCamera();
		Wait(4.0);
		cam0->SetFPS(10); // cam0.SetFPS //was 3
		cam0->SetBrightness(30);//20
		cam0->SetSize(320,240); // cam0.SetSize(320 , 240)
		//		cam0->SetExposureAuto();
		//		cam0->SetExposureHoldCurrent();
		cam0->SetExposureManual(0.000488281);//0.8 or 0.000488281
		//cam0->SetWhiteBalanceAuto();
		cam0->SetWhiteBalanceHoldCurrent();
		cam0->SetWhiteBalanceManual(3800);
		// open the camera
		//		IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
		//		IMAQdxConfigureGrab(session);
#endif

		ArmMotor0->SetSafetyEnabled(false); //Safety ArmMotor0
		//ArmMotor0->SetExpiration(2.200);
		//ArmMotor0->Set(0.0);
		myRobot->SetSafetyEnabled(true); //Safety Drive (Talon2 - Talon5)
		myRobot->SetExpiration(2.200);
		myRobot->ArcadeDrive(0.0,0.0);
		HangerMotor6->SetSafetyEnabled(false); //Safety HangerMotor6
		//HangerMotor6->SetExpiration(2.200);
		//HangerMotor6->Set(0.0);
		IntakeMotor7->SetSafetyEnabled(false); //Safety IntakeMotor7
		//IntakeMotor7->SetExpiration(2.200);
		//IntakeMotor7->Set(0.0);
		//SpareTalon1->SetSafetyEnabled(true); //Safety SpareTalon1
		//SpareTalon1->SetExpiration(2.200);
		//SpareTalon1->Set(0.0);

	}

	void AutonomousInit()
	{
		aimIsReady = 1;
		timer1->Reset();
		timer1->Start();
		//DriveTalon2->SetEncPosition(0);
		//DriveTalon5->SetEncPosition(0);

		DriveEncoderR->Reset();
		DriveEncoderL->Reset();

		pGyro->Reset();


		def1 = Brick->GetRawButton(1);
		def2 = Brick->GetRawButton(2);
		def3 = Brick->GetRawButton(3);
		def4 = Brick->GetRawButton(4);
		def5 = Brick->GetRawButton(5);
		def6 = Brick->GetRawButton(6);
		def7 = Brick->GetRawButton(7);
		def8 = Brick->GetRawButton(8);

#ifdef NEWBRICK
		button1 = BrickA->GetRawButton(9); // New Brick Position Select
		button2 = BrickA->GetRawButton(10);
		button3 = BrickA->GetRawButton(11);
		button4 = Brick->GetRawButton(9); //B Side
		button5 = Brick->GetRawButton(10);
#else
		button1 = Brick->GetRawButton(1); // New Brick Position Select
		button2 = Brick->GetRawButton(2);
		button3 = Brick->GetRawButton(3);
		button4 = Brick->GetRawButton(4);
		button5 = Brick->GetRawButton(5);


#endif
		pos1 = BrickA->GetRawButton(1); //Existing Brick Position Select
		pos2 = BrickA->GetRawButton(2);
		pos3 = BrickA->GetRawButton(3);
		pos4 = BrickA->GetRawButton(4);
		pos5 = BrickA->GetRawButton(5);
		pos6 = BrickA->GetRawButton(6);
		pos7 = BrickA->GetRawButton(7);
		pos8 = BrickA->GetRawButton(8);


		State = DRIVEFORWARD;
		Drive = DRIVESTRAIGHT;
		SubRoute = SUB1;
		TBFunc = DROPNSNATCH;
		OTBDrive = ROADTOAIM;

#ifdef USBCAMERA
		cam0->StartCapture();
#endif
#ifdef DOMORETHANCAMERA
		CameraLedSpike->Set(Relay::kOn);
		DriveEncoderR->Reset();
		DriveEncoderL->Reset();
		ArmMotor0->Set(0.0);
		myRobot->ArcadeDrive(0.0,0.0);
		HangerMotor6->Set(0.0);
		IntakeMotor7->Set(0.0);
		//SpareTalon1->Set(0.0);
		DeployHanger->Set(DoubleSolenoid::kReverse);
#endif

	}
	//TODO: AUTO

	void AutonomousPeriodic()
	{ // encoder = 16.2984657
		static int autonSelect = 0;
		static int BrickDefense = 0;
		static int BrickPos = 0;
		static int LEncoder = 0;
		static int REncoder = 0;
		static int TrueCounter = 0;
		static bool DBBit0 = 0;
		static bool DBBit1 = 0;
		static bool DBBit2 = 0;
		static bool DBBit3 = 0;
		static bool DBBit4 = 0;
		static bool reset = 0;
		static bool btarget = 0;
		static bool OneTrack = 0;
		static bool HighGear = 1;
		static bool Clamp = 0;
		static bool CloseShot = 0;
		static bool AirSwitch = 0;
		static bool armUpLimit = 0;
		static bool armDownLimit = 0;
		static bool camSwitch = 0;
		static bool stopDrop = 0;
		static bool Action = 0;
		static bool ActionSTP = 0;
		static float time = 0.0;
		static float yStick = 0.0;
		static float xStick = 0.0;
		static float ArmMotor = 0.0;
		static float gyro1 = 0.0;
		static float Destination = 0.0;
		static float IntakeMotor = 0.0;
		static float Beam = 0.0;

		//static bool altShot = 1; // temp auto selector

		unsigned int DefenseSub;
		unsigned int PositionSub;
		unsigned int AutoAimSub;
		unsigned int GoBackSub;
		unsigned int GoBackLRSub;
		unsigned int MiscSub;



		Beam = BeamBreak->GetVoltage();

		time = timer1->Get(); //get time from start of Auton/Reset in seconds



		//LEncoder = -DriveTalon2->GetEncPosition();
		//REncoder = DriveTalon5->GetEncPosition();

		LEncoder = -DriveEncoderL->GetDistance();
		REncoder = DriveEncoderR->GetDistance();


		gyro = pGyro->GetAngle();
		Spyro = -pGyro->GetAngle();
		gyro1 = -pGyro->GetAngle();

		if(Spyro >= 1)
		{
			Spyro = 1;
		}
		if(Spyro <= -1)
		{
			Spyro = -1;
		}

		//#ifdef BRICK



#ifdef NEWBRICK
		BrickDefense = (def1 + (def2 * 2) + (def3 *3) + (def4 * 4) + (def5 * 5) + (def6 * 6) + (def7 * 7));  //1st step the 1 of 7 Defenses we have to get past//2nd step, the 1 of 5 positions we are in after crossing the defense
		//BrickPos = (pos1 << 6 | pos2 << 7 | pos3 << 7 | pos4 << 9 | pos5 << 10);
#else
		BrickDefense = (button1 | button2 << 1 | button3 << 2);  //1st step the 1 of 7 Defenses we have to get past

#endif

		BrickPos = (pos1 | pos2 << 1 | pos3 << 2 | pos4 << 3 | pos5 << 4);

		if(BrickDefense != 0)
		{
			autonSelect = BrickDefense;  // 1st step the defense we must get past
		}
		if(BrickDefense == 0)
		{
			autonSelect = 103; //will do default case (OPTION 3)
		}
		printf("auton select in Enabled %1d, \n", autonSelect);
		SmartDashboard::PutNumber("Auton Select", autonSelect);
		SmartDashboard::PutNumber("LEFT ENCODER", LEncoder);
		SmartDashboard::PutNumber("RIGHT ENCODER", REncoder);
		SmartDashboard::PutNumber("Gyro", gyro);
		SmartDashboard::PutNumber("State", State);
		SmartDashboard::PutNumber("Drive", Drive);
		SmartDashboard::PutNumber("BrickDefense", BrickDefense);

		//camSwitch = button4;
		//stopDrop = button5;

		switch(autonSelect) //BrickDefense - 1st step the 7 defenses we must get past .... -y goes forward -x turns left
		{
		// Second row of 5 switches for positionSelect
		//
		case 1: //Low Bar
			switch(SubRoute)
			{
			case SUB1:
				if(pos6)	PositionSub = PositionSix(Drive, xStick, yStick, LEncoder, gyro1, CloseShot, AirSwitch, ArmMotor, Clamp);
				if(pos7)	PositionSub = PositionSeven(Drive, OneTrack, xStick, yStick, LEncoder, gyro1, CloseShot, AirSwitch, ArmMotor, Clamp, Destination, TrueCounter, camSwitch, IntakeMotor, Beam);
				if(pos8)	PositionSub = PositionEight(Drive, OneTrack, xStick, yStick, LEncoder, gyro1, CloseShot, AirSwitch, ArmMotor, Clamp, Destination, TrueCounter, camSwitch, IntakeMotor, Beam, Action, ActionSTP);
				if(pos7 && button1) PositionSub = PositionSevenThree(Drive, OneTrack, xStick, yStick, LEncoder, gyro1, CloseShot, AirSwitch, ArmMotor, Clamp, Destination, TrueCounter, camSwitch, IntakeMotor, Beam);
				if(pos6 == 0 && pos7 == 0 && pos8 == 0)
				{
					DefenseSub = LowBar(Drive, yStick, LEncoder, stopDrop, ArmMotor, Action);
				}

				break; // SUB1 BREAK

			case SUB2:
				if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
				if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
				if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
				if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
				if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);

				break; // SUB2 BREAK

			case SUB3:
				Drive = NOSTRAIGHT;
				AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);
				break; // SUB3 BREAK
			case GOBACKRIGHT:
				if(pos1) GoBackLRSub = GoBackONEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
				break;
			}
			break; // End of Case 1 Low Bar~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			case 2: //Rough terrain
				switch(SubRoute)
				{

				case SUB1:
					DefenseSub = RoughTerrian(Drive, yStick, LEncoder, stopDrop, ArmMotor, IntakeMotor, Beam, Clamp); // RoughTerrian Sub-routine
					break; // drive forward break

				case SUB2:
					if(button1 && pos2) PositionSub = PosTwoLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
					if(button1 && pos5) PositionSub = PosFiveLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
					if(button1 == 0)
					{
						if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
					}
					break; // SUB2 BREAK

				case SUB3:
					AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp); // Au000toaim subroutine
					break;// auto aim break
				case GOBACK:
					if(pos1)	GoBackSub = GoBackPosOne(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos2)	GoBackSub = GoBackPosTwo(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos3)	GoBackSub = GoBackPosThree(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos4)	GoBackSub = GoBackPosFour(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos5) 	GoBackSub = GoBackPosFive(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					break; // end of GOBACK
				case GOBACKLEFT:
					if(pos3) GoBackLRSub = GoBackTHREEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos4) GoBackLRSub = GoBackFOURToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos5) GoBackLRSub = GoBackFIVEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
				break;
				case GOBACKRIGHT:
					if(pos2) GoBackLRSub = GoBackTWOToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos3) GoBackLRSub = GoBackTHREEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					if(pos4) GoBackLRSub = GoBackFOURToFIVE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					break;

				}
				break; // End of Case 2 Rough Terrain~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				case 3: //Porticulis
					switch(SubRoute)
					{

					case SUB1:
							DefenseSub = Portculis(Drive, yStick,LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp); // RoughTerrian Sub-routine
						break; // drive forward break

					case SUB2:
						if(button1 && pos2) PositionSub = PosTwoLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						if(button1 && pos5) PositionSub = PosFiveLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						if(button1 == 0)
						{
							if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
						}
						break; // SUB2 BREAK

					case SUB3:
						AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp); // Au000toaim subroutine
						break;// auto aim break
					case GOBACK:
						if(pos1)	GoBackSub = GoBackPosOne(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos2)	GoBackSub = GoBackPosTwo(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos3)	GoBackSub = GoBackPosThree(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos4)	GoBackSub = GoBackPosFour(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos5) 	GoBackSub = GoBackPosFive(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						break; // end of GOBACK
					case GOBACKLEFT:
						if(pos3) GoBackLRSub = GoBackTHREEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos4) GoBackLRSub = GoBackFOURToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos5) GoBackLRSub = GoBackFIVEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
					break;
					case GOBACKRIGHT:
						if(pos2) GoBackLRSub = GoBackTWOToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos3) GoBackLRSub = GoBackTHREEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						if(pos4) GoBackLRSub = GoBackFOURToFIVE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						break;


					}
					break; // End of Case 3 - Porticulis~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					case 4: //Chevy
						switch(SubRoute)
						{

						case SUB1:
							DefenseSub = Chevy(Drive, yStick,LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP); // RoughTerrian Sub-routine
							break; // drive forward break

						case SUB2:
							if(button1 && pos2) PositionSub = PosTwoLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							if(button1 && pos5) PositionSub = PosFiveLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							if(button1 == 0)
							{
								if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
							}
							break; // SUB2 BREAK

						case SUB3:
							AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp); // Au000toaim subroutine
							break;// auto aim break
						case GOBACK:
							if(pos1)	GoBackSub = GoBackPosOne(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos2)	GoBackSub = GoBackPosTwo(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos3)	GoBackSub = GoBackPosThree(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos4)	GoBackSub = GoBackPosFour(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos5) 	GoBackSub = GoBackPosFive(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							break; // end of GOBACK

						case GOBACKLEFT:
							if(pos3) GoBackLRSub = GoBackTHREEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos4) GoBackLRSub = GoBackFOURToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos5) GoBackLRSub = GoBackFIVEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
						break;
						case GOBACKRIGHT:
							if(pos2) GoBackLRSub = GoBackTWOToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos3) GoBackLRSub = GoBackTHREEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							if(pos4) GoBackLRSub = GoBackFOURToFIVE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							break;

						}
						break; // End of Case 4 Chevy~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

						case 5: //Moat
							switch(SubRoute)
							{

							case SUB1:
								DefenseSub = Moat(Drive, yStick, LEncoder, stopDrop, ArmMotor, IntakeMotor, Beam, Clamp); // RoughTerrian Sub-routine
								break; // drive forward break

							case SUB2:
								if(button1 && pos2) PositionSub = PosTwoLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								if(button1 && pos5) PositionSub = PosFiveLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								if(button1 == 0)
								{
									if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
								}
								break; // SUB2 BREAK

							case SUB3:
								AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp); // Au000toaim subroutine
								break;// auto aim break
							case GOBACK:
								if(pos1)	GoBackSub = GoBackPosOne(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos2)	GoBackSub = GoBackPosTwo(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos3)	GoBackSub = GoBackPosThree(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos4)	GoBackSub = GoBackPosFour(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos5) 	GoBackSub = GoBackPosFive(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								break; // end of GOBACK
							case GOBACKLEFT:
								if(pos3) GoBackLRSub = GoBackTHREEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos4) GoBackLRSub = GoBackFOURToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos5) GoBackLRSub = GoBackFIVEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
							break;
							case GOBACKRIGHT:
								if(pos2) GoBackLRSub = GoBackTWOToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos3) GoBackLRSub = GoBackTHREEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								if(pos4) GoBackLRSub = GoBackFOURToFIVE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								break;

							}
							break; // End of Case 5 - Moat~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

							case 6: //Rockwall
								switch(SubRoute)
								{

								case SUB1:
									DefenseSub = RockWall(Drive, yStick, LEncoder, stopDrop, ArmMotor, IntakeMotor, Beam, Clamp); // RoughTerrian Sub-routine
									break; // drive forward break

								case SUB2:
									if(button1 && pos2) PositionSub = PosTwoLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									if(button1 && pos5) PositionSub = PosFiveLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									if(button1 == 0)
									{
										if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
									}
									break; // SUB2 BREAK

								case SUB3:
									AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp); // Au000toaim subroutine
									break;// auto aim break
								case GOBACK:
									if(pos1)	GoBackSub = GoBackPosOne(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos2)	GoBackSub = GoBackPosTwo(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos3)	GoBackSub = GoBackPosThree(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos4)	GoBackSub = GoBackPosFour(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos5) 	GoBackSub = GoBackPosFive(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									break; // end of GOBACK
								case GOBACKLEFT:
									if(pos3) GoBackLRSub = GoBackTHREEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos4) GoBackLRSub = GoBackFOURToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos5) GoBackLRSub = GoBackFIVEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
								break;
								case GOBACKRIGHT:
									if(pos2) GoBackLRSub = GoBackTWOToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos3) GoBackLRSub = GoBackTHREEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									if(pos4) GoBackLRSub = GoBackFOURToFIVE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									break;


								}
								break; // End of Case 6 - RockWall~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

								case 7: //Ramparts
									switch(SubRoute)
									{

									case SUB1:
										DefenseSub = Ramparts(Drive, yStick, LEncoder, stopDrop, ArmMotor, IntakeMotor, Beam, Clamp); // RoughTerrian Sub-routine
										break; // drive forward break

									case SUB2:
										if(button1 && pos2) PositionSub = PosTwoLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										if(button1 && pos5) PositionSub = PosFiveLong(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										if(button1 == 0)
										{
											if(pos1)	PositionSub = PositionOne(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
											if(pos2)	PositionSub = PositionTwo(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
											if(pos3)	PositionSub = PositionThree(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
											if(pos4)	PositionSub = PositionFour(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
											if(pos5)	PositionSub = PositionFive(Drive, xStick, yStick, LEncoder, gyro1, CloseShot);
										}
										break; // SUB2 BREAK

									case SUB3:
										AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp); // Au000toaim subroutine
										break;// auto aim break
									case GOBACK:
										if(pos1)	GoBackSub = GoBackPosOne(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos2)	GoBackSub = GoBackPosTwo(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos3)	GoBackSub = GoBackPosThree(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos4)	GoBackSub = GoBackPosFour(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos5) 	GoBackSub = GoBackPosFive(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										break; // end of GOBACK
									case GOBACKLEFT:
										if(pos3) GoBackLRSub = GoBackTHREEToTWO(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos4) GoBackLRSub = GoBackFOURToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos5) GoBackLRSub = GoBackFIVEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
									break;
									case GOBACKRIGHT:
										if(pos2) GoBackLRSub = GoBackTWOToTHREE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos3) GoBackLRSub = GoBackTHREEToFOUR(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										if(pos4) GoBackLRSub = GoBackFOURToFIVE(autonSelect, Drive, yStick, xStick, gyro1, LEncoder, ArmMotor, Action, stopDrop, IntakeMotor, Beam, Clamp, ActionSTP, HighGear);
										break;


									}
									break; // End of Case 7 - Ramparts~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


									default: //OPTION 3 do nothing

										Drive = NOSTRAIGHT;
										xStick = 0.0;
										yStick = 0.0;

										break; // end of default case

		}//END SWITCH CASES


		switch(Drive) //DRIVE STRAIGHT CODE
		{
		case DRIVESTRAIGHT:
			xStick = Spyro * .3;
			if((Spyro >= .3) || (Spyro <= -.25))
			{
				xStick = Spyro * .35;
			}
			break;
		case NOSTRAIGHT:
			break;

		case STRAIGHTENCODER:
			if(REncoder > LEncoder)
			{
				xStick = (REncoder - LEncoder) *-.050;
			}
			if(LEncoder > REncoder)
			{
				xStick = (LEncoder - REncoder) *.050;
			}
			break;
		}

		//camSwitch = button4;
		//ArmMotor0->Set(0.0);
		ArmMotor0->Set(ArmMotor);
		myRobot->ArcadeDrive(-yStick,xStick);
		HangerMotor6->Set(0.0);
		IntakeMotor7->Set(IntakeMotor);
		//SpareTalon1->Set(0.0);

		ActionArmStop->Set(ActionSTP);
		ActionArm->Set(Action);
		Shifter->Set(HighGear);
		BallClamp->Set(Clamp);
		ShortShot->Set(CloseShot); //CloseShot=false?

		Sole0->Set(AirSwitch);
		Sole6->Set(AirSwitch);
		Sole7->Set(AirSwitch);
		Sole8->Set(AirSwitch);


		if(c->GetPressureSwitchValue()) {Compressor2->Set(Relay::kOff);}
		else {Compressor2->Set(Relay::kForward);}




		SmartDashboard::PutBoolean("isTarget", isTarget);

		//SmartDashboard::PutNumber("SonicTime", SonicTime);
		//SmartDashboard::PutNumber("RightSonic", RightSonic);
		//SmartDashboard::PutNumber("LeftSonic", LeftSonic);
		SmartDashboard::PutNumber("XSTICK", xStick);
		SmartDashboard::PutNumber("YSTICK", yStick);
		SmartDashboard::PutNumber("LEFT ENCODER", LEncoder);
		SmartDashboard::PutNumber("RIGHT ENCODER", REncoder);
		SmartDashboard::PutNumber("GYRO1", gyro1);
		SmartDashboard::PutNumber("OneTrack", OneTrack);
		SmartDashboard::PutNumber("Destination", Destination);
		SmartDashboard::PutNumber("ArmMotor", ArmMotor);
		//	SmartDashboard::PutBoolean("box1", box1);
		//	SmartDashboard::PutBoolean("box2", box2);
		//	SmartDashboard::PutBoolean("box3", box3);
		//	SmartDashboard::PutBoolean("box4", box4);
		//	SmartDashboard::PutBoolean("box5", box5);
		//	SmartDashboard::PutBoolean("box6", box6);
		SmartDashboard::PutNumber("State", State);

	}

	//TODO: TELEOP
	void TeleopInit()
	{
		aimIsReady = 1;
#ifdef SPIGYRO
		pGyro->Reset();
#endif
		//DriveTalon2->SetEncPosition(0);
		//DriveTalon5->SetEncPosition(0);
		DriveEncoderR->Reset();
		DriveEncoderL->Reset();

#ifdef USBCAMERA
		cam0->StartCapture();
#endif
		pSonicOutput->DisablePWM();
#ifdef DOMORETHANCAMERA

		ArmMotor0->Set(0.0);
		myRobot->ArcadeDrive(0.0,0.0);
		HangerMotor6->Set(0.0);
		IntakeMotor7->Set(0.0);
		//SpareTalon1->Set(0.0);
		Sole0->Set(false);
		Sole7->Set(false);
		Sole6->Set(false);
		Sole8->Set(false);
		Shifter->Set(true); //lowgear=true highgear=false
		DeployHanger->Set(DoubleSolenoid::kReverse);
		deployOnce = 0;
		//		box1 = 0;

#endif

	}

	void TeleopPeriodic() // -y goes forward -x turns left
	{
#ifdef DOMORETHANCAMERA
		static int LEncoder = 0;
		static int REncoder = 0;
		static int SonicTime = 15;
		static int ClampTime = 0;
		static int IntakeTime = 0;
		static int TrueCounter = 0;
		static int specialTime = 0;
		static int actionTime = 0;
		static int actionEnd = 0;
		static int ClampTimeAA = 0;
		static bool btarget = 0;
		static bool OneTrack = 0;
		static bool HighGear = 0;
		static bool Clamp = 0;
		static bool Toggle = 0;
		static bool Toggle2 = 0;
		static bool CloseShot = 0;
		static bool Hanger = 0;
		static bool ballReady = 0;
		static bool ArmUp = 0;
		static bool ArmDown = 0;
		static bool ballClamped = 0;
		static bool box4 = 0;
		static bool box5 = 0;
		static bool ShootingShort = 0;
		static bool ShootingLong = 0;
		static bool readyWinch = 0;
		static bool AirSwitch = 0;
		static bool camSwitch = 1;
		static bool Action = 0;
		static bool ActionStop = 0;
		static bool aimReadyGo = 0;
		static bool actionChevy = 0;
		static bool AimReady = 0;
		static bool imageGrab = 0;
		static bool noname = 0;
		static bool Dest2 = 0;
		//static bool deployOnce = 0;
		static float Beam = 0;
		static float yStick = 0.0;
		static float xStick = 0.0;
		static float gyro1 = 0.0;
		static float RightSonic = 0.0;
		static float LeftSonic = 0.0;
		static float IntakeMotor = 0.0;
		static float ArmMotor = 0.0;
		static float HangerMotor = 0.0;
		static float Destination = 0.0;



		box4 = Brick->GetRawButton(4);
		box5 = Brick->GetRawButton(5);

		//LEncoder = DriveTalon2->GetEncPosition();
		//REncoder = -DriveTalon5->GetEncPosition();
		LEncoder = -DriveEncoderL->GetDistance();
		REncoder = DriveEncoderR->GetDistance();

		xStick = DrvStick->GetRawAxis(2);
		yStick = DrvStick->GetRawAxis(1);
		//xStick = xStick *0.8;  // limit xStick to 80%
		//	RightSonic = (102.0 * pRightSonic->GetVoltage());
		//	LeftSonic = (102.0 * pLeftSonic->GetVoltage());
		Beam = BeamBreak->GetVoltage();
		pSonicOutput->Set(0);
		SonicTime --;

		ArmUp = ArmUpHE->Get();
		ArmDown = ArmDownHE->Get();

		//Sole0->Set(false);
		//Sole7->Set(false);
		//Sole6->Set(false);
		//Sole8->Set(false);
		//DeployHanger->Set(DoubleSolenoid::kReverse);

		IntakeMotor = 0.0;
		ArmMotor = 0.0;
		HangerMotor = 0.0;

		ActionStop = 0;
		Action = 0;


#endif

		btarget = 0;

#ifdef AXISCAMERA
		btarget = doVision();

		// grab an image, draw the circle, and provide it for the camera server which will
		// in turn send it to the dashboard.
		//		camera->GetImage(frame);
		//		imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		//		CameraServer::GetInstance()->SetImage(frame);
		//		SendToDashboard(frame, imaqError);
		//		CameraServer::GetInstance()->SetImage(frame);
#endif
#ifdef USBCAMERA
		//		cam0->GetImage(frame);
		//	imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		//	CameraServer::GetInstance()->SetImage(frame);
#endif
#ifdef DOMORETHANCAMERA
#ifdef SPIGYRO
		gyro = pGyro->GetAngle(); //Gyro angle
		Spyro = pGyro->GetAngle();
		gyro1 = -pGyro->GetAngle();
		if(Spyro >= 1)
		{
			Spyro = 1;
		}
		if(Spyro <= -1)
		{
			Spyro = -1;
		}
		if(SonicTime <= 0)
		{
			pSonicOutput->Set(1);
			SonicTime = 15;
		}
#endif

#ifdef SPfIACCEL
		accelerationX = pAccel->GetX();
		accelerationY = pAccel->GetY();
		accelerationZ = pAccel->GetZ();
		SmartDashboard::PutNumber("AccelX", accelerationX);
		SmartDashboard::PutNumber("AccelY", accelerationY);
		SmartDashboard::PutNumber("AccelZ", accelerationZ);
#endif

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DR1V3R C0NTR0L$~~~~~~~~~~~~~~~~~~~~~C@LEB~~~~~~~~~~~~~~~~~~~~~~~$WAG~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~and~hopefully~Z@CH~next~year

		if(DrvStick->GetRawButton(6)) // Shift To High Gear
		{
			HighGear = 0;//gear
		}
		else
		{
			HighGear = 1;//lowgear
		}

		if(DrvStick->GetRawButton(3)) // Auto Camera
		{

			btarget = doVisionWithProcessing();
		}

		if(DrvStick->GetRawButton(8)) // Front Flash Light working
		{
			FrontFlashSpike->Set(Relay::kForward);
			Action = 1;
		}
		else
		{
			FrontFlashSpike->Set(Relay::kOff);
		}

		if(DrvStick->GetRawButton(7)) // Action Arm
		{
			Action = 1;
		}

		if(DrvStick->GetRawButton(5))
		{
			actionChevy = 1;
			Action = 1;
			actionTime++;
			if(actionTime >= 30)
			{
				ActionStop = 1;
				Action = 0;
			}
		}
		else
		{
			actionTime = 0;
			if(actionChevy)
			{
				actionEnd++;
				if(actionEnd <= 10)//10
				{
					Action = 1;
				}
				if(actionEnd <= 8)//8
				{
					ActionStop = 1;
				}
				if(actionEnd >= 11)//11
				{
					actionChevy = 0;
					actionEnd = 0;
				}
			}
		}


		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~0P3R@T0R C0NTR0L$~~~~~~~~~~~~~~~~~~~$TEF~~~~~~~~~~~~~~~~~~~~~~~~Y0L0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~and~hopefully~ETH@N~next~year~

		if(OpStick->GetRawAxis(1) <= -1) // Close Shot
		{
			CloseShot = 1;
		}

		if(OpStick->GetRawAxis(1) >= 1) // Far Shot
		{
			CloseShot = 0;
		}

		if(OpStick->GetRawAxis(0) <= -1) // in-take
		{
			IntakeMotor = 1.0;
		}

		if(OpStick->GetRawAxis(0) >= 1) // out-take
		{
			IntakeMotor = -1.0;
		}

//		if(OpStick->GetRawButton(11)) // Auto Aim
//		{
//			Drive = NOSTRAIGHT;
//			AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);
//		}
//		else
//		{
//			camSwitch = 1;
//			TrueCounter = 0;
//			Destination = 0;
//			OneTrack = 0;
//			AirSwitch = 0;
//		}




		if(OpStick->GetRawButton(7)) // Special In-take
		{
			IntakeMotor = 1.0;
			if(Beam >= 3.0)
			{
				ballReady = 1;
			}
			if(ballReady)
			{
				specialTime++;
				if(specialTime >= 12)
				{
					IntakeMotor = 0.0;
				}
			}

		}
		else
		{
			ballReady = 0;
			ballClamped = 0;
			IntakeTime = 0;
			specialTime = 0;
		}
		if(OpStick->GetRawButton(8) && (OpStick->GetRawButton(9) == 0) && (OpStick->GetRawButton(10) == 0)) // Auto Aim
		{
			Drive = NOSTRAIGHT;
			AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);
		}
		else
		{
			camSwitch = 1;
			TrueCounter = 0;
			Destination = 0;
			OneTrack = 0;
			AirSwitch = 0;
		}
		if(teleOpAirSwitch)
		{
			ClampTimeAA++;
				Sole0->Set(true);
				Sole7->Set(true);
				Sole6->Set(true);
				Sole8->Set(true);
			if(ClampTimeAA >= 30)
			{
				CloseShot = 0;
				Sole0->Set(false);
				Sole7->Set(false);
				Sole6->Set(false);
				Sole8->Set(false);
				teleOpAirSwitch = 0;
			}
		}
		else
		{
			ClampTimeAA = 0;
		}

		/*			if(OpStick->GetRawButton(10)) // Clamp Toggle
			{
				if(Clamp == 0)
				{
					if(Toggle == 0)
					{
						Clamp = 1;
						Toggle2 = 1;
					}

				}
				else
				{
					if(Toggle2 == 0)
					{
						Clamp = 0;
						Toggle = 1;
					}
				}
			}
			else
			{
				Toggle = 0;
				Toggle2 = 0;
			}
		 */
		if(OpStick->GetRawButton(6)) // Shoot
		{
			ShootingLong = 1;
		}

		if(ShootingLong)
		{
			Clamp = 1;
			CloseShot = 0;
			ClampTime++;

			if(ClampTime >= 10)//20
			{
				Sole0->Set(true);
				Sole7->Set(true);
				Sole6->Set(true);
				Sole8->Set(true);
			}
			if(ClampTime >= 30)//30
			{
				ShootingLong = 0;
				ClampTime = 0;
				Sole0->Set(false);
				Sole7->Set(false);
				Sole6->Set(false);
				Sole8->Set(false);
			}
		}

		if(OpStick->GetRawButton(5)) // Shoot
		{
			ShootingShort = 1;
		}

		if(ShootingShort)
		{
			Clamp = 1;
			ClampTime++;
			if(ClampTime >= 1)//10
			{
				CloseShot = 1; //shortshot enabled
			}
			if(ClampTime >= 5)//20
			{
				Sole0->Set(true);
				Sole7->Set(true);
				Sole6->Set(true);
				Sole8->Set(true);
			}
			if(ClampTime >= 15)//30
			{
				ShootingShort = 0;
				ClampTime = 0;  // -
				CloseShot = 0;
				Sole0->Set(false);
				Sole7->Set(false);
				Sole6->Set(false);
				Sole8->Set(false);
			}

		}

		if(OpStick->GetRawButton(1)) // In-take
		{
			Clamp = 0;
		}

		if(OpStick->GetRawButton(3)) // Out-take
		{
			Clamp = 1;
		}

		//		if(OpStick->GetRawButton(5)) // Front Flash Light working
		//		{
		//			FrontFlashSpike->Set(Relay::kForward);
		//		}
		//		else
		//		{
		//			FrontFlashSpike->Set(Relay::kReverse);
		//		}

		//		if(box4)
		//		{
		//			DeployHanger->Set(DoubleSolenoid::kForward);
		//		}
		//		else
		//		{
		//			DeployHanger->Set(DoubleSolenoid::kReverse);
		//		}
		//
		//		if(box5)
		//		{
		//			HangerMotor = 1.0;
		//		}

		if((OpStick->GetRawButton(9)) && (OpStick->GetRawButton(10)))
		{
			deployOnce = 1;
			readyWinch = 1;
		}
		else
		{
			readyWinch = 0;
		}
		if(deployOnce)
		{
			DeployHanger->Set(DoubleSolenoid::kForward);
		}
		else
		{
			DeployHanger->Set(DoubleSolenoid::kReverse);
		}
		if(readyWinch)
		{
			if(OpStick->GetRawButton(8))
			{
				HangerMotor = 1.0;
			}
		}



		ArmMotor = (OpStick->GetRawAxis(3)); // Arm Motor for Axis3
		if(ArmMotor >= .75) {ArmMotor = .75;} //Arm Motor Limit
		if(ArmMotor <= -.75) {ArmMotor = -.75;} // Arm Motor Limit

		Shifter->Set(HighGear);
		BallClamp->Set(Clamp);
		ShortShot->Set(CloseShot);
		ActionArm->Set(Action);
		ActionArmStop->Set(ActionStop);


		//SmartDashboard::PutNumber("IntakeMotor", IntakeMotor);
		//SmartDashboard::PutNumber("HangerMotor", HangerMotor);
		//SmartDashboard::PutNumber("Arm Motor Input", OpStick->GetRawAxis(3));

		ArmMotor0->Set(ArmMotor);
		myRobot->ArcadeDrive(-yStick,xStick); // at the top Limit xStick by 80%
		HangerMotor6->Set(HangerMotor);
		IntakeMotor7->Set(IntakeMotor);

		if(c->GetPressureSwitchValue()) {Compressor2->Set(Relay::kOff);}
		else {Compressor2->Set(Relay::kForward);}

		//if(DrvStick->GetRawButton(1)) {Compressor2->Set(Relay::kForward);}
		//else {Compressor2->Set(Relay::kOff);}

		//if(DrvStick->GetRawButton(2)) {CameraLedSpike->Set(Relay::kForward);}
		//else {CameraLedSpike->Set(Relay::kOff);}



		//myRobot->ArcadeDrive(DrvStick->GetRawAxis(1),DrvStick->GetRawAxis(2));
		SmartDashboard::PutNumber("Beam", Beam);
		SmartDashboard::PutBoolean("BeamBreak", BeamBreak);
		//SmartDashboard::PutNumber("Clamp", Clamp);
		SmartDashboard::PutNumber("SonicTime", SonicTime);
		//SmartDashboard::PutNumber("RightSonic", RightSonic);
		//SmartDashboard::PutNumber("LeftSonic", LeftSonic);
		SmartDashboard::PutNumber("XSTICK", xStick);
		SmartDashboard::PutNumber("YSTICK", yStick);
		SmartDashboard::PutNumber("LEFT ENCODER", LEncoder);
		SmartDashboard::PutNumber("RIGHT ENCODER", REncoder);
		SmartDashboard::PutNumber("GYRO1", gyro1);
		SmartDashboard::PutNumber("ArmMotor", ArmMotor);
		//SmartDashboard::PutNumber("SPYRO", Spyro);
		//SmartDashboard::PutNumber("SPYRO2", Spyro2);
		//SmartDashboard::PutNumber("SPYRO3", Spyro3);
		//SmartDashboard::PutNumber("Distance", distance);
		//SmartDashboard::PutNumber("cur0", pdp->GetCurrent(0));
		//SmartDashboard::PutNumber("Pressure Switch", Pressure->GetVoltage());
		//SmartDashboard::PutNumber("Spyro", Spyro);
		SmartDashboard::PutNumber("OneTrack", OneTrack);
		SmartDashboard::PutNumber("Destination", Destination);
		//SmartDashboard::PutNumber("Gyro Angle", gyro);
		//		SmartDashboard::PutBoolean("box1", box1);
		//		SmartDashboard::PutBoolean("box2", box2);
		//		SmartDashboard::PutBoolean("box3", box3);
		//		SmartDashboard::PutBoolean("box4", box4);
		//		SmartDashboard::PutBoolean("box5", box5);
		//		SmartDashboard::PutBoolean("box6", box6);
		SmartDashboard::PutBoolean("CloseShot", CloseShot);
		//SmartDashboard::PutNumber("Axis1", OpStick->GetRawAxis(1));
#endif
	}


	void DisbledPeriodic()
	{
		ArmMotor0->Set(0.0);
		myRobot->ArcadeDrive(0.0,0.0);
		HangerMotor6->Set(0.0);
		IntakeMotor7->Set(0.0);
		//SpareTalon1->Set(0.0);
		DeployHanger->Set(DoubleSolenoid::kReverse);
		deployOnce = 0;

		DriveEncoderR->Reset();
		DriveEncoderL->Reset();

#ifdef USBCAMERA        // stop image acquisition
		//		IMAQdxStopAcquisition(session);
		cam0->StopCapture();
#endif

	}

	void TestPeriodic()
	{
		lw->Run();
	}

	//TODO:SUB-ROUTINE
	//------------------------------------------------------------
	//---------------------AUTON SUB-ROUTINES---------------------
	//------------------------------------------------------------
	//Check all encoder & yStick values

	//--------DEFENSES--------
	unsigned int LowBar(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, bool &Action)
	{
		static int armCount = 0;


		ArmMotor = -0.07;
		armCount++;
		Action = 1;
		Drive = DRIVESTRAIGHT;
		yStick = -0.70;

		if(armCount >= 10)
		{
			ArmMotor = 1.0;
		}
		if(armCount >= 60)//was 20
		{
			ArmMotor = 0.0;
		}

		if(LEncoder >= 1925)
		{
			ArmMotor = 0.0;
			yStick = 0.0;
			if(stopDrop)
			{

			}
			else
			{
				SubRoute = SUB2;
			}

		}
		return SubRoute;
	}
	unsigned int Moat(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp)
	{
		static int armCount = 0;
		static bool ballReady = 0;
		static bool endGrab = 0;
		static bool snatchGrab = 0;
		static bool safeCheck = 0;
		static int ArmCount = 0;
		static int goCount = 0;
		static int armSafeCnt = 0;
		static int backArmTime = 0;
		static int intakeCount = 0;
		static int goBackArmCnt = 0;
		IntakeMotor = 0.0;

//		if(button5 && goBackAfter)
//		{
//			goBackArmCnt++;
//			ArmMotor = -1.0;
//			if(goBackArmCnt >= 60)
//			{
//				ArmMotor = 0.0;
//			}
//			Drive = DRIVESTRAIGHT;
//			yStick = 0.95;
//			if(LEncoder <= -2000)
//			{
//				yStick = 0.0;
//			}
//		}
		//else
		//{
			if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
			{
				snatchGrab = 1;
				ArmCount++;
				goCount++;
				armSafeCnt++;
				ArmMotor = 1.0;
				IntakeMotor = 1.0;

				if(armSafeCnt >= 45 && safeCheck == 0)
				{
					ArmMotor = 0.0;
					safeCheck = 1;
				}

		//			IntakeMotor = 1.0;
				if(safeCheck == 1 || goCount >= 150)
				{
					ballReady = 1;
				}
				if(ballReady)
				{
					intakeCount++;
					if(intakeCount >= 100)
					{
						IntakeMotor = 0.0;
					}
					snatchGrab = 0; // -- !!!! TEST !!!! --
				}
				if((ArmCount >= 50) && (intakeCount >= 55))
				{
					Clamp = 1;
					ArmMotor = -1.0;
					backArmTime++;
					if(backArmTime >= 30)
					{
						Clamp = 0;
						IntakeMotor = 1.0;
						ArmMotor = 0.0;
					}
				}
			}
			if(snatchGrab == 0)
			{
				Drive = DRIVESTRAIGHT;
				yStick = -0.825;
				if(LEncoder >= 1800)
				{
					armCount++;
					ArmMotor = 1.0;
					if(armCount >= 60)
					{
						ArmMotor = 0.0;
					}
				}
				if(LEncoder >= 2275)  // was 2150
				{
					ArmMotor = 0.0;
					yStick = 0.0;
					if(stopDrop)
					{

					}
					else
					{
						SubRoute = SUB2;
					}
				}
			}
		return SubRoute;
		//}
	}

	unsigned int RockWall(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp)
	{
		static int armCount = 0;
		static bool ballReady = 0;
		static bool endGrab = 0;
		static bool snatchGrab = 0;
		static bool safeCheck = 0;
		static int ArmCount = 0;
		static int armSafeCnt = 0;
		static int goCount = 0;
		static int backArmTime = 0;
		static int intakeCount = 0;
		IntakeMotor = 0.0;

		if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
		{
			snatchGrab = 1;
			ArmCount++;
			goCount++;
			armSafeCnt++;

			ArmMotor = 1.0;
			IntakeMotor = 1.0;

			if(armSafeCnt >= 45 && safeCheck == 0)
			{
				ArmMotor = 0.0;
				safeCheck = 1;
			}
			if(safeCheck == 1 || goCount >= 150)
			{
				ballReady = 1;
			}
			if(ballReady)
			{
				intakeCount++;
				if(intakeCount >= 55)
				{
					IntakeMotor = 0.0;
				}
				snatchGrab = 0; // -- !!!! TEST !!!! --
			}
			if((ArmCount >= 50) && (intakeCount >= 55))
			{
				Clamp = 1;
				ArmMotor = -1.0;
				backArmTime++;
				if(backArmTime >= 30)
				{
					Clamp = 0;
					IntakeMotor = 1.0;
					ArmMotor = 0.0;
				}
			}
		}
		if(snatchGrab == 0)
		{

			Drive = DRIVESTRAIGHT;
			yStick = -0.725;
			if(LEncoder >= 800)
			{
				yStick = -0.665;
			}
			if(LEncoder >= 1450)
			{
				armCount++;
				ArmMotor = 1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
			}
			if(LEncoder >= 1825)
			{
				ArmMotor = 0.0;
				yStick = 0.0;
				if(stopDrop)
				{

				}
				else
				{
					SubRoute = SUB2;
				}
			}
		}
		return SubRoute;
	}

	unsigned int RoughTerrian(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp)
	{
		static int armCount = 0;
		static bool ballReady = 0;
		static bool endGrab = 0;
		static bool snatchGrab = 0;
		static bool safeCheck = 0;
		static int ArmCount = 0;
		static int armSafeCnt = 0;
		static int goCount = 0;
		static int backArmTime = 0;
		static int intakeCount = 0;
		static int goBackArmCnt = 0;
		IntakeMotor = 0.0;

//		if(button5 && goBackAfter)
//		{
//			goBackArmCnt++;
//			ArmMotor = -1.0;
//			if(goBackArmCnt >= 60)
//			{
//				ArmMotor = 0.0;
//			}
//			Drive = DRIVESTRAIGHT;
//			yStick = 0.95;
//			if(LEncoder <= -2000)
//			{
//				yStick = 0.0;
//			}
//		}
//		else
//		{
			if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
			{
				snatchGrab = 1;
				ArmCount++;
				goCount++;
				armSafeCnt++;
				ArmMotor = 1.0;
				IntakeMotor = 1.0;

				if(armSafeCnt >= 45 && safeCheck == 0)
				{
					ArmMotor = 0.0;
					safeCheck = 1;
				}
				if(safeCheck == 1 || goCount >= 150)
				{
					ballReady = 1;
				}
				if(ballReady)
				{
					intakeCount++;
					if(intakeCount >= 100)
					{
						IntakeMotor = 0.0;
					}
					snatchGrab = 0; // -- !!!! TEST !!!! --
				}
				if((ArmCount >= 50) && (intakeCount >= 55))
				{
					Clamp = 1;
					ArmMotor = -1.0;
					backArmTime++;
					if(backArmTime >= 30)
					{
						Clamp = 0;
						IntakeMotor = 1.0;
						ArmMotor = 0.0;
					}
				}
			}
			if(snatchGrab == 0)
			{
				Drive = DRIVESTRAIGHT;
				yStick = -0.75;
				if(LEncoder >= 1400)
				{
					armCount++;
					ArmMotor = 1.0;
					if(armCount >= 60)
					{
						ArmMotor = 0.0;
					}
				}

				if(LEncoder >= 1725)
				{
					ArmMotor = 0.0;
					yStick = 0.0;
					if(stopDrop)
					{

					}
					else
					{
						SubRoute = SUB2;
					}
				}
			}
		//}
			return SubRoute;

	}

	unsigned int Chevy(unsigned int &Drive, float &yStick, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP)
	{
		static bool actionChevy = 0;
		static int armCount = 0;
		static bool ballReady = 0;
		static bool endGrab = 0;
		static bool snatchGrab = 0;
		static bool safeCheck = 0;
		//static bool firstGrab = 0;
		static int ArmCount = 0;
		static int actionTime = 0;
		static int goCount = 0;
		static int armSafeCnt = 0;
		static int backArmTime = 0;
		static int intakeCount = 0;

		IntakeMotor = 0.0;

//		if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
//		{
//			snatchGrab = 1;
//			ArmCount++;
//			goCount++;
//			armSafeCnt++;
//			ArmMotor = 1.0;
//			IntakeMotor = 1.0;
//
//			if(armSafeCnt >= 45 && safeCheck == 0)
//			{
//				ArmMotor = 0.0;
//				safeCheck = 1;
//			}
//		//	IntakeMotor = 1.0;
//			if(Beam >= 3.0 || goCount >= 150)
//			{
//				ballReady = 1;
//			}
//			if(ballReady)
//			{
//				intakeCount++;
//				if(intakeCount >= 10)
//				{
//					IntakeMotor = 0.0;
//				}
//				snatchGrab = 0; // -- !!!! TEST !!!! --
//			}
//			if((ArmCount >= 50) && (ballReady))
//			{
//				Clamp = 1;
//				ArmMotor = -1.0;
//				backArmTime++;
//				if(backArmTime >= 30)
//				{
//					Clamp = 0;
//					IntakeMotor = 1.0;
//					ArmMotor = 0.0;
//					if(Beam <= 3.0)
//					{
//						endGrab = 1;
//					}
//				}
//			}
//		}

		if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
		{
			snatchGrab = 1;
			ArmCount++;
			goCount++;
			armSafeCnt++;
			ArmMotor = 1.0;
			IntakeMotor = 1.0;

			if(armSafeCnt >= 45 && safeCheck == 0)
			{
				ArmMotor = 0.0;
				safeCheck = 1;
			}
				if(safeCheck == 1 || goCount >= 150)
				{
					ballReady = 1;
				}
				if(ballReady)
				{
					intakeCount++;
					if(intakeCount >= 100)
					{
						IntakeMotor = 0.0;
						//firstGrab = 1;
					}
					snatchGrab = 0; // -- !!!! TEST !!!! --
				}
			if((ArmCount >= 50) && (intakeCount >= 55))
			{
				Clamp = 1;
				ArmMotor = -1.0;
				backArmTime++;
				if(backArmTime >= 30)
				{
					Clamp = 0;
					IntakeMotor = 1.0;
					ArmMotor = 0.0;
				}
			}
		}
		if(snatchGrab == 0)
		{
			Drive = DRIVESTRAIGHT;
			yStick = -0.625;


			actionChevy = 1;
			Action = 1;
			actionTime++;
			if(actionTime >= 30)
			{
				ActionSTP = 1;
				Action = 0;
			}
			if(LEncoder >= 900) // was 1200
			{
				yStick = -0.75;
			}
			if(LEncoder >= 1300) // was 1300
			{
				yStick = -0.75;
			}
			if(LEncoder >= 1350) // was 1500
			{
				yStick = -0.75;
				armCount++;
				ArmMotor = 1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
			}
			if(LEncoder >= 1675) // 1700, 1575
			{
				ArmMotor = 0.0;
				if(stopDrop)
				{

				}
				else
				{
					//ArmMotor = 0.0;
					SubRoute = SUB2;
				}
			}
		}
		return SubRoute;
	}

	unsigned int Portculis(unsigned int &Drive, float &yStick, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp)
	{
		static int armCount = 0;
		static bool ballReady = 0;
		static bool endGrab = 0;
		static bool snatchGrab = 0;
		static bool safeCheck = 0;
		static int ArmCount = 0;
		static int goCount = 0;
		static int armSafeCnt = 0;
		static int backArmTime = 0;
		static int intakeCount = 0;
		IntakeMotor = 0.0;

		if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
		{
			snatchGrab = 1;
			ArmCount++;
			goCount++;
			armSafeCnt++;

			ArmMotor = 1.0;
			IntakeMotor = 1.0;

			if(armSafeCnt >= 45 && safeCheck == 0)
			{
				ArmMotor = 0.0;
				safeCheck = 1;
			}
			if(safeCheck == 1 || goCount >= 150)
			{
				ballReady = 1;
			}
			if(ballReady)
			{
				intakeCount++;
				if(intakeCount >= 100)
				{
					IntakeMotor = 0.0;
				}
				snatchGrab = 0; // -- !!!! TEST !!!! --
			}
			if((ArmCount >= 50) && (intakeCount >= 55))
			{
				Clamp = 1;
				ArmMotor = -1.0;
				backArmTime++;
				if(backArmTime >= 30)
				{
					Clamp = 0;
					IntakeMotor = 1.0;
					ArmMotor = 0.0;
				}
			}
		}

		if(snatchGrab == 0)
		{
			armCount++;
			Action = 1;
			Drive = DRIVESTRAIGHT;
			yStick = -0.75;

			if(armCount >= 10)
			{
				ArmMotor = 1.0;
			}
			if(armCount >= 30)
			{
				ArmMotor = 0.0;
			}

			if(LEncoder >= 1700)
			{
				ArmMotor = 0.0;
				yStick = 0.0;
				if(stopDrop)
				{

				}
				else
				{
					SubRoute = SUB2;
				}
			}
		}
		return SubRoute;
	}

	unsigned int Ramparts(unsigned int &Drive, float &yStick, int &LEncoder, bool &stopDrop, float &ArmMotor, float &IntakeMotor, float &Beam, bool &Clamp)
	{
		static int armCount = 0;
		static bool ballReady = 0;
		static bool endGrab = 0;
		static bool snatchGrab = 0;
		static bool safeCheck = 0;
		static int ArmCount = 0;
		static int goCount = 0;
		static int armSafeCnt = 0;
		static int backArmTime = 0;
		static int intakeCount = 0;
		IntakeMotor = 0.0;


		if((button4) && (endGrab == 0)) // Checks for the snatch n' grab modifier
		{
			snatchGrab = 1;
			ArmCount++;
			goCount++;
			armSafeCnt++;
			ArmMotor = 1.0;
			IntakeMotor = 1.0;

			if(armSafeCnt >= 45 && safeCheck == 0)
			{
				ArmMotor = 0.0;
				safeCheck = 1;
			}
			if(safeCheck == 1 || goCount >= 150)
			{
				ballReady = 1;
			}
			if(ballReady)
			{
				intakeCount++;
				if(intakeCount >= 100)
				{
					IntakeMotor = 0.0;
				}
				snatchGrab = 0; // -- !!!! TEST !!!! --
			}
			if((ArmCount >= 50) && (intakeCount >= 55))
			{
				Clamp = 1;
				ArmMotor = -1.0;
				backArmTime++;
				if(backArmTime >= 30)
				{
					Clamp = 0;
					IntakeMotor = 1.0;
					ArmMotor = 0.0;
				}
			}
		}

		if(snatchGrab == 0)
		{

			Drive = DRIVESTRAIGHT;
			yStick = -1.0; //0.85

			if(LEncoder >= 1800)
			{
				yStick = -0.825; // -0.65
				armCount++;
				ArmMotor = 1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
			}
			if(LEncoder >= 2000)//was 2050
			{
				ArmMotor = 0.0;
				yStick = 0.0;
				if(stopDrop)
				{

				}
				else
				{
					//ArmMotor = 0.0;
					SubRoute = SUB2;
				}
			}
		}
		return SubRoute;
	}
	//-------AutoAim--------
	void AutoAim(unsigned int &Drive, bool &OneTrack, float &Destination, int &TrueCounter,bool &camSwitch, float &xStick, float &gyro, bool &AirSwitch, bool &Clamp)
	{
		static bool btarget = 0;
		static bool AimReady = 0;
	//	static bool goProcess = 0;
		static bool imageGrab = 0;
		static bool noname = 0;
//		static bool failSafe = 0;
		static int ClampTime = 0;
		static bool Dest2 = 0;
//		if(globNoName && failSafe == 0)
//		{
//			imageGrab = 0;
//			btarget = 0;
//			noname = 0;
//			Dest2 = 0;
//			AimReady = 0;
//			ClampTime = 0;
//			camSwitch = 0;
//			failSafe = 1;
//		}
//


//****  Need to initialize:
//			camSwitch = 1;
//			TrueCounter = 0;
//			Destination = 0;
//			OneTrack = 0;
//			AirSwitch = 0;
//(for 2nd shot) ****

		if(aimIsReady && camSwitch)
		{
			imageGrab = 0;
			btarget = 0;
			noname = 0;
			Dest2 = 0;
			AimReady = 0;
			ClampTime = 0;
			camSwitch = 0;
		}

		if(OneTrack == 0)
		{
			TrueCounter++;
			if(TrueCounter <= 4) //changed from 5, FOUR IS FOR TESTING
			{
				noname = doVision();
			}
			else
			{
				imageGrab = 1;
			}

			if(imageGrab)
			{
				btarget = doVisionWithProcessing();
			}
			if((btarget) && Dest2 == 0)
			{
				Destination = TargetAngle;
				AADest = Destination;
				pGyro->Reset();
				OneTrack = 1;
				imageGrab = 0;
				Dest2 = 1;
			}
		}

		if(OneTrack)
		{

			xStick = (gyro - Destination) * -.1725; //-.075

			if(((gyro - Destination) <= 6) && ((gyro - Destination) >= -6))
			{
				xStick = (gyro - Destination) * -.25; // -.05 was -.245 on comp bot
			}

			if(((gyro - Destination) <= 3) && ((gyro - Destination) >= -3))
			{
				xStick = (gyro - Destination) * -.4; //new stuff
			}

			if(xStick >= 0.6) //was .7 then .55
			{
				xStick = 0.6;
			}
			if(xStick <= -0.6)
			{
				xStick = -0.6;
			}

			if(((gyro - Destination) <= .4) && ((gyro - Destination) >= -.4)) //was .5, .4
			{
				AimReady = 1;
			}
			if(AimReady)
			{
				Clamp = 1;
				ClampTime++;
				xStick = 0.0;
				//pGyro->Reset();
				//				noname = doVision();
				if(ClampTime >= 20)
				{
					AirSwitch = 1;
					teleOpAirSwitch = 1;
					noname = doVision();
					if(button5 && ClampTime >= 25)
					{
						goBackAfter = 1;
						AirSwitch = 0;
						SubRoute = GOBACK;
					}
					if(button2 && ClampTime >= 25)
					{
						SubRoute = GOBACKLEFT;
					}
					if(button3 && ClampTime >= 25)
					{
						SubRoute = GOBACKRIGHT;
					}
				}
			}
			Drive = NOSTRAIGHT;
			SmartDashboard::PutNumber("OneTrack", OneTrack);
		}
		else
		{
			if(aimIsReady)
			{
				AimReady = 0;
			}
			else
			{
				ClampTime = 0;
				AirSwitch = 0;
				xStick = 0.0;
				//pGyro->Reset();
				Drive = NOSTRAIGHT;
			}
		}
//		SmartDashboard::PutNumber("failSafe", failSafe);
		//return SubRoute;
	}

	//-------POSITION--------
	unsigned int PositionOne(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		static bool ResetOnce = 0;
		static bool gotTurn = 0;
		static int ResetCount = 0;

		if(ResetOnce == 0)
		{
			DriveEncoderL->Reset();
			ResetOnce = 1;
		}

		ResetCount++;
		if(ResetCount >= 10)
		{
			Drive = DRIVESTRAIGHT;
			yStick = -0.6;
			if(LEncoder >= 950) //1200 // +75
			{
				yStick = 0.0;
				reachTurn = 1;
			}
		}

		if(reachTurn)
		{
			Drive = NOSTRAIGHT;
			xStick = 0.65;
			if(gyro1 <= -57)
			{
				pGyro->Reset();
				timer1->Reset();
				xStick = 0.0;
				gotTurn = 1;
			}
			if(gotTurn)
			{
				Drive = DRIVESTRAIGHT;
				CloseShot = 1;
				yStick = -0.6;
				if(LEncoder >= 1500)
				{
					yStick = 0.0;
					SubRoute = SUB3;
				}
			}

		}
		return SubRoute;
	}

	unsigned int PositionTwo(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		static bool ResetOnce = 0;
		static int ResetCount = 0;
		if(ResetOnce == 0)
		{
			DriveEncoderL->Reset();
			ResetOnce = 1;
		}

		ResetCount++;
		if(ResetCount >= 10)
		{
			CloseShot = 1;
			Drive = DRIVESTRAIGHT;
			yStick = -0.7;

			if(LEncoder >= 1525) // +75
			{
				yStick = 0.0;
				xStick = 0.0;
				reachTurn = 1;
			}
		}
		if(reachTurn)
		{
			Drive = NOSTRAIGHT;
			xStick = 0.6;
			yStick = 0.0;
			if(gyro1 <= -57)
			{
				xStick = 0.0;
				yStick = 0.0;
				SubRoute = SUB3;
			}

		}
		return SubRoute;
	}

	unsigned int PositionThree(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		//		if(gyro1 <= -19)
		//		{
		//			yStick = 0.0;
		//			xStick = 0.0;
		//			SubRoute = SUB3;
		//		}
		static bool ResetOnce = 0;
		static int ResetCount = 0;
		if(ResetOnce == 0)
		{
			DriveEncoderL->Reset();
			ResetOnce = 1;
		}

		ResetCount++;
		if(ResetCount >= 10)
		{
			CloseShot = 1;
			Drive = DRIVESTRAIGHT;
			yStick = -0.6;
			if(LEncoder >= 825) // +75
			{
				reachTurn = 1;
				yStick = 0.0;
			}
			if(reachTurn)
			{
				Drive = NOSTRAIGHT;
				xStick = 0.6;
				yStick = 0.0;
				if(gyro1 <= -16)
				{
					xStick = 0.0;
					SubRoute = SUB3;
				}
			}

		}

		return SubRoute;
	}

	unsigned int PositionFour(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		static bool ResetOnce = 0;
		static int ResetCount = 0;

		if(ResetOnce == 0)
		{
			DriveEncoderL->Reset();
			ResetOnce = 1;
		}

		ResetCount++;
		if(ResetCount >= 10)
		{
			CloseShot = 1;
			Drive = DRIVESTRAIGHT;
			yStick = -0.6;
			if(LEncoder >= 925) // +25
			{
				reachTurn = 1;
				yStick = 0.0;
			}
			if(reachTurn)
			{
				Drive = NOSTRAIGHT;
				xStick = -0.575;
				if(gyro1 >= 5)
				{
					xStick = 0.0;
					SubRoute = SUB3;
				}
			}
		}

		return SubRoute;
	}

	unsigned int PositionFive(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		static bool ResetOnce = 0;
		static int ResetCount = 0;
		if(ResetOnce == 0)
		{
			DriveEncoderL->Reset();
			ResetOnce = 1;
		}

		ResetCount++;
		if(ResetCount >= 10)
		{
			CloseShot = 1;
			Drive = DRIVESTRAIGHT;
			yStick = -0.6;

			if(LEncoder >= 1475) // +75
			{
				yStick = 0.0;
				xStick = 0.0;
				reachTurn = 1;
			}
		}
		if(reachTurn)
		{
			Drive = NOSTRAIGHT;
			xStick = -0.625;
			yStick = 0.0;
			if(gyro1 >= 49)
			{
				xStick = 0.0;
				yStick = 0.0;
				SubRoute = SUB3;
			}

		}
		return SubRoute;
	}

	unsigned int PositionSix(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp)
	{
		static bool reachShot = 0;
		static int armCount = 0;

		CloseShot = 1;
		Clamp = 1;
		Drive = DRIVESTRAIGHT;
		yStick = -0.6;

		if(LEncoder >= 400)
		{
			armCount++;
			if(armCount >= 10)
			{
				ArmMotor = 1.0;
			}
			if(armCount >= 20)
			{
				ArmMotor = 0.0;
			}
		}
		if(LEncoder >= 1000)
		{
			ArmMotor = 0.0;
			yStick = 0.0;
			xStick = 0.0;
			reachShot = 1;

		}
		if(reachShot)
		{
			ArmMotor = 0.0;
			AirSwitch = 1;
			SubRoute = SUB2;
		}

		return SubRoute;
	}
	// TODO:tb

	unsigned int PositionSeven(unsigned int &Drive, bool &OneTrack, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp, float &Destination, int &TrueCounter,bool &camSwitch, float &IntakeMotor, float &Beam)
	{
		static bool goingBack = 0;
		static bool droppedIt = 0;
		static bool BBOnce = 0;
		static bool ballSeen = 0;
		static bool securedBallOne = 0;
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gyroOnce = 0;
		static int encoderResetCnt = 0;
		static int armCount = 0;
		static int armBackCount = 0;
		static int armGrabCount = 0;
		static int grabBackCount = 0;
		static int shotTime = 0;
		static int intakeCount = 0;
		static int armSnatchedTime = 0;
		static int spitInTime = 0;
		static float oldGyro = 0;


		switch(OTBDrive)
		{
			case ROADTOAIM:
				if(LEncoder < 1765)
				{
					Drive = DRIVESTRAIGHT;
					yStick = -0.825;
				}
				if(LEncoder >= 1765)
				{
					OTBFunc = PREPARETOAIM;
					yStick = 0.0;
				}
				break; // End of ROADTOAIM
			case ROADTOBALL:
				if(armBackCount < 50)
				{
					armBackCount++;
					ArmMotor = -1.0;
				}
				if(armBackCount >= 50)
				{
					ArmMotor = 0.0;
				}
				if(completeTurn == 0)
				{
					Drive = NOSTRAIGHT;
					xStick = -0.6;
					if(gyro1 >= (-oldGyro - AADest))
					{
						SmartDashboard::PutNumber("oldGyro", oldGyro);
						xStick = 0.0;
						completeTurn = 1;
					}
				}
				if(completeTurn)
				{
					if(encoderReset == 0)
					{
						encoderResetCnt++;
						if(encoderResetCnt >= 7)
						{
							pGyro->Reset();
						}
						if(encoderResetCnt >= 10)
						{
							encoderReset = 1;
						}
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.825;
					if(LEncoder <= 575)
					{
						OTBFunc = GRABBALL;
					}
					if(LEncoder <= 35) // -10
					{
						yStick = 0.0;
					}
				}
				break; // End of ROADTOBALL
			case LASTROAD:
					Drive = DRIVESTRAIGHT;
					yStick = -0.95;
				if(LEncoder >= 1765)
				{
					armCount = 0;
					goingBack = 0;
					OTBFunc = PREPARETOAIM;
					yStick = 0.0;
				}
				break; // End of LASTROAD
			case NOTHING:

				break; // End of NOTHING
		}
		switch(OTBFunc)
		{
			case PREPARETOAIM:
				OTBDrive = NOTHING;
				if(armCount < 40)
				{
					armCount++;
					ArmMotor = 1.0;
				}
				if(armCount >= 40)
				{
					ArmMotor = 0.0;
					OTBFunc = OTBAUTOAIM;
				}
				break; // End of PREPARETOAIM
			case OTBAUTOAIM:
				if(goingBack == 0)
				{
					if(gyroOnce == 0)
					{
						oldGyro = gyro1;
						gyroOnce = 1;
					}

					Drive = NOSTRAIGHT;
					AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);
					if(AirSwitch)
					{
						shotTime++;
						if(shotTime >= 4)
						{
							AirSwitch = 0;
						}
						if(shotTime >= 6)
						{
							goingBack = 1;
						}
					}
				}
				else
				{
					TrueCounter = 0;
					Destination = 0;
					OneTrack = 0;
					AirSwitch = 0;
					shotTime = 0;
				}

				if(goingBack)
				{
					camSwitch = 1;
					OTBDrive = ROADTOBALL;
				}
				break; // End of AUTOAIM
			case PREPARETOCROSS:
				if(armBackCount < 50)
				{
					armBackCount++;
					ArmMotor = -1.0;
					OTBDrive = ROADTOBALL;
				}
				if(armBackCount >= 50)
				{
					ArmMotor = 0.0;
				}

				break; // End of PREPARETOCROSS
			case GRABBALL:
				if(securedBallOne == 0)
				{
					Clamp = 1;
					IntakeMotor = 1.0;

					if(droppedIt == 0)
					{
						if(armGrabCount < 50)
						{
							armGrabCount++;
							ArmMotor = 1.0;
						}
						if(armGrabCount >= 50)
						{
							ArmMotor = 0.0;
							droppedIt = 1;
						}
					}
					if(Beam >= 3.0 && BBOnce == 0)
					{
						ballSeen = 1;
						BBOnce = 1;
					}
					if(ballSeen)
					{
						intakeCount++;
						armSnatchedTime++;
						if(intakeCount >= 15)
						{
							OTBDrive = LASTROAD;
							IntakeMotor = 0.0;

						}

						if(armSnatchedTime >= 10)
						{
							Clamp = 1;
							ArmMotor = -1.0;
							grabBackCount++;
							if(grabBackCount >= 30)
							{
								Clamp = 0;
								IntakeMotor = 1.0;
								ArmMotor = 0.0;
								if(Beam <= 3.0)
								{
									spitInTime++;
									if(spitInTime >= 15)
									{
										ArmMotor = 1.0;
										IntakeMotor = 0.0;
									}
									if(spitInTime >= 30)
									{
										ballSeen = 0;
										securedBallOne = 1;
									}
								}
							}
						}
					}
				}
				break; // End of GRABBALL
			case NOTHINGFUNC:

				break; // End of NOTHINGFUNC
		}
		return SubRoute;
	} // end of p7

	unsigned int PositionSevenThree(unsigned int &Drive, bool &OneTrack, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp, float &Destination, int &TrueCounter,bool &camSwitch, float &IntakeMotor, float &Beam)
	{
		static bool goingBack = 0;
		static bool droppedIt = 0;
		static bool BBOnce = 0;
		static bool ballSeen = 0;
		static bool securedBallOne = 0;
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gyroOnce = 0;
		static int encoderResetCnt = 0;
		static int armCount = 0;
		static int armBackCount = 0;
		static int armGrabCount = 0;
		static int grabBackCount = 0;
		static int shotTime = 0;
		static int intakeCount = 0;
		static int armSnatchedTime = 0;
		static int spitInTime = 0;
		static float oldGyro = 0;


		switch(OTBDrive)
		{
			case ROADTOAIM:
				if(LEncoder < 1765)
				{
					Drive = DRIVESTRAIGHT;
					yStick = -0.825;
				}
				if(LEncoder >= 1765)
				{
					OTBFunc = PREPARETOAIM;
					yStick = 0.0;
				}
				break; // End of ROADTOAIM
			case ROADTOBALL:
				if(armBackCount < 50)
				{
					armBackCount++;
					ArmMotor = -1.0;
				}
				if(armBackCount >= 50)
				{
					ArmMotor = 0.0;
				}
				if(completeTurn == 0)
				{
					Drive = NOSTRAIGHT;
					xStick = 0.6;
					if(gyro1 <= (oldGyro - AADest))
					{
						SmartDashboard::PutNumber("oldGyro", oldGyro);
						xStick = 0.0;
						completeTurn = 1;
					}
				}
				if(completeTurn)
				{
					if(encoderReset == 0)
					{
						encoderResetCnt++;
						if(encoderResetCnt >= 7)
						{
							pGyro->Reset();
						}
						if(encoderResetCnt >= 10)
						{
							encoderReset = 1;
						}
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.825;
					if(LEncoder <= 575)
					{
						OTBFunc = GRABBALL;
					}
					if(LEncoder <= 35) // -10
					{
						yStick = 0.0;
					}
				}
				break; // End of ROADTOBALL
			case LASTROAD:
					Drive = DRIVESTRAIGHT;
					yStick = -0.95;
				if(LEncoder >= 1765)
				{
					armCount = 0;
					goingBack = 0;
					OTBFunc = PREPARETOAIM;
					yStick = 0.0;
				}
				break; // End of LASTROAD
			case NOTHING:

				break; // End of NOTHING
		}
		switch(OTBFunc)
		{
			case PREPARETOAIM:
				OTBDrive = NOTHING;
				if(armCount < 40)
				{
					armCount++;
					ArmMotor = 1.0;
				}
				if(armCount >= 40)
				{
					ArmMotor = 0.0;
					OTBFunc = OTBAUTOAIM;
				}
				break; // End of PREPARETOAIM
			case OTBAUTOAIM:
				if(goingBack == 0)
				{
					if(gyroOnce == 0)
					{
						oldGyro = gyro1;
						gyroOnce = 1;
					}

					Drive = NOSTRAIGHT;
					AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);
					if(AirSwitch)
					{
						shotTime++;
						if(shotTime >= 4)
						{
							AirSwitch = 0;
						}
						if(shotTime >= 6)
						{
							goingBack = 1;
						}
					}
				}
				else
				{
					TrueCounter = 0;
					Destination = 0;
					OneTrack = 0;
					AirSwitch = 0;
					shotTime = 0;
				}

				if(goingBack)
				{
					camSwitch = 1;
					OTBDrive = ROADTOBALL;
				}
				break; // End of AUTOAIM
			case PREPARETOCROSS:
				if(armBackCount < 50)
				{
					armBackCount++;
					ArmMotor = -1.0;
					OTBDrive = ROADTOBALL;
				}
				if(armBackCount >= 50)
				{
					ArmMotor = 0.0;
				}

				break; // End of PREPARETOCROSS
			case GRABBALL:
				if(securedBallOne == 0)
				{
					Clamp = 1;
					IntakeMotor = 1.0;

					if(droppedIt == 0)
					{
						if(armGrabCount < 50)
						{
							armGrabCount++;
							ArmMotor = 1.0;
						}
						if(armGrabCount >= 50)
						{
							ArmMotor = 0.0;
							droppedIt = 1;
						}
					}
					if(Beam >= 3.0 && BBOnce == 0)
					{
						ballSeen = 1;
						BBOnce = 1;
					}
					if(ballSeen)
					{
						intakeCount++;
						armSnatchedTime++;
						if(intakeCount >= 15)
						{
							OTBDrive = LASTROAD;
							IntakeMotor = 0.0;

						}

						if(armSnatchedTime >= 10)
						{
							Clamp = 1;
							ArmMotor = -1.0;
							grabBackCount++;
							if(grabBackCount >= 30)
							{
								Clamp = 0;
								IntakeMotor = 1.0;
								ArmMotor = 0.0;
								if(Beam <= 3.0)
								{
									spitInTime++;
									if(spitInTime >= 15)
									{
										ArmMotor = 1.0;
										IntakeMotor = 0.0;
									}
									if(spitInTime >= 30)
									{
										ballSeen = 0;
										securedBallOne = 1;
									}
								}
							}
						}
					}
				}
				break; // End of GRABBALL
			case NOTHINGFUNC:

				break; // End of NOTHINGFUNC
		}
		return SubRoute;
	} // end of p7,3


	unsigned int PositionEight(unsigned int &Drive, bool &OneTrack, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot, bool &AirSwitch, float &ArmMotor, bool &Clamp, float &Destination, int &TrueCounter,bool &camSwitch, float &IntakeMotor, float &Beam, bool &Action, bool &ActionSTP)
	{
		static bool ballSeen = 0;
		static bool ballSeenTwo = 0;
		static bool securedBallOne = 0;
		static bool securedBallTwo = 0;
		static bool madeTurn = 0;
		static bool aimTurned = 0;
		static bool reachShot = 0;
		static bool goingBack = 0;
		static bool aimTurnedTwo = 0;
		static bool reachShotTwo = 0;
		static bool goingBackTwo = 0;
		static bool speedCheck = 0;
		static bool turnCheck = 0;
		static bool doneTurnToLB = 0;
		static bool bopIt = 0;
		static bool droppedIt = 0;
		static bool gyroResetOnce = 0;
		static bool bopItTwo = 0;
		static bool checkUno = 0;
		static bool BBOnce = 0;
		static bool BBDuo = 0;
		static bool quickAct = 0;
		static bool encoderReset = 0;
 		static int armCount = 0;
		static int intakeCount = 0;
		static int intakeCountTwo = 0;
		static int shotTime = 0;
		static int turnCount = 0;
		static int turnCountTwo = 0;
		static int oldGyro = 0;
		static int spitInTime = 0;
		static int backArmTime = 0;
		static int armSnatchedTime = 0;
		static int quickActTime = 0;
		static int encoderResetCnt = 0;
		static int leftIntakeCnt = 0;
		static int leftIntakeCntTwo = 0;
		static int spitInTimeTwo = 0;
		static int backArmTimeTwo = 0;
		static int armSnatchedTimeTwo = 0;


		switch(TBFunc)
		{
			case DROPNSNATCH:
//			if(securedBallOne == 0)
//			{
//				Action = 1;
//				Clamp = 1;
//				IntakeMotor = 1.0;
//
//				if(droppedIt == 0)
//				{
//					if(armCount <= 45)
//					{
//						ArmMotor = 1.0;
//						armCount++;
//					}
//					if(armCount >= 45)
//					{
//						ArmMotor = 0.0;
//						droppedIt = 1;
//					}
//				}
//					if(Beam >= 3.0)
//					{
//						ballSeen = 1;
//					}
//				if(ballSeen)
//				{
//					TBDrive = TURNTOLOWBAR;
//					intakeCount++;
//					if(bopIt == 0)
//					{
//						if(intakeCount >= 20)
//						{
//							ArmMotor = -0.8;
//						}
//						if(intakeCount >= 50)
//						{
//							ArmMotor = .8;
//						}
//						if(intakeCount >= 60)
//						{
//							ArmMotor = 0.0;
//							bopIt = 1;
//						}
//					}
//					if(intakeCount >= 65)
//					{
//						IntakeMotor = 0.0;
//						Clamp = 0;
//						ballSeen = 0;
//						securedBallOne = 1;
//					}
//				}
//			}

				if(securedBallOne == 0)
				{
					quickActTime++;
					if(quickActTime >= 1 && quickAct == 0)
					{
						Action = 1;
					}
					if(quickActTime >= 10)
					{
						Action = 0;
						quickAct = 1;
					}
					if(quickAct && quickActTime >= 18)
					{
						Action = 1;
					}
					Clamp = 1;
					IntakeMotor = 1.0;

					if(droppedIt == 0)
					{
						if(armCount <= 45)
						{
							ArmMotor = 0.8;
							armCount++;
						}
						if(armCount >= 20)
						{
							ArmMotor = 0.6;
						}
						if(armCount >= 45)
						{
							ArmMotor = 0.0;
							droppedIt = 1;
						}
					}
					if(Beam >= 3.0 && BBOnce == 0)
					{
						ballSeen = 1;
						BBOnce = 1;
					}
					if(ballSeen)
					{
						intakeCount++;
						armSnatchedTime++;
						if(intakeCount >= 15)
						{
							IntakeMotor = 0.0;
						}
							TBDrive = TURNTOLOWBAR;
						if(armSnatchedTime >= 10)
						{
							Clamp = 1;
							ArmMotor = -1.0;
							backArmTime++;
							if(backArmTime >= 30)
							{
								Clamp = 0;
								IntakeMotor = 1.0;
								ArmMotor = 0.0;
								leftIntakeCnt++;
								if(leftIntakeCnt >= 15)
								{
									spitInTime++;
									if(spitInTime >= 10)
									{
										ArmMotor = 1.0;
										IntakeMotor = 0.0;
									}
									if(spitInTime >= 35)
									{
										ArmMotor = 0.0;
										ballSeen = 0;
										securedBallOne = 1;
									}
								}
							}
						}
					}
					//					TBDrive = TURNTOLOWBAR;
					//					intakeCount++;
					//					if(bopIt == 0)
					//					{
					//						if(intakeCount >= 20)
					//						{
					//							ArmMotor = -0.8;
					//						}
					//						if(intakeCount >= 50)
					//						{
					//							ArmMotor = .8;
					//						}
					//						if(intakeCount >= 60)
					//						{
					//							ArmMotor = 0.0;
					//							bopIt = 1;
					//						}
					//					}
					//					if(intakeCount >= 65)
					//					{
					//						IntakeMotor = 0.0;
					//						Clamp = 0;
					//						ballSeen = 0;
					//						securedBallOne = 1;
					//					}
					//				}
								}
			break;// end of DROPNSNATCH

			case TURNTOAUTOAIM:
				if(aimTurned == 0)
				{
					TBDrive = NOTHINGDRIVE;
					if(turnCount <= 10) turnCount++;
					if(turnCount >= 10)
					{
						Drive = NOSTRAIGHT;
						yStick = 0.0;
						xStick = 0.6;
						if(gyro1 <= -30)
						{
							xStick = 0.0;
							oldGyro = gyro1;
							reachShot = 1;
							aimTurned = 1;
						}
					}
				}
				if(reachShot && goingBack == 0)
				{
					Drive = NOSTRAIGHT;
					AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);

					if(AirSwitch)
					{
						shotTime++;
						if(shotTime >= 3)
						{
							AirSwitch = 0;
						}
						if(shotTime >= 5)
						{
							goingBack = 1;
						}
					}
				}
				else
				{

					TrueCounter = 0;
					Destination = 0;
					OneTrack = 0;
					AirSwitch = 0;
					shotTime = 0;
				}
				if(goingBack)
				{
					TBDrive = GOINGBACK;
					TBFunc = NOTHINGNESS;
				}
			break;// end of TURNTOAUTOAIM

			case BALLGRABTWO:
//				if(securedBallTwo == 0)
//				{
//					IntakeMotor = 1.0;
//					if(Beam >= 3.0)
//					{
//						ballSeenTwo = 1;
//						Clamp = 1;
//					}
//					if(ballSeenTwo)
//					{
//						//if(gyroResetOnce == 0) pGyro->Reset();
//						TBDrive = GOINGBACKWBALL;
//						intakeCountTwo++;
//						if(bopItTwo == 0)
//						{
//							if(intakeCountTwo >= 20)
//							{
//								ArmMotor = -0.8;
//							}
//							if(intakeCountTwo >= 50)
//							{
//								ArmMotor = .8;
//							}
//							if(intakeCountTwo >= 70)
//							{
//								ArmMotor = 0.0;
//								bopItTwo = 1;
//							}
//						}
//						if(intakeCountTwo >= 80)
//						{
//							IntakeMotor = 0.0;
//							Clamp = 0;
//							ballSeenTwo = 0;
//							securedBallTwo = 1;
//						}
//					}
//				}
				if(securedBallTwo == 0)
				{
					Clamp = 1;
					IntakeMotor = 1.0;

					if(Beam >= 3.0 && BBDuo == 0)
					{
						ballSeenTwo = 1;
						BBDuo = 1;
					}
					if(ballSeenTwo)
					{
						intakeCountTwo++;
						armSnatchedTimeTwo++;
						if(intakeCountTwo >= 15)
						{
							IntakeMotor = 0.0;
						}
							TBDrive = TURNTOLOWBAR;
						if(armSnatchedTimeTwo >= 10)
						{
							Clamp = 1;
							ArmMotor = -1.0;
							backArmTimeTwo++;
							if(backArmTimeTwo >= 30)
							{
								Clamp = 0;
								IntakeMotor = 1.0;
								ArmMotor = 0.0;
								leftIntakeCntTwo++;
								if(leftIntakeCntTwo >= 15)
								{
									spitInTimeTwo++;
									if(spitInTimeTwo >= 10)
									{
										ArmMotor = 1.0;
										IntakeMotor = 0.0;
									}
									if(spitInTimeTwo >= 35)
									{
										ArmMotor = 0.0;
										ballSeenTwo = 0;
										securedBallTwo = 1;
									}
								}
							}
						}
					}
				}

			break; // end of BALLGRABTWO

			case TURNTOAUTOAIMTWO:
				camSwitch = 1;
				if(aimTurnedTwo == 0)
				{
					TBDrive = NOTHINGDRIVE;
					Drive = NOSTRAIGHT;
					if(turnCountTwo < 10) turnCountTwo++;
					if(turnCountTwo >= 10)
					{
						yStick = 0.0;
						xStick = 0.6;
						if(gyro1 <= -30)
						{
							xStick = 0.0;
							oldGyro = gyro1;
							reachShotTwo = 1;
							aimTurnedTwo = 1;
						}
					}
				}
				if(reachShotTwo && goingBackTwo == 0)
				{
					Drive = NOSTRAIGHT;
					AutoAim(Drive, OneTrack, Destination, TrueCounter, camSwitch, xStick, gyro, AirSwitch, Clamp);

					if(AirSwitch)
					{
						shotTime++;
						if(shotTime >= 3)
						{
							AirSwitch = 0;
						}
						if(shotTime >= 5)
						{
							goingBackTwo = 1;
						}
					}
				}
				else
				{
					TrueCounter = 0;
					Destination = 0;
					OneTrack = 0;
					AirSwitch = 0;
					shotTime = 0;
				}
				if(goingBackTwo)
				{
					TBDrive = GOINGBACK;
					TBFunc = NOTHINGNESS;
				}
			break;// end of TURNTOAUTOAIMTWO
			case NOTHINGNESS:
			break; // end of nothingness
		}// end of switch TBFunc

		switch(TBDrive)
		{
			case TURNTOLOWBAR:
				if(doneTurnToLB == 0)
				{
					if(madeTurn == 0) Drive = NOSTRAIGHT;
					yStick = -0.9;
					xStick = -0.75;
					if(gyro1 >= 35 && madeTurn == 0)
					{
						xStick = 0.0;
						madeTurn = 1;
					}
					if(madeTurn)
					{
						xStick = 0.75;
						if(gyro1 <= 0)
						{
							xStick = 0.0;
							yStick = -0.85;
							Drive = DRIVESTRAIGHT;
						}
					}
					if(LEncoder >= 2200)
					{
						yStick = 0.0;
						xStick = 0.0;
						TBFunc = TURNTOAUTOAIM;
						doneTurnToLB = 1;
					}
				}

			break;// end of TURNTOLOWBAR

			case GOINGBACK:
				if(turnCheck == 0)
				{
					Drive = NOSTRAIGHT;
					//yStick = 0.375;
					Clamp = 1;
					xStick = -0.675;
					if(gyro1 >= (33 - AADest))
					{
						xStick = 0.0;
						turnCheck = 1;
					}
				}
				if(encoderReset == 0 && turnCheck)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 7)
					{
						pGyro->Reset();
					}
					if(encoderResetCnt >= 10)
					{
						encoderReset = 1;
					}
				}
				if(speedCheck == 0 && encoderReset)
				{
					if(turnCheck)
					{
						Drive = DRIVESTRAIGHT;
						yStick = 0.875;
					}
					if(LEncoder <= 700)
					{
						//yStick = 0.775;
						TBFunc = BALLGRABTWO;
					}
					if(LEncoder <= 300)
					{
						//yStick = 0.70;
					}
					if(LEncoder <= 100)
					{
						yStick = 0.0;
						speedCheck = 1;
					}
				}
			break; // end of GOINGBACK

			case GOINGBACKWBALL:
				Drive = DRIVESTRAIGHT;
				Clamp = 0;
				yStick = -0.9;
				if(LEncoder >= 1500)
				{
					yStick = -1.0;
				}
				if(LEncoder >= 2100)
				{
					yStick = 0.0;
					TBFunc = TURNTOAUTOAIMTWO;
				}
			break; // GOINGBACKWBALL
			case NOTHINGDRIVE:
			break; // end of nothing
		}// end of switch TBDrive
		SmartDashboard::PutNumber("globNoName", globNoName);
		return SubRoute;
	}// end of PositionEight
	//TODO: GOBACK SUBROUTINES
	unsigned int GoBackPosOne(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{ // pos one is undesired to return to neutral. usage could be used for draw bridge auto. otherwise this whole subroutine can be removed
		return SubRoute;
	}
	unsigned int GoBackPosTwo(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosTwoTurn = 51;

		if(autonSelect == 2)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosTwoTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}

		}
		if(autonSelect == 5)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosTwoTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 6)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosTwoTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 7)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosTwoTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackPosThree(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//---Turn Constants
		static int PosThreeTurn = 16;

		if(autonSelect == 2)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosThreeTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
				if(completeTurn)
				{
					armCount++;
					ArmMotor = -1.0;
					if(armCount >= 60)
					{
						ArmMotor = 0.0;
					}
					if(encoderReset == 0)
					{
						encoderResetCnt++;
						if(encoderResetCnt >= 15)
						{
							DriveEncoderR->Reset();
							DriveEncoderL->Reset();
							pGyro->Reset();
							encoderReset = 1;
						}
					}
					if(encoderReset)
					{
						Drive = DRIVESTRAIGHT;
						yStick = 0.95;
						if(gearCheck == 0)
						{
							if(LEncoder <= -150) HighGear = 0;
							if(LEncoder <= -1700)
							{
								HighGear = 1;
								gearCheck = 1;
							}
						}
						if(LEncoder <= -2550)
						{
							yStick = -0.375;
							floorItBackCnt++;
							if(floorItBackCnt >= 5)
							{
								yStick = 0.0;
							}
						}
					}
				}
			}
		}
		if(autonSelect == 5)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosThreeTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}

		}
		if(autonSelect == 6)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosThreeTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					//Drive = STRAIGHTENCODER;
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 7)
		{
			if(completeTurn == 0)
			{
				xStick = -0.625;
				if(gyro1 >= (PosThreeTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackPosFour(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		// Turn Constants
		static int PosFourTurn = -12;

		if(autonSelect == 2)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFourTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 5)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFourTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 6)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFourTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 7)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFourTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackPosFive(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		// Turn Constants
		static int PosFiveTurn = -50;
		if(autonSelect == 2) // GobackRoughTerrian
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFiveTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 5)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFiveTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 6)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFiveTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
			if(completeTurn)
			{
				armCount++;
				ArmMotor = -1.0;
				if(armCount >= 60)
				{
					ArmMotor = 0.0;
				}
				if(encoderReset == 0)
				{
					encoderResetCnt++;
					if(encoderResetCnt >= 15)
					{
						DriveEncoderR->Reset();
						DriveEncoderL->Reset();
						pGyro->Reset();
						encoderReset = 1;
					}
				}
				if(encoderReset)
				{
					Drive = DRIVESTRAIGHT;
					yStick = 0.95;
					if(gearCheck == 0)
					{
						if(LEncoder <= -150) HighGear = 0;
						if(LEncoder <= -1700)
						{
							HighGear = 1;
							gearCheck = 1;
						}
					}
					if(LEncoder <= -2550)
					{
						yStick = -0.375;
						floorItBackCnt++;
						if(floorItBackCnt >= 5)
						{
							yStick = 0.0;
						}
					}
				}
			}
		}
		if(autonSelect == 7)
		{
			if(completeTurn == 0)
			{
				xStick = 0.625;
				if(gyro1 <= (PosFiveTurn - AADest))
				{
					xStick = 0.0;
					completeTurn = 1;
				}
			}
		}
		return SubRoute;
	}
	//TODO: GO BACK FOR SALLY AND DRAWBRIDGE

	unsigned int GoBackONEToTWO(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosOneTurn = 57;
		if(completeTurn == 0)
		{
			xStick = -0.65;
			if(gyro1 >= (PosOneTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.95;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;
				}
				if(LEncoder <= -2600)
				{
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackTWOToTHREE(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosTwoTurn = 75;
		if(completeTurn == 0)
		{
			xStick = -0.65;
			if(gyro1 >= (PosTwoTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.935;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;

					if(LEncoder <= -1300)
					{
						arcIT = 1;
					}
				}
				if(arcIT && doneArc == 0)
				{
					yStick = 0.835;
					Drive = NOSTRAIGHT;
					xStick = 0.72;
					if(gyro1 <= -15)
					{
						xStick = 0.0;
						doneArc = 1;
					}
				}
				if(LEncoder <= -2600)
				{
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackTHREEToTWO(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosFourTurn = -12;
		if(completeTurn == 0)
		{
			xStick = 0.625;
			if(gyro1 <= (PosFourTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.935;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;

					if(LEncoder <= -850)
					{
						arcIT = 1;
					}
				}
				if(arcIT && doneArc == 0)
				{
					yStick = 0.83;
					Drive = NOSTRAIGHT;
					xStick = -0.725;
					if(gyro1 >= 10)
					{
						xStick = 0.0;
						doneArc = 1;
					}
				}
				if(LEncoder <= -2050)
				{
					HighGear = 1;
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
	}
	unsigned int GoBackTHREEToFOUR(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosThreeTurn = 47;
		if(completeTurn == 0)
		{
			xStick = -0.625;
			if(gyro1 >= (PosThreeTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.935;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;

					if(LEncoder <= -900)
					{
						arcIT = 1;
					}
				}
				if(arcIT && doneArc == 0)
				{
					yStick = 0.83;
					Drive = NOSTRAIGHT;
					xStick = 0.725;
					if(gyro1 <= -13)
					{
						xStick = 0.0;
						doneArc = 1;
					}
				}
				if(LEncoder <= -2000)
				{
					HighGear = 1;
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
	return SubRoute;
	}
	unsigned int GoBackFOURToTHREE(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosFourTurn = -47;
		if(completeTurn == 0)
		{
			xStick = 0.625;
			if(gyro1 <= (PosFourTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.935;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;

					if(LEncoder <= -900)
					{
						arcIT = 1;
					}
				}
				if(arcIT && doneArc == 0)
				{
					yStick = 0.83;
					Drive = NOSTRAIGHT;
					xStick = -0.725;
					if(gyro1 >= 10)
					{
						xStick = 0.0;
						doneArc = 1;
					}
				}
				if(LEncoder <= -1800)
				{
					HighGear = 1;
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackFOURToFIVE(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosThreeTurn = 10;
		if(completeTurn == 0)
		{
			xStick = -0.625;
			if(gyro1 >= (PosThreeTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.935;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;

					if(LEncoder <= -800)
					{
						arcIT = 1;
					}
				}
				if(arcIT && doneArc == 0)
				{
					yStick = 0.83;
					Drive = NOSTRAIGHT;
					xStick = 0.725;
					if(gyro1 <= -10)
					{
						xStick = 0.0;
						doneArc = 1;
					}
				}
				if(LEncoder <= -1800)
				{
					HighGear = 1;
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
		return SubRoute;
	}
	unsigned int GoBackFIVEToFOUR(int &autonSelect, unsigned int &Drive, float &yStick, float &xStick, float &gyro1, int &LEncoder, float &ArmMotor, bool &Action, bool &stopDrop, float &IntakeMotor, float &Beam, bool &Clamp, bool &ActionSTP, bool &HighGear)
	{
		static bool completeTurn = 0;
		static bool encoderReset = 0;
		static bool gearCheck = 0;
		static bool turnUno = 0;
		static bool turnTwo = 0;
		static bool backReady = 0;
		static bool arcIT = 0;
		static bool doneArc = 0;
		static int armCount = 0;
		static int encoderResetCnt = 0;
		static int floorItBackCnt = 0;

		//turn constants
		static int PosFourTurn = -72;
		if(completeTurn == 0)
		{
			xStick = 0.625;
			if(gyro1 <= (PosFourTurn - AADest))
			{
				xStick = 0.0;
				completeTurn = 1;
			}
		}
		if(completeTurn)
		{
			armCount++;
			ArmMotor = -1.0;
			if(armCount >= 60)
			{
				ArmMotor = 0.0;
			}
			if(encoderReset == 0)
			{
				encoderResetCnt++;
				if(encoderResetCnt >= 7)
				{
					DriveEncoderR->Reset();
					DriveEncoderL->Reset();
					pGyro->Reset();
				}
				if(encoderResetCnt >= 10)
				{
					encoderReset = 1;
				}
			}
			if(encoderReset)
			{
				yStick = 0.935;
				if(arcIT == 0)
				{
					HighGear = 0;
					Drive = DRIVESTRAIGHT;

					if(LEncoder <= -1250)
					{
						arcIT = 1;
					}
				}
				if(arcIT && doneArc == 0)
				{
					yStick = 0.83;
					Drive = NOSTRAIGHT;
					xStick = -0.725;
					if(gyro1 >= 10)
					{
						xStick = 0.0;
						doneArc = 1;
					}
				}
				if(LEncoder <= -1900)
				{
					HighGear = 1;
					yStick = -0.375;
					floorItBackCnt++;
					if(floorItBackCnt >= 5)
					{
						yStick = 0.0;
					}
				}
			}
		}
	}

	//TODO: MISC
	unsigned int PosTwoLong(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		static int turnCount = 0;
		yStick = -0.7;
		if(LEncoder >= 1500)
		{
			yStick = 0.0;
			reachTurn = 1;
		}
		if(reachTurn)
		{
			turnCount++;
			if(turnCount >= 70)
			{
				CloseShot = 0;
				Drive = NOSTRAIGHT;
				xStick = 0.625;
				if(gyro1 <= -25)
				{
					xStick = 0.0;
					SubRoute = SUB3;
				}
			}
		}
		return SubRoute;
	}
	unsigned int PosFiveLong(unsigned int &Drive, float &xStick, float &yStick, int &LEncoder, float &gyro1, bool &CloseShot)
	{
		static bool reachTurn = 0;
		static int turnCount = 0;
		yStick = -0.7;
		if(LEncoder >= 1500)
		{
			yStick = 0.0;
			reachTurn = 1;
		}
		if(reachTurn)
		{
			turnCount++;
			if(turnCount >= 70)
			{
				CloseShot = 0;
				Drive = NOSTRAIGHT;
				xStick = -0.625;
				if(gyro1 >= 20)
				{
					xStick = 0.0;
					SubRoute = SUB3;
				}
			}
		}
		return SubRoute;
	}
	//--------------------------------------------------------
	//--------------------------------------------------------

	//****************************************************
	bool doVision()
	{
		// grab an image, draw the circle, and provide it for the camera server which will
		// in turn send it to the dashboard.
#ifdef AXISCAMERA
		camera->GetImage(frame);
		//			imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);

		CameraServer::GetInstance()->SetImage(frame);
#endif
#ifdef USBCAMERA
		// grab an image, draw the circle, and provide it for the camera server which will
		// in turn send it to the dashboard.
		//		IMAQdxGrab(session, frame, true, NULL);
		cam0->GetImage(frame);
		//		imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		CameraServer::GetInstance()->SetImage(frame);
#endif
		return 0;
	}
	//***********

	bool doVisionWithProcessing()
	{

		// grab an image, draw the circle, and provide it for the camera server which will
		// in turn send it to the dashboard.
#ifdef AXISCAMERA
		camera->GetImage(frame);
		//			imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
#endif
#ifdef USBCAMERA
		// grab an image, draw the circle, and provide it for the camera server which will
		// in turn send it to the dashboard.
		//		IMAQdxGrab(session, frame, true, NULL);
		cam0->GetImage(frame);

		//		imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);

		//		CameraServer::GetInstance()->SetImage(frame);

#endif
#ifdef CAMERA
#ifdef CALIBRATECAMERA
		//Update threshold values from SmartDashboard. For performance reasons it is recommended to remove this after calibration is finished.
		RING_HUE_RANGE.minValue = SmartDashboard::GetNumber("Tote hue min", RING_HUE_RANGE.minValue);
		RING_HUE_RANGE.maxValue = SmartDashboard::GetNumber("Tote hue max", RING_HUE_RANGE.maxValue);
		RING_SAT_RANGE.minValue = SmartDashboard::GetNumber("Tote sat min", RING_SAT_RANGE.minValue);
		RING_SAT_RANGE.maxValue = SmartDashboard::GetNumber("Tote sat max", RING_SAT_RANGE.maxValue);
		RING_VAL_RANGE.minValue = SmartDashboard::GetNumber("Tote val min", RING_VAL_RANGE.minValue);
		RING_VAL_RANGE.maxValue = SmartDashboard::GetNumber("Tote val max", RING_VAL_RANGE.maxValue);
#endif
		//change from normal image to processed image based on input from SmartDashboard
		//comment this out and pick one for competition
		seebinary = SmartDashboard::GetNumber("See Binary", seebinary);

		imaqError = imaqColorThreshold(binaryFrame, frame, 255, IMAQ_HSV, &RING_HUE_RANGE, &RING_SAT_RANGE, &RING_VAL_RANGE);

		//Send particle count to dashboard
		//int numParticles = 0;
		imaqError = imaqCountParticles(binaryFrame, 1, &numParticles);
		SmartDashboard::PutNumber("Masked particles", numParticles);


		//filter out small particles
		areaMin = SmartDashboard::GetNumber("Area min %", AREA_MINIMUM);
		criteria[0] = {IMAQ_MT_AREA_BY_IMAGE_AREA, areaMin, 100, false, false};
		imaqError = imaqParticleFilter4(binaryFrame, binaryFrame, criteria, 1, &filterOptions, NULL, NULL);


		//move this lower in the code to see more processing
		if (seebinary)
		{
			//Send masked image to dashboard to assist in tweaking mask.
			CameraServer::GetInstance()->SetImage(binaryFrame);
			//SendToDashboard(binaryFrame, imaqError);
		}else
		{
			//send normal image
			//imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
			CameraServer::GetInstance()->SetImage(frame);
			//SendToDashboard(frame, imaqError);
		}

		//Send particle count after filtering to dashboard
		imaqError = imaqCountParticles(binaryFrame, 1, &numParticles);
		SmartDashboard::PutNumber("Filtered particles", numParticles);

		if(numParticles > 0) {
			//Measure particles and sort by particle size
			std::vector<ParticleReport> particles;
			for(int particleIndex = 0; particleIndex < numParticles; particleIndex++)
			{
				ParticleReport par;
				imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_AREA_BY_IMAGE_AREA, &(par.PercentAreaToImageArea));
				imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_AREA, &(par.Area));
				imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_TOP, &(par.BoundingRectTop));
				imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_LEFT, &(par.BoundingRectLeft));
				imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_BOTTOM, &(par.BoundingRectBottom));
				imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_RIGHT, &(par.BoundingRectRight));
				particles.push_back(par);

			}
			sort(particles.begin(), particles.end(), CompareParticleSizes);

			//This example only scores the largest particle. Extending to score all particles and choosing the desired one is left as an exercise
			//for the reader. Note that this scores and reports information about a single particle (single L shaped target). To get accurate information
			//about the location of the tote (not just the distance) you will need to correlate two adjacent targets in order to find the true center of the tote.
			scores.Aspect = AspectScore(particles.at(0));
			SmartDashboard::PutNumber("Aspect", scores.Aspect);
			scores.Area = AreaScore(particles.at(0));
			SmartDashboard::PutNumber("Area", scores.Area);
			isTarget = scores.Area > SCORE_MIN && scores.Aspect > SCORE_MIN;

			//Send distance and tote status to dashboard. The bounding rect, particularly the horizontal center (left - right) may be useful for rotating/driving towards a tote
			SmartDashboard::PutBoolean("IsTarget", isTarget);
			SmartDashboard::PutNumber("Distance", computeDistance(binaryFrame, particles.at(0)));
			//double TargetAngle = 0;

			TargetAngle = 0.1625 * computeAngle(binaryFrame, particles.at(0));  //was 0.161


			SmartDashboard::PutNumber("Target Angle", TargetAngle);

			return isTarget;
		} else {
			SmartDashboard::PutBoolean("IsTarget", false);
			return isTarget;
		}
#endif
	}


	//Send image to dashboard if IMAQ has not thrown an error
	void SendToDashboard(Image *image, int error)
	{
		if(error < ERR_SUCCESS) {
			DriverStation::ReportError("Send To Dashboard error: " + std::to_string((long)imaqError) + "\n");
		} else {
			CameraServer::GetInstance()->SetImage(image);
		}
	}

	//Comparator function for sorting particles. Returns true if particle 1 is larger
	static bool CompareParticleSizes(ParticleReport particle1, ParticleReport particle2)
	{
		//we want descending sort order
		return particle1.PercentAreaToImageArea > particle2.PercentAreaToImageArea;
	}

	/**
	 * Converts a ratio with ideal value of 1 to a score. The resulting function is piecewise
	 * linear going from (0,0) to (1,100) to (2,0) and is 0 for all inputs outside the range 0-2
	 */
	double ratioToScore(double ratio)
	{
		return (fmax(0, fmin(100*(1-fabs(1-ratio)), 100)));
	}


	double AreaScore(ParticleReport report)
	{
		double boundingArea = (report.BoundingRectBottom - report.BoundingRectTop) * (report.BoundingRectRight - report.BoundingRectLeft);
		//Area of Rect is 240.  Tape is 80sq inches of this
		return ratioToScore((AREA_RATIO)*report.Area/boundingArea);
	}

	/**
	 * Method to score if the aspect ratio of the particle appears to match the retro-reflective target. Target is 12"W x 20"H so aspect should be 1.6
	 */
	double AspectScore(ParticleReport report)
	{
		return ratioToScore((RATIO*(report.BoundingRectRight-report.BoundingRectLeft)/(report.BoundingRectBottom-report.BoundingRectTop)));
	}


	/**
	 * Computes the estimated distance to a target using the width of the particle in the image. For more information and graphics
	 * showing the math behind this approach see the Vision Processing section of the ScreenStepsLive documentation.
	 *
	 * @param image The image to use for measuring the particle estimated rectangle
	 * @param report The Particle Analysis Report for the particle
	 * @return The estimated distance to the target in feet.
	 */
	double computeDistance (Image *image, ParticleReport report) {
		double normalizedWidth, targetWidth;
		int xRes, yRes;

		imaqGetImageSize(image, &xRes, &yRes);
		normalizedWidth = 2*(report.BoundingRectRight - report.BoundingRectLeft)/xRes;
		SmartDashboard::PutNumber("Width", normalizedWidth);
		targetWidth = 20;  //targets are 20"wide by 12" tall

		return  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
	}

	double computeAngle (Image *image, ParticleReport report) {
		double normalizedWidth;
		int xRes, yRes;

		imaqGetImageSize(image, &xRes, &yRes);
		normalizedWidth = 2*(report.BoundingRectRight - report.BoundingRectLeft)/xRes;
		SmartDashboard::PutNumber("Width", normalizedWidth);
		SmartDashboard::PutNumber("BoundingRectRight", report.BoundingRectRight);
		SmartDashboard::PutNumber("BoundingRectLeft", report.BoundingRectLeft);
		SmartDashboard::PutNumber("BoundingRectBottom", report.BoundingRectBottom);
		SmartDashboard::PutNumber("BoundingRectTop", report.BoundingRectTop);

		//return  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
		return (((report.BoundingRectRight-report.BoundingRectLeft)*0.5)+report.BoundingRectLeft)-165; // 160 for center/ 165 for more left


	}


};

START_ROBOT_CLASS(Robot)
