#include <stdio.h>
#include "tiendien.h"

float TinhTienBacThang(int so_kwh) {
    int so_du = so_kwh;
    float tong_tien = 0;

    int kwh_bac;
    float tien_bac;

    printf("\n CHI TIET TIEN DIEN (CHUA VAT) \n");

    // Bậc 1: 0 - 50 kWh
    if (so_du > 0) {
        kwh_bac = (so_du > 50) ? 50 : so_du;  // Chỉ gán giá trị, không khai báo lại
        tien_bac = kwh_bac * 1800.0;
        tong_tien += tien_bac;
        so_du -= kwh_bac;
        printf("Bac 1 (0-50)   : %3d kWh x 1.800d = %8.0f d\n", kwh_bac, tien_bac);
    }

    // Bậc 2: 51 - 100 kWh
    if (so_du > 0) {
        kwh_bac = (so_du > 50) ? 50 : so_du;  // Tái sử dụng lại biến
        tien_bac = kwh_bac * 1900.0;
        tong_tien += tien_bac;
        so_du -= kwh_bac;
        printf("Bac 2 (51-100) : %3d kWh x 1.900d = %8.0f d\n", kwh_bac, tien_bac);
    }

    // Bậc 3: 101 - 200 kWh
    if (so_du > 0) {
        kwh_bac = (so_du > 100) ? 100 : so_du;
        tien_bac = kwh_bac * 2200.0;
        tong_tien += tien_bac;
        so_du -= kwh_bac;
        printf("Bac 3 (101-200): %3d kWh x 2.200d = %8.0f d\n", kwh_bac, tien_bac);
    }

    // Bậc 4: 201 - 300 kWh
    if (so_du > 0) {
        kwh_bac = (so_du > 100) ? 100 : so_du;
        tien_bac = kwh_bac * 2800.0;
        tong_tien += tien_bac;
        so_du -= kwh_bac;
        printf("Bac 4 (201-300): %3d kWh x 2.800d = %8.0f d\n", kwh_bac, tien_bac);
    }

    // Bậc 5: 301 - 400 kWh
    if (so_du > 0) {
        kwh_bac = (so_du > 100) ? 100 : so_du;
        tien_bac = kwh_bac * 3100.0;
        tong_tien += tien_bac;
        so_du -= kwh_bac;
        printf("Bac 5 (301-400): %3d kWh x 3.100d = %8.0f d\n", kwh_bac, tien_bac);
    }

    // Bậc 6: Tren 400 kWh
    if (so_du > 0) {
        kwh_bac = so_du;
        tien_bac = kwh_bac * 3200.0;
        tong_tien += tien_bac;
        printf("Bac 6 (> 400)  : %3d kWh x 3.200d = %8.0f d\n", kwh_bac, tien_bac);
    }

    printf("---------------------------------------------\n");
    printf("Tong tien chua VAT:                   %.0f d\n", tong_tien);

    return tong_tien;
}
