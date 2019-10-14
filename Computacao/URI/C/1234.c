#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Sentenca_Dancante (char s[]) {
  int i, fl;
  for ( i=0, fl=1 ; s[i] ; i++, fl*=(-1) ){
    if (isalpha(s[i]))
      if (fl==1)
        if (islower(s[i]))
          s[i] = toupper(s[i]);
        else;
      else
        if (isupper(s[i]))
          s[i] = tolower(s[i]);
        else;
    else
      fl*=(-1);
  }
}

int main () {
  char s[50];
    while (gets (s) != NULL){
    Sentenca_Dancante (s);
    puts (s);
  }
  return 0;
}
