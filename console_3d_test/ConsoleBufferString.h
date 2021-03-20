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
	ConsoleBufferString(bool full_screan);
	ConsoleBufferString(const ConsoleBufferString& orig) = delete;
	ConsoleBufferString(ConsoleBufferString&& orig) = delete;
	ConsoleBufferString& operator=(const ConsoleBufferString& orig) = delete;
	ConsoleBufferString& operator=(ConsoleBufferString&& orig) = delete;
	~ConsoleBufferString();
		
	struct VerticalLine
	{
		char  _symbol;
		float _position_ray_x;
		float _position_ray_y;
		float _ray_size;
		int   _current_rays_amount;
		bool  _Is_wallblock_conor;

		VerticalLine(char symbol, float position_ray_x,
			float position_ray_y, float ray_size,
			int current_rays_amount, bool Is_wallblock_conor)
		{
			_symbol = symbol;
			_position_ray_x = position_ray_x;
			_position_ray_y = position_ray_y;
			_ray_size = ray_size;
			_current_rays_amount = current_rays_amount;
			_Is_wallblock_conor = Is_wallblock_conor;
		}

		void PrintCircle()
		{
			float radius = (_self->_console_height / 2) * 0.3f;
			float center = (float)(trunc(_position_ray_x)) + 0.5f;
			float x = _position_ray_x + (abs(center - _position_ray_x) * radius) / 0.3;

			float r_sqare = pow(radius, 2);
			float x_sqare = pow((x - center), 2);
			int height = ceil(2 * sqrt(r_sqare - x_sqare));

			int highest_y = (float)(_self->_console_height / 2.0f) - (float)height / _ray_size;
			int lowest_y = _self->_console_height - highest_y;

			for (int j = 0; j < _self->_console_height; j++)
			{
				if (j >= highest_y && j <= lowest_y)
				{
					_self->screen[j * _self->_console_width + _current_rays_amount] = (wchar_t)_symbol;
					#ifdef DEBUG
					WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
					#endif
				}
			}
		}

		void PrintWall()
		{
			_self->previous_symbol = '!';

			int highest_y = (float)(_self->_console_height / 2.0f)
				- (float)_self->_console_height / _ray_size;
			int lowest_y = _self->_console_height - highest_y;

			for (int j = 0; j < _self->_console_height; j++)
			{
				if (j < highest_y)
					_self->screen[j * _self->_console_width + _current_rays_amount] = ' ';
				else if (j >= highest_y && j <= lowest_y)
				{
					if (_Is_wallblock_conor)
					{
						_self->screen[j * _self->_console_width + _current_rays_amount] = ' ';
					}
					else
					{
						if (_ray_size >= 18)
						{
							_self->screen[j * _self->_console_width + _current_rays_amount] = 9617;
						}
						else if (_ray_size < 18 && _ray_size >= 12)
						{
							_self->screen[j * _self->_console_width + _current_rays_amount] = 9618;
						}
						else if (_ray_size < 12 && _ray_size >= 6)
						{
							_self->screen[j * _self->_console_width + _current_rays_amount] = 9619;
						}
						else if (_ray_size < 6)
						{
							_self->screen[j * _self->_console_width + _current_rays_amount] = 9608;
						}
					}
				}

				else if (j > lowest_y)
				{
					if (j <= _self->_console_height / 2.0f + (_self->_console_height / 8.0f))
					{
						_self->screen[j * _self->_console_width + _current_rays_amount] = '.';
					}
					else if (j > _self->_console_height / 2.0f + (_self->_console_height / 8.0f)
						&& j <= _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 2)
					{
						_self->screen[j * _self->_console_width + _current_rays_amount] = ':';
					}
					else if (j > _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 2
						&& j <= _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 3)
					{
						_self->screen[j * _self->_console_width + _current_rays_amount] = '?';
					}
					else if (j > _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 3
						&& j <= _self->_console_height)
					{
						_self->screen[j * _self->_console_width + _current_rays_amount] = '#';
					}
				}
			}
		}
	};

	stack<VerticalLine> DetectedObjects;

	//void PrintVerticalLine(VerticalLine vertical_line);

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
	void Render(Map& map, Item& item, Entity& player, FPS& _fps);
	void PrintDebugInfo(Entity& player, Map& map, FPS& _fps);
};
