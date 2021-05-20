#include <stdio.h>
#include <ctype.h>

void Criptografia (char *c)
{
  if (isspace (*c))
  {
    *c = 92;
  }
  else
    if (isdigit (*c))
    {
      *c = -15 + *c;
    }
    else
      if (islower (*c))
      {
        *c = 'z' - (*c - 'a');
      }
      else
        if (isupper (*c))
        {
          *c = 'Z' - (*c - 'A');
        }
}

int main()
{
  char c;

  scanf("%c", &c);

  while (c != '#')
  {
    Criptografia(&c);
    printf("%c", c);
    scanf("%c", &c);
  }

  printf("\n");
  return 0;
}
