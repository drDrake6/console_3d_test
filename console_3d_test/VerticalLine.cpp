#include "Headers.h"

void ConsoleBufferString::VerticalLine::PrintObject()
{
	switch (_object.GetSymbol())
	{
	    case 'o':
	    	PrintCircle();
	    	break;
	    case '=':
	    	PrintRectangle();
	    	break;
		case '^':
			PrintTriangle();
			break;
		case 'X':
			PrintRhombus();
			break;
		case '+':
			PrintMedKit();
			break;
		case 'T':
			PrintTrap();
	    default:
	    	break;
	}
}

void ConsoleBufferString::VerticalLine::PrintCircle()
{
	Door* door = dynamic_cast<Door*>(&_object);
	if (door)
	{
		PrintDoor();
		return;
	}

	float size = 0.3f;
	float radius = (_self->_console_height / 2) * size;
	float center = _object.GetPosition_X();
	float x = _position_ray_x + (abs(center - _position_ray_x) * radius) / size;

	float r_sqare = pow(radius, 2);
	float x_sqare = pow((x - center), 2);
	int height = ceil(2 * sqrt(r_sqare - x_sqare));

	int highest_y = (float)(_self->_console_height / 2.0f) 
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount]
				= (wchar_t)_object.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintRectangle()
{
	float size = 3.0f;
	int height = (_self->_console_height) / size;
	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount] 
				= (wchar_t)_object.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintTriangle()
{
	Door* door = dynamic_cast<Door*>(&_object);
	if (door)
	{
		PrintDoor();
		return;
	}

	float size = 0.2f;
	float h = (_self->_console_height / 2.0f) * size;
	float x = (abs(_object.GetPosition_X() - _position_ray_x)) * (h / size);

	int height;
	if (x < 0)
		height = x * 2;
	else
		height = x * 2 - 2 * (x * 2 - h);

	int highest_y = ((float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size);
	int lowest_y = _self->_console_height -
		((float)(_self->_console_height / 2.0f) - 
		(h * 2) / _ray_size);

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount] 
				= (wchar_t)_object.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if(j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintRhombus()
{
	Door* door = dynamic_cast<Door*>(&_object);
	if (door)
	{
		PrintDoor();
		return;
	}

	float size = 0.25f;
	float h = ((float)(_self->_console_height) / 2.0f) * size;
	float x = (abs(_object.GetPosition_X() - _position_ray_x)) * (h / size);
	
	int height;
	if (x < 0)
		height = x;
	else
		height = x - 2 * (x - h);
	
	int highest_y = ((float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size);
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount] 
				= (wchar_t)_object.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintMedKit()
{
	float size = 2.0f;
	int h = (_self->_console_height) / size;
	float x = (abs(_object.GetPosition_X() - _position_ray_x)) * (h * size);

	int height;

	if (x <= _self->_console_height / (size * 3))
	{
		height = h;
	}
	else
	{
		height = h / 3;
	}

	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount]
				= (wchar_t)_object.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintDoor()
{
	int height = (_self->_console_height);
	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width
				+ _current_rays_amount] = (wchar_t)_object.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintTrap()
{
	Trap& trap = dynamic_cast<Trap&>(_object);

	if(trap.GetDamage() == 5.0f)
		PrintWeakTrap();
	else if (trap.GetDamage() == 10.0f)
		PrintMediumTrap();
	else if (trap.GetDamage() == 15.0f)
		PrintStrongTrap();
}

void ConsoleBufferString::VerticalLine::PrintWeakTrap()
{

	int height = (_self->_console_height);
	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			if (_ray_size >= 18)
			{
				_self->screen[j * _self->_console_width
					+ _current_rays_amount] = 9617;
			}
			else if (_ray_size < 18 && _ray_size >= 12)
			{
				_self->screen[j * _self->_console_width
					+ _current_rays_amount] = 9618;
			}
			else if (_ray_size < 12)
			{
				_self->screen[j * _self->_console_width
					+ _current_rays_amount] = 9619;
			}
			
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintMediumTrap()
{
	int height = (_self->_console_height);
	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			if (_ray_size >= 18)
			{
				_self->screen[j * _self->_console_width
					+ _current_rays_amount] = 9617;
			}
			else
			{
				_self->screen[j * _self->_console_width
					+ _current_rays_amount] = 9618;
			}
			
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintStrongTrap()
{
	int height = (_self->_console_height);
	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width
				+ _current_rays_amount] = 9617;
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
		else if (j > lowest_y)
		{
			return;
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintWall(float ray_size, int current_rays_amount, bool Is_wallblock_conor)
{
	_self->previous_symbol = '!';

	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)_self->_console_height / ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j < highest_y)
			_self->screen[j * _self->_console_width + current_rays_amount] = ' ';
		else if (j >= highest_y && j <= lowest_y)
		{
			if (Is_wallblock_conor)
			{
				_self->screen[j * _self->_console_width + current_rays_amount] 
					= ' ';
			}
			else
			{
				if (ray_size >= 18)
				{
					_self->screen[j * _self->_console_width 
						+ current_rays_amount] = 9617;
				}
				else if (ray_size < 18 && ray_size >= 12)
				{
					_self->screen[j * _self->_console_width 
						+ current_rays_amount] = 9618;
				}
				else if (ray_size < 12 && ray_size >= 6)
				{
					_self->screen[j * _self->_console_width 
						+ current_rays_amount] = 9619;
				}
				else if (ray_size < 6)
				{
					_self->screen[j * _self->_console_width 
						+ current_rays_amount] = 9608;
				}
			}
		}

		else if (j > lowest_y)
		{
			if (j <= _self->_console_height / 2.0f + (_self->_console_height / 8.0f))
			{
			_self->screen[j * _self->_console_width + current_rays_amount] = '.';
			}
			else if (j > _self->_console_height / 2.0f + (_self->_console_height / 8.0f)
			&& j <= _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 2)
			{
			_self->screen[j * _self->_console_width + current_rays_amount] = ':';
			}
			else if (j > _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 2
			&& j <= _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 3)
			{
			_self->screen[j * _self->_console_width + current_rays_amount] = '?';
			}
			else if (j > _self->_console_height / 2.0f + (_self->_console_height / 8.0f) * 3
			&& j <= _self->_console_height)
			{
			_self->screen[j * _self->_console_width + current_rays_amount] = '#';
			}
		}
	}
}
