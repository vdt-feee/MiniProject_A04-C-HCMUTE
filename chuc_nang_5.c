// Trần Duy Nam, Mã số sinh viên: 26119156

#include <stdio.h>
#include <stdlib.h>
#include "tiendien.h"
/*
Nếu Dev 5 gọi lại hàm TinhTienBacThang của (ChucNang2) để tính tiền cho 12 tháng, màn hình sẽ bị in ra 12 cái hóa đơn chi tiết rất dàii. Để code oke hơn,
ng số 5 sẽ viết một hàm tính tiền trong IM LẶNG (chỉ tính toán và trả về kết quả, không dùng lệnh printf bên trong), vẫn dùng thuật toán cũ ở chucnang2.

*/

float TinhTienCua1Thang(int so_kwh){
    int so_du = so_kwh;
    float tong_tien = 0;
    float tien_bac = 0;
    int kwh_bac;


    // BAC 1
    if (so_du > 0) {
        kwh_bac = (so_du > 50) ? 50 : so_du;  // Chỉ gán giá trị, không khai báo lại
        tien_bac = kwh_bac * 1800.0;
        tong_tien = tong_tien + tien_bac;
        so_du = so_du - kwh_bac;
    }

    // BAC 2
    if(so_du > 0){
        kwh_bac = (so_du > 50) ? 50 : so_du;
        tien_bac = kwh_bac * 1900.0;
        tong_tien = tong_tien + tien_bac;
        so_du = so_du - kwh_bac;
    }
    // BAC 3
    if(so_du > 0){
        kwh_bac = (so_du > 100) ? 100 : so_du;
        tong_tien = tong_tien + kwh_bac * 2200.0;  // tom tat cho gọn hơn bac 1,2 nha ae
        so_du =  so_du - kwh_bac;
    }
    // BAC 4
    if(so_du > 0){
        kwh_bac = (so_du > 100) ? 100 : so_du;
        tong_tien = tong_tien + kwh_bac * 2800.0;  // tom tat cho gọn hơn bac 1,2 nha ae
        so_du =  so_du - kwh_bac;
    }

    // BAC 5
    if(so_du > 0){
        kwh_bac = (so_du > 100) ? 100 : so_du;
        tong_tien = tong_tien + kwh_bac * 3100.0;  // tom tat cho gọn hơn bac 1,2 nha ae
        so_du =  so_du - kwh_bac;
    }
    // BAC 6
    if(so_du > 0){
        kwh_bac = so_du;
        tong_tien = tong_tien + kwh_bac * 3200.0;  // vì bậc 6 kh giới hạn trần nên ta gán thẳng luôn
        so_du =  so_du - kwh_bac;
    }
    return tong_tien * 1.08; // Cong luon 8% VAT
}

void CanhBaoVuotNguong(int mang_kwh[], int so_thang, float tien_nguong){
    int Vuot = 0;
    printf("\n--- CANH BAO NHUNG THANG VUOT NGUONG %.0f vnd ---\n", tien_nguong);
    for(int i = 0; i < so_thang; i++){
        float tien_thang = TinhTienCua1Thang(mang_kwh[i]);

        if(tien_thang > tien_nguong){
            Vuot++;
            printf("\n  THONG BAO: THANG THU %d : %d kWh, VUOT NGUONG TIEN, SO TIEN THANG LA %.0f ", i+1, mang_kwh[i], tien_thang);
        }
    }
    if(Vuot == 0 ){
        printf(" \n Xin Chuc Mung! Khong co thang nao vuot chi tieu \n ");
    }
}

