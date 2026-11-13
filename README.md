# VTMenu iOS — VNG và quốc tế 2.33.1 (232546)

Đã cập nhật nguồn từ `VTMenu_iOS_ESP_Spam_R6.5_AccountSafe_100(1).zip` theo hai dump và hai Info.plist được cung cấp.

- VNG: `com.vng.playtogether`, executable `PLAYTOGETHERVNG`.
- Quốc tế: `com.haegin.playtogether`, executable `PLAYTOGETHER`.
- Cả hai: phiên bản **2.33.1**, build **232546**. Alias VNG `ptg.vng` được giữ từ mã nguồn gốc; không có plist riêng để xác minh alias này.

## Offset và cách phân giải

74 field cố định tại 82 vị trí được đối chiếu bằng namespace, class, tên field và kiểu dữ liệu trong cả hai dump, rồi chuyển vào `src/ios_field_offsets.hpp`. Các field này có cùng layout ở VNG và quốc tế. `IMap.cinemachineBrain` được sửa từ **0x40 sang 0x48**; tại 0x40 là `occlusionArea`, không phải CinemachineBrain.

Các hàm game tiếp tục được tìm bằng metadata IL2CPP lúc chạy, nên không chép RVA của VNG sang quốc tế. `analysis/method_rva_profiles.json` ghi riêng RVA mới của 9 hàm từng có trong bảng native cũ cho từng client. 48 mục hàm của cấu hình hiện có cũng đã đối chiếu tên và kiểu trả về trong cả hai dump (`analysis/dynamic_target_audit.json`).

Static field dùng `field_static_get_value` / `field_static_set_value` thay cho giả định `Il2CppClass + 0xB8`. Hàm singleton giữ tra cứu `Self`, `_instance` và các tên backing field qua metadata. Các generic definition trong dump ghi offset `0x0`, nên không lấy đó làm offset instance. List dùng metadata; độ dài/header mảng dùng API IL2CPP. Collection tra `_count`, `_freeList`, `_lastIndex` / `_freeCount` theo đúng type thay vì giả định HashSet và Dictionary có cùng thứ tự field.

Metadata phiên bản, nhãn menu, plugin và công cụ tạo IPA đều cập nhật. Plugin từ chối phiên bản/build khác. Luồng đóng gói chỉ kiểm metadata cũng phải khớp phiên bản/build.

## Kiểm thử và giới hạn

Xem `VALIDATION.json`. Kiểm thử portable không phải chạy trên iPhone. Gói này là **mã nguồn**, chưa có dylib/IPA mới đã build hoặc ký.

Đã có hai UnityFramework ARM64 không mã hóa và kiểm tra tĩnh:

| File đầu vào | Client | UUID |
| --- | --- | --- |
| UnityFramework | Quốc tế | 509b4c13a6ef393ead2bd36ef6f88ae5 |
| UnityFramework(1) | VNG | 56b9c25802a936b18ad75e38c67dd370 |

Hai getter ActorSystem khớp RVA của dump tương ứng và giải mã thành LDR X0 tại 0x58 / 0x70 rồi RET. Mỗi binary có đủ 26 API IL2CPP bắt buộc và các API tùy chọn menu đang tìm. Đã thu 9 đoạn mã máy cho các hàm được bảo vệ và 50 đoạn cho 48 mục dynamic target (có overload). Địa chỉ và bytes được lưu trong `analysis/native_binary_audit.json`.

Plugin kiểm UUID và 9 đoạn mã máy theo bundle trước khi khởi tạo backend. Công cụ tạo IPA mặc định kiểm UUID và SHA-256 toàn bộ UnityFramework đúng client. Không có global-metadata.dat riêng để kiểm hash metadata; không tuyên bố đã kiểm chứng ABI MethodInfo hay hiệu quả trong game chỉ từ các đoạn mã máy này.

Bảng/chữ ký và báo cáo cũ lưu tại `analysis/history_2_32_0`; các file PATCH_R*.md là lịch sử, không phải kết quả kiểm thử bản này.

## Build và đóng gói

Chạy `./build_dylib.sh` trên macOS có Xcode/iPhoneOS SDK hoặc workflow `.github/workflows/build-ios.yml` có sẵn. Không có SDK này trong môi trường đã sửa nguồn.

`tao_ipa_menu.py` ở chế độ CLI mặc định kiểm metadata/Mach-O, UUID và SHA-256 framework đúng client. Kết quả ghi riêng `native_binary_verified` và `metadata_hash_verified`; thiếu hash metadata không được ghi là đã xác minh. Phải ký hợp lệ đầu ra trước khi cài.

Kiểm tra lại dump:

```sh
python scripts/verify_ios_update.py --vng dumpvng.cs --global-dump dumpqt.cs
```

Các tính năng, điều kiện map và bố cục menu giữ theo gói đầu vào; đây không phải cập nhật thêm tính năng.

Kiểm tra lại hai framework (tự xác định VNG/quốc tế bằng các getter):

```sh
python scripts/verify_ios_native.py UnityFramework UnityFramework_VNG --output native-audit.json
```

Các kiểm tra native ở đây là kiểm tra tĩnh. Không có dylib/IPA mới được build trong môi trường này và chưa chạy thử trên iPhone.

## Máy chủ key

Địa chỉ hiện tại: `http://40.160.135.244:10005/`. Đã đổi cả socket HTTP và NSURLSession dự phòng. Giữ nguyên API path và quy trình xác thực. Cần build lại dylib và thay bản đang cài để áp dụng. Chưa kiểm thử kết nối/xác thực trên thiết bị.
