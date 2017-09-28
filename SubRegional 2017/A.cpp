#include <bits/stdc++.h>
using namespace std;

struct freq {
    int n[9]; // qtd de notas de 0 a 8 no segmento.
    int mf; // nota mais frequente no segmento(0 a 8).
    freq() {
        fill(n,n+9,0);
        mf=8;
    }
    
    // combinar dois segmentos 
    freq operator + (const freq &b) const { 
        freq nf; nf.mf=0;
        for (int i = 0; i < 9; i++) { 
            nf.n[i] = n[i]+b.n[i];
            if(nf.n[i] >= nf.n[nf.mf]) nf.mf=i;           
        }      
        return nf;
    }
    
    // adicionar uma nota a todo o segmento. 
    freq operator + (const int& note) const {
        freq nf; nf.mf=0;
        for (int i = 0; i < 9; i++) { 
          nf.n[i] = n[(i-note+9)%9];
          if(nf.n[i] >= nf.n[nf.mf]) nf.mf=i;           
        }      
        return nf;
    }
};

const int MAX = 100001;
int h;
int d[MAX]; 
freq t[MAX<<1];
int n;

// setup da árvore
void build() {
    for(int i = n-1;i>0;i--) {
        t[i] = t[i<<1] + t[i<<1|1];
    }
    fill(d,d+n,0);
}

void apply(int p, int v) {
    t[p] = t[p] + v;
    if(p < n) d[p] = (d[p] + v) % 9;
}

void push(int p) {
    int i,s;
    for(s = h; s>0;s--) {
        i = p>>s;    
        if(d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i]=0;
        }
    }    
}

void build(int p) {
    while(p>1) {
        p>>=1;
        t[p] = t[p<<1] + t[p<<1|1];
        t[p] = t[p] + d[p];
    }
}

int query(int l, int r) {
    l+=n; r+=n;
    push(l); 
    push(r-1);        
    freq res1 = freq();
    freq res2 = freq();
    for(;l<r;l>>=1, r>>=1) {
        if(l&1) {res1 = res1 + t[l++];}
        if(r&1) {res2 = res2 + t[--r];}
    }
    freq res = res1 + res2;
    return res.mf;
}

void modify(int l, int r, int value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    push(l); push(r-1);
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

int main() {
    int q, a, b, f;
    scanf("%d %d", &n, &q);
    h = sizeof(int) * 8 - __builtin_clz(n);
   
    for (int i = 0; i < n; i++) {
        t[n+i].n[1] = t[n+i].mf = 1;
    } 
    build();
    
    while(q--) {
        scanf("%d %d", &a, &b);
        f = query(a, b + 1);
        modify(a, b + 1, f);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", query(i,i+1));
    }
    return 0;	
}