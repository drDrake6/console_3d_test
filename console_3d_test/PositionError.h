#pragma once
class PositionError : public out_of_range
{
public:
	PositionError(string message);
	~PositionError() = default;
};

