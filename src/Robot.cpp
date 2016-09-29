#include "WPILib.h"

#include "Constants/Ports.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/HangerWinch.h"
#include "Subsystems/HangerArm.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Clamp.h"
#include "OperatorInterface.h"


// Initialize a single static instance of all of your subsystems to NULL
OperatorInterface *operatorInterface = 0;
IntakeRoller *intakeRoller = 0;
HangerWinch *hangerWinch = 0;
HangerArm *hangerArm = 0;
Clamp *clamp = 0;
Drivetrain *drivetrain = 0;

class Robot: public IterativeRobot
{
private:

	void RobotInit()
	{
		std::cout << "starting RobotInit" << std::endl;
		intakeRoller = IntakeRoller::GetInstance();
		//hangerWinch->GetInstance();
		//hangerArm->GetInstance();
		clamp = Clamp::GetInstance();
		drivetrain = Drivetrain::GetInstance();
		operatorInterface = OperatorInterface::GetInstance();
		//chooser = new SendableChooser();
		//chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		//SmartDashboard::PutData("Auto Modes", chooser);
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
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */


	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

