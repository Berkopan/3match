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

**Requirements:** a C++20 compiler, CMake 3.14+, and SFML 3 (Graphics and Audio components).

The current `CMakeLists.txt` contains **Homebrew-specific, hard-coded SFML 3.0.0_1 paths** under `/opt/homebrew/Cellar/sfml/`. If your SFML installation uses a different location or version, update `SFML_DIR` and the include directory in `CMakeLists.txt` before building.

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

**Gereksinimler:** C++20 destekleyen bir derleyici, CMake 3.14+ ve SFML 3 (Graphics ve Audio bileşenleri).

Mevcut `CMakeLists.txt`, `/opt/homebrew/Cellar/sfml/` altında **Homebrew'e özel, sabit SFML 3.0.0_1 yolları** içeriyor. SFML farklı bir dizine veya sürüme kuruluysa derlemeden önce `CMakeLists.txt` içindeki `SFML_DIR` ve include dizinini güncelle.

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
