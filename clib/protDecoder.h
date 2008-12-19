#ifndef _PROTDECODER_H_
#define _PROTDECODER_H_

#include "apDefinitions.h"
#ifdef __BORLANDC__ 
       #include "gsDefinitions.h"
#endif
#include <stdio.h>
#include <string.h>
#include "apDefinitions.h"
#include "circBuffer.h"
#include "apUtils.h"


#ifdef __cplusplus
       extern "C"{
#endif

void protParserInit (void);

#ifdef _IN_PC_
     float protParseDecode (unsigned char* fromSPI,  FILE* outFile);
     void printState(FILE* outfile);
#else
     void protParseDecode (unsigned char* fromSPI);
#endif

void getTime (unsigned char * values);
tGpsData getGpsStruct (void);
tRawData getRawStruct (void);
tXYZData getXYZStruct (void);
tAttitudeData getAttStruct (void);
tAknData getAknStruct (void);
tBiasData getBiasStruct (void);
tDynTempData getDynStruct (void);
tDiagData getDiagStruct (void);
tSensStatus getSensStruct (void);
tPilotData getPilotStruct(void);
void setAknFilter (unsigned char value);
void hil_getRawRead (unsigned short * rawData);
void hil_getGPSRead (unsigned char * gpsMsg);

#ifdef __cplusplus
       }
#endif


#endif /* _PROTDECODER_H_ */
