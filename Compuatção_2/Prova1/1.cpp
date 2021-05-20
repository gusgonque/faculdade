class Relogio{
  private:
    int hor {0};
    int min {0};
    int seg {0};
  public:
    Relogio(){}
    Relogio(int h,int m,int s) : hor(h), min(m), seg(s)
    {}
    void setHora (int h, int m, int s){
      if(h<24 && h>0)
        hor=h;
      if(m>60 && m<0)
        min=m;
      if(s<60 && s>0)
        seg=s;
        
    }
    void getHora (){
      printf("%2d;%2d;%2d", hor,min,seg);
    }
    void avancar (){
      seg++;
      if(seg>59){
        seg=0;
        min++;
      }
      if(min>59){
        min=0;
        hor++;
      }
      if(hor>23){
        hor=0;
        min=0;
        seg=0;
      }
    }
    void operator += (Relogio rel2){
      seg += rel2->seg;
      if(seg>59){
        seg-=60;
        min++;
      }

      min += rel2->min;
      if(min>59){
        min-=60;
        if(min>59){
          min-=60;
          hor++;
        }
        hor++;
      }

      hor += rel2->hor;
      if(hor>23){
        hor-=24;
        if(hor>23){
          hor-=24;
        }
      }
    }
};
