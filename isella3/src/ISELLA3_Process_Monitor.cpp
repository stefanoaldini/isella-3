/************************************************************************
Fraunhofer IPA, 2011
ISELLA3 - ArmModule 

Author: Attila Achenbach, email: attila.achenbach@googlemail.com
************************************************************************/

// ISELLA3 Process Monitor.cpp : Defines the class behaviors for the
// ProcessMonitor
//
// This file defines the behavior of the object ProcessMonitor by defining
// its functions.

// Includes added by AA
//#include "stdafx.h"
#include <sys/time.h>
#include "ISELLA3_Process_Monitor.h" // for the object ProcessMonitor and functions
#include "Definitions.h" // for using the Maxon Motor Control EPOS library
#include <iostream>
//#include <windows.h> // for using timers

unsigned long * CISELLA3ProcessMonitor::ulStart()
{
	gettimeofday(&T_Start,NULL);
	//sstrBuffer << "T_Start: " << (unsigned long)((double)(ulT_Start.QuadPart) * 1000000.0 / (double) ulFrequency.QuadPart) << " ";
	ulT_Start = (unsigned long)(double)(T_Start.tv_sec) * 1000000 + (unsigned long)(double)(T_Start.tv_usec);
	return &ulT_Start;
}

unsigned long * CISELLA3ProcessMonitor::ulStop()
{
	gettimeofday(&T_Stop,NULL);
	//sstrBuffer << "T_Stop: " << (unsigned long)((double)(ulT_Stop.QuadPart) * 1000000.0 / (double) ulFrequency.QuadPart) << " ";
	ulT_Stop = (unsigned long)(double)(T_Stop.tv_sec) * 1000000 + (unsigned long)(double)(T_Stop.tv_usec);
	return &ulT_Stop;
}

unsigned long * CISELLA3ProcessMonitor::ulTimestamp()
{
	gettimeofday(&T_Stamp,NULL);
	//sstrBuffer << "T_Start: " << (unsigned long)((double)(ulT_Start.QuadPart) * 1000000.0 / (double) ulFrequency.QuadPart) << " ";
	ulT_Stamp = (unsigned long)(double)(T_Stamp.tv_sec) * 1000000 + (unsigned long)(double)(T_Stamp.tv_usec);
	return &ulT_Stamp;
}

unsigned long * CISELLA3ProcessMonitor::ulDiff()
{
	ulT_Diff = (unsigned long)(double)(T_Stop.tv_sec - T_Start.tv_sec) * 1000000 + (unsigned long)(double)(T_Stop.tv_usec - T_Start.tv_usec);
	return &ulT_Diff;
}

unsigned long * CISELLA3ProcessMonitor::ulDiffTimestamp()
{
	ulT_Diff = (unsigned long)(double)(T_Stamp.tv_sec - T_Start.tv_sec) * 1000000 + (unsigned long)(double)(T_Stamp.tv_usec - T_Start.tv_usec);
	return &ulT_Diff;
}

// Write Process Data to file for monitoring (Overloaded method)
void CISELLA3ProcessMonitor::ClearBuffer()
{
	sstrBuffer.str(std::string());
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, bool * bValue)
{
	sstrBuffer << strValueTag << ": \t" << *bValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, short * sValue)
{
	sstrBuffer << strValueTag << ": \t" << *sValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, int * iValue)
{
	sstrBuffer << strValueTag << ": \t" << *iValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, double * dValue)
{
	sstrBuffer << strValueTag << ": \t" << *dValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, long * lValue)
{
	sstrBuffer << strValueTag << ": \t" << *lValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, unsigned long * ulValue)
{
	sstrBuffer << strValueTag << ": \t" << *ulValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, unsigned long ulValue)
{
	sstrBuffer << strValueTag << ": \t" << ulValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, float * fValue)
{
	sstrBuffer << strValueTag << ": \t" << *fValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, char * cValue)
{
	sstrBuffer << strValueTag << ": \t" << *cValue << " \t";
}

void CISELLA3ProcessMonitor::WriteProcessDataToBuffer(string strValueTag, string * strValue)
{
	sstrBuffer << strValueTag << ": \t" << *strValue << " \t";
}

void CISELLA3ProcessMonitor::WriteBufferEndl()
{
	sstrBuffer << endl;
}

void CISELLA3ProcessMonitor::WriteBufferToFile()
{
	processdatafile.open("ISELLA3_Process_Data33.txt");
	processdatafile << sstrBuffer.str();
	processdatafile.close();
	std::cout << "Data written to file" << endl;
}

void CISELLA3ProcessMonitor::WriteBufferToFile(string strFilename)
{
	processdatafile.open(strFilename.c_str());
	processdatafile << sstrBuffer.str();
	processdatafile.close();
}

void CISELLA3ProcessMonitor::MaxonRecorder()
{
}
