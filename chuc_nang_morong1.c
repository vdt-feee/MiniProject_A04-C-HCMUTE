
#include <stdio.h>
#include "tiendien.h"

void UocTinhKWhThietBi(void) {
    int so_thiet_bi;
    float tong_kwh = 0;
    int kiem_tra;

    printf("\n--- UOC TINH DIEN NANG 30 NGAY ---\n");

    // Bắt lỗi khi nhập số lượng thiết bị
    do {
        printf("Nhap so luong thiet bi can tinh: ");
        kiem_tra = scanf("%d", &so_thiet_bi);

        if (kiem_tra == 0) {
            printf("Loi: Ban da nhap chu. Vui long nhap so!\n");
            while (getchar() != '\n');
        } else if (so_thiet_bi <= 0) {
            printf("Loi: So luong thiet bi phai lon hon 0!\n");
        }
    } while (kiem_tra == 0 || so_thiet_bi <= 0);

    for (int i = 0; i < so_thiet_bi; i++) {
        float cong_suat, gio;

        // Nhập công suất (có bắt lỗi cơ bản)
        printf("Thiet bi %d - Cong suat (W): ", i + 1);
        while (scanf("%f", &cong_suat) == 0 || cong_suat < 0) {
             printf("Loi nhap lieu. Nhap lai cong suat (W): ");
             while (getchar() != '\n');
        }

        // Nhập số giờ (có bắt lỗi cơ bản)
        printf("Thiet bi %d - So gio dung moi ngay: ", i + 1);
        while (scanf("%f", &gio) == 0 || gio < 0 || gio > 24) {
             printf("Loi nhap lieu (Gio tu 0-24). Nhap lai: ");
             while (getchar() != '\n');
        }

        // Tính số kWh trong 1 tháng (30 ngày)
        float kwh_thiet_bi = (cong_suat * gio / 1000.0) * 30.0;
        tong_kwh += kwh_thiet_bi;
    }

    printf("---------------------------------------------\n");
    printf("-> Uoc tinh tong dien nang: %.1f kWh/thang\n", tong_kwh);
}
