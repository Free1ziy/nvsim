/*
 * Mat.h
 *
 *  Created on: May 29, 2010
 *      Author: xydong
 */

#ifndef MAT_H_
#define MAT_H_

#include "FunctionUnit.h"
#include "SubArray.h"
#include "PredecodeBlock.h"
#include "typedef.h"
#include "Comparator.h"

class Mat: public FunctionUnit {
public:
	Mat();
	virtual ~Mat();

	/* Functions */
	void PrintProperty();
	void Initialize(int _numRowSubarray, int _numColumnSubarray, int _numAddressBit, long _numDataBit,
			int _numWay, int _numRowPerSet, bool _split, int _numActiveSubarrayPerRow, int _numActiveSubarrayPerColumn,
			int _muxSenseAmp, bool _internalSenseAmp, int _muxOutputLev1, int _muxOutputLev2,
			BufferDesignTarget _areaOptimizationLevel, MemoryType _memoryType);
	void CalculateArea();
	void CalculateRC();
	void CalculateLatency(double _rampInput);
	void CalculatePower();
	Mat & operator=(const Mat &);

	/* Properties */
	bool initialized;	/* Initialization flag */
	bool invalid;		/* Indicate that the current configuration is not valid, pass down to all the sub-components */
	bool internalSenseAmp;
	int numRowSubarray;		/* Number of subarray rows in a mat */
	int numColumnSubarray;	/* Number of subarray columns in a mat */
	int numAddressBit;		/* Number of mat address bits */
	long numDataBit;		/* Number of mat data bits */
	int numWay;				/* Number of cache ways distributed to this mat, non-cache it is 1 */
	int numRowPerSet;		/* For cache design, the number of wordlines which a set is partitioned into */
	bool split;			/* Whether the row decoder is at the middle of subarrays */
	int numActiveSubarrayPerRow;	/* For different access types */
	int numActiveSubarrayPerColumn;	/* For different access types */
	int muxSenseAmp;	/* How many bitlines connect to one sense amplifier */
	int muxOutputLev1;	/* How many sense amplifiers connect to one output bit, level-1 */
	int muxOutputLev2;	/* How many sense amplifiers connect to one output bit, level-2 */
	BufferDesignTarget areaOptimizationLevel;
	MemoryType memoryType;

	double predecoderLatency;	/* The maximum latency of all the predecoder blocks, Unit: s */

	SubArray subarray;
	PredecodeBlock rowPredecoderBlock1;
	PredecodeBlock rowPredecoderBlock2;
	PredecodeBlock bitlineMuxPredecoderBlock1;
	PredecodeBlock bitlineMuxPredecoderBlock2;
	PredecodeBlock senseAmpMuxLev1PredecoderBlock1;
	PredecodeBlock senseAmpMuxLev1PredecoderBlock2;
	PredecodeBlock senseAmpMuxLev2PredecoderBlock1;
	PredecodeBlock senseAmpMuxLev2PredecoderBlock2;

	Comparator comparator;
};

#endif /* MAT_H_ */
