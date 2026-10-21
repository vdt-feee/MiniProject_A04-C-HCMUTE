// Trần Ngọc Thắng, Mã số sinh viên: 26119192
// Phan Quang Thành, Mã số sinh viên: 26119188

#include <stdio.h>
#include "tiendien.h" // Nhúng bản hợp đồng chung vào

int NhapVaTinhSoKWh() {
    int dau_ky, cuoi_ky;
    int kiem_tra;

    // input Đầu kỳ, và tránh TH nhap sai
    do {
        printf("Nhap chi so cong to dau ky (kWh): ");
        kiem_tra = scanf("%d", &dau_ky); // Kiem tra input dung hay sai
    //  scanf trả về 1 là đúng, 0 là sai

        if (kiem_tra == 0) {
            printf("Loi: Ban da nhap chu. Vui long nhap so!\n");
            while (getchar() != '\n'); // Clear bộ nhớ đệm
        } else if (dau_ky < 0) {
            printf("Loi: Chi so dau ky khong duoc am!\n");
        }
    } while (kiem_tra == 0 || dau_ky < 0);


    // Nhap CK, va tranh TH nhap sai
    do {
        printf("Nhap chi so cong to cuoi ky (kWh): ");
        kiem_tra = scanf("%d", &cuoi_ky);

        if (kiem_tra == 0) {
            printf("Loi: Ban da nhap chu. Vui long nhap so!\n");
            while (getchar() != '\n'); // Hút sạch bộ nhớ đệm
        } else if (cuoi_ky < dau_ky) {
            printf("Loi: Chi so cuoi ky phai lon hon hoac bang chi so dau ky (%d)!\n", dau_ky);
        }
    } while (kiem_tra == 0 || cuoi_ky < dau_ky);

    // In ra so dien tieu thu
    int so_kwh = cuoi_ky - dau_ky;
    printf("\n--> So kWh tieu thu la: %d\n", so_kwh);

    return so_kwh;
}
