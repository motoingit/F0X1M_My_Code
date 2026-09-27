/*
Longest Job First
  - nonPremptive ig
*/
#include <stdio.h>
// process schema
typedef struct {
  int pid, at, bt;
  int rt, ct, tat, wt;
  int rem, status;
} Process;
// Longest Job First
void LJF(Process p[], int nProcess){
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < nProcess){
        int idx = -1;

        // Find longest available process
        for (int i = 0; i < nProcess; i++){
            if (p[i].status == 0 && p[i].at <= currentTime){
                if (idx == -1 || p[i].bt > p[idx].bt ||
                    (p[i].bt == p[idx].bt && p[i].pid < p[idx].pid)
                ){
                  idx = i;
                }
            }
        }

        // CPU idle
        if (idx == -1){
            currentTime++;
            continue;
        }

        // First CPU execution
        p[idx].rt = currentTime - p[idx].at;

        // Execute completely
        currentTime += p[idx].bt;

        p[idx].ct = currentTime;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        p[idx].status = 1;
        completedCount++;
    }
}

int main(void){
  int n;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  Process p[n];

  for (int i = 0; i < n; i++){
      p[i].pid = i + 1;

      printf("P%d (AT BT): ", p[i].pid);
      scanf("%d %d", &p[i].at, &p[i].bt);

      p[i].rt = -1;
      p[i].ct = 0;
      p[i].tat = 0;
      p[i].wt = 0;
      p[i].status = 0;
  }

  LJF(p, n);

  float avgRT = 0;
  float avgTAT = 0;
  float avgWT = 0;

  printf("\n");
  printf("%-6s %-6s %-6s %-6s %-6s %-6s %-6s\n",
    "PID", "AT", "BT", "RT", "CT", "TAT", "WT");
  printf("------------------------------------------------\n");
  for (int i = 0; i < n; i++){
      printf("P%-5d %-6d %-6d %-6d %-6d %-6d %-6d\n",
        p[i].pid,
        p[i].at,
        p[i].bt,
        p[i].rt,
        p[i].ct,
        p[i].tat,
        p[i].wt);

      avgRT += p[i].rt;
      avgTAT += p[i].tat;
      avgWT += p[i].wt;
  }

  printf("\nAverage Response Time   = %.2f", avgRT / n);
  printf("\nAverage Turnaround Time = %.2f", avgTAT / n);
  printf("\nAverage Waiting Time    = %.2f\n", avgWT / n);

return 0;}
