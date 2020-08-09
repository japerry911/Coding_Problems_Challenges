"""
---FIFO OS Scheduling---
et another easy kata!

If you are newbie on codewars then i suggest you to go through this.
Background:
this kata is sort of educational too so, it you don;t want to learn go away!
CPU scheduling is a process which allows one process to use the CPU while the execution of another process is on hold(or 
in waiting state) due to unavailability of any resource like I/O etc, thereby making full use of CPU. The aim of CPU 
scheduling is to make the system efficient, fast and fair.read more about scheduling in operating system

Non-Preemptive Scheduling:
Under non-preemptive scheduling, once the CPU has been allocated to a process, the process keeps the CPU until it 
releases the CPU either by terminating or by switching to the waiting state.
Preemptive Scheduling
In this type of Scheduling, the tasks are usually assigned with priorities. At times it is necessary to run a certain 
task that has a higher priority before another task although it is running. Therefore, the running task is interrupted for some time and resumed later when the priority task has finished its execution.
Scheduling Algorithms
To decide which process to execute first and which process to execute last to achieve maximum CPU utilisation, you will 
implement these algorithms in follow-up series, they are
First Come First Serve(FCFS) Scheduling (current kata)
Shortest-Job-First(SJF) Scheduling (Non Pre-emptive)
Shortest-Job-First(SJF) Scheduling (Pre-emptive)
Priority Scheduling (Non Pre-emptive)
Priority Scheduling (Pre-emptive)
Round Robin(RR) Scheduling
Multilevel Queue Scheduling
Multilevel Feedback Queue Scheduling
Task: First Come First Serve(FCFS) Scheduling
Input:
Implement a function fcfs with given processes processes(array) which consist of arrival time and burst time as single 
row for each process and given processes will be sorted by arrival time.(i.e [Arrival time, Burst time]). (No two 
processes will have the same arrival time)
Terms:
As the name suggests, the process which arrives first, gets executed first, or we can say that the process which 
requests the CPU first, gets the CPU allocated first. (just like FIFO if you will)

Arrival time : Point of time at which process enters into ready queue (or ram).
Burst Time : Time duration required by process to get executed on CPU.
Completion Time : Point of time at which process completes it's execution.
Response Time : RT = Time at which the CPU starts the execution of the process - Arrival Time
Turn Around Time : total time taken by process to get executed (including waiting time and all), formula : TAT = 
Completion TIme - Arrival Time
Waitng Time : WT = Turn Around Time (total time) - Burst Time(useful time)
Throughput : Throughput means the efficiency of the scheduling algo that is the average "useful time" (time where 
the CPU is actually used) per process.
Note: for the current task, RT and WT are actually the very same value.

General Steps:
CPU locates very first process arrived in ready queue and start executing it and complete it;s execution depending 
upon Burst time of that process and if there;s no process arrived in ready queue then CPU have to wait until next 
process arrives in ready queue. (NOTE: note various timing to get expected output (see example below))
Start again for next process in ready queue.
Output:
Return Average Completion Time, Average Turn Around Time, Average Waiting Time and Throughput in tuple (A-CT, A-TAT, 
A-WT, Throughput) all rounded to two decimal places.
Example:
  processes = [[0, 2],
               [1, 2],
               [5, 3],
               [6, 4],
               [7, 9]]
  first process is considered as p1 and second as p2 and so on..
  (I used gnatt chart to explain this process)

  process p1's arrival time is 0th second (process p1 arrives at 0th second in ready queue) and burst time(executing 
  time) is 2 seconds.
  ready queue = [p1]
  CPU starts executing process p1 and p1 takes 2 seconds to complete it;s task so,
  gnatt chart : --------------------------
                | p1 |    |    |    |    |
                --------------------------
                0    2

  during executing process p1 another process p2 enters ready queue (since, process p2;s arrival time is at 1st second) 
  and it takes also 2 seconds to get executed.
  ready queue = [p2]
  gnatt chart : --------------------------
                | p1 | p2 |    |    |    |
                --------------------------
                0    2    4

  at the end of 4th second, no other processes arrived in ready queue (p3's arrival time is 5 and p4;s 6)
  ready queue = [] 
  since, there;s no process arrived in ready queue the CPU is ideal(free) so, CPU wait for the process to be 
  arrived in ready queue.
  gnatt chart : --------------------------
                | p1 | p2 | -- |    |    |
                --------------------------
                0    2    4    5
  at 5th second process p3 arrives in ready queue and takes 3 seconds to get executed.
  ready queue = [p3]
  gnatt chart : --------------------------
                | p1 | p2 | -- | p3 |    |
                --------------------------
                0    2    4    5    8
  while CPU was executing p3, process p4 and p5 arrived in ready queue at 6th and 7th second respectively.
  ready queue = [p4, p5] (CPU chooses process which arrived first in ready queue)
  gnatt chart : --------------------------
                | p1 | p2 | -- | p3 | p4 |
                --------------------------
                0    2    4    5    8    12

  ready queue = [p5]
  gnatt chart : -------------------------------
                | p1 | p2 | -- | p3 | p4 | p5 |
                -------------------------------
                0    2    4    5    8    12   21
  - left side of process in gnatt chart is a point of time at which process got CPU for the first time.
  - right side of process in gnatt chart is a point of time at which process completes it;s execution.

  (AT = Arival Time, BT = Burst Time, CT = Completion Time, TAT = Turn Around Time, WT = Waiting Time, 
  RT = Response Time) (see formula above)

  Process | AT | BT | CT | TAT | WT | RT   
    p1    |  0 |  2 |  2 |  2  |  0 |  0  
    p2    |  1 |  2 |  4 |  3  |  1 |  1  
    p3    |  5 |  3 |  8 |  3  |  0 |  0  
    p4    |  6 |  4 | 12 |  6  |  2 |  2  
    p5    |  7 |  9 | 21 | 14  |  5 |  5  

  Average CT = 9.4
  Average TAT = 5.6
  Average WT = 1.6
  Average RT = 1.6
  Throughput = (2+2+3+4+9)/5 = 4 seconds

  (NOTE : Response Time is not tested in this kata (explained here for follow-up series))
Have Fun!
There is lot of information which is not required for this kata but required for follow-up series so, 
it;s best to put these basic information in very first kata of series.
"""

def fcfs(processes):
    scheduler = dict()
    avg_completion_time = 0
    avg_turnaround_time = 0
    avg_waiting_time = 0
    through_put = 0
    time_clock = 0

    for process in processes:
        if time_clock < process[0]:
            time_clock += process[0] - time_clock

        scheduler[process[0]] = [time_clock, time_clock + process[1], process[1]]

        time_clock += process[1]

    for process in scheduler.keys():
        avg_completion_time += scheduler[process][1]
        avg_turnaround_time += scheduler[process][1] - process
        avg_waiting_time += scheduler[process][1] - process - scheduler[process][2]
        through_put += scheduler[process][2]

    avg_completion_time /= len(scheduler.keys())
    avg_turnaround_time /= len(scheduler.keys())
    avg_waiting_time /= len(scheduler.keys())
    through_put /= len(scheduler.keys())

    return round(avg_completion_time, 2), round(avg_turnaround_time, 2), round(avg_waiting_time, 2), \
           round(through_put, 2)
