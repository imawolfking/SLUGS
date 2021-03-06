/*
The MIT License

Copyright (c) 2009 UCSC Autonomous Systems Lab

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "circBuffer.h"
// #include "gpsSplit.h"
 // #include "apDefinitions.h"
// #include "gpsParse.h"
#include "gps.h"

unsigned char quickSort(unsigned short *arr, char elements) {

  #define  MAX_LEVELS  6

  unsigned short  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R ;

  beg[0]=0; end[0]=elements;
  while (i>=0) {
    L=beg[i]; R=end[i]-1;
    if (L<R) {
      piv=arr[L]; if (i==MAX_LEVELS-1) return 0;
      while (L<R) {
        while (arr[R]>=piv && L<R) {
        	R--; 
        }
        if (L<R){ 
        	arr[L++]=arr[R];
        }
        while (arr[L]<=piv && L<R) {
        	L++;
        } 
        if (L<R) {
        	arr[R--]=arr[L];
      	}   
      }
      arr[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L; 
    } else {
      i--;     
    }
  }
  return 1; 
}

int main(int argc, char* argv[])
{
	unsigned short myArray[] ={1456, 7856, 1450, 1423, 1423 }
	char i;
	
	quickSort(&myArray[0], 5)
	
	for( i = 0; i < 5; i += 1 )
	{
		printf("%d ", myArray[i]);
	}
	
  /*char str[] ="- This,a,,,,,sample,string.";
  char * pch;
	char count = 0;
	char str2[] = "This,is,a,,,,,,,sample,string";
	char token[TOKEN_SIZE];
	
  printf ("Splitting string \"%s\" into tokens using strtok:\n",str);
  pch = strtok (str,",");
  while (pch != NULL)
  {
    printf ("%d\t%s\n",count++,pch);
    pch = strtok (NULL, ",");
  }


  // char * pch;
  printf ("Looking for the ',' character in \"%s\"... using strchr \n",str2);
  pch=strchr(str2,',');
  while (pch!=NULL)
  {
    printf ("found at %d\n",pch-str2+1);
    pch=strchr(pch+1,',');
  }

  printf ("Looking for the ',' character in \"%s\"... using myTokenizer \n",str2);
  myTokenizer(str2,',', token);
  printf ("found token %s\n",token);
	while (!myTokenizer(NULL, ',', token))
  {
    printf ("found token %s\n",token);
  }
	printf ("found token %s\n",token);
	*/
	
	// unsigned char msg1 [] = "@$GPRMC,040302.663,A,3939.7,N,10506.6,W,5.27,358.86,200804,,*1A\r\n\0";
	// 	unsigned char msg2 [] = "N$GPGGA,213924.000,4221.1129,N,07102.9146,W,1,04,3.9,129.7,M,-33.7,M,,0000*68\r\n";
	// 	unsigned char msg3 [] = "&$GPGGA,213922.000,4221.1129,N,07102.91";
	// 	unsigned char msg4 [] = "(46,W,1,04,3.9,129.7,M,-33.7,M,,0000*6E\r\n";
	// 	
	// 	char i;
	// 	
	// 	float gpsData[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
	// 	gpsInit();
	// 	
	// 	for(i=0; i<strlen(msg1); i++){
	// 		writeBack(uartBuffer, (unsigned char)msg1[i]);
	// 	}
	// 	for(i=0; i<strlen(msg2); i++){
	// 		writeBack(uartBuffer, (unsigned char)msg2[i]);
	// 	}
	// 	for(i=0; i<strlen(msg3); i++){
	// 		writeBack(uartBuffer, (unsigned char)msg3[i]);
	// 	}
	// 	
	// 	printf("%c\n\r", peak(uartBuffer));
	// 	
	// 	getGpsMainData(gpsData);
	// 	
	// 	printf("%f\t%f\t%f\t%f\t%f\n\r", gpsData[0], gpsData[1], gpsData[2], gpsData[3], gpsData[4]);
	// 
	// 	printf("%d\n\r", getLength(uartBuffer));
	
   return(0);
}
	
	
 /*  char i;
 
	
	unsigned char msg1 [] = "@$GPRMC,040302.663,A,3939.7,N,10506.6,W,5.27,358.86,200804,,*1A\r\n";
	unsigned char msg2 [] = "N$GPGGA,213924.000,4221.1129,N,07102.9146,W,1,04,3.9,129.7,M,-33.7,M,,0000*68\r\n";
	unsigned char msg3 [] = "&$GPGGA,213922.000,4221.1129,N,07102.91";
	unsigned char msg4 [] = "(46,W,1,04,3.9,129.7,M,-33.7,M,,0000*6E\r\n";
	
	unsigned char outBuffer [128] ={0}, parsedData[128]={0};
	
	gpsInit();
	
	printf("Message 1\n");
	gpsSeparate(msg2, outBuffer);	
		printf("\n");
		printf(outBuffer);
		printf("\nValid: %d Type:%d", outBuffer[MSIZE-1], outBuffer[0]);
		printf("\n");
		printf(msg2);
	
	gpsParse(outBuffer, parsedData);
	
	for(i=0;i<6;i++){
		printf("%d ", parsedData[i]);
	}
	
	tFloatToChar flCh;
	tIntToChar inCh;
	
	flCh.chData[0] = parsedData[6];
	flCh.chData[1] = parsedData[7];
	flCh.chData[2] = parsedData[8];
	flCh.chData[3] = parsedData[9];
	printf("%f ", flCh.flData);
	
	flCh.chData[0] = parsedData[10];
	flCh.chData[1] = parsedData[11];
	flCh.chData[2] = parsedData[12];
	flCh.chData[3] = parsedData[13];
	printf("%f ", flCh.flData);

	flCh.chData[0] = parsedData[14];
	flCh.chData[1] = parsedData[15];
	flCh.chData[2] = parsedData[16];
	flCh.chData[3] = parsedData[17];
	printf("%f ", flCh.flData);
	
	inCh.chData[0] = parsedData[18];
	inCh.chData[1] = parsedData[19];
	printf("%d ", inCh.inData);

	inCh.chData[0] = parsedData[20];
	inCh.chData[1] = parsedData[21];
	printf("%d ", inCh.inData);
	
	inCh.chData[0] = parsedData[22];
	inCh.chData[1] = parsedData[23];
	printf("%d ", inCh.inData);
	
	for(i=24;i<26;i++){
		printf("%d ", parsedData[i]);
	}
	
	printf("\n");
	
	unsigned char thischr [] = "$PMTK251,19200*22\r\n";
	printf("Baud Rate %d", getChecksum(thischr, 17));
	
	unsigned char thischr2 [] = "$PMTK300,200,0,0,0,0*2F\r\n";
	printf("Frequency %d", getChecksum(thischr2, 23));
	
	unsigned char thischr3 [] = "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n";
	printf("Sentences %d", getChecksum(thischr3, 49));
				
	/*printf("Message 2\n");
	gpsSeparate(msg2, outBuffer);	
		printf("\n");
		printf(outBuffer);
		printf("\nValid: %d Type:%d", outBuffer[MSIZE-1], outBuffer[0]);
		printf("\n");
		printf(msg2);
	


	printf("First Call to GPS Separate\n");
	gpsSeparate(msg3, outBuffer);	
	printf("============================\n");
	
	printf("Second Call to GPS Separate\n");	
	gpsSeparate(msg4, outBuffer);	
	printf("============================\n");
	
	printf(outBuffer);
	printf("\nValid: %d Type:%d", outBuffer[MSIZE-1], outBuffer[0]);
	printf("\n");
	printf(msg3);
	printf(msg4);

	printf("============================\n");
	printf("============================\n");
	printf("============================\n");
	printf("============================\n");
	printf("Char: %d, Short: %d, Int: %d, Float: %d, Long:%d", sizeof(char), sizeof(short), sizeof(int), sizeof(float), sizeof(long));
	printf("\n");	
	*/
