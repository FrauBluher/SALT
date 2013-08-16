/* 
 * File:   main.c
 * Author: Pavlo
 *
 * Created on August 3, 2013, 1:10 PM
 */


#include <xc.h>
#include "I2CdsPIC.h"
#include "MPU60xx.h"
#include <string.h>
#include <stdlib.h>
#include <uart.h>
#include "SALTStabilizationInnerOuterLoop.h" /* Model's header file */
#include "rtwtypes.h"                        /* MathWorks types */


_FOSCSEL(FNOSC_FRC);
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF);
_FICD(JTAGEN_OFF & ICS_PGD1);

void UART2Init();
void IMU2String(char *output, MPU6050_Data input);
void ClockInit();
void MotorInit();
void TimersInit();
void PinInit();


MPU6050_Data imuData;
char strBuff[128] = "";

extern real32_T commandedAngle; /* '<Root>/Data Store Memory' */
extern real32_T torqueInputX; /* '<Root>/Data Store Memory11' */
extern real32_T AccelX; /* '<Root>/Data Store Memory12' */
extern real32_T GyroX; /* '<Root>/Data Store Memory13' */
extern real32_T AccelZ; /* '<Root>/Data Store Memory14' */
extern real32_T GyroZ; /* '<Root>/Data Store Memory15' */
extern real32_T CommandedY; /* '<Root>/Data Store Memory16' */
extern real32_T AccelY; /* '<Root>/Data Store Memory17' */
extern real32_T CommandedX; /* '<Root>/Data Store Memory18' */
extern real32_T torqueInputY; /* '<Root>/Data Store Memory19' */
extern real32_T GyroY; /* '<Root>/Data Store Memory6' */
extern real32_T fieldWeakening; /* '<Root>/Data Store Memory9' */

extern D_Work_SALTStabilizationInnerOu SALTStabilizationInnerOut_DWork;

int main(void)
{
	ClockInit();
	PinInit();
	SALTStabilizationInnerOuterLoop_initialize();
	TimersInit();
	MotorInit();

	CommandedX = 0;
	CommandedY = 0;
	torqueInputX = 100;
	torqueInputY = 100;

	I2C_Init(9600);
	I2C1BRG = 0x4E;
	UART2Init();
	MPU60xx_Init();

	TRISDbits.TRISD11 = 0;

	PDC1 = 2500;
	PDC2 = 2500;
	PDC3 = 2500;
	PDC4 = 2500;
	PDC5 = 2500;
	PDC6 = 2500;

	while (1) {
	};
	//Sit and Spin
}

void UART2Init(void)
{
	U2MODEbits.UARTEN = 0; // Disable the port
	U2MODEbits.USIDL = 0; // Stop on idle
	U2MODEbits.IREN = 0; // No IR decoder
	U2MODEbits.RTSMD = 0; // Ready to send mode (irrelevant)
	U2MODEbits.UEN = 0; // Only RX and TX
	U2MODEbits.WAKE = 1; // Enable at startup
	U2MODEbits.LPBACK = 0; // Disable loopback
	U2MODEbits.ABAUD = 0; // Disable autobaud
	U2MODEbits.URXINV = 0; // Normal operation (high is idle)
	U2MODEbits.PDSEL = 0; // No parity 8 bit
	U2MODEbits.STSEL = 0; // 1 stop bit
	U2MODEbits.BRGH = 0;

	IPC7 = 0x4400;
	// U2STA Register
	// ==============
	U2STAbits.URXISEL = 0; // RX interrupt on every character
	U2STAbits.OERR = 0; // clear overun error


	// U2BRG Register
	// ==============
	U2BRG = 26; //115200

	// Enable the port;
	U2MODEbits.UARTEN = 1; // Enable the port
	U2STAbits.UTXEN = 1; // Enable TX
}

void IMU2String(char *strBuff, MPU6050_Data input)
{
	char textBuff[16] = "";
	strcat(strBuff, itoa(textBuff, input.accelX, 10));
	strcat(strBuff, ",");
	strcat(strBuff, itoa(textBuff, input.accelY, 10));
	strcat(strBuff, ",");
	strcat(strBuff, itoa(textBuff, input.accelZ, 10));
	strcat(strBuff, ",");
	strcat(strBuff, itoa(textBuff, input.gyroX, 10));
	strcat(strBuff, ",");
	strcat(strBuff, itoa(textBuff, input.gyroY, 10));
	strcat(strBuff, ",");
	strcat(strBuff, itoa(textBuff, input.gyroZ, 10));
	strcat(strBuff, "\r\n\0");
}

void MotorInit()
{
#if defined(__dsPIC33FJ64GS608__)
	PTCONbits.PTEN = 0;

	/* Setup for the Auxiliary clock to use the FRC as the REFCLK */
	/* ((FRC * 16) / APSTSCLR) = (7.49 * 16) / 1 = 119.84 MHz */
	ACLKCONbits.FRCSEL = 1; /* FRC is input to Auxiliary PLL */
	ACLKCONbits.SELACLK = 1; /* Auxiliary Oscillator provides the clock
	source */
	ACLKCONbits.APSTSCLR = 1; /* Divide Auxiliary clock by 1 */
	ACLKCONbits.ENAPLL = 1; /* Enable Auxiliary PLL */
	while (ACLKCONbits.APLLCK != 1); /* Wait for Auxiliary PLL to Lock */

	//setup PWM ports
	PWMCON1bits.ITB = 0; /* PTPER provides the PWM time period value */
	PWMCON2bits.ITB = 0; /* PTPER provides the PWM time period value */
	PWMCON3bits.ITB = 0; /* PTPER provides the PWM time period value */
	PWMCON4bits.ITB = 0; /* PTPER provides the PWM time period value */
	PWMCON5bits.ITB = 0; /* PTPER provides the PWM time period value */
	PWMCON6bits.ITB = 0; /* PTPER provides the PWM time period value */

	IOCON1bits.PENH = 1;
	IOCON2bits.PENH = 1;
	IOCON3bits.PENH = 1;
	IOCON4bits.PENH = 1;
	IOCON5bits.PENH = 1;
	IOCON6bits.PENH = 1;

	//Setup desired frequency by setting period for 1:64 prescaler
	PTPER = 10100;
	PHASE1 = 0;
	PHASE2 = 0;
	PHASE3 = 0;
	PHASE4 = 0;
	PHASE5 = 0;
	PHASE6 = 0;

	PTCONbits.PTEN = 1;
#endif

}

void ClockInit(void)
{
#if defined(__dsPIC33FJ64GS608__)
    PLLFBD = 242; // M = 50 MIPS
    CLKDIVbits.PLLPOST = 0;
    CLKDIVbits.PLLPRE = 7;
    OSCTUN = 0;
    RCONbits.SWDTEN = 0;
    __builtin_write_OSCCONH(0x01); // Initiate Clock Switch to Primary (3?)
    __builtin_write_OSCCONL(0x01); // Start clock switching
    while (OSCCONbits.COSC != 0b001); // Wait for Clock switch to occur
    while (OSCCONbits.LOCK != 1) {
    };
#endif
}

void PinInit(void)
{
	TRISBbits.TRISB12 = 0;
	TRISBbits.TRISB13 = 0;
	TRISDbits.TRISD11 = 0;
	TRISDbits.TRISD10 = 0;
	TRISDbits.TRISD0 = 0;
	TRISDbits.TRISD1 = 0;
	TRISDbits.TRISD2 = 0;
	TRISDbits.TRISD12 = 0;
	TRISCbits.TRISC13 = 0;
	TRISCbits.TRISC14 = 0;

	LATBbits.LATB14 = 1;
	LATBbits.LATB15 = 1;
	
	LATDbits.LATD0 = 1;
	LATDbits.LATD1 = 1;
	LATDbits.LATD2 = 1;
	LATDbits.LATD12 = 1;
	LATCbits.LATC13 = 1;
	LATCbits.LATC14 = 1;

}

void TimersInit(void)
{
	T1CONbits.TON = 0;
	T1CONbits.TCS = 0;
	T1CONbits.TGATE = 0;
	T1CONbits.TCKPS = 0b11; // Select 1:256 Prescaler
	TMR1 = 0x00;
	PR1 = 400;
	IPC0bits.T1IP = 0x01;
	IFS0bits.T1IF = 0;
	IEC0bits.T1IE = 1;
	T1CONbits.TON = 1;

	T2CONbits.TON = 0;
	T2CONbits.TCS = 0;
	T2CONbits.TGATE = 0;
	T2CONbits.TCKPS = 0b11; // Select 1:256 Prescaler
	TMR2 = 0x00;
	PR2 = 800;
	IPC1bits.T2IP = 0x01;
	IFS0bits.T2IF = 0;
	IEC0bits.T2IE = 1;
	T2CONbits.TON = 1;
}

/* Since we're just worried about getting data off of the IMU at a constant time
 * interval, we're going to just put it all of the stringification/sensing/sending
 * in this interrupt.  Usually a no-no, but this is fine.  Just don't use this in any
 * code that has any other timing requirements.
 */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
	MPU60xx_Get6AxisData(&imuData);

	AccelX = (real32_T) imuData.accelX;
	AccelY = (real32_T) imuData.accelY;
	AccelZ = (real32_T) imuData.accelZ;
	GyroX = (real32_T) imuData.gyroX;
	GyroY = (real32_T) imuData.gyroY;
	GyroZ = (real32_T) imuData.gyroZ;

	SALTStabilizationInnerOuterLoop_step();

	PDC1 = (uint16_t) SALTStabilizationInnerOut_DWork.T1;
	PDC2 = (uint16_t) SALTStabilizationInnerOut_DWork.T2;
	PDC3 = (uint16_t) SALTStabilizationInnerOut_DWork.T3;
	PDC4 = (uint16_t) SALTStabilizationInnerOut_DWork.T4;
	PDC5 = (uint16_t) SALTStabilizationInnerOut_DWork.T5;
	PDC6 = (uint16_t) SALTStabilizationInnerOut_DWork.T6;

	LATDbits.LATD11 = 1;
	IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
	uint8_t i;
	IMU2String(strBuff, imuData);

	for (i = 0; i < strlen(strBuff); i++) {
		WriteUART2(strBuff[i]);
		while (BusyUART2());
	}

	memset(strBuff, NULL, 128);

	IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag
}

