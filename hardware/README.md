# Donanım ve malzeme listesi

## Elektronik elemanlar

Aşağıdaki ürün özellikleri proje için paylaşılan parça listesinden alınmıştır. Paket büyüklükleri, robotta kullanılan adetleri ifade etmez.

| Eleman | Özellik / açıklama |
| --- | --- |
| Step motor ve sürücü | 28BYJ-48 redüktörlü step motor ve ULN2003A sürücü kartı; projede 2 takım |
| Mikrodenetleyici kartı | Arduino UNO R3 klon, CH340 USB çipli, USB kablolu |
| Buzzer | 5–12 V, 12 mm |
| Direnç | 330 Ω, 1/4 W; 10 adetlik paket |
| Buton | 4 pinli siyah push button, 6 × 6 × 5 mm; kodda 3 buton |
| LED | 3 mm yeşil LED; 10 adetlik paket |
| Jumper kablo | Erkek–erkek, 30 cm / 300 mm, 40 pin ayrılabilir |
| DC motor | 3–6 V hobi ve oyuncak motoru |
| Breadboard | BB-301 orta boy |

## Diğer bileşenler

Proje belgesi ve kaynak kodda ayrıca şu bileşenler yer alır:

- Kızılötesi kumanda ve IR alıcısı
- İpin sarılıp bırakılması için 2 makara ve misina
- 100 × 50 cm çalışma plakası

## Kodla bağlantısı

Motor, buton, IR alıcısı ve buzzer pin atamaları [ana README içinde](../README.md#koddaki-pin-atamaları) bulunur. Mevcut firmware içinde ayrı DC temizlik motoru ve yeşil LED için kontrol tanımlanmamıştır.
