#include <stdio.h>

int Transformar_Hora_Min ( int h ) {
    return (h*60);
}

int Tempo_Jogo_Min ( int min_i, int min_f ) {
    if (min_i < min_f)
        return (min_f - min_i);
    else
        if (min_i == min_f)
            return ((24*60) - (min_f - min_i));
        else
            return ((24*60) + (min_f - min_i));
}

int main () {
    int h_i,m_i,h_f,m_f,h_r,m_r;
    scanf ("%d %d %d %d", &h_i, &m_i, &h_f, &m_f);
    m_r = Tempo_Jogo_Min ( (m_i + Transformar_Hora_Min (h_i)), m_f + Transformar_Hora_Min (h_f) );
    h_r = m_r / 60;
    m_r %= 60;
    printf ("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h_r, m_r);
    return 0;
}
