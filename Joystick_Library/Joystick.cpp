#include "Joystick.h"

#define JOYSTICK_AXIS_MINIMUM -32767
#define JOYSTICK_AXIS_MAXIMUM 32767

#define JOYSTICK_INCLUDE_X_AXIS  B00000001
#define JOYSTICK_INCLUDE_Y_AXIS  B00000010
#define JOYSTICK_INCLUDE_Z_AXIS  B00000100
#define JOYSTICK_INCLUDE_RX_AXIS B00001000



//It gives the user option to set custom number of buttons and axises.
//Also the REPORT_ID.
//Custom REPORT_ID is needed if more then one Arduino board is used.
Joystick_::Joystick_(
	uint8_t hidReportId,
    uint8_t buttonCount,
	
	bool includeXAxis,
	bool includeYAxis,
	bool includeZAxis,
	bool includeRxAxis)

{
    // Set the USB HID Report ID
    _hidReportId = hidReportId;

    // Save Joystick Settings defined by the user in Arduino IDE
    _buttonCount = buttonCount;
	_includeAxisFlags = 0;
	_includeAxisFlags |= (includeXAxis ? JOYSTICK_INCLUDE_X_AXIS : 0);
	_includeAxisFlags |= (includeYAxis ? JOYSTICK_INCLUDE_Y_AXIS : 0);
	_includeAxisFlags |= (includeZAxis ? JOYSTICK_INCLUDE_Z_AXIS : 0);
	_includeAxisFlags |= (includeRxAxis ? JOYSTICK_INCLUDE_RX_AXIS : 0);


	
	// Finding how many buttons are in the last byte.
	uint8_t buttonsInLastByte = _buttonCount % 8;

	// Finding how many paddings are needed in the last byte.
	uint8_t paddingBits = 0;

	if (buttonsInLastByte > 0){
		paddingBits = 8 - buttonsInLastByte;
	}
	

	// Finding how many axises are used. 
	// By default all four are used and are with state true.
	uint8_t axisCount = (includeXAxis == true) + (includeYAxis == true) + (includeZAxis == true) + (includeRxAxis == true);
		
	// Array for storing descriptor instructions	
    uint8_t tempHidReportDescriptor[150];
    int hidReportDescriptorSize = 0;

// ==========================================================================	
//	Descriptor for the type of device and its report id. 

    // USAGE_PAGE (Generic Desktop)
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0x05;
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

    // USAGE (Joystick)
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0x04;

    // COLLECTION (Application)
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0xa1;
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

    // REPORT_ID (Default: 3)
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0x85;
    tempHidReportDescriptor[hidReportDescriptorSize++] = _hidReportId;
	
	
// ==========================================================================	
//	Descriptor for all buttons. By default they are 16. 		
	
	if (_buttonCount > 0) {

		// USAGE_PAGE (Button)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x05;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;

		// USAGE_MINIMUM (Button 1)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x19;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

		// USAGE_MAXIMUM (Button 16)            
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x29;
		tempHidReportDescriptor[hidReportDescriptorSize++] = _buttonCount;

		// LOGICAL_MINIMUM (0)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x15;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x00;

		// LOGICAL_MAXIMUM (1)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x25;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

		// REPORT_SIZE (1)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x75;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

		// REPORT_COUNT (number of buttons)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x95;
		tempHidReportDescriptor[hidReportDescriptorSize++] = _buttonCount;

		// UNIT_EXPONENT (0)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x55;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x00;

		// UNIT (None)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x65;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x00;

		// INPUT (Data,Var,Abs)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x81;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x02;

		// Descriptor for how many padding bits are needed
		if (paddingBits > 0){
			
			// REPORT_SIZE (1)
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x75;
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

			// REPORT_COUNT (number of padding bits)
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x95;
			tempHidReportDescriptor[hidReportDescriptorSize++] = paddingBits;
					
			// INPUT (Const,Var,Abs)
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x81;
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x03;   	
		}

	}


	
// ==========================================================================	
//	Descriptor for all of the axises - X, Y, Z, Rx Axis	
	

	if (axisCount > 0) {

		// USAGE_PAGE (Generic Desktop)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x05;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;
		
		// USAGE (Pointer)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;

		// LOGICAL_MINIMUM (-32767)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x16;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x01;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x80;

		// LOGICAL_MAXIMUM (+32767)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x26;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0xFF;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x7F;

		// REPORT_SIZE (16)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x75;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x10;

		// REPORT_COUNT (axisCount)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x95;
		tempHidReportDescriptor[hidReportDescriptorSize++] = axisCount;
						
		// COLLECTION (Physical)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0xA1;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x00;


		// If X Axis is used set specific descriptor for it
		if (includeXAxis == true){
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x30;
		}

		// If Y Axis is used set specific descriptor for it
		if (includeYAxis == true){
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x31;
		}
		
		// If Z Axis is used set specific descriptor for it
		if (includeZAxis == true){
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x32;
		}
		
		// If RX Axis is used set specific descriptor for it
		if (includeRxAxis == true){
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x09;
			tempHidReportDescriptor[hidReportDescriptorSize++] = 0x33;
		}
		
		
		// INPUT (Data,Var,Abs)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x81;
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0x02;
		
		// END_COLLECTION (Physical)
		tempHidReportDescriptor[hidReportDescriptorSize++] = 0xc0;
		
	} 

	// END_COLLECTION(Aplication)
    tempHidReportDescriptor[hidReportDescriptorSize++] = 0xc0;
	
	
	// Using memcpy to copy the HID Report Descriptor from tempHidReportDescriptor
	// to customHidReportDescriptor with the right size
	uint8_t *customHidReportDescriptor = new uint8_t[hidReportDescriptorSize];
	memcpy(customHidReportDescriptor, tempHidReportDescriptor, hidReportDescriptorSize);

	// Setup the structure for HID report
	static HIDSubDescriptor node(customHidReportDescriptor, hidReportDescriptorSize);
	HID().AppendDescriptor(&node);


// Setup Joystick State

	if (buttonCount > 0){
		_buttonValuesArraySize = _buttonCount / 8;
		if ((_buttonCount % 8) > 0){
			_buttonValuesArraySize++;
		}
		_buttonValues = new uint8_t[_buttonValuesArraySize];
	}
	

	// Calculating how many bytes is the size of HID Report
	_hidReportSize = _buttonValuesArraySize;
	_hidReportSize = _hidReportSize + (axisCount * 2);

// Initalizing Joystick State

	_xAxis = 0;
	_yAxis = 0;
	_zAxis = 0;
	_rxAxis = 0;

	// Giving all buttons a value 0 - not presssed
    for (int index = 0; index < _buttonValuesArraySize; index++)
    {
        _buttonValues[index] = 0;
    }
}

// Function for sending  the updated state of the joystick.
void Joystick_::begin(bool initAutoSendState)
{
	_autoSendState = initAutoSendState;
	sendState();
}


// Function for setting the value of a button
void Joystick_::setButton(uint8_t button, uint8_t value)
{
	if (value == 0){
		releaseButton(button);
	}
	else{
		pressButton(button);
	}
}

// Function for pressing a button
void Joystick_::pressButton(uint8_t button)
{
    if (button >= _buttonCount) return;

    int index = button / 8;
    int bit = button % 8;

	bitSet(_buttonValues[index], bit);
	if (_autoSendState) sendState();
}

// Function for releasing a button
void Joystick_::releaseButton(uint8_t button)
{
    if (button >= _buttonCount) return;

    int index = button / 8;
    int bit = button % 8;

    bitClear(_buttonValues[index], bit);
	if (_autoSendState) sendState();
}



// Functions for setting the value of axises

void Joystick_::setXAxis(int16_t value)
{
	_xAxis = value;
	if (_autoSendState) sendState();
}

void Joystick_::setYAxis(int16_t value)
{
	_yAxis = value;
	if (_autoSendState) sendState();
}

void Joystick_::setZAxis(int16_t value)
{
	_zAxis = value;
	if (_autoSendState) sendState();
}

void Joystick_::setRxAxis(int16_t value)
{
	_rxAxis = value;
	if (_autoSendState) sendState();
}



// Set 16 bit values and range - minimum maximum
int Joystick_::buildAndSet16BitValue(
	bool includeValue, 
	int16_t value, 
	int16_t valueMinimum, 
	int16_t valueMaximum, 
	int16_t actualMinimum, 
	int16_t actualMaximum, 
	uint8_t dataLocation[]) 

{
	int16_t convertedValue;
	uint8_t highByte;
	uint8_t lowByte;

	//Finding the smaller value of the two
	int16_t realMinimum = min(valueMinimum, valueMaximum);
	//Finding the larger value of the two
	int16_t realMaximum = max(valueMinimum, valueMaximum);

	if (includeValue == false) return 0;

	if (value < realMinimum){
		value = realMinimum;
	}

	if (value > realMaximum){
		value = realMaximum;
	}

	if (valueMinimum > valueMaximum){		
		value = realMaximum - value + realMinimum;
	}
	//Converting a value taken from 16-bit range to 8-bit range
	convertedValue = map(value, realMinimum, realMaximum, actualMinimum, actualMaximum);

	//Converting the range from 16-bit to 8-bit
	highByte = (uint8_t)(convertedValue >> 8);
	lowByte = (uint8_t)(convertedValue & 0x00FF);
	
	dataLocation[0] = lowByte;
	dataLocation[1] = highByte;
	
	return 2;
}

// Set axises value and range
int Joystick_::buildAndSetAxisValue(bool includeAxis, int16_t axisValue, int16_t axisMinimum, int16_t axisMaximum, uint8_t dataLocation[]) 
{
	return buildAndSet16BitValue(includeAxis, axisValue, axisMinimum, axisMaximum, JOYSTICK_AXIS_MINIMUM, JOYSTICK_AXIS_MAXIMUM, dataLocation);
}




//Sends the updated state of the joistick to the computer.
//Its used only if AutoSendState is with state false.
void Joystick_::sendState()
{	
	//array with the same size of _hidReport
	uint8_t data[_hidReportSize];
	int index = 0;
	
	// Load Button State
	for (; index < _buttonValuesArraySize; index++)
	{
		data[index] = _buttonValues[index];		
	}

	
	// Values of axises
	index = index + buildAndSetAxisValue(_includeAxisFlags & JOYSTICK_INCLUDE_X_AXIS, _xAxis, _xAxisMinimum, _xAxisMaximum, &(data[index]));
	index = index + buildAndSetAxisValue(_includeAxisFlags & JOYSTICK_INCLUDE_Y_AXIS, _yAxis, _yAxisMinimum, _yAxisMaximum, &(data[index]));
	index = index + buildAndSetAxisValue(_includeAxisFlags & JOYSTICK_INCLUDE_Z_AXIS, _zAxis, _zAxisMinimum, _zAxisMaximum, &(data[index]));
	index = index + buildAndSetAxisValue(_includeAxisFlags & JOYSTICK_INCLUDE_RX_AXIS, _rxAxis, _rxAxisMinimum, _rxAxisMaximum, &(data[index]));


	// _hidReportId - Report number. By default is 3
	// data - array of values in same order as HID descriptor
	// _hidReportSize - length of the descriptor
	HID().SendReport(_hidReportId, data, _hidReportSize);
}
