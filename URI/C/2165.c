#include <stdio.h>
#include <string.h>

int main () {
  char s[501];
  gets(s);
  if (strlen(s)<=140)
    printf("TWEET\n");
  else
    printf("MUTE\n");
  return 0;
}
