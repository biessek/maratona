#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<list>
using namespace std;
typedef pair<int, list<int>::iterator> tupla;
const int MAXTAM = 318;
int N, Q;
 
map<int, tupla > P;
struct setor {      
    int q;
    list<int>::iterator l,r;
    setor() {
        q=0;
    }
} QTR[MAXTAM];
    
list<int> A;
 
void remove(int p) {
    tupla q = P[p]; // setor.
    QTR[q.first].q--;
   
    int setor = q.first;
    if(q.second == QTR[setor].l) {
      QTR[setor].l++;
    } else if(q.second == QTR[setor].r) {      
      QTR[setor].r--;
    } else {  
      list<int>::iterator it = QTR[setor].l; it++;
      while(it!=QTR[setor].r){
        if(*it == p) break;  
        it++;
      }      
    }
    A.erase(q.second);
     
    while(setor+1<MAXTAM && QTR[setor+1].q > 0) {
        QTR[setor+1].q--;
        QTR[setor].r = QTR[setor+1].l;  
        P[*QTR[setor].r].first = setor;
        QTR[setor+1].l++;
        QTR[setor].q++;
        if(QTR[setor].q==1) {
          QTR[setor].l = QTR[setor].r;
        }
        setor++;
    }
}
 
void insere(int p, int e) {
    int setor = e? P[e].first:0;
    list<int>::iterator posicao = e? P[e].second : A.end();
    posicao++;
    P[p].first = setor;
    P[p].second = A.insert(posicao,p);
    QTR[setor].q++;
    if(QTR[setor].q==1) {
      QTR[setor].r = QTR[setor].l = P[p].second;
    } else if(e == *QTR[setor].r) {
      QTR[setor].r = P[p].second;
    }
    while(setor+1<MAXTAM && QTR[setor].q >MAXTAM ) {
        QTR[setor+1].q++;
        QTR[setor+1].l = QTR[setor].r;  
        P[*QTR[setor].r].first = setor+1;
        QTR[setor].r--;
        QTR[setor].q--;
        if(QTR[setor+1].q==1) {
          QTR[setor+1].r = QTR[setor+1].l;
        }
        setor++;
    }
}
    
int query(int p, int e) {
  if(e==p) return 0;
 
  int set1, set2;
  set1 = P[p].first;
  set2 = P[e].first;
  list<int>::iterator l1, l2;
  if(set1==set2) {
    bool contando = false;
    int res=0;
    for(l1 = QTR[set1].l;l1!=QTR[set1].r;l1++) {
      if(*l1 == p || *l1 == e) {
        if(contando) break;
        else contando = true;
      }
      else if(contando)  res++;
    }
    return res;
  } else {
    if(set2 < set1) { swap(p,e); swap(set2,set1);}
    int res=0;    
    if(QTR[set1].r != P[p].second) {
      l1=P[p].second; l1++;  l2 =  QTR[set1].r; l2++;
      while(l1!=l2) { res++;  l1++; } 
    }
    if(QTR[set2].l != P[e].second) {
      l1=QTR[set2].l; l2 = P[e].second;
      while(l1!=l2) { res++;  l1++; } 
    }
    set1++; set2;
    while(set1<set2) {
      res+=QTR[set1++].q;
    }
    return res;
  }
 
}
    
// void printsetores() {
//     for(int q=0;q<MAXTAM;q++) {
//         if(QTR[q].q > 0) {
//             printf("setor %d|%d %d = %d\n", q, QTR[q].q, *QTR[q].l,*QTR[q].r);
//         }
//     }
//      puts("ini");
//      for(map<int,pair<int,list<int>::iterator> >::iterator it = P.begin();it!=P.end();it++) 
//          printf("p %d = %d\n", (*it).first, (*it).second.first);
// }
  
int main() {
    int i, p, e;
    char op;
    fill(QTR,QTR+MAXTAM,setor());      
    A.clear();
    P.clear();
    scanf("%d", &N);
   
    for(i=0;i<N;i++) {
        scanf("%d", &p);            
        insere(p, !A.empty()? A.back(): 0);
    }            
  
    scanf("%d", &Q);
    while(Q--) {
        scanf(" %c", &op);  
        if(op == 'I') {
            scanf(" %d %d", &p, &e);    
            insere(p,e);            
        } else if(op == 'Q') {
            scanf(" %d %d", &p, &e);    
            // printsetores(); puts("res");
            printf("%d\n", query(p,e));
        } else {
            scanf(" %d", &p);   
            remove(p);
        }
        // printsetores(); 
    }
         // printf("%d\n", P[99999].first);
    return 0;
}