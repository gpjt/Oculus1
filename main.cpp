#include <Windows.h>
#include "OVR_CAPI.h"


int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int)
{
	ovr_Initialize();

	ovrHmd HMD = ovrHmd_Create(0);

	if (!HMD)
	{
		MessageBoxA(NULL, "Oculus Rift not detected.", "", MB_OK); return(0); 
	}

	if (HMD->ProductName[0] == '\0')  
	{
		MessageBoxA(NULL, "Rift detected, display not enabled.", "", MB_OK);
	}

	MessageBoxA(NULL, "Up and running, all initialized!", "", MB_OK);

	// Release and close down
	ovrHmd_Destroy(HMD);
	ovr_Shutdown();

	return(0);
}
