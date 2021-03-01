

// Modified for application as a standalone API by Adam Sperry June 2017


/*****************************************************************
Name:               PolarisSpectra.h

Description:	This file is the header for the CommandHandling
				class. It defines everything required for the class.


All Northern Digital Inc. ("NDI") Media and/or Sample Code and/or
Sample Code Documentation (collectively referred to as "Sample Code")
is licensed and provided "as is" without warranty of any kind.  The
licensee, by use of the Sample Code, warrants to NDI that the Sample
Code is fit for the use and purpose for which the licensee intends to
use the Sample Code. NDI makes no warranties, express or implied, that
the functions contained in the Sample Code will meet the licensee’s
requirements or that the operation of the programs contained therein
will be error free.  This warranty as expressed herein is exclusive
and NDI expressly disclaims any and all express and/or implied, in fact
or in law, warranties, representations, and conditions of every kind
pertaining in any way to the Sample Code licensed and provided by NDI
hereunder, including without limitation, each warranty and/or condition
of quality, merchantability, description, operation, adequacy,
suitability, fitness for particular purpose, title, interference with
use or enjoyment, and/or non infringement, whether express or implied
by statute, common law, usage of trade, course of dealing, custom, or
otherwise.  No NDI dealer, distributor, agent or employee is authorized
to make any modification or addition to this warranty.

In no event shall NDI nor any of its employees be liable for any direct,
indirect, incidental, special, exemplary, or consequential damages,
sundry damages or any damages whatsoever, including, but not limited to,
procurement of substitute goods or services, loss of use, data or profits,
or business interruption, however caused.  In no event shall NDI’s
liability to the licensee exceed the amount paid by the licensee for the S
ample Code or any NDI products that accompany the Sample Code. The said
imitations and exclusions of liability shall apply whether or not any
such damages are construed as arising from a breach of a representation,
warranty, guarantee, covenant, obligation, condition or fundamental term
or on any theory of liability, whether in contract, strict liability, or
tort (including negligence or otherwise) arising in any way out of the
use of the Sample Code even if advised of the possibility of such damage.
In no event shall NDI be liable for any claims, losses, damages, judgments,
costs, awards, expenses or liabilities of any kind whatsoever arising
directly or indirectly from any injury to person or property, arising
from the Sample Code or any use thereof.


Copyright (C) 2002, 2003, Northern Digital Inc. All rights reserved.


*****************************************************************/

#ifndef POLARISSPECTRA_H
#define POLARISSPECTRA_H

#pragma once

#include "polarisspectralinux_global.h"
#include <cstdlib>
#include "APIStructures.h"
#include "Comm32.h"
#include "Conversions.h"
#include <map>
#include <cstring>

using namespace std;

/*****************************************************************
Defines   
*****************************************************************/
#define NUM_COM_PORTS		10	/* number of com ports */
#define POLARIS_SYSTEM		1	/* type of system, POLARIS */
#define AURORA_SYSTEM		2	/* or AURORA */
#define ACCEDO_SYSTEM		3	/* or ACCEDO */
#define VICRA_SYSTEM		4	/* or VICRA */
#define SPECTRA_SYSTEM	    5	/* or SPECTRA */

/*****************************************************************
Structures
*****************************************************************/
/* NONE */

/*****************************************************************
Routine Definitions
*****************************************************************/
	class POLARISSPECTRA_API PolarisSpectra {
		public:
			PolarisSpectra();
			virtual ~PolarisSpectra();


			/*****************************************************************
			Name:			close

			Inputs:
			None.

			Return Value:
			None.

			Description:   Handles closing the Polaris Spectra
			*****************************************************************/
			void close();


			/*****************************************************************
			Name:				nCloseComPorts

			Inputs:
			None.

			Return Value:
			int , 0 if fails and 1 is passes

			Description:
			This routine closes all open COM ports.
			*****************************************************************/
			int nCloseComPorts();


			/*****************************************************************
			Name:				nOpenComPort

			Inputs:
            char nPort - the port to be opened

			Return Value:
			int - 1if successful, 0 otherwise

			Description:
			This routine opens the selected com port and sets its settings
			to the default communication parameters
			*****************************************************************/
            int nOpenComPort(char *nPort);


			/*****************************************************************
			Name:

			Inputs:
			None.

			Return Value:
			int - 0 if it fails, nCheckResponse if passes

			Description:
			This routine sends a serial break to the system, reseting it.
			*****************************************************************/
			int nHardWareReset(bool bWireless);


			/*****************************************************************
			Name:				nSetSystemComParms

			Inputs:
			int nBaudRate - the baud rate to set
			int nDateBits - the data bit setting
			int nParity - the parity setting
			int nStopBits - the stop bit setting
			int nHardware - whether or not to use hardware handshaking

			Return Value:
			int - 0 if fails, else nCheckResponse

			Description:
			This routine sets the systems com port parameters, remember
			to immediatley set the computers com port settings after this
			routine is called.
			*****************************************************************/
			int nSetSystemComParms(int nBaudRate,
				int nDataBits,
				int nParity,
				int nStopBits,
				int nHardware);


			/*****************************************************************
			Name:				nSetSystemComParms

			Inputs:
			int nBaud - the baud rate to set
			int nDateBits - the data bit setting
			int nParity - the parity setting
			int nStop - the stop bit setting
			int nHardware - whether or not to use hardware handshaking

			Return Value:
			int - 0 if fails, else 1

			Description:
			This routine sets the computer's com port parameters, remember
			to immediatley set the computer's com port settings after the
			system's com port parameters.
			*****************************************************************/
			int nSetCompCommParms(int  nBaud,
				int nDataBits,
				int nParity,
				int nStop,
				int nFlowControl);


			/*****************************************************************
			Name:				nBeepSystem

			Inputs:
			int nBeeps - the number of times the system should beep

			Return Value:
			int - 0 if fails, else nCheckResponse

			Description:
			This routine sends the beep command to the System, causing
			it to beep.
			*****************************************************************/
			int nBeepSystem(int nBeeps);


			/*****************************************************************
			Name:				Initialize

			Inputs:
			None.

			Return Value:
			int - 0 if fails, else int - 1

			Description:    This routine handles all all the necessary commands
			for a complete initialization.
			*****************************************************************/
			int Initialize();


			/*****************************************************************
			Name:				nInitializeSystem

			Inputs:
			None.

			Return Value:
			int - 0 if fails, else nCheckResponse

			Description:   This routine initializes the System by sending the
			INIT command.  Remember to reset the appropriate
			variables.
			*****************************************************************/
			int nInitializeSystem();


			/*****************************************************************
			Name:				nSetFiringRate

			Inputs:
			None.

			Return Value:
			int - 0 if fails, else nCheckResponse

			Description:   This routine sets the POLARIS System's firing rate
			by sending the IRATE command.
			*****************************************************************/
			int nSetFiringRate();


			/*****************************************************************
			Name:				nGetSystemInfo

			Inputs:
			None.

			Return Value:
			int - 0 if fails, 1 if passes

			Description:   This routine gets the System information through
			the VER and SFLIST commands, remember that it is
			not the same calls for the AURORA and POLARIS the
			reply mode numbers are different.
			*****************************************************************/
			int nGetSystemInfo();


			/*****************************************************************
			Name:				nInitializeAllPorts

			Inputs:
			None.

			Return Value:
			int - 1 is successful, 0 otherwise

			Description:   This routine intializes all the ports using the
			PINIT call.  It also makes calls to the PVWR routine
			and TTCFG routine to virtual load tool definitions.
			*****************************************************************/
			int nInitializeAllPorts();


			/*****************************************************************
			Name:				nInitializeHandle

			Inputs:
			int nHandle - the handle to be intialized

			Return Value:
			int - 1 if successful, otherwise 0

			Description:   This routine initializes the specified handle using
			the PINIT command.
			*****************************************************************/
			int nInitializeHandle(int nHandle);


			/*****************************************************************
			Name:				nEnableAllPorts

			Inputs:
			None.

			Return Value:
			int - 1 if successful, 0 otherwise

			Description:   This routine enables all the port handles that need
			to be enabled using the PENA command.
			*****************************************************************/
			int nEnableAllPorts();


			/*****************************************************************
			Name:				nEnableOnePorts

			Inputs:
			None.

			Return Value:
			int - 1 if successful, 0 otherwise

			Description:   This routine enables specified port handles that need
			to be enabled using the PENA command.
			*****************************************************************/
			int nEnableOnePorts(int nPortHandle);


			/*****************************************************************
			Name:				nDisablePort

			Inputs:
			int nPortHandle - handle to be disabled

			Return Value:
			int - 1 if successful, 0 otherwise

			Description:    This routine disables the supplied port handle
			using the PDIS call.
			*****************************************************************/
			int nDisablePort(int nPortHandle);


			/*****************************************************************
			Name:				nActivateAllPorts

			Inputs:
			None.

			Return Value:
			int - 1 if successful, 0 otherwise

			Description:    This is the routine that activates all ports using

			*****************************************************************/
			int nActivateAllPorts();


			/*****************************************************************
			Name:			nLoadTTCFG

			Inputs:
			char * pszPortID - the physical port to be loaded with TTCFG

			Return Value:
			int - 1 if successful, 0 otherwise

			Description:
			This routine loads the Test Tool ConFiGutation to the specified
			port.
			*****************************************************************/
			int nLoadTTCFG(char * pszPortID);


			/*****************************************************************
			Name:				nGetHandleForPort

			Inputs:
			char * pszPortID - the physical port to match a handle to

			Return Value:
			int - 0 if fails, port handle if passes

			Description:
			This routine takes a physical port location and matches a handle
			to it.  These handles have already been defined with a PHSR
			*****************************************************************/
			int nGetHandleForPort(char * pszPortID);


			/*****************************************************************
			Name:				nLoadVirtualSROM

			Inputs:
			char * pszFileName - the file to be loaded
			char * pszPhysicalPortID - the physical port id that is being
			loaded to.
			bool bPassive - is this a passive port or not

			Return Value:
			int - 1 if successful, 0 otherwise.

			Description:
			This routine virtual loads a SROM file to the specified port.
			It uses the PVWR command to do this.
			*****************************************************************/
			int nLoadVirtualSROM(char * pszFileName,
				char * pszPhysicalPortID,
				bool bPassive);


			/*****************************************************************
			Name:				nFreePortHandles

			Inputs:
			None.

			Return Value:
			int - 0 if fails, 1 if passes

			Description:
			This routine frees all port handles that need to be freed
			using the PHF command.
			*****************************************************************/
			int nFreePortHandles();


			/*****************************************************************
			Name:				nGetPortInformation

			Inputs:
			int nPortHandle - the handle to get information for

			Return Value:
			int - 1 if successful, 0 otherwise

			Description:
			This routine gets the port handling information for the supplied
			handle.  It uses the PHINF call to get this information.
			*****************************************************************/
			int nGetPortInformation(int nPortHandle);


			/*****************************************************************
			Name:				nStartTracking

			Inputs:
			None.

			Return Value:
			int - 0 if fails, else nCheckResponse

			Description:    This routine starts that System tracking.  It uses
			the TSTART command to do this.
			*****************************************************************/
			int nStartTracking();


			/*****************************************************************
			Name:				nGetTXTransforms

			Inputs:
			bool bReturnOOV - whether or not to return values outside
			of the characterized volume.

			Return Value:
			int - 1 if successful, 0 otherwise.

			Description:
			This routine gets the transformation information using the TX
			command.  Remember that if you want to track outside the
			characterized volume you need to set the flag.
			*****************************************************************/
			int nGetTXTransforms(bool bReportOOV);


			/*****************************************************************
			Name:				nGetBXTransforms

			Inputs:
			bool bReturnOOV - whether or not to return values outside
			of the characterized volume.

			Return Value:
			int - 1 if successful, 0 otherwise.

			Description:
			This routine gets the transformation information using the BX
			command.  Remember that if you want to track outside the
			characterized volume you need to set the flag.
			*****************************************************************/
			int nGetBXTransforms(bool bReportOOV);


			/*****************************************************************
			Name:				nStopTracking

			Inputs:
			None.

			Return Value:
			int - 0 if fails, nCheckResponse if passes

			Description:   This routine stops the System's tracking by using
			the TSTOP call.
			*****************************************************************/
			int nStopTracking();


			/*****************************************************************
			Name:				nGetNewAlerts

			Inputs:
			None.

			Return Value:
			int - 0 if fails, 1 if passes

			Description:   This routine gets the new alerts and fills the
			new alerts structure with the appropriate flags.
			***********************************************************/
			int nGetAlerts(bool bNewAlerts);


			/*****************************************************************
			Name:				ErrorMessage

			Inputs:
			None.

			Return Value:
			None.

			Description:    This routine loads and displays the error that
			corresponds with the reply string from the system.
			*****************************************************************/
			void ErrorMessage();


			/*****************************************************************
			Name:				WarningMessage

			Inputs:
			None.

			Return Value:
			None.

			Description:    This routine loads and displays the warning that
			corresponds with the reply string from the system.
			*****************************************************************/
			void WarningMessage();


			/***********************************************************
			Name: CreateTimeoutTable

			Returns: int

			Description: Retrieves the timeout values for each API
			command and creates a list of them
			***********************************************************/
			int CreateTimeoutTable();


			/***********************************************************
			Name: nLookupTimeout

			Returns: int
			Argument: char *szCommand

			Description: Looks up the command in the Timeout value list
			(m_dtTimeoutValues) and returns the timeout
			value for the specified command
			***********************************************************/
			int nLookupTimeout(char *szCommand);
			

			/*****************************************************************
			Variables
			*****************************************************************/
			bool
				m_bLogToFile,				/* log to file */
				m_bDateTimeStampFile,		/* include date and time stamp in log file */
				m_bIsTracking;				/* used to keep track of whether the system is tracking */
			char
                m_szLogFile[5000];		/* log file name */

			SystemInformation
				m_dtSystemInformation;		/* System Information variable - structure */

			HandleInformation
				m_dtHandleInformation[NO_HANDLES];	/* Handle Information variable - structure */

			int
				m_nRefHandle; /* the handle for the tool acting as the reference tool */

			DiagNewAlertFlags
				m_dtNewAlerts; /* alert information */

            map<const char*, int>
				m_dtTimeoutValues;

		protected:
			/*****************************************************************
			Routine Definitions
			*****************************************************************/
			void ApplyXfrms();
			int nSendMessage(char * pszCommand, bool bAddCRC);
			int nGetResponse();
			int nGetBinaryResponse();
			int nVerifyResponse(char * pszReply, bool bCheckCRC);
			int nCheckResponse(int nResponse);
			void LogToFile(int nDirection, char *psz);

			void InitCrcTable();
			unsigned int CalcCrc16(unsigned int crc, int data);
			unsigned CalcCRCByLen(char *pszString, int nLen);
			int SystemCheckCRC(char *psz);
			unsigned int SystemGetCRC(char *psz, int nLength);

			int nAddCRCToCommand(char * pszCommandString);
			int nAddCRToCommand(char * pszCommandString);
			int nBuildCommand(char * pszCommandString, bool bAddCRC);

			/*****************************************************************
			Variables
			*****************************************************************/
			Comm32Port
				*pCOMPort;					/* pointer to the Comm32 class */

			char
				m_szLastReply[MAX_REPLY_MSG],	/* Last reply received from the system */
				m_szCommand[MAX_COMMAND_MSG];		/* command to send to the system */
			bool
				m_bClearLogFile,				/* clear log file on intialization */
				m_bDisplayErrorsWhileTracking;	/* display the error while tracking */
			int
				m_nTimeout,
				m_nDefaultTimeout;						/* timeout value in seconds */
			bool
				bComPortOpen[NUM_COM_PORTS];	/* array of com ports - if true they are open */
			int
				m_nPortsEnabled;				/* the number of port enable by nEnableAllPorts */
	};
/************************END OF FILE*****************************/

#endif // POLARISSPECTRA_H
