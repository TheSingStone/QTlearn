#include <iostream>
#include <math.h>

using namespace std;

int CLIP(int min,int max,int num)
{
    int output = (num < min) ? min :((num > max) ? max : num);
    return output;
}

#define BIT_12_MAX 4095
typedef struct{
    unsigned short grid_gamma[3][1024];
    unsigned int Gamma_LUT[3][512];
}Gamma_TAB;
double inv_output_gamma_simulation_gamma_value[2][3]={
    {1.4,1.1,0.6},
    {1.4,1.1,0.6}
};
Gamma_TAB * Inv_Output_Gamma_Tab_1;
Gamma_TAB * Inv_Output_Gamma_Paras;

int main()
{
    int ii,jj,kk;
    Inv_Output_Gamma_Tab_1 = new Gamma_TAB;
    Inv_Output_Gamma_Paras = new Gamma_TAB;

    for(int ii = 0,jj = 0; ii < BIT_12_MAX;ii += 4,jj++){
        for(int kk = 0; kk < 3;kk++){
            if(inv_output_gamma_simulation_gamma_value[0][kk] != 0)
                Inv_Output_Gamma_Tab_1->grid_gamma[kk][jj] = int(BIT_12_MAX * pow((double)ii / BIT_12_MAX,inv_output_gamma_simulation_gamma_value[0][kk])+0.5);
            else
                Inv_Output_Gamma_Tab_1->grid_gamma[kk][jj] = BIT_12_MAX;
        }
    }
    unsigned char d0 = 0, d1 = 0;

    for( ii = 0,jj = 0; ii < 1024; ii += 2,jj++){
        for(kk = 0; kk < 3; kk++){
            d0 = Inv_Output_Gamma_Tab_1->grid_gamma[kk][ii + 1] - Inv_Output_Gamma_Tab_1->grid_gamma[kk][ii];
            if( ii <= 1020)
                d1 = Inv_Output_Gamma_Tab_1->grid_gamma[kk][ii + 2] - Inv_Output_Gamma_Tab_1->grid_gamma[kk][ii + 1];
            else
                d1 = BIT_12_MAX - Inv_Output_Gamma_Tab_1->grid_gamma[kk][ii + 1];
//                d1 = 0;
            d0 = CLIP(0,255,d0);
            d1 = CLIP(0,255,d1);
            Inv_Output_Gamma_Tab_1->Gamma_LUT[kk][jj] = (Inv_Output_Gamma_Tab_1->grid_gamma[kk][ii] << 16) + (d0 << 8) +d1;
        }
    }
    FILE *File_OUT2;
    if((File_OUT2 = fopen("D:\\InvOutputGammaTbl.txt","w")) != NULL){
        for(jj = 0; jj < 3;jj++)
            for( kk = 0; kk < 1024; kk++)
            {
                fprintf(File_OUT2,"%d;\n",Inv_Output_Gamma_Tab_1->grid_gamma[jj][kk]);
                if(kk == 1023)
                    fprintf(File_OUT2,"---------\n");

            }
        fclose(File_OUT2);
    }
    FILE *File_OUT;
    if((File_OUT = fopen("D:\\InvOutputGammaLUT.txt","w")) != NULL){
    for(jj = 0; jj < 3;jj++)
        for( kk = 0; kk < 512; kk++)
        {
            fprintf(File_OUT,"0x%08x,\n",Inv_Output_Gamma_Tab_1->Gamma_LUT[jj][kk]);
            if(kk == 511)
                fprintf(File_OUT,"----------\n");

        }
    fclose(File_OUT);
    }


    return 0;
}

