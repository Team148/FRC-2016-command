#include "Flashlight.h"

Flashlight *Flashlight::m_instance = 0;

using namespace std;

Flashlight::Flashlight() : Subsystem("Flashlight") {
	cout << "Flashlight constructor " << endl;
	FlashlightRelay = new Relay(FLASHLIGHT);
	cout << "info: Flashlight class created on port " << FLASHLIGHT << endl;

}

Flashlight* Flashlight::GetInstance() {
	if (m_instance == 0) {
		cout <<"info: GetInstance Creating Flashlight Class" << endl;
		m_instance = new Flashlight();
	}
	return m_instance;
}


void Flashlight::TurnOn() {
	cout << "info: Setting Flashlight relay value to kOn" << endl;
	FlashlightRelay->Set(Relay::Value::kForward); 			//kOn sets both forward/reverse outputs to 12V
}

void Flashlight::TurnOff() {
	cout << "info: Setting Flashlight relay value to kOff" << endl;
	FlashlightRelay->Set(Relay::Value::kOff); 			//kOff sets both forward/reverse outputs to 0
}
