# 3-match

[English](#english) · [Türkçe](#türkçe)

<p align="center">
  <img src="docs/gameplay.png" alt="3-match game board preview / 3-match oyun tahtası önizlemesi" width="378">
</p>

<p align="center"><sub>Gameplay preview recreated using the game's original sprites. / Oyunun özgün görselleriyle oluşturulmuş oynanış önizlemesi.</sub></p>

## English

A simple desktop match-3 puzzle game built with **C++20** and **SFML 3**.

### Gameplay

- Swap two adjacent gems by pressing the mouse button on one gem and releasing it on a neighboring cell.
- Match at least three gems of the same type horizontally or vertically.
- Matched gems disappear, gems above them fall, and new gems enter from the top.
- Swaps that do not produce a match are reversed.

The game uses a **9 × 9** grid with five gem types.

### Build and run

**Requirements:** a C++20 compiler, CMake 3.22+, and an installed SFML 3 package (Graphics and Audio components).

CMake now locates SFML 3 without machine-specific paths. If SFML is installed outside CMake's default search locations, provide its installation prefix when configuring, e.g. `cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/sfml`.

```bash
git clone https://github.com/Berkopan/3match.git
cd 3match
cmake -S . -B build
cmake --build build
./build/3-match
```

Run the executable **from the repository root** so the relative `assets/board.png` and `assets/gems.png` paths resolve correctly.

### License

MIT — see [LICENSE](LICENSE).

---

## Türkçe

**C++20** ve **SFML 3** kullanılarak geliştirilmiş basit bir masaüstü üçlü eşleştirme oyunu.

### Oynanış

- Bir taşın üzerinde fare tuşuna basıp komşu bir hücrede bırakarak iki taşı yer değiştir.
- Yatay veya dikey olarak aynı türden en az üç taşı eşleştir.
- Eşleşen taşlar kaybolur, üstlerindeki taşlar aşağı düşer ve yukarıdan yeni taşlar gelir.
- Eşleşme oluşturmayan hamleler geri alınır.

Oyunda beş farklı taş türünden oluşan **9 × 9** boyutunda bir tahta bulunur.

### Derleme ve çalıştırma

**Gereksinimler:** C++20 destekleyen bir derleyici, CMake 3.22+ ve kurulu SFML 3 paketi (Graphics ve Audio bileşenleri).

CMake artık SFML 3'ü bilgisayara özgü sabit yollar kullanmadan buluyor. SFML, CMake'in varsayılan arama yolları dışında kuruluysa yapılandırırken kurulum önekini belirt: `cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/sfml`.

```bash
git clone https://github.com/Berkopan/3match.git
cd 3match
cmake -S . -B build
cmake --build build
./build/3-match
```

Oyunu **repo kök dizininden** başlat; görseller `assets/board.png` ve `assets/gems.png` göreli yollarından yükleniyor.

### Lisans

MIT — ayrıntılar için [LICENSE](LICENSE) dosyasına bakabilirsin.
