#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <cstdlib>
#include "task.h"
using namespace std;

//runs through the task list to see if all the tasks are finished
//if they are, it returns true
bool allFinished(Task* list, int numTasks)
{
  for(int i = 0; i < numTasks; i++)
  {
    if(!list[i].isFinished())
      {
          return false;
      }
  }
  return true;
}

//function to reset the progress values of each task
//This allows us to use the same array of tasks on each scheduler
void resetTasks(Task* list, int numTasks)
{
  for(int i = 0; i < numTasks; i++)
  {
    list[i].setProgress(list[i].getQuota());
  }
}



void RoundRobinScheduler(Task* list, int numTasks, int quantum)
{
//reset the array of tasks
  resetTasks(list, numTasks);
  int numSwitches = 0;
  int quantumIterations = 0;
  cout << "Beginning Round Robin Scheduling..." << endl << endl;
//continue until tasks are complete....
  while(!allFinished(list, numTasks))
  {

//~~~~~print out schedule after each loop~~~~~
    for(int i = 0; i < numTasks; i++)
    {
      cout << i << ":\t";
      cout << "[";
      for(int j = 0; j < list[i].getProgress(); j++)
      {
        cout << ".";
      }
      cout << "]" << endl;
    }
    cout << endl;

    for(int i = 0; i < numTasks; i++)
    {
//if the task is NOT finished, subtract the quantum from its current progress
      if(!list[i].isFinished())
      {
        list[i].setProgress(list[i].getProgress() - quantum);
        quantumIterations++;
        numSwitches++;
      }
    }
  }
  cout << "Finished Scheduling" << endl;
  cout << "Number of Task Switches: " << numSwitches << endl;
  cout << "Quantum Iterations: " << quantumIterations << endl << endl;
}



void SequentialScheduler(Task* list, int numTasks, int quantum)
{
//keep track of number of process switches and number of times quantum is subtracted
//from the current progress
  resetTasks(list, numTasks);
  int numSwitches = 0;
  int quantumIterations = 0;
  cout << "Beginning Sequential Scheduling..." << endl << endl;

  for(int i = 0; i < numTasks; i++)
  {

//~~~~~~~~print out task list~~~~~~~~~~~~~~~
    for(int i = 0; i < numTasks; i++)
    {
      cout << i << ":\t";
      cout << "[";
      for(int j = 0; j < list[i].getProgress(); j++)
      {
        cout << ".";
      }
      cout << "]" << endl;
    }
    cout << endl;

//while the task still has quota, continue to process
    while(list[i].getProgress() > 0)
    {
      list[i].setProgress(list[i].getProgress() - quantum);
      quantumIterations++;
    }
    numSwitches++;
  }
  cout << "Finished Scheduling" << endl;
  cout << "Number of Task Switches: " << numSwitches << endl;
  cout << "Quantum Iterations: " << quantumIterations << endl << endl;
}

void ShortestRemainingTimeScheudler(Task* list, int numTasks, int quantum)
{

}

#endif
