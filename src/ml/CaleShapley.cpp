//
// Created by ch on 2016/11/9.
//
// »é½éËù ½éÉÜÎÊÌâ

#include <tchar.h>
const int N=4;
void GaleShapley(const int (&man)[N][N], const int (&woman)[N][N],int (&match)[N]){
    int wm[N][N];
    int choose[N];
    int manIndex[N];
    int i,j;
    int w,m;
    for ( i = 0; i < N; ++i) {
        match[i] = -1;
        choose[i]=-1;
        manIndex=0;
        for ( j = 0; j <N ; ++j) {
            wm[i][woman[i][j]] = j;
        }
    }
    bool bSingle= false;
    while (!bSingle){
        bSingle=true;
        for (i = 0; i <N ; ++i) {
            if(match[i] !=-1){
                continue;
            }
            bSingle= false;
            j=manIndex[i]++;
            w=man[i][j];
            m=choose[w];
            if((m==-1)||(wm[w][i]<wm[w][m])){
                match[i]=w;
                choose[w]=i;
                if(m!=-1){
                    match[m]=-1;
                }
            }

        }
    }


}

int _tmain(int argc, _TCHAR* argv[]){
    int man[N][N]={
            {2,3,1,0},
            {2,1,3,0},
            {0,2,3,1},
            {1,3,2,0},
    };
    int woman[N][N]={
            {0,3,2,1},
            {0,1,2,3},
            {0,2,3,1},
            {1,0,3,2},
    };
    int match[N];
    GaleShapley(man,woman,match);
//    Print(match,N);
//    Validate(man,woman,match);
    return 0;
}

