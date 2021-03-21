#ifndef JOYSTICK_h
#define JOYSTICK_h

#define JOYSTICK_DEFAULT_REPORT_ID         0x03  // This is the default value for the REPORT_ID - 3
#define JOYSTICK_DEFAULT_BUTTON_COUNT        16	 // Default number of buttons
#define JOYSTICK_DEFAULT_AXIS_MINIMUM         0  //  
#define JOYSTICK_DEFAULT_AXIS_MAXIMUM      1023  // Default minimun and maximum values for all axises


class Joystick_
{
private:

    // State of the joystick - axises and buttons
	int16_t	_xAxis;
	int16_t	_yAxis;
	int16_t	_zAxis;
	int16_t	_rxAxis;
    uint8_t *_buttonValues = NULL;

    // Settings for the joystick
    bool _autoSendState;
    uint8_t _buttonCount;
    uint8_t _buttonValuesArraySize = 0;
	uint8_t	_includeAxisFlags;

	//Assigning the default values for minimum and maximum
	int16_t _xAxisMinimum = JOYSTICK_DEFAULT_AXIS_MINIMUM;
	int16_t _xAxisMaximum = JOYSTICK_DEFAULT_AXIS_MAXIMUM;

	int16_t _yAxisMinimum = JOYSTICK_DEFAULT_AXIS_MINIMUM;
	int16_t _yAxisMaximum = JOYSTICK_DEFAULT_AXIS_MAXIMUM;

	int16_t _zAxisMinimum = JOYSTICK_DEFAULT_AXIS_MINIMUM;
	int16_t _zAxisMaximum = JOYSTICK_DEFAULT_AXIS_MAXIMUM;

	int16_t _rxAxisMinimum = JOYSTICK_DEFAULT_AXIS_MINIMUM;
	int16_t _rxAxisMaximum = JOYSTICK_DEFAULT_AXIS_MAXIMUM;

	uint8_t _hidReportId;
	uint8_t _hidReportSize; 

protected:

	// Set 16 bit values and range - minimum maximum
	int buildAndSet16BitValue(
		bool includeValue, 
		int16_t value, 
		int16_t valueMinimum, 
		int16_t valueMaximum, 
		int16_t actualMinimum, 
		int16_t actualMaximum, 
		uint8_t dataLocation[]);

	// Set axises value and range
	int buildAndSetAxisValue(
		bool includeAxis, 
		int16_t axisValue, 
		int16_t axisMinimum, 
		int16_t axisMaximum, 
		uint8_t dataLocation[]);


public:

	//Function for the user to define how many axises and buttons he want.
	//If left unfilled in Arduino IDE, it uses the default settings
	Joystick_(
		uint8_t hidReportId = JOYSTICK_DEFAULT_REPORT_ID,
        uint8_t buttonCount = JOYSTICK_DEFAULT_BUTTON_COUNT,

		bool includeXAxis = true,
		bool includeYAxis = true,
		bool includeZAxis = true,
		bool includeRxAxis = true);


	// Function for sending  the updated state of the joystick.
	void begin(bool initAutoSendState = true);

	
	// Function for setting the range of X axis
	inline void setXAxisRange(int16_t minimum, int16_t maximum){
		_xAxisMinimum = minimum;
		_xAxisMaximum = maximum;
	}

	// Function for setting the range of Y axis
	inline void setYAxisRange(int16_t minimum, int16_t maximum){
		_yAxisMinimum = minimum;
		_yAxisMaximum = maximum;
	}

	// Function for setting the range of Z axis
	inline void setZAxisRange(int16_t minimum, int16_t maximum){
		_zAxisMinimum = minimum;
		_zAxisMaximum = maximum;
	}

	// Function for setting the range of RX axis
	inline void setRxAxisRange(int16_t minimum, int16_t maximum){
		_rxAxisMinimum = minimum;
		_rxAxisMaximum = maximum;
	}



	// Functions for setting the values of the different axises
	void setXAxis(int16_t value);
	void setYAxis(int16_t value);
	void setZAxis(int16_t value);
	void setRxAxis(int16_t value);


	// Function for setting the values of the different buttons
	void setButton(uint8_t button, uint8_t value);

	// Functions for pressing and releasing buttons
	void pressButton(uint8_t button);
	void releaseButton(uint8_t button);


	// Function for sending  the updated state of the joystick.
	// Its used only if AutoSendState is with state false.
	void sendState();
};

#endif
