// File: tiendien.h

#ifndef TIENDIEN_H
#define TIENDIEN_H // Tên đặt cho vui, cho minh họa chứ không liên quan gì tới tiendien.h nhé ae

// Hàm của Dev 1: Yêu cầu nhập chỉ số đầu/cuối, bắt lỗi (cuối < đầu), trả về số kWh.
int NhapVaTinhSoKWh(void);

// Hàm của Dev 2: Nhận vào số kWh, tính tiền theo 6 bậc, in chi tiết và trả về tiền chưa VAT.
float TinhTienBacThang(int so_kwh);

// Hàm của Dev 3: Nhận vào số tiền chưa VAT, tính thêm 8% VAT và in ra tổng tiền phải trả.
float TinhTongTienVAT(float tien_chua_vat);

// Hàm của Dev 4: Nhận vào mảng chứa số điện 12 tháng, in ra tháng cao nhất, thấp nhất, trung bình
void ThongKe12Thang(int mang_kwh[], int so_thang);

// Hàm của Dev 5: Nhận vào mảng 12 tháng và số tiền ngưỡng, in ra các tháng vượt ngưỡng
float TinhTienCua1Thang(int so_kwh);
void CanhBaoVuotNguong(int mang_kwh[], int so_thang, float tien_nguong);

// Chức năng mở rộng 1: Ước tính số kWh từ danh sách thiết bị
void UocTinhKWhThietBi();

// Chức năng mở rộng 2: Xuất hóa đơn ra file text
void XuatHoaDonRaFile(int so_kwh);
#endif
