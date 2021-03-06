#pragma once

//#define DEBUG
#define _FULL_SCREAN_ 1
#define _WINDOW_ 0

class ConsoleBufferString
{
	HANDLE hConsole;
	wchar_t* screen = nullptr;
	int _size = 0;
	int _console_width;
	int _console_height;	
	char previous_symbol;
	const COORD FirstCell = { 0, 0 };
	DWORD dwBytesWritten = 0;
	static ConsoleBufferString* _self;		
	bool PlayerHasMap = false;

	ConsoleBufferString(bool full_screan);
	ConsoleBufferString(const ConsoleBufferString& orig) = delete;
	ConsoleBufferString(ConsoleBufferString&& orig) = delete;
	ConsoleBufferString& operator=(const ConsoleBufferString& orig) = delete;
	ConsoleBufferString& operator=(ConsoleBufferString&& orig) = delete;
	~ConsoleBufferString();
		
	struct VerticalLine
	{
		GameObject& _object;
		float _position_ray_x;
		float _position_ray_y;
		float _ray_size;
		int   _current_rays_amount;
		bool  _Is_wallblock_conor;

		VerticalLine(GameObject& object, float position_ray_x,
			float position_ray_y, float ray_size,
			int current_rays_amount, bool Is_wallblock_conor) : _object(object)
		{
			_position_ray_x = position_ray_x;
			_position_ray_y = position_ray_y;
			_ray_size = ray_size;
			_current_rays_amount = current_rays_amount;
			_Is_wallblock_conor = Is_wallblock_conor;
		}

		void PrintObject();
		void PrintCircle();
		void PrintRectangle();
		void PrintTriangle();
		void PrintRhombus();
		void PrintMedKit();
		void PrintDoor();
		void PrintTrap();
		void PrintWeakTrap();
		void PrintMediumTrap();
		void PrintStrongTrap();
		void PrintExit();

		static void PrintWall(float ray_size, int current_rays_amount, bool Is_wallblock_conor);
	};

	stack<VerticalLine> DetectedObjects;

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
	void Render(Map& map, Player& player, FPS& _fps, GameSpace& gameSpace);
	void PrintDebugInfo(const Player& player, Map& map, FPS& _fps, const GameSpace& gameSpace);
	void PrintStat(Map& map, const Player& player);
	void PrintGameOver();
	void PrintWin();
	void ClearScrean();
	void PrintStringInCenter(string& str);
};
