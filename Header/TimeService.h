#pragma once
#include<chrono>
using namespace std;

namespace Utility {
	class TimeService {


	private:

		chrono::steady_clock::time_point previousTime;
		float deltaTime;
		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:
		void initialize();
		void update();
		float getDeltaTime();
	};
}