/*
 * SenseAmp.h
 *
 *  Created on: May 19, 2010
 *      Author: Xiangyu
 */

#ifndef SENSEAMP_H_
#define SENSEAMP_H_

#include "FunctionUnit.h"

class SenseAmp: public FunctionUnit {
public:
	SenseAmp();
	virtual ~SenseAmp();

	/* Functions */
	void PrintProperty();
	void Initialize(long long _numColumn, bool _currentSense, double _senseVoltage /* Unit: V */, double _pitchSenseAmp);
	void CalculateArea();
	void CalculateRC();
	void CalculateLatency(double _rampInput);
	void CalculatePower();
	SenseAmp & operator=(const SenseAmp &);

	/* Properties */
	bool initialized;	/* Initialization flag */
	bool invalid;		/* Indicate that the current configuration is not valid */
	long long numColumn;		/* Number of columns */
	bool currentSense;	/* Whether the sensing scheme is current-based */
	double senseVoltage;	/* Minimum sensible voltage */
	double capLoad;		/* Load capacitance of sense amplifier */
	double pitchSenseAmp;	/* The maximum width allowed for one sense amplifier layout */
};

#endif /* SENSEAMP_H_ */
