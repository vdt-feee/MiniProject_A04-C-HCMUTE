
// Vũ Duy Thức, Mã số sinh viên: 26119205

#include <stdio.h>
#include "tiendien.h"

void XuatHoaDonRaFile(int so_kwh) {
    // Mở file ở chế độ ghi ("w"). Nếu file chưa có, nó sẽ tự tạo. Nếu có rồi, nó sẽ ghi đè
    FILE *file = fopen("HoaDon_TienDien.txt", "w");

    if (file == NULL) {
        printf("Loi: Khong the tao hoac mo file hoa don!\n");
        return;
    }

    fprintf(file, "=================================\n");
    fprintf(file, "      HOA DON TIEN DIEN\n");
    fprintf(file, "=================================\n");
    fprintf(file, "Tong so kWh tieu thu: %d kWh\n", so_kwh);

    // Gọi hàm tính tiền ngầm (đã có bên Chức năng 5) để lấy ra tổng tiền
    float tong_tien = TinhTienCua1Thang(so_kwh);

    fprintf(file, "---------------------------------\n");
    fprintf(file, "TONG TIEN (Gom 8%% VAT): %.0f VND\n", tong_tien);
    fprintf(file, "=================================\n");

    fclose(file);
    printf("\n Thanh cong! Da xuat hoa don ra file 'HoaDon_TienDien.txt'\n");
    printf(" Ban hay kiem tra trong thu muc chua code nhaaaaa \n");
}
