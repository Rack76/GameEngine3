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

		TEST_METHOD(TestIfRunRepetitiveTasksRunsTasksWithDelay)
		{
			TaskManager tskMnger;
			int nbExec = 0;
			int* pnbExec = &nbExec;
			unsigned int ID = tskMnger.registerRepetitiveTask([pnbExec]() {(* pnbExec)++; }, 2);
			tskMnger.runTasks();
			tskMnger.runTasks();
			tskMnger.runTasks();
			assert(nbExec == 1);
		}
	};
}
