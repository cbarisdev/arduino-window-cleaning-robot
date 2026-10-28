# Cam temizleme robotu projesi

**Proje tarihi: 10 Mayıs 2025 (10.05.2025)**

## Amaç

İki step motor ve ip mekanizması kullanarak 100 × 50 cm çalışma alanında cam yüzeyi üzerinde hareket etmesi amaçlanan Arduino tabanlı bir cam temizleme robotu prototipi geliştirmek.

## Mekanizma

İki makara üzerindeki iplerin sarılması ve bırakılmasıyla robotun hareket ettirilmesi amaçlanır. Motorlar ULN2003A sürücüleri üzerinden kontrol edilir. Projede üç buton ve kızılötesi kumanda kullanılır.

## Planlanan hareket sırası

1. Merkezden (50, 25) başla.
2. Üst kenara, ardından sağ üst köşeye git.
3. İlk satırı sağdan sola tara.
4. Her satırın sonunda 10 cm aşağı in ve yatay yönü değiştir.
5. Alt satır tamamlanınca merkeze dön.

Diğer iki kontrol sırasıyla sol orta (0, 25) ve alt orta (50, 0) noktalarını hedefler.

## Uygulama durumu

Mevcut kod hedef konum farklarını sabit bir adım/cm katsayısıyla motor adımlarına dönüştürür. Gerçek ip geometrisi ve konum geri bildirimi kullanılmadığından bu yaklaşımın hassasiyeti donanım üzerinde ayrıca değerlendirilmelidir. Kod değiştirilmeden arşivlenmiştir; bilinen sınırlamalar ana README içinde listelenmiştir.

Bu metin özgün proje raporunun kısa bir özetidir. Başarı oranı, konum hatası veya temizlik performansı için ölçüm sonucu sağlanmamıştır.
