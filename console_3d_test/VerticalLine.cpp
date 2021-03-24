#include "Headers.h"

void ConsoleBufferString::VerticalLine::PrintObject()
{
	switch (_item.GetSymbol())
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
	    default:
	    	break;
	}
}

void ConsoleBufferString::VerticalLine::PrintCircle()
{
	float radius = (_self->_console_height / 2) * 0.3f;
	float center = _item.GetPosition_X();
	float x = _position_ray_x + (abs(center - _position_ray_x) * radius) / 0.3;

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
			_self->screen[j * _self->_console_width + _current_rays_amount] = (wchar_t)_item.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintRectangle()
{
	int height = (_self->_console_height) / 3;
	int highest_y = (float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size;
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount] = (wchar_t)_item.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintTriangle()
{
	float h = (_self->_console_height / 2) * 0.3f;
	float center = _item.GetPosition_X();
	float x = _position_ray_x + (abs(center - _position_ray_x) * h) / 0.3;

	int height;
	if (x < center)
		height = x * 2;
	else
		height = x * 2 - 2 * (x * 2 - h);

	int highest_y = ((float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size);
	int lowest_y = _self->_console_height -
		((float)(_self->_console_height / 2.0f) - (h * 2 - center) / _ray_size);

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount] = (wchar_t)_item.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
		}
	}
}

void ConsoleBufferString::VerticalLine::PrintRhombus()
{
	float h = (_self->_console_height / 2) * 0.3f;
	float center = _item.GetPosition_X();
	float x = _position_ray_x + (abs(center - _position_ray_x) * h) / 0.3;

	int height;
	if (x < center)
		height = x;
	else
		height = 2 * h - x;

	int highest_y = ((float)(_self->_console_height / 2.0f)
		- (float)height / _ray_size);
	int lowest_y = _self->_console_height - highest_y;

	for (int j = 0; j < _self->_console_height; j++)
	{
		if (j >= highest_y && j <= lowest_y)
		{
			_self->screen[j * _self->_console_width + _current_rays_amount] = (wchar_t)_item.GetSymbol();
#ifdef DEBUG
			WriteConsoleOutputCharacter(_self->hConsole, _self->screen, _self->_size, _self->FirstCell, &(_self->dwBytesWritten));
#endif
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
				_self->screen[j * _self->_console_width + current_rays_amount] = ' ';
			}
			else
			{
				if (ray_size >= 18)
				{
					_self->screen[j * _self->_console_width + current_rays_amount] = 9617;
				}
				else if (ray_size < 18 && ray_size >= 12)
				{
					_self->screen[j * _self->_console_width + current_rays_amount] = 9618;
				}
				else if (ray_size < 12 && ray_size >= 6)
				{
					_self->screen[j * _self->_console_width + current_rays_amount] = 9619;
				}
				else if (ray_size < 6)
				{
					_self->screen[j * _self->_console_width + current_rays_amount] = 9608;
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
