#include <LPC21xx.H>
#include "timer.h"

// TIMER
#define mCOUNTER_ENABLE   (1<<0)
#define mCOUNTER_RESET    (1<<1)

// CompareMatch
#define mINTERRUPT_ON_MR0 (1<<0)
#define mRESET_ON_MR0     (1<<1)
#define mMR0_INTERRUPT    (1<<0)

void InitTimer0(void){
	T0TCR |= mCOUNTER_ENABLE;
}

void WaitOnTimer0(unsigned int uiTime){

	T0TCR |= mCOUNTER_RESET;
	T0TCR = mCOUNTER_ENABLE;
	
	while(T0TC<(15*uiTime)){}
}

void InitTimer0Match0(unsigned int iDelayTime){
	T0MR0 = 15*iDelayTime;
	T0MCR |= mRESET_ON_MR0 | mMR0_INTERRUPT;
	T0TCR |= mCOUNTER_RESET;
	T0TCR |= mCOUNTER_ENABLE;
}

void WaitOnTimer0Match0(void){
	T0TCR = mCOUNTER_ENABLE;
	while((T0IR&mMR0_INTERRUPT) !=0 ){             // gdy wyzeruje sie timer koniec opůznienia
		}
	T0IR = T0IR | mMR0_INTERRUPT;
}
