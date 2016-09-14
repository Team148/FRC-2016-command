#include "Pneumatic.h"

Pneumatic *Pneumatic::m_instance = 0;

using namespace std;

Pneumatic::Pneumatic() : Subsystem("Pneumatic") {
	m_comp = new Compressor(0); //TODO: add Constant
	m_relay = new Relay(COMPRESSOR_RELAY);
	m_comp->SetClosedLoopControl(true);
	m_comp->Start();
}

Pneumatic* Pneumatic::GetInstance() {
	if (m_instance ==  0) {
		cout << "info: GetInstance Creating Pneumatic Class" << endl;
		m_instance = new Pneumatic();
	}
	return m_instance;
}

void Pneumatic::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new RunCompressor());
}
