# Arduino Window Cleaning Robot

**Proje tarihi: 10 Mayıs 2025 (10.05.2025)**

Arduino Uno ve iki 28BYJ-48 step motorla, ip ve makara mekanizması üzerinden cam yüzeyinde hareket etmesi amaçlanan cam temizleme robotu prototipi.

[Robot animasyonunu izle](docs/videos/robot-animation.mp4)

## Proje

100 × 50 cm çalışma alanında robotun merkezden başlayarak yatay satırlar boyunca ilerlemesi ve başlangıç noktasına dönmesi hedeflenir. Bu depo mevcut prototip kodunu, malzeme listesini ve animasyon videosunu içerir; donanım üzerinde doğrulanmış bir hassas konumlandırma sistemi olarak sunulmaz.

## Malzemeler

Kullanılan elektronik elemanlar ve mekanik bileşenler [donanım listesinde](hardware/README.md) açıklanmıştır.

## Dosyalar

- `firmware/robot_final/robot_final.ino`: mevcut Arduino kodu, değiştirilmeden kopyalanmıştır.
- `hardware/README.md`: kullanılan parçalar ve özellikleri.
- `docs/videos/robot-animation.mp4`: robot animasyonu.
- [Proje özeti](docs/project-report.md)
- [Animasyon videosu](docs/videos/robot-animation.mp4)

## Koddaki pin atamaları

| Bileşen | Arduino pinleri |
| --- | --- |
| Sağ motor sürücüsü | 1, 2, 3, 4 |
| Sol motor sürücüsü | 8, 9, 10, 11 |
| Butonlar | 5, 6, 7 (`INPUT_PULLUP`) |
| IR alıcısı | 12 |
| Buzzer | 13 |

Bu tablo kaynak kodunu yansıtır; doğrulanmış devre şeması değildir. Butonlar etkin olduğunda girişin LOW olması beklenir.

## Yazılımı açma

1. Arduino IDE ile `firmware/robot_final/robot_final.ino` dosyasını açın.
2. Kodun kullandığı `Stepper` ve `IRremote` kütüphanelerini hazırlayın.
3. Kart olarak Arduino Uno ve ilgili seri portu seçin.
4. Donanım bağlantılarını ve aşağıdaki sınırlamaları inceleyerek kodu derleyin.

Özgün projede kullanılan IDE ve kütüphane sürümleri kayıtlı değildir. Bu depo hazırlanırken derleme veya fiziksel robot testi yapılmamıştır.

## Kontroller

| Kontrol | IR kodu | Yazılımdaki hedef |
| --- | --- | --- |
| Buton 1 | `BA45FF00` | Üst sağ köşeye git, 10 cm aralıklı satırları tara, merkeze dön |
| Buton 2 | `B946FF00` | Sol orta noktaya git: (0, 25) |
| Buton 3 | `B847FF00` | Alt orta noktaya git: (50, 0) |

Başlangıç konumu yazılımda (50, 25) olarak kabul edilir. Motorlar için 2048 adım/devir, 100 adım/cm ve 10 RPM değerleri tanımlıdır.

## Mevcut sınırlamalar

- Fiziksel butonlar yalnızca `IrReceiver.decode()` başarılı olduğunda okunur; bağımsız buton kontrolü henüz sağlanmaz.
- İplerin konuma bağlı uzunlukları hesaplanmaz. Sabit adım/cm ve eşit motor adımları kullanıldığı için hedef koordinatlar gerçek konumu garanti etmez.
- Başlangıç konumunu ölçen bir referanslama, limit sensörü veya konum geri bildirimi kodda bulunmaz.
- Hareket döngüleri tamamlanana kadar yeni kontroller okunmaz.
- Sağ motor atamalarındaki pin 1, Uno'nun seri haberleşme TX piniyle ortaktır; kod ayrıca `Serial.begin(9600)` çağırır.
- `tone()` çağrılarının hemen ardından `noTone()` çağrılır; beklenen 200 ms ses süresi korunmaz.
- Ayrı temizlik motorunu kontrol eden bir bölüm mevcut kodda bulunmaz.