#include "Headers.h"

Map::Map(Set<string> map)
{
	int height = map.GetSize();
	int width = map[0].size();
	for (int i = 1; i < height; i++)
	{
		if (map[i].size() != width)
		{
			cerr << "Error, not smooth map!\n";
			return;
		}
	}

	_height = height;
	_width = width;
	_map = map;
}

int Map::GetHeight() const
{
	return _height;
}

int Map::GetWidth() const
{
	return _width;
}

Set<string> Map::GetMap()
{
	return _map;
}

string Map::operator[](int index) const
{
	if (index >=0 && index < _height)
	{
		return _map[index];
	}	
}

string& Map::operator[](int index)
{
	if (index >= 0 && index < _height)
	{
		return _map[index];
	}
}
