void Preencher_String (char *s[], char c) {
  int i;
  for ( i = 0 ; *(s+i) ; i++) {
    *(s+i) = c;
  }
}
