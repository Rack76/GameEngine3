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

		TEST_METHOD(TestIfRunTasksRunsTasksWithDelay)
		{
			TaskManager tskMnger;
			int nbExec = 0;
			int* pnbExec = &nbExec;
			tskMnger.registerTask([pnbExec]() {(*pnbExec)++; }, 3);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 1);
		}

		TEST_METHOD(TestIfRunRepetitiveTasksRunsTasksWithDelay)
		{
			TaskManager tskMnger;
			int nbExec = 0;
			int* pnbExec = &nbExec;
			unsigned int ID = tskMnger.registerRepetitiveTask([pnbExec]() {(* pnbExec)++; }, 2);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 1);
		}

		TEST_METHOD(TestIfRunRepetitiveTasksRunsTasksPeriodicallyWithDelay)
		{
			TaskManager tskMnger;
			int nbExec = 0;
			int* pnbExec = &nbExec;
			unsigned int ID = tskMnger.registerRepetitiveTask([pnbExec]() {(*pnbExec)++; }, 3, 3);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 0);
			tskMnger.runTasks();
			assert(nbExec == 0);
			for (int i = 0; i < 3; i++)
			{
				tskMnger.runTasks();
				assert(nbExec == i + 1);
				tskMnger.runTasks();
				assert(nbExec == i + 1);
				tskMnger.runTasks();
				assert(nbExec == i + 1);
			}
		}
	};
}
