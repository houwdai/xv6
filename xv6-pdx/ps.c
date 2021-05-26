
#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"

int
main(void)
{
  struct uproc* table;
  int i;
  uint max = 1; // 1, 16, 64, 72
  int catch = 0;
  uint elapsed_sec, elapsed_mod, total_sec, total_mod;
  table = malloc(sizeof(struct uproc) * max);
  catch = getprocs(max, table);
  if(catch == -1)
    printf(1, "\nError: Invalid max or NULL uproc table\n");
  else {
    printf(1, "MAX =%d\t", max);
    printf(1, "\nPID\tName\tUID\tGID\tPPID\tElapsed\tCPU\tState\tSize");
    for(i = 0;i < catch;++i) {
      elapsed_mod = table[i].elapsed_ticks % 1000;
      elapsed_sec = table[i].elapsed_ticks / 1000;
      total_mod = table[i].CPU_total_ticks % 1000;
      total_sec = table[i].CPU_total_ticks / 1000;
      printf(1, "\n%d\t%s\t%d\t%d\t%d\t%d.%d\t%d.%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, elapsed_sec, elapsed_mod, total_sec, total_mod);
      printf(1, "%s\t%d\n", table[i].state, table[i].size);
    }
  }
  free(table);
  exit();
}
#endif // CS333_P2