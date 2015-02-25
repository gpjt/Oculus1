#include <Windows.h>
#include "OVR_CAPI.h"


int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int)
{
	ovr_Initialize();

	ovrHmd hmd = ovrHmd_Create(0);

	if (!hmd)
	{
		MessageBoxA(NULL, "Oculus Rift not detected.", "", MB_OK); 
		return(0); 
	}

	if (hmd->ProductName[0] == '\0')  
	{
		MessageBoxA(NULL, "Rift detected, display not enabled.", "", MB_OK);
	}

	ovrHmd_ConfigureTracking(
		hmd, 
		ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, 
		0
	);


	MessageBoxA(NULL, "Up and running, all initialized!", "", MB_OK);

	// Release and close down
	ovrHmd_Destroy(hmd);
	ovr_Shutdown();

	return(0);
}
