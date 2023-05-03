#include "CppUnitTest.h"
#include "../GameEngine/src/TaskManager.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameEngineTest
{
	TEST_CLASS(TaskManagerTest)
	{
	public:
		
		TEST_METHOD(TestIfRunTasksCancelsTasks)
		{
			TaskManager tskMnger;
			unsigned int ID = tskMnger.registerTask([]() {}, 0);
			tskMnger.runTasks();
			assert(tskMnger.cancel(ID));
		}
	};
}
