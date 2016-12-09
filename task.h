#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Task
{
  private:
    int taskPriority;
    int taskQuota;
    int taskProgress;

  public:
    //generates task with a random priority(1-5) and random quota(1-10)
    Task()
    {
      taskPriority = rand()%5+1;
      taskQuota = rand()%10+1;
      taskProgress = taskQuota;
    }

    //getters
    int getPriority(){return taskPriority;}
    int getQuota(){return taskQuota;}
    int getProgress(){return taskProgress;}

    //setters
    void setPriority(int inputPriority)
    {
      taskPriority = inputPriority;
    }

    void setQuota(int inputQuota)
    {
      taskQuota = inputQuota;
    }

    void setProgress(int inputProgress)
    {
      taskProgress = inputProgress;
    }

    bool isFinished() const
    {
      return (taskProgress <= 0)?true:false;
    }
};

#endif
