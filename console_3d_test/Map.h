#pragma once
class Map
{
	Set<string> _map;
	int _height = 0;
	int _width = 0;

public:
	Map() = default;
	Map(Set<string> map);
	int GetHeight() const;
	int GetWidth() const;
	Set<string> GetMap();
	string operator[](int index) const;
	string& operator[](int index);
};

