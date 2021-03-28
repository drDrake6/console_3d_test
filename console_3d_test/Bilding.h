#pragma once
class Bilding : public GameObject
{
protected:
	float width;
	bool _IsParallelToX;

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override {};
public:
	Bilding();
	Bilding(char symbol, float positionX, float positionY, const Map& map,
		float collision_area, bool IsParallelToX);

	float GetWidth() const;

	void BuildInit(char symbol, float positionX, float positionY, const Map& map,
		float collision_area, bool IsParallelToX);
	virtual void Initialize(float positionX, float positionY, const Map& map,
		float collision_area, bool IsParallelToX) = 0;

	bool InRenderArea(float x, float y) const override;
	bool InCollisionArea(float x, float y) const override;
	bool IsParallelToX();
	void Reverse(const Map& map);
	void SetPosition(const Map& map);

	virtual ~Bilding() = 0 {};
};

