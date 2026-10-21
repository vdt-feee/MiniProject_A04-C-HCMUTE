//  Vũ Duy Thức, Mã số sinh viên: 26119205

#include <stdio.h>
#include "tiendien.h"

int main() {
    int chon;

    int so_kwh_hien_tai = 0;
    float tien_chua_vat = 0;

    int mang_12_thang[12] = {0};
    int da_nhap_12_thang = 0;

    do {
        printf(" \n ");
        printf("\n=========================================\n");
        printf("   PHAN MEM TINH TIEN DIEN SINH HOAT\n");
        printf("=========================================\n");
        printf("1. Nhap chi so va Tinh so kWh tieu thu\n");
        printf("2. Tinh tien dien theo bac thang\n");
        printf("3. Tinh thue VAT va Tong tien\n");
        printf("4. Nhap va Thong ke 12 thang\n");
        printf("5. Canh bao thang vuot nguong\n");
        printf("6. [Mo rong] Uoc tinh kWh tu thiet bi\n");
        printf("7. [Mo rong] Xuat hoa don ra file Text\n");
        printf("0. Thoat chuong trinh\n");
        printf("=========================================\n");
        printf("Moi ban chon chuc nang (0-7): \n");

        // Chống treo máy ở ngay Menu
        if (scanf("%d", &chon) == 0) {
            while(getchar() != '\n');
            chon = -1;
        }

        switch(chon) {
            case 1:
                so_kwh_hien_tai = NhapVaTinhSoKWh();
                break;

            case 2:
                if (so_kwh_hien_tai == 0) {
                    printf("Loi: Vui long chay Chuc nang 1 de nhap kWh truoc!\n");
                } else {
                    tien_chua_vat = TinhTienBacThang(so_kwh_hien_tai);
                }
                break;

            case 3:
                if (tien_chua_vat == 0) {
                    printf("Loi: Vui long chay Chuc nang 2 de tinh tien chua VAT truoc!\n");
                } else {
                    TinhTongTienVAT(tien_chua_vat);
                }
                break;

            case 4:
                ThongKe12Thang(mang_12_thang, 12);
                da_nhap_12_thang = 1;
                break;

            case 5:
                if (da_nhap_12_thang == 0) {
                    printf("Loi: Vui long chay Chuc nang 4 de nhap 12 thang truoc!\n");
                } else {
                    float nguong;
                    printf("\nNhap so tien nguong de canh bao (VND): ");
                    while (scanf("%f", &nguong) == 0 || nguong < 0) {
                        printf("Loi: Nhap sai. Vui long nhap so khong am: ");
                        while(getchar() != '\n');
                    }
                    CanhBaoVuotNguong(mang_12_thang, 12, nguong);
                }
                break;

            case 6:
                // Gọi hàm từ file chuc_nang_morong1.c
                UocTinhKWhThietBi();
                break;

            case 7:
                // Bắt buộc phải có số điện thì mới ghi file được
                if (so_kwh_hien_tai == 0) {
                    printf("Loi: Vui long chay Chuc nang 1 de nhap kWh truoc!\n");
                } else {
                    // Gọi hàm từ file chuc_nang_morong2.c
                    XuatHoaDonRaFile(so_kwh_hien_tai);
                }
                break;

            case 0:
                printf("Tam biet! Dong chuong trinh.\n");
                break;

            default:
                printf("Loi: Lua chon khong hop le. Vui long nhap tu 0 den 7!\n");
        }
    } while (chon != 0); // 0 : chon == 0

    return 0;
}
