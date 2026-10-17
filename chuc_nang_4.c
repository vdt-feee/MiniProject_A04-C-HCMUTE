#include <stdio.h>
#include <stdlib.h>
#include "tiendien.h"

void ThongKe12Thang(int mang_kwh[], int so_thang){
    int tong_kwh = 0;

    int max_kwh = -1;
    int min_kwh = 99999999;
    int thang_max = 1; int thang_min = 1;
    int kiemtra = 0;
    printf("\n NHAP DU LIEU %d THANG \n", so_thang);

    for(int i = 0; i < so_thang; i++){
        do {
            printf("Nhap so kWh cua thang %d: ", i+1);
            kiemtra = scanf("%d", &mang_kwh[i]);
            if(kiemtra == 0){
                    printf(" \n BAN DA NHAP CHU, VUI LONG NHAP LAI SO \n");
                    while(getchar() != '\n');
           }
            else if(mang_kwh[i] < 0){
            printf(" BAN DA NHAM SO AM, VUI LONG NHAP LAI > 0");
           }
        }while(mang_kwh[i] < 0 || kiemtra == 0);
        // Tính max, min và tổng luôn nha ae
        tong_kwh = tong_kwh + mang_kwh[i];
        // MAX
        if(mang_kwh[i] > max_kwh){
            max_kwh = mang_kwh[i];
            thang_max = i + 1; // vi chi so thu 2 thi do la thang 3
        }
        // MIN
        if(mang_kwh[i] < min_kwh){
            min_kwh = mang_kwh[i];
            thang_min = i + 1;
        }
    }

    float trungbinh = (float)tong_kwh / so_thang;

    printf("\n--- BANG CHI TIET THONG KE CUA %d THANG ---\n", so_thang);
    printf("Thang tieu thu NHIEU nhat: Thang %d (%d kWh)\n", thang_max, max_kwh);
    printf("Thang tieu thu IT nhat   : Thang %d (%d kWh)\n", thang_min, min_kwh);
    printf("Muc tieu thu TRUNG BINH  : %.1f kWh/thang\n", trungbinh);

}
