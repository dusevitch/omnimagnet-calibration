

// Modified for application as a standalone API by Adam Sperry June 2017


/*****************************************************************
Name:               Conversion.h

Description:	This is the header for the conversion.cpp file.
				It includes the definitions for the conversion
				routines.


All Northern Digital Inc. ("NDI") Media and/or Sample Code and/or
Sample Code Documentation (collectively referred to as "Sample Code")
is licensed and provided "as is" without warranty of any kind.  The
licensee, by use of the Sample Code, warrants to NDI that the Sample
Code is fit for the use and purpose for which the licensee intends to
use the Sample Code. NDI makes no warranties, express or implied, that
the functions contained in the Sample Code will meet the licensee's
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
or business interruption, however caused.  In no event shall NDI's
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

#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "polarisspectralinux_global.h"

/*****************************************************************
Defines   
*****************************************************************/
#define RAD_TO_DEGREES        (180 / 3.1415926) 

/*****************************************************************
Structures
*****************************************************************/


/*****************************************************************
Variables
*****************************************************************/


/*****************************************************************
Routine Definitions
*****************************************************************/
	unsigned int uASCIIToHex( char szStr[], int nLen );
    bool bExtractValue( char *pszVal, unsigned uLen, float fDivisor, float *pfValue );

	int nGetHex2(char *sz);
	int nGetHex1(char *sz);
	int nGetHex4(char *sz);
	float fGetFloat(char *sz);

    extern "C" {
		/********************************************************************
		Name:        CvtQuatToRotationMatrix

		Input Values:
		QuatRotation
		*pdtQuatRot :Ptr to the quaternion rotation.

		Output Values:
		RotationMatrix
		dtRotationMatrix :The 3x3 determined rotation matrix.

		Returned Value:
		None.
		Description:
		This routine determines the rotation matrix that corresponds
		to the given quaternion.

		Let the quaternion be represented by:

		| Q0 |
		Q = | Qx |
		| Qy |
		| Qz |

		and the rotation matrix by:

		| M00 M01 M02 |
		M = | M10 M11 M12 |
		| M20 M21 M22 |

		then assuming the quaternion, Q, has been normalized to convert
		Q to M we use the following equations:

		M00 = (Q0 * Q0) + (Qx * Qx) - (Qy * Qy) - (Qz * Qz)
		M01 = 2 * ((Qx * Qy) - (Q0 * Qz))
		M02 = 2 * ((Qx * Qz) + (Q0 * Qy))
		M10 = 2 * ((Qx * Qy) + (Q0 * Qz))
		M11 = (Q0 * Q0) - (Qx * Qx) + (Qy * Qy) - (Qz * Qz)
		M12 = 2 * ((Qy * Qz) - (Q0 * Qx))
		M20 = 2 * ((Qx * Qz) - (Q0 * Qy))
		M21 = 2 * ((Qy * Qz) + (Q0 * Qx))
		M22 = (Q0 * Q0) - (Qx * Qx) - (Qy * Qy) + (Qz * Qz)
		*********************************************************************/
        void POLARISSPECTRA_API CvtQuatToRotationMatrix(QuatRotation *pdtQuatRot,
                                        RotationMatrix dtRotMatrix);


		/*******************************************************************
		Name:         DetermineEuler

		Input Values:
		RotationMatrix
		dtRotationMatrix :The 3x3 rotation matrix to convert.

		Output Values:
		Rotation
		*pdtEulerRot :Rotation is Euler angle format.
		Roll, pitch, yaw Euler angles which define the required rotation.

		Returned Value:
		None.

		Description:
		This routine calculates the Euler angles given the 3x3 rotation matrix.
		*******************************************************************/
        void POLARISSPECTRA_API DetermineEuler(RotationMatrix dtRotMatrix, Rotation *pdtEulerRot);


		/**************************************************************
		Name:        CvtQuatToEulerRotation

		Input Values:
		QuatRotation
		*pdtQuatRot :Ptr to the quaternion rotation.

		Output Values:
		Rotation
		*pdtEulerRot :Ptr to the determined rotation Euler angles.

		Returned Value:
		None.

		Description:
		This routine determines the rotation in Euler angles (degrees)that
		corresponds to the given quaternion rotation.
		******************************************************************/
        void POLARISSPECTRA_API CvtQuatToEulerRotation(QuatRotation *pdtQuatRot, Rotation *pdtEulerRot);


		/*****************************************************************
		Name:               QuatRotatePoint

		Input Values:
		QuatRotation
		*RotationQuaternionPtr: pointer to the quaternion
		defining the rotation

		QuatVector3dStruct
		*OriginalPositionPtr  : pointer to struct containing the
		original position of the given point
		*RotatedPositionPtr   : pointer to struct containing the
		rotated position of the given point

		Output Values:
		The vector pointed to by RotatedPositionPtr is over written
		with the calculated position of the point after rotation.

		Returned Value:
		None

		Description:
		This routine calculates the 3-D position of a given point after
		being rotated by a rotation defined by the given quaternion

		*****************************************************************/
        void POLARISSPECTRA_API QuatRotatePoint(QuatRotation *RotationQuaternionPtr,
                                Position3d   *OriginalPositionPtr,
                                Position3d   *RotatedPositionPtr);


		/*****************************************************************
		Name:            QuatInverseXfrm

		Input Values:
		QuatTransformation
		*pdtXfrm             : input transformation

		Output Values:
		QuatTransformation
		*pdtNewXfrm          : new inversed transformation

		Returned Value:
		None

		Description:
		This routine determines the inverse transform to the given
		transformation

		*****************************************************************/
        void POLARISSPECTRA_API QuatInverseXfrm(QuatTransformation *pdtXfrm, QuatTransformation *pdtNewXfrm);


		/*****************************************************************
		Name:            QuatCombineXfrms

		Input Values:
		QuatTransformation
		*pdtXfrm12           : Transformation from RF 1 to RF 2
		*pdtXfrm23           : Transformation from RF 2 to RF 3

		Output Values:
		QuatTransformation
		*pdtXfrm13           : Output Transformation from RF 1 to RF 3

		Returned Value:
		None

		Description:
		This routine combines the input transformations from RF 1 to RF 2
		and RF 2 to RF 3 to generate a new transformation from RF 1 to RF 3
		*****************************************************************/
        void POLARISSPECTRA_API QuatCombineXfrms(QuatTransformation *pdtXfrm12,
                                QuatTransformation *pdtXfrm23,
                                QuatTransformation *pdtXfrm13);
    }

#endif
/************************END OF FILE*****************************/

