/*
	File Name: DueOverclock.cpp
	File By: Alexandre Rouma
	
	Use this code at your own risk ! I will NOT be responsible if you break your arduino !!!
*/

#include "Arduino.h"
#include "DueOverclock.h"

DueOverclockClass DueOverclock;

void DueOverclockClass::setCoreFrequency(int frq){
	cpuMult = (frq / 6) - 1;
	EFC0->EEFC_FMR = EEFC_FMR_FWS(4);
	EFC1->EEFC_FMR = EEFC_FMR_FWS(4);
	PMC->CKGR_PLLAR = (CKGR_PLLAR_ONE | CKGR_PLLAR_MULA(cpuMult) | CKGR_PLLAR_PLLACOUNT(0x3fUL) | CKGR_PLLAR_DIVA(1UL));
	while (!(PMC->PMC_SR & PMC_SR_LOCKA)) {}
	PMC->PMC_MCKR = ( PMC_MCKR_PRES_CLK_2 | PMC_MCKR_CSS_PLLA_CLK);
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY)) {}
	SystemCoreClockUpdate();
}
	
void DueOverclockClass::setCoreMultiplier(int mlt){
	cpuMult = mlt;
	EFC0->EEFC_FMR = EEFC_FMR_FWS(4);
	EFC1->EEFC_FMR = EEFC_FMR_FWS(4);
	PMC->CKGR_PLLAR = (CKGR_PLLAR_ONE | CKGR_PLLAR_MULA(cpuMult) | CKGR_PLLAR_PLLACOUNT(0x3fUL) | CKGR_PLLAR_DIVA(1UL));
	while (!(PMC->PMC_SR & PMC_SR_LOCKA)) {}
	PMC->PMC_MCKR = ( PMC_MCKR_PRES_CLK_2 | PMC_MCKR_CSS_PLLA_CLK);
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY)) {}
	SystemCoreClockUpdate();
}
	
int DueOverclockClass::getCoreFrequency(){
	return (cpuMult + 1) * 6;
}
	
int DueOverclockClass::getCoreMultiplier(){
	return cpuMult;
}

long DueOverclockClass::delayToOC(long del){
	float d = (del * (getCoreFrequency() / DEFAULT_FRQ));
	return d;
}

long DueOverclockClass::delayFromOC(long del){
	float d = (del / (getCoreFrequency() / DEFAULT_FRQ));
	return d;
}
	
void DueOverclockClass::OCDelay(long del){
	delay(delayToOC(del));
}

void DueOverclockClass::OCDelayMicroseconds(long del){
	delay(delayToOC(del));
}

long DueOverclockClass::OCMillis(){
	return delayFromOC(millis());
}

long DueOverclockClass::OCMicros(){
	return delayFromOC(micros());
}