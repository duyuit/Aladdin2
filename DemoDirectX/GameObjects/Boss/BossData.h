#pragma once
class BossState;
class Boss;
class BossData
{
public:
	BossData();
	~BossData();

	Boss      *boss = nullptr;
	BossState *state = nullptr;
	void Update();
};



