# Aqualyze — OTA Firmware Demo (ESP32 + Arduino IoT Cloud)

Modul demonstrasi **Over-The-Air (OTA) firmware update** untuk ESP32 DevKit 38-pin menggunakan Arduino IoT Cloud, dibuat untuk tugas mata kuliah IoT. Project ini membuktikan bahwa firmware pada perangkat dapat diperbarui dari jarak jauh lewat WiFi — tanpa kabel USB — setelah upload awal dilakukan.

## Fitur
- Upload awal via USB, update selanjutnya via OTA WiFi langsung dari Arduino Cloud
- Sinkronisasi status perangkat (`deviceStatus`), versi firmware (`firmwareVersionCloud`), dan heartbeat counter (`otaCounter`) ke dashboard cloud secara real-time
- Kontrol LED jarak jauh (`ledState`) dari dashboard
- Versi V2 menambahkan heartbeat LED otomatis sebagai bukti visual bahwa OTA berhasil

## Hardware
- ESP32 DevKit 38-pin (WiFi + Bluetooth)
- LED indikator pada GPIO 2

## Stack
- Arduino IoT Cloud (Thing, Device, Dashboard)
- Library `ArduinoIoTCloud` & `Arduino_ConnectionHandler`

## Struktur File
```
Aqualyze_0.1_jun19a.ino   → firmware utama (versi aktif)
thingProperties.h         → variabel & koneksi cloud (auto-generated)
arduino_secrets.h         → kredensial WiFi & device key (tidak di-commit)
```

## Versi
| Versi | Upload | Catatan |
|---|---|---|
| 1.0.0 | USB | Bootstrap awal, counter tiap 10 detik |
| 2.0.0 | OTA via WiFi | Counter tiap 5 detik, LED heartbeat otomatis |

> ⚠️ File `arduino_secrets.h` berisi kredensial WiFi dan device key — jangan ikut di-push ke repository publik.
