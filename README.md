# BAI_TAP_VN_01

## Tên gọi là Mã Caesar. 

# Thuật toán mã hoá
Mỗi chữ cái trong bản rõ được dịch chuyển k vị trí trong bảng chữ cái (A–Z).
Công thức (với chữ cái đã đổi sang số 0–25):
C=(P+k)mod26
P: số của ký tự gốc.
k: khóa (số dịch chuyển, 0–25).
C: số của ký tự đã mã hoá.

## Thuật toán giải mã 
<img width="667" height="102" alt="image" src="https://github.com/user-attachments/assets/12a048cb-3b15-4435-a5f0-ad814625bf5f" /> </p>
## Không gian khoá 
Khóa k là một số nguyên từ 0 đến 25 (thường loại trừ 0 vì không mã hóa gì).
⇒ Kích thước không gian khoá: 26 khả năng (thực tế 25 hữu ích).
## Cách phá mã( không cần khoá) 
Do không gian khoá rất nhỏ, có thể brute-force:
Thử tất cả 26 giá trị k.
Giải mã bản mã với từng k.
Đọc ra kết quả; bản rõ đúng sẽ xuất hiện ngay.
Ngoài ra:
Phân tích tần suất: Trong tiếng Anh, chữ E thường xuất hiện nhiều nhất. So sánh tần suất ký tự của bản mã với bảng tần suất ngôn ngữ để suy ra k.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

<img width="512" height="222" alt="image" src="https://github.com/user-attachments/assets/b84d872e-d7f2-49a4-86b2-94e736c3f94d" />

# Chương trình.
<img width="745" height="390" alt="image" src="https://github.com/user-attachments/assets/b7edfc1d-7fab-4432-af65-dec326c27230" />

## Tên gọi là Mã Affine
# Thuật toán mã hoá 
C=(a×P+b)mod26
P: số của ký tự gốc (0–25)
C: số ký tự mã hóa
a, b: khóa
# Thuật toán giải mã 
<img width="654" height="179" alt="image" src="https://github.com/user-attachments/assets/830b515e-a09c-44c4-ba6a-ca96d68a8811" />
# Không gian khoá 
Số giá trị a hợp lệ: các số 0–25 mà gcd(a,26)=1
→ Tập {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25} ⇒ 12 giá trị.
Số giá trị b: 0–25 ⇒ 26 giá trị.
⇒ Tổng số khoá: 12 × 26 = 312
# Cách phá khoá ( không cần khoá )
Brute force: Thử 312 cặp (a,b) ⇒ dễ dàng với máy tính.
Phân tích tần suất: Giống Caesar, dựa vào tần suất chữ cái trong ngôn ngữ.

# Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

<img width="565" height="288" alt="image" src="https://github.com/user-attachments/assets/76f609f8-6800-4787-97f7-d66f02ce9fe3" />

# chương trình 
<img width="884" height="446" alt="image" src="https://github.com/user-attachments/assets/dbbadb1c-b7f4-4ec1-9b73-011fa997535a" />
Chọn a = 5, b = 8

Bản rõ: AFFINE

Mã hoá từng ký tự:

A(0) → (5×0+8) mod 26 = 8 → I

F(5) → (5×5+8) mod 26 = 7 → H
⇒ Kết quả: IHHWVC.
# Tên gọi là Transposition Cipher
# Thuật toán mã hoá
Chọn khoá: Một từ khóa, ví dụ ZEBRA. Đánh số thứ tự chữ cái khóa theo thứ tự bảng chữ cái: Z(5), E(2), B(1), R(4), A(3) ⇒ thứ tự cột: 3-5-2-4-1.
Viết bản rõ thành nhiều hàng theo độ dài khóa.
Ví dụ: Bản rõ “ATTACKATDAWN” và khóa ZEBRA (độ dài 5).
Viết vào bảng 5 cột, điền theo hàng:
A T T A C
K A T D A
W N X X X   (thêm X nếu thiếu)
Đọc theo thứ tự cột dựa vào vị trí đã sắp xếp khóa: cột 1→3→5→2→4.
⇒ Bản mã.
# Thuật toán giải mã
Biết khóa và độ dài bản mã.
Tính số hàng.
Điền bản mã theo thứ tự cột (dựa trên khóa sắp xếp) vào bảng.
Đọc theo hàng để thu bản rõ.
# Không gian khoá
Nếu khóa là hoán vị của n cột ⇒ số khóa = n!.
Ví dụ: dùng 8 cột → 8! = 40,320 khóa.
Nếu khóa là một từ, không gian khóa phụ thuộc vào số hoán vị chữ cái trong từ.
# Cách phá mã (không cần khoá)
Phân tích tần suất: Vì không thay đổi ký tự, tần suất giống văn bản thường ⇒ có thể nhận diện.
Brute force: Thử mọi hoán vị n! (khi n nhỏ).
Phân tích mẫu: Tìm khoảng cách lặp của các cụm chữ, suy ra số cột/chu kỳ.
Tấn công kết hợp: Suy đoán độ dài khóa, sau đó thử tất cả hoán vị.
# Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

<img width="524" height="218" alt="image" src="https://github.com/user-attachments/assets/35679d99-b253-4e3f-aca4-4c8eb3ad14bb" />

# Chương trình 
<img width="713" height="379" alt="image" src="https://github.com/user-attachments/assets/adf441f4-6eef-4305-9017-6a0d57d37557" />

# Tên Gọi Là Vigenère Cipher
# Thuật toán mã hoá 
<img width="648" height="243" alt="image" src="https://github.com/user-attachments/assets/263da424-2e86-4036-8e4f-e82cc52d5452" />
# Thuật toán giải mã 
<img width="329" height="85" alt="image" src="https://github.com/user-attachments/assets/2c11eb0c-737e-4f46-8a9e-c56c8962b009" />
# Không gian khoá 
<img width="734" height="83" alt="image" src="https://github.com/user-attachments/assets/e75d9040-f42e-4f6b-8683-63b199c7dc8f" />
# Cách phá mã (không cần khóa)
Dù lớn hơn Caesar/Affine, Vigenère không an toàn hiện đại.
Các kỹ thuật kinh điển:
Tấn công Kasiski: Tìm khoảng cách lặp của chuỗi chữ cái lặp để ước lượng độ dài khóa.
Chỉ số trùng hợp (Index of Coincidence): Ước lượng độ dài khóa dựa vào thống kê.
Khi biết độ dài khóa n, tách bản mã thành n dãy, mỗi dãy là Caesar cipher ⇒ dùng phân tích tần suất cho từng dãy.
# Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

<img width="522" height="206" alt="image" src="https://github.com/user-attachments/assets/a8a41074-d89d-4249-b1ea-cd2d3535481b" />

# Chương trình 
<img width="681" height="370" alt="image" src="https://github.com/user-attachments/assets/453e5239-412f-4ede-8f8d-c95f352a94a8" />

# Tên gọi là Playfair Cipher

# Thuật toán mã hoá & giải mã
a. Chuẩn bị bảng khóa (5×5)
Chọn từ khóa (ví dụ: MONARCHY).
Viết từ khóa vào bảng 5x5, loại bỏ chữ trùng, sau đó điền các chữ cái còn lại theo thứ tự alphabet.
Gộp I và J chung một ô (hoặc Q tùy biến).
Ví dụ khóa MONARCHY:

M O N A R
C H Y B D
E F G I/J K
L P Q S T
U V W X Z

 # b. Quy tắc mã hoá
Chia bản rõ thành cặp chữ cái (digraph):
Nếu cặp trùng (ví dụ “LL”), chèn X (hoặc Q) giữa: “LX L…”.
Nếu còn lẻ, thêm X cuối.
Với từng cặp (A,B):
Cùng hàng: Thay mỗi chữ bằng chữ bên phải (vòng lại nếu cuối hàng).
Cùng cột: Thay mỗi chữ bằng chữ bên dưới (vòng lại nếu cuối cột).
Khác hàng/cột: Mỗi chữ thay bằng chữ ở cùng hàng nhưng ở cột của chữ kia (tạo hình chữ nhật).

# c. Giải mã
Làm ngược: nếu cùng hàng lấy bên trái, cùng cột lấy bên trên, chữ nhật đổi cột như trên.

# Không gian khóa
<img width="614" height="85" alt="image" src="https://github.com/user-attachments/assets/8d3b0d69-5d22-447a-93b4-03f5aab8c0a1" />
# Cách phá mã (không cần khóa)
Không thể brute-force toàn bộ 25!
Tuy nhiên vẫn bị phá bằng:
Phân tích tần suất digraph (cặp chữ).
Phương pháp Friedman/Kasiski mở rộng cho digraph.
Tấn công chọn bản rõ/bản mã.
So với Caesar, Affine, Vigenère, Playfair mạnh hơn nhưng vẫn không đủ an toàn hiện đại.
# Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

<img width="547" height="209" alt="image" src="https://github.com/user-attachments/assets/fcf91901-e8f8-4d55-8c8a-bad9b091e234" />

# Chương trình 

<img width="673" height="411" alt="image" src="https://github.com/user-attachments/assets/03dc3e8f-9809-4ecd-a35e-117a1dd5ceed" />














