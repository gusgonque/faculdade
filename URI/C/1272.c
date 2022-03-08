#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  int n, i, j;
  char str[100];

  scanf("%d%*c", &n);
  for ( i = 0 ; i < n ; i++ )
  {
    scanf("%[^\n]%*c", &str);
    for ( j = 0 ; j < strlen(str) ; j++ )
    {
      while (str[j] == ' ' && j < strlen(str))
        j++;
      if (isalpha(str[j]))
        printf("%c", str[j]);
      while (str[j] != ' ' && j < strlen(str))
        j++;
    }
    printf("\n");
  }

  return 0;
}
