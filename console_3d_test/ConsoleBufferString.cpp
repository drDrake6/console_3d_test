#include "Headers.h"

ConsoleBufferString* ConsoleBufferString::_self = nullptr;

ConsoleBufferString::ConsoleBufferString(bool full_screan)
{
	SetConsoleBufferMode();
	SetConsoleActiveScreenBuffer(hConsole);

	if (full_screan)
	{
		SetFullScrean();

		HDC hDCScreen = GetDC(NULL);
		int Horres = GetDeviceCaps(hDCScreen, HORZRES);
		int Vertres = GetDeviceCaps(hDCScreen, VERTRES);
		ReleaseDC(NULL, hDCScreen);

		_console_width = Horres / 8;
		_console_height = Vertres / 16;
	}
	
	else
	{
		HWND hWnd = GetConsoleWindow();
		RECT rc;
		GetClientRect(hWnd, &rc);
		_console_width = rc.right / 8;
		_console_height = rc.bottom / 16;
	}

	_size = _console_width * _console_height + 1;
	screen = new wchar_t[_size];
	
	for (size_t i = 0; i < _size; i++)
	{
		screen[i] = ' ';
	}

	screen[_size] = '\0';

	WriteInBuffer();
}

ConsoleBufferString::~ConsoleBufferString()
{
	if (!screen)
	{
		delete[] screen;
	}
}

void ConsoleBufferString::PrintVerticalLine(float ray_size, int current_rays_amount, bool Is_wallblock_conor)
{
	int hjghest_y = (float)(_console_height / 2.0f) - (float)_console_height / ray_size;
	int lowest_y = _console_height - hjghest_y;

	for (int j = 0; j < _console_height; j++)
	{
		if (j < hjghest_y)
			screen[j * _console_width + current_rays_amount] = ' ';
		else if (j >= hjghest_y && j <= lowest_y)  
		{
			if (Is_wallblock_conor)
			{
				screen[j * _console_width + current_rays_amount] = ' ';
			}
			else
			{
				if (ray_size >= 18)
				{
					screen[j * _console_width + current_rays_amount] = 9617;
				}
				else if (ray_size < 18 && ray_size >= 12)
				{
					screen[j * _console_width + current_rays_amount] = 9618;
				}
				else if (ray_size < 12 && ray_size >= 6)
				{
					screen[j * _console_width + current_rays_amount] = 9619;
				}
				else if (ray_size < 6)
				{
					screen[j * _console_width + current_rays_amount] = 9608;
				}
			}
		}
			
		else if (j > lowest_y)
		{
			if (j <= _console_height / 2.0f + (_console_height / 8.0f))
			{
				screen[j * _console_width + current_rays_amount] = '.';
			}
			else if (j > _console_height / 2.0f + (_console_height / 8.0f)
				&& j <= _console_height / 2.0f + (_console_height / 8.0f) * 2)
			{
				screen[j * _console_width + current_rays_amount] = ':';
			}
			else if (j > _console_height / 2.0f + (_console_height / 8.0f) * 2
				&& j <= _console_height / 2.0f + (_console_height / 8.0f) * 3)
			{
				screen[j * _console_width + current_rays_amount] = '?';
			}
			else if (j > _console_height / 2.0f + (_console_height / 8.0f) * 3
				&& j <= _console_height)
			{
				screen[j * _console_width + current_rays_amount] = '#';
			}
		}
	}
}

void ConsoleBufferString::HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = 0;
	SetConsoleCursorInfo(hConsole, &info);
}

int ConsoleBufferString::GetConsoleWidth()
{
	return _console_width;
}

int ConsoleBufferString::GetConsoleHight()
{
	return _console_height;
}

void ConsoleBufferString::SetFullScrean()
{
	keybd_event(VK_MENU, 0x38, 0, 0);		//press ALT
	keybd_event(VK_RETURN, 0x1c, 0, 0);	//press ENTER
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);	//release ENTER
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);	//release ALT
}

void ConsoleBufferString::NotHighLightConsole()
{
	DWORD prev_mode;
	GetConsoleMode(hConsole, &prev_mode);
	SetConsoleMode(hConsole, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

ConsoleBufferString* ConsoleBufferString::Instance(bool full_screan)
{
	if (!_self)
	{
		_self = new ConsoleBufferString(full_screan);
	}
	return _self;
}

wchar_t ConsoleBufferString::operator[](int index) const
{
	return screen[index];
}

wchar_t& ConsoleBufferString::operator[](int index)
{
	return screen[index];
}

void ConsoleBufferString::WriteChar(int index, wchar_t symbol)
{
	screen[index] = symbol;
}

void ConsoleBufferString::WriteInBuffer()
{
	if (screen)
	{
		WriteConsoleOutputCharacter(hConsole, screen, _size, FirstCell, &dwBytesWritten);
	}
}

bool ConsoleBufferString::DeleteInstance()
{
	if (_self)
	{
		delete _self;
		_self = nullptr;
		return true;
	}
	return false;
}

void ConsoleBufferString::SetConsoleBufferMode()
{
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // Буфер экрана
}

void ConsoleBufferString::Render(Map& map, Entity* player, FPS& _fps)
{
	float conor_per_ray = player->GetConorOfView() / _console_width;
	float current_conor = player->GetView_Position();
	float Point_On_RayX;
	float Point_On_RayY;

	for (int i = _console_width - 1; i >= 0; i--)
	{
		Point_On_RayX = 0;
		Point_On_RayY = 0;

		bool Is_wallblock_conor = false;

		float conor_cos = cosf(current_conor);
		float conor_sin = sinf(current_conor);

		for (float ray_size = 0;;)
		{
			ray_size += 0.1f;					

			Point_On_RayX = player->GetPosition_X() + ray_size * conor_cos;
			Point_On_RayY = player->GetPosition_Y() + ray_size * conor_sin;

			if (map[(short)Point_On_RayX][(short)Point_On_RayY] != ' ')
			{
				vector<pair<float, float>> p;
				for (int wall_conor_y = 0; wall_conor_y < 2; wall_conor_y++)
				{
					for (int wall_conor_x = 0; wall_conor_x < 2; wall_conor_x++)
					{
						float vect_y = (int)Point_On_RayY + wall_conor_y - player->GetPosition_Y();
						float vect_x = (int)Point_On_RayX + wall_conor_x - player->GetPosition_X();

						float current_rayX = Point_On_RayX - player->GetPosition_X();
						float current_rayY = Point_On_RayY - player->GetPosition_Y();

						float module = sqrt(pow(vect_x, 2) + pow(vect_y, 2));

						float scalar_product = current_rayY * vect_y + current_rayX * vect_x;
						float modules_product = module * ray_size;
						float current_cos = scalar_product / modules_product;
						p.push_back(make_pair(module, current_cos));
					}
				}

				sort(p.begin(), p.end());

				if (acos(p.at(0).second) <= conor_per_ray / 2)
					Is_wallblock_conor = true;
				if (acos(p.at(1).second) <= conor_per_ray / 2)
					Is_wallblock_conor = true;
				if (acos(p.at(2).second) <= conor_per_ray / 2)
					Is_wallblock_conor = true;

				PrintVerticalLine(ray_size, i, Is_wallblock_conor);
				break;
			}
		}
		if (current_conor + conor_per_ray >= 360)
		{
			current_conor = 0;
		}
		else
		{
			current_conor += conor_per_ray;
		}
	}

	PrintDebugInfo(player, map, _fps);

	WriteInBuffer();
}

void ConsoleBufferString::PrintDebugInfo(Entity* player, Map& map, FPS& _fps)
{
	swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, PV=%3d, FPS=%2.2f", 
		player->GetPosition_X(), player->GetPosition_Y(), 
		(int)abs(((player->GetView_Position() * 180.0f) / 3.14f)) % 360, 
		1.0f / _fps.GetFPS());

	for (int nx = 0; nx < map.GetHeight(); nx++)
		for (int ny = 0; ny < map.GetWidth(); ny++)
		{
			screen[(nx + 1) * _console_width + ny] = map[nx][ny];
		}
	screen[((int)(player->GetPosition_X()) + 1) * _console_width + (int)(player->GetPosition_Y())] = 'P';

	screen[_size - 1] = '\0';
}
