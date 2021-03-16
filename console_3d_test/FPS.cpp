#include "Headers.h"
FPS::FPS()
{
	frame_1 = chrono::system_clock::now();
	frame_2 = chrono::system_clock::now();
}

void FPS::current_Calc_Period()
{
	frame_2 = chrono::system_clock::now();
	Current_frame = frame_2 - frame_1;
	frame_1 = frame_2;
	fps = Current_frame.count();
}

float FPS::GetFPS()
{
	return fps;
}
