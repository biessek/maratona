#include <cstdio>
#include <string>
#include <set>
using namespace std;
set<string> move;

int main() {
    int N, w, p, x,y, pos, moves, rw;
    string board,board1,board2, board3;
    bool wf;
    char c;
    while(scanf("%d", &N) && N) {
        board  = string(N*N,'0');
        board1 = string(board1);
        board2 = string(board2);
        board3 = string(board3);

        wf=false;
        move.clear();
        moves = N<<1;
        p=0;
        w=-1;
        rw=0;
        while(moves--) {
            p=(p%2)+1;
            scanf("%d %d %c", &y, &x, &c);
            if(!wf) {
                if(c=='+') c='1';
                else c='0';
                y--; x--;                                
                rw++;
                pos = y * N + x; // board
                board[pos]=c;
                if(move.find(board) != move.end()) w= (p%2)+1;
    
                pos = x * N + (N-y-1); // board 1
                board1[pos]=c;

                pos = (N-y-1) * N + (N - x - 1); // board 2                
                board2[pos-1]=c;

                pos = (N-x-1) * N + y; // board 2                
                board3[pos-1]=c;

                
                move.insert(board);
                move.insert(board1);
                move.insert(board2);
                move.insert(board3);
            }            
        } 
        if(w==-1) puts("Draw");
        else printf("Player %d wins on move %d\n",w, rw - 1);
    }
    return 0;
}
