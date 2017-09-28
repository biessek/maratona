#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;


int custo[2500];

int temps(int ts, bool bug=false) {
    int m; char stime[5];
    if(!bug) {
        m = ts/60;
        ts = ts-m*60;
        sprintf(stime, "%02d%02d", m, ts);
        sscanf(stime,"%d", &ts);        
        return ts;
    }

    if(ts>=99) {
        m = ts/60;
        m--;
        int s=60;
        while(s<=99) {
            if(m*60+s==ts) break;
            s++;
            if(s==100) { m++; s=0;}
        }
        sprintf(stime, "%02d%02d", m, s);
        sscanf(stime,"%d", &ts);        
    }

    return ts;
}

int custot(int t) {
    int resp = 1;
    int dig, cd;
    int ant=-1;
    resp += int(floor(log10(t)))+1;
    cd=0;
    while(t>=10) {
        dig=t%10;
        cd+=dig!=ant;
        t/=10;
        ant=dig;
    }
        cd+=t!=ant;

           
    return resp+cd-1;
}

void cc() {    
    custo[0]=0; 
    char stempo[5];
    int tempo;
    
    for(int i = 0; i<=2400;i++) {        
        custo[i]=custot(i);                
    }
}

int main() {
    int n, i, min, seg, p, segv, tempo, j, mtempo;
    int tempoc, it;
    cc();
    
    scanf("%d\n", &n);
    for(i=1;i<=n;i++) {
        scanf("%d:%d", &min, &seg);
        scanf("%d", &p);
        seg+=min*60;
        segv=(p * seg) / 100; 

        tempo = mtempo = 2500;
        for(j=seg-segv;j<=seg+segv;j++) {
            tempoc = temps(j);
 //           printf("tempo %d === %d|%d\n",j, tempoc,custo[tempoc]);
            if(custo[tempoc] < mtempo || (custo[tempoc] == mtempo && abs(j-seg) < abs(tempo-seg))) {
                mtempo = custo[tempoc];
                tempo  = j;
                it=1;
            } 

            tempoc = temps(j,true);
 //           printf("tempo %d === %d|%d\n",j, tempoc,custo[tempoc]);
            if(custo[tempoc] < mtempo || (custo[tempoc] == mtempo && abs(j-seg) < abs(tempo-seg))) {
                mtempo = custo[tempoc];
                tempo  = j;
                it=2;
            } 
        }
        
        printf("CASO #%d: ",i);

        printf("%d\n",temps(tempo,it==2));
        
    }

    return 0;
}
