#include"../../Header/TimeService.h"
namespace Utility {
	void TimeService::updateDeltaTime()
	{
		deltaTime = calculateDeltaTime();
		updatePreviousTime();

	}
	float TimeService::calculateDeltaTime()
	{
		int delta = chrono::duration_cast<chrono::microseconds>
			(chrono::steady_clock::now() - previousTime).count();
		return static_cast<float>(delta)/ 1000000.0;
	}
	void TimeService::updatePreviousTime()
	{
		previousTime = chrono::steady_clock::now();
	}
	void TimeService::initialize()
	{
		previousTime = chrono::steady_clock::now();
		deltaTime = 0;
	}
	void TimeService::update()
	{
		updateDeltaTime();
	}
	float TimeService::getDeltaTime()
	{
		return deltaTime;
	}
}