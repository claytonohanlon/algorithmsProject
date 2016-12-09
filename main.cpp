#include "task.h"
#include "scheduler.h"

//clayton
int main()
{
  srand(time(NULL));

  int numTasks = 0;
  cout << "number of tasks: " << endl;
  cin >> numTasks;

  int quantum = 0;
  cout << "enter quantum: " << endl;
  cin >> quantum; cout << endl;

  Task* taskList = new Task[numTasks];

  RoundRobinScheduler(taskList, numTasks, quantum);
  SequentialScheduler(taskList, numTasks, quantum);

  return 0;
}
