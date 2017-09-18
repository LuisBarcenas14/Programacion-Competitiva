#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXCANDIDATES 10
#define TRUE true
#define FALSE false

bool is_a_solution(int a[], int k, int n){
    return (k == n);
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates){
    c[0] = TRUE;
    c[1] = FALSE;
    *ncandidates = 2;
}

void process_solution(int a[], int k){
    int i; /* counter */
    printf("{");
    for (i=1; i<=k; i++)
        if (a[i] == TRUE) printf(" %d",i);
    printf(" }\n");
}

bool finished = false;
/* found all solutions yet? */
void backtrack(int a[], int k, int n){
    int c[MAXCANDIDATES];   /* candidates for next position */
    int ncandidates;        /* next position candidate count */
    int i;                  /* counter */
    cout<<"k: "<<k<<" n: "<<n<<endl;
    if (is_a_solution(a,k,n))
        process_solution(a,k);
    else {
        k = k+1;
        construct_candidates(a,k,n,c,&ncandidates);
        //cout<<"a: "<<<<endl;
        for (i=0; i<ncandidates; i++) {
            a[k] = c[i];
            backtrack(a,k,n);
            if (finished) return;
            /* terminate early */
        }
    }
}

int main(){
    int a[10];
    /* solution vector */
    //a[0]=2;
    //a[1]=4;
    //a[2]=6;

    int n=3;
    backtrack(a,0,n);
    return 0;
}
