#include "Robot.h"


// Initialize a single static instance of all of your subsystems to NULL
OperatorInterface *operatorInterface = 0;
IntakeRoller *intakeRoller = 0;
HangerWinch *hangerWinch = 0;
HangerArm *hangerArm = 0;
Drivetrain *drivetrain = 0;
Pneumatic *pneumatic = 0;
Flashlight *flashlight = 0;
ActionArm *actionArm = 0;
Clamp *clamp = 0;
Catapult *catapult = 0;
Logger *logger = 0;

class Robot: public IterativeRobot
{
public:

private:
	SendableChooser* chooser;
	std::unique_ptr<Command> autonCommand;
	int position;
	int defense;
	int actions;
	bool sw1;
	bool sw2;
	bool sw3;
	bool sw4;
	bool sw5;


	void RobotInit()
	{
		std::cout << "starting RobotInit" << std::endl;
		logger = new Logger();
		logger->Start();
		intakeRoller = IntakeRoller::GetInstance();
		flashlight = Flashlight::GetInstance();
		drivetrain = Drivetrain::GetInstance();
		pneumatic = Pneumatic::GetInstance();
		operatorInterface = OperatorInterface::GetInstance();
		actionArm = ActionArm::GetInstance();
		clamp = Clamp::GetInstance();
		catapult = Catapult::GetInstance();
		chooser = new SendableChooser();

	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();


		position = operatorInterface->GetSelectorA();
		defense = operatorInterface->GetSelectorB();
		actions = operatorInterface->GetDSSwitches();
		UpdateSmartDash();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		position = operatorInterface->GetSelectorA();
		defense = operatorInterface->GetSelectorB();
		actions = operatorInterface->GetDSSwitches();

		switch(position) {
		case 1:  //position 1
			std::cout << "info: position " << position << "def " << defense << "Actions " << actions << std::endl;
			autonCommand.reset(new Position1(defense, actions));
			break;
		case 2:  //position 2
			std::cout << "info: position " << position << "def " << defense << "Actions " << actions << std::endl;
			autonCommand.reset(new Position2(defense, actions));
			break;
		case 3:  //position 3
			std::cout << "info: position " << position << "def " << defense << "Actions " << actions << std::endl;
			autonCommand.reset(new Position3(defense, actions));
			break;
		case 4:  //position 4
			std::cout << "info: position " << position << "def " << defense << "Actions " << actions << std::endl;
			autonCommand.reset(new Position4(defense, actions));
			break;
		case 5:  //position 5
			std::cout << "info: position " << position << "def " << defense << "Actions " << actions << std::endl;
			autonCommand.reset(new Position5(defense, actions));
			break;
		default:  //Do Nothing
			std::cout << "info: DEFAULT position " << position << "def " << defense << "Actions " << actions << std::endl;
			autonCommand==NULL;
		}

		if (autonCommand != NULL)
			autonCommand->Start();

	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		//Update SmartDashboard
		UpdateSmartDash();
		RobotLog();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonCommand != NULL)
			autonCommand->Cancel();

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		//Update SmartDashboard
		UpdateSmartDash();
		RobotLog();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
	
	void UpdateSmartDash()
	{
		//Subsystems
		SmartDashboard::PutData(Drivetrain::GetInstance());
		SmartDashboard::PutData(ActionArm::GetInstance());
		SmartDashboard::PutData(IntakeRoller::GetInstance());


		SmartDashboard::PutBoolean("Lowgear:",Drivetrain::GetInstance()->GetGear());
		SmartDashboard::PutBoolean("Beam Status:",IntakeRoller::GetInstance()->IsBeamBroke());
		SmartDashboard::PutData("ShortLong",new ShootCatapult(true));
		SmartDashboard::PutData("ShortShot", new ShootCatapult(false));

		//Auton
		SmartDashboard::PutData("Auton Modes", chooser);
		SmartDashboard::PutNumber("Position", position);
		SmartDashboard::PutNumber("Defense", defense);
		SmartDashboard::PutBoolean("Switch 1", operatorInterface->GetSw1());
		SmartDashboard::PutBoolean("Switch 2", operatorInterface->GetSw2());
		SmartDashboard::PutBoolean("Switch 3", operatorInterface->GetSw3());
		SmartDashboard::PutBoolean("Switch 4", operatorInterface->GetSw4());
		SmartDashboard::PutBoolean("Switch 5", operatorInterface->GetSw5());

	}
	void RobotLog()
	{
		//Add all subsystems to log here.
		drivetrain->Log();

		logger->WriteBuffertoFile();
	}
	
};

START_ROBOT_CLASS(Robot)

