#include <stdio.h>
#include <math.h>

int ordem_decres (double *a, double *b, double *c) {
double aux_a, aux_b, aux_c;

aux_a=*a;
aux_b=*b;
aux_c=*c;

if(aux_a>aux_b){
  if(aux_a>aux_c){
    if(aux_b>aux_c){
      return 1;
    }
    else
      return 2;
  }
  else
    return 3;
}
else
  if(aux_b>aux_c){
    if(aux_c>aux_a)
      return 4;
    else
      return 5;
    }
  else
    return 6;
}

int main(){
double a, b, c;
int caso;
scanf("%lf %lf %lf", &a, &b, &c);
caso = ordem_decres(&a, &b, &c);

switch (caso){
  case 1:
 if ( a >= b + c ) {
   printf ("NAO FORMA TRIANGULO\n");
   return 0;
 }
 else
   if ( pow(a,2) == (pow(b,2) + pow(c,2)) ) {
     printf("TRIANGULO RETANGULO\n");
     if(((a!=b)&&(a!=c))&&(b!=c)) {
     }
     else
       printf("TRIANGULO ISOSCELES\n");
       return 0;
   }
   else
     if( pow ( a , 2 ) > pow ( b , 2 ) + pow ( c , 2 )) {
       printf("TRIANGULO OBTUSANGULO\n");
       if(((a!=b)&&(a!=c))&&(b!=c)) {
       }
       else
         printf("TRIANGULO ISOSCELES\n");
         return 0;
     }
     else
       printf("TRIANGULO ACUTANGULO\n");
       if(a==b&&b==c){
         printf("TRIANGULO EQUILATERO\n");
         return 0;
       }
       else
         if(((a!=b)&&(b!=c))&&(a!=c)) {
         }
         else
           printf("TRIANGULO ISOSCELES\n");
           return 0;
    break;
  case 2:
 if ( a >= b + c ) {
   printf ("NAO FORMA TRIANGULO\n");
   return 0;
 }
 else
   if ( pow(a,2) == (pow(b,2) + pow(c,2)) ) {
     printf("TRIANGULO RETANGULO\n");
     if(((a!=b)&&(a!=c))&&(b!=c)) {
     }
     else
       printf("TRIANGULO ISOSCELES\n");
       return 0;
   }
   else
     if( pow ( a , 2 ) > pow ( b , 2 ) + pow ( c , 2 )) {
       printf("TRIANGULO OBTUSANGULO\n");
       if(((a!=b)&&(a!=c))&&(b!=c)) {
       }
       else
         printf("TRIANGULO ISOSCELES\n");
         return 0;
     }
     else
       printf("TRIANGULO ACUTANGULO\n");
       if(a==b&&b==c){
         printf("TRIANGULO EQUILATERO\n");
         return 0;
       }
       else
         if(((a!=b)&&(b!=c))&&(a!=c)) {
         }
         else
           printf("TRIANGULO ISOSCELES\n");
           return 0;
    break;
  case 3:
 if ( c >= b + a ) {
   printf ("NAO FORMA TRIANGULO\n");
   return 0;
 }
 else
   if ( pow(c,2) == (pow(b,2) + pow(a,2)) ) {
     printf("TRIANGULO RETANGULO\n");
     if(((c!=a)&&(c!=b))&&(a!=b)) {
     }
     else
       printf("TRIANGULO ISOSCELES\n");
       return 0;
   }
   else
     if( pow ( c , 2 ) > pow ( a , 2 ) + pow ( b , 2 )) {
       printf("TRIANGULO OBTUSANGULO\n");
       if(((c!=a)&&(c!=b))&&(a!=b)) {
       }
       else
         printf("TRIANGULO ISOSCELES\n");
         return 0;
     }
     else
       printf("TRIANGULO ACUTANGULO\n");
       if(c==a&&a==b){
         printf("TRIANGULO EQUILATERO\n");
         return 0;
       }
       else
         if(((c!=a)&&(a!=b))&&(c!=b)) {
         }
         else
           printf("TRIANGULO ISOSCELES\n");
           return 0;
    break;
  case 4:
  if ( b >= c + a ) {
   printf ("NAO FORMA TRIANGULO\n");
   return 0;
 }
 else
   if ( pow(b,2) == (pow(a,2) + pow(c,2)) ) {
     printf("TRIANGULO RETANGULO\n");
     if(((b!=c)&&(b!=a))&&(c!=a)) {
     }
     else
       printf("TRIANGULO ISOSCELES\n");
       return 0;
   }
   else
     if( pow ( b , 2 ) > pow ( a , 2 ) + pow ( c , 2 )) {
       printf("TRIANGULO OBTUSANGULO\n");
       if(((b!=c)&&(b!=a))&&(c!=a)) {
       }
       else
         printf("TRIANGULO ISOSCELES\n");
         return 0;
     }
     else
       printf("TRIANGULO ACUTANGULO\n");
       if(b==c&&c==a){
         printf("TRIANGULO EQUILATERO\n");
         return 0;
       }
       else
         if(((b!=c)&&(c!=a))&&(c!=a)) {
         }
         else
           printf("TRIANGULO ISOSCELES\n");
           return 0;
    break;
  case 5:
 if ( b >= a + c ) {
   printf ("NAO FORMA TRIANGULO\n");
   return 0;
 }
 else
   if ( pow(b,2) == (pow(a,2) + pow(c,2)) ) {
     printf("TRIANGULO RETANGULO\n");
     if(((b!=a)&&(b!=c))&&(a!=c)) {
     }
     else
       printf("TRIANGULO ISOSCELES\n");
       return 0;
   }
   else
     if( pow ( b , 2 ) > pow ( a , 2 ) + pow ( c , 2 )) {
       printf("TRIANGULO OBTUSANGULO\n");
       if(((b!=a)&&(b!=c))&&(a!=c)) {
       }
       else
         printf("TRIANGULO ISOSCELES\n");
         return 0;
     }
     else
       printf("TRIANGULO ACUTANGULO\n");
       if(b==a&&a==c){
         printf("TRIANGULO EQUILATERO\n");
         return 0;
       }
       else
         if(((b!=a)&&(a!=c))&&(b!=c)) {
         }
         else
           printf("TRIANGULO ISOSCELES\n");
           return 0;
    break;
  case 6:
 if ( c >= b + a ) {
   printf ("NAO FORMA TRIANGULO\n");
   return 0;
 }
 else
   if ( pow(c,2) == (pow(b,2) + pow(a,2)) ) {
     printf("TRIANGULO RETANGULO\n");
     if(((c!=b)&&(c!=a))&&(b!=a)) {
     }
     else
       printf("TRIANGULO ISOSCELES\n");
       return 0;
   }
   else
     if( pow ( c , 2 ) > pow ( b , 2 ) + pow ( a , 2 )) {
       printf("TRIANGULO OBTUSANGULO\n");
       if(((c!=b)&&(c!=a))&&(b!=a)) {
       }
       else
         printf("TRIANGULO ISOSCELES\n");
         return 0;
     }
     else
       printf("TRIANGULO ACUTANGULO\n");
       if(c==b&&b==a){
         printf("TRIANGULO EQUILATERO\n");
         return 0;
       }
       else
         if(((c!=b)&&(b!=a))&&(c!=a)) {
         }
         else
           printf("TRIANGULO ISOSCELES\n");
           return 0;
    break;
}

return 0;
}
