#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;


#define Size 16
#define Size_seg 4

int main(void)
{
    char lineBuf[1000];
    fstream fileOut1;
    char filename[100];

    int i, j, k, m, n, temp, pos, sel;
    int bit, bit_value;

    int poker[Size_seg]={0}, poker2[Size]={0};
    int tab_tmp[Size_seg][Size]={0}, tab_tmp2[Size_seg][Size]={0}, tab[Size_seg][Size]={0};
    int seg[Size_seg] = {0, 16, 32, 48};

    unsigned char A[6][4][4]={
             {{0,1,2,3},{3,2,1,0},{1,3,0,2},{2,0,3,1}},
             {{0,2,3,1},{3,1,0,2},{1,0,2,3},{2,3,1,0}},
             {{0,3,1,2},{3,0,2,1},{1,2,3,0},{2,1,0,3}},
             {{0,1,3,2},{3,2,0,1},{1,3,2,0},{2,0,1,3}},//
             {{0,2,1,3},{3,1,2,0},{1,0,3,2},{2,3,0,1}},//
             {{0,3,2,1},{3,0,1,2},{1,2,0,3},{2,1,3,0}}};//

    printf("table bits: ");
    scanf(" %d",&bit);


    sprintf(filename, "D://dither_random_tab_%dbit_v8.txt", bit);
    fileOut1.open(filename, ios::out);//¶}±Ҁɮ׍

    srand((unsigned) time(NULL));

    sprintf(lineBuf,"tmp:\n");
    fileOut1.write(lineBuf, strlen(lineBuf));

    // tmp
    for(i = 0; i < Size; i++)
    {
        tab_tmp[0][i] = (seg[0] + i)>>(6-bit);
        tab_tmp[1][i] = (seg[1] + i)>>(6-bit);
        tab_tmp[2][i] = (seg[2] + i)>>(6-bit);
        tab_tmp[3][i] = (seg[3] + i)>>(6-bit);

        sprintf(lineBuf,"%2d: %2d %2d %2d %2d\n", i, tab_tmp[0][i], tab_tmp[1][i], tab_tmp[2][i], tab_tmp[3][i]);
        fileOut1.write(lineBuf, strlen(lineBuf));
    }

    for(j=0; j<5; j++)
    {
        sprintf(lineBuf,"\n========= #%d ==========\n",j);
        fileOut1.write(lineBuf, strlen(lineBuf));

        sprintf(lineBuf,"\nshuffle:\n");
        fileOut1.write(lineBuf, strlen(lineBuf));

        // seg rand
        //init
        for(i = 0; i < Size_seg; i++)
            poker[i] = i;
        for(i = 0; i < Size; i++)
            poker2[i] = i;

        //shuffle
        for(i = 0; i < Size_seg; ++i){
            pos = rand()%(Size_seg);

            temp = poker[i];
            poker[i] = poker[pos];
            poker[pos] = temp;
        }
        for(i = 0; i < Size; ++i){
            pos = rand()%(Size);

            temp = poker2[i];
            poker2[i] = poker2[pos];
            poker2[pos] = temp;
        }

        for(i = 0; i < Size_seg; ++i){
            sprintf(lineBuf,"%d ", poker[i]);
            fileOut1.write(lineBuf, strlen(lineBuf));
        }
        sprintf(lineBuf,"\n");
        fileOut1.write(lineBuf, strlen(lineBuf));

        for(i = 0; i < Size; ++i){
            sprintf(lineBuf,"%d ", poker2[i]);
            fileOut1.write(lineBuf, strlen(lineBuf));
        }

        // select for A[3+sel]
        sel = rand()%3;
        sprintf(lineBuf,"\n\nsel B: %d\n", sel);
        fileOut1.write(lineBuf, strlen(lineBuf));

        // tmp2
        sprintf(lineBuf,"\ntmp2:\n");
        fileOut1.write(lineBuf, strlen(lineBuf));

        for(k = 0; k < 4; k++)//A[k][m][]
        {
            for(m = 0; m < 4; m++)
            {
                i=4*k+m;
                n=k;
                if(k==3) n=k+sel;

                tab_tmp2[0][i] = (tab_tmp[poker[A[n][m][0]]][i]);
                tab_tmp2[1][i] = (tab_tmp[poker[A[n][m][1]]][i]);
                tab_tmp2[2][i] = (tab_tmp[poker[A[n][m][2]]][i]);
                tab_tmp2[3][i] = (tab_tmp[poker[A[n][m][3]]][i]);

                sprintf(lineBuf,"%2d: %2d %2d %2d %2d\n", i, tab_tmp2[0][i], tab_tmp2[1][i], tab_tmp2[2][i], tab_tmp2[3][i]);
                /*sprintf(lineBuf,"%2d: %2d %2d %2d %2d -> %d %d %d, A %d %d %d %d, p %d %d %d %d\n", i, tab_tmp2[0][i], tab_tmp2[1][i], tab_tmp2[2][i], tab_tmp2[3][i],
                    k,m,n,A[n][m][0],A[n][m][1],A[n][m][2],A[n][m][3],
                    poker[A[n][m][0]],poker[A[n][m][1]],poker[A[n][m][2]],poker[A[n][m][3]]);*/
                fileOut1.write(lineBuf, strlen(lineBuf));
            }
        }

        // table
        sprintf(lineBuf,"\n\nfinal:\n");
        fileOut1.write(lineBuf, strlen(lineBuf));

        for(i = 0; i < Size; i++)
        {
            tab[0][i] = (tab_tmp2[0][poker2[i]]);
            tab[1][i] = (tab_tmp2[1][poker2[i]]);
            tab[2][i] = (tab_tmp2[2][poker2[i]]);
            tab[3][i] = (tab_tmp2[3][poker2[i]]);

            sprintf(lineBuf,"%2d: %2d %2d %2d %2d\n", i, tab[0][i], tab[1][i], tab[2][i], tab[3][i]);
            fileOut1.write(lineBuf, strlen(lineBuf));

        }
        sprintf(lineBuf,"\n");
        fileOut1.write(lineBuf, strlen(lineBuf));
    }

    fileOut1.close();
    system("pause");
    return 0;
}
