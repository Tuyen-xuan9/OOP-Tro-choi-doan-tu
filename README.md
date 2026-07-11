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

vào thư mục click vào WordGuess.exe và bắt đầu chơi

## Yêu cầu hệ thống

- Trình biên dịch C++ hỗ trợ **C++11** trở lên 
- Hệ điều hành: **Windows** 
