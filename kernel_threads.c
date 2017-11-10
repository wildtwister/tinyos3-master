

#include "tinyos.h"
#include "kernel_sched.h"
#include "kernel_proc.h"

/** 
  @brief Create a new thread in the current process.
  */
Tid_t sys_CreateThread(Task task, int argl, void* args)
{
   TCB* t = (TCB*) allocate_thread(THREAD_SIZE);

	return NOTHREAD;
}

/**
  @brief Return the Tid of the current thread.
 */
Tid_t sys_ThreadSelf()
{
	return (Tid_t) CURTHREAD;
}

/**
  @brief Join the given thread.
  */
int sys_ThreadJoin(Tid_t tid, int* exitval)
{
	int ev;
  TCB* localTCB;
  PTCB* localPTCB;

  localTCB = get_TCB(tid);
  localPTCB = localTCB->owner_ptcb;



  Mutex_lock();

  pthread_join(tid, ev);

  if (ev == ESRCH) 
  {
    perror("Given Thread with TID: %d was not found to be joined", tid);
  }
  else if (ev == EDEADLK)
  {
    perror("Given Thread with TID: %d couldn't be joined as it's the running Thread", tid);
  }
  else if (ev == EINVAL)
  {
    perror("Given Thread with TID: %d is not joinable", tid);
  }
  return -1;
}

/**
  @brief Detach the given thread.
  */
int sys_ThreadDetach(Tid_t tid)
{
	return -1;
}

/**
  @brief Terminate the current thread.
  */
void sys_ThreadExit(int exitval)
{

}

