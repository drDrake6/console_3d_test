#pragma once
class FPS
{
	chrono::duration<float> Current_frame;
	chrono::time_point<chrono::system_clock> frame_1;
	chrono::time_point<chrono::system_clock> frame_2;
	float fps;
	
public:
	FPS();
	void current_Calc_Period();
	float GetFPS();
};

