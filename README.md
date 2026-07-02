# Trò Chơi Đoán Từ (Word Guessing Game)

Một trò chơi đoán từ (kiểu Hangman) viết bằng **C++**, chạy trên terminal. Người chơi đoán từng ký tự để lấp đầy một từ bị ẩn, có tính điểm, đếm số lần đoán sai, đếm giờ và hỗ trợ gợi ý (hint).

---

## 📁 Cấu trúc dự án

```
├── main.cpp        # Điểm khởi chạy chương trình
├── Game.h / .cpp    # Lớp điều khiển luồng chơi chính (game loop)
├── Player.h / .cpp # Lớp quản lý người chơi (tên, điểm, số lần sai)
├── WordList.h / .cpp # Lớp quản lý danh sách từ, đọc từ file
├── Utils.h / .cpp   # Lớp tiện ích: in màn hình, xử lý chuỗi, đồng hồ đếm giờ (Timer)
└── input.txt        # Danh sách các từ dùng để chơi
```

## Kiến trúc & mối quan hệ giữa các lớp

- **`Game`** là lớp trung tâm. Nó điều phối toàn bộ vòng lặp chơi: khởi tạo → chọn độ khó → chơi → kết thúc vòng → hỏi chơi tiếp.
- **`Player`** lưu trạng thái người chơi: tên, điểm số, số lần đoán sai; cũng chịu trách nhiệm nhận input từ bàn phím (tên, ký tự đoán, số nguyên).
- **`WordList`** đọc danh sách từ từ file `input.txt` và chọn ngẫu nhiên một từ để chơi.
- **`Utils`** là tập hợp hàm tĩnh (in màn hình, ẩn ký tự, xử lý ký tự đoán, kiểm tra hoàn thành...).

## Tính năng chính

| Tính năng | Mô tả |
|---|---|
| 3 mức độ khó | Ẩn 30% / 50% / 70% số ký tự trong từ |
| Gợi ý (Hint) | Nhấn `?` để mở 1 ký tự ngẫu nhiên, tốn **5 điểm** (yêu cầu tối thiểu 5 điểm) |
| Hệ thống điểm | +5 điểm cho mỗi ký tự đoán đúng, -5 điểm khi dùng hint |
| Giới hạn đoán sai | Thua sau **7 lần** đoán sai |
| Đồng hồ đếm giờ | Tính thời gian chơi mỗi ván (hỗ trợ pause khi thắng/thua) |
| Chơi nhiều ván | Có thể chơi lại nhiều lần trong một phiên, đổi độ khó mỗi ván |
| Danh sách từ tùy chỉnh | Đọc từ file `input.txt`, dễ dàng thêm/bớt từ |

## Cách chơi

1. Nhập tên khi được yêu cầu.
2. Nhấn **Enter** để vào menu chọn độ khó.
3. Chọn độ khó (`1`, `2`, hoặc `3`).
4. Ở mỗi lượt, nhập **1 ký tự** để đoán, hoặc nhập `?` để dùng gợi ý.
5. Đoán đúng hết các ký tự trong từ để thắng; đoán sai 7 lần thì thua.
6. Sau mỗi ván, nhập `c` để chơi tiếp hoặc phím bất kỳ khác để kết thúc.

## Biên dịch & chạy

Dự án chỉ dùng thư viện chuẩn C++ (STL), không cần thư viện ngoài. Yêu cầu trình biên dịch hỗ trợ C++11 trở lên (do dùng `<chrono>`).

**Windows (dùng `system("cls")` / `system("pause")`):**
```bash
g++ -std=c++11 main.cpp Game.cpp Player.cpp Utils.cpp WordList.cpp -o WordGuess.exe
WordGuess.exe
```

> ⚠️ Lưu ý: code hiện dùng `system("cls")` và `system("pause")` — đây là các lệnh đặc thù của **Windows (cmd.exe)**. Trên Linux/macOS cần đổi thành `system("clear")` và bỏ/thay `system("pause")` bằng cách đọc input thủ công.

Đảm bảo file `input.txt` nằm cùng thư mục với file thực thi.

## Yêu cầu hệ thống

- Trình biên dịch C++ hỗ trợ **C++11** trở lên 
- Hệ điều hành: **Windows** 

## Ghi chú 
- Chuỗi hiển thị trong console không dùng dấu tiếng Việt có dấu (chỉ dùng tiếng Việt không dấu) để tránh lỗi encoding trên console Windows mặc định.
