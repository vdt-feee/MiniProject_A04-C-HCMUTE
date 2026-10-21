// Nguyễn Ngọc Thịnh, Mã số sinh viên: 26119199

#include <stdio.h>
#include "tiendien.h"

float TinhTongTienVAT(float tien_chua_vat) {
    // Theo đề bài, VAT là 8% (tức là 0.08)
    float tien_vat = tien_chua_vat * 0.08;
    float tong_tien = tien_chua_vat + tien_vat;

    // In thêm phần đuôi của hóa đơn sao cho thẳng cột với chức năng 2 nha
    printf("Thue VAT (8%%):                        %.0f d\n", tien_vat);
    printf("=============================================\n");
    printf("TONG TIEN CAN THANH TOAN:             %.0f d\n", tong_tien);

    return tong_tien;
}
