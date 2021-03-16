#pragma once

#define _FULL_SCREAN_ 1
#define _WINDOW_ 0

class ConsoleBufferString
{
	HANDLE hConsole;
	wchar_t* screen = nullptr;
	int _size = 0;
	int _console_width;
	int _console_height;	
	const COORD FirstCell = { 0, 0 };
	DWORD dwBytesWritten = 0;
	static ConsoleBufferString* _self;		
	ConsoleBufferString(bool full_screan);
	ConsoleBufferString(const ConsoleBufferString& orig) = delete;
	ConsoleBufferString(ConsoleBufferString&& orig) = delete;
	ConsoleBufferString& operator=(const ConsoleBufferString& orig) = delete;
	ConsoleBufferString& operator=(ConsoleBufferString&& orig) = delete;
	~ConsoleBufferString();
		
	void PrintVerticalLine(float Ray_size, int current_rays_amount, bool Is_wallblock_conor);

public:
	void HideCursor();
	int GetConsoleWidth();
	int GetConsoleHight();
	void SetFullScrean();
	void NotHighLightConsole();
	static ConsoleBufferString* Instance(bool full_screan);
	wchar_t operator[](int index) const;
	wchar_t& operator[](int index);
	void WriteChar(int index, wchar_t symbol);
	void WriteInBuffer();
	static bool DeleteInstance();
	void SetConsoleBufferMode();
	void Render(Map& map, Entity* player, FPS& _fps);
	void PrintDebugInfo(Entity* player, Map& map, FPS& _fps);
};
