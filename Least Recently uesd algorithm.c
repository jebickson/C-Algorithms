#include <stdio.h>
#include <conio.h>

int ref[50], frm[10], recent[50], nof, nor, pf=0;

int lru() {
    int i, min=9999, pos=0;
    for(i=0;i<nof;i++)
        if(recent[frm[i]]<min){ min=recent[frm[i]]; pos=i; }
    return pos;
}

void main() {
    int i,j,k,flag,pos;
    clrscr();
    printf("Enter no. of frames & references: ");
    scanf("%d%d",&nof,&nor);
    printf("Enter reference string: ");
    for(i=0;i<nor;i++) scanf("%d",&ref[i]);
    for(i=0;i<nof;i++) frm[i]=-1;

    for(i=0;i<nor;i++){
        flag=0;
        for(j=0;j<nof;j++)
            if(frm[j]==ref[i]){ flag=1; break; }
        if(!flag){
            pos=(i<nof)?i:lru();
            frm[pos]=ref[i]; pf++;
        }
        recent[ref[i]]=i;
        printf("Ref %2d -> ",ref[i]);
        for(k=0;k<nof;k++)
            if(frm[k]!=-1) printf("%2d ",frm[k]); else printf("-- ");
        printf("\n");
    }
    printf("\nTotal Page Faults = %d",pf);
    getch();
}

