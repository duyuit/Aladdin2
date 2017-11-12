#include "AppleState.h"
class AppleBreakState :public AppleState
{
public:
	AppleBreakState(D3DXVECTOR3 pos);
	~AppleBreakState();
	void Update(float dt);
	AppleState::StateName GetNameState();
};

