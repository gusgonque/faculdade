void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Mostrar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    printf("%d\n", v[aux]);
  }
}

void Preencher_Vetor (int v[], int t, int x) {
  int i;
  for ( i = 0 ; i < t ; i++) {
    v[i] = x;
  }
}
