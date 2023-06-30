# 映像メディア通信特論 (Advanced Visual Media Communications)
名古屋工業大学大学院

第２クオーター，金曜5-6限 (Q2 Fri: 5-6)

担当教員：福嶋　慶繁 (Norishige Fukushima)

# 1. イントロダクション (Introduction)

課題無し (No short report)

# 2. 情報源符号化 (Information Source Coding)
## 課題 (Short Report)

ディレクトリ構成 (Directory Structure)
+ [data_2/data](./data_2/data)
+ [data_2/entropy](./data_2/entropy)

### data
圧縮するデータと7zの圧縮コマンドラインツール（windows用）が入っている)

#### Usage for 7z
[7-Zip Zstandard Edition](https://github.com/mcmilk/7-Zip-zstd)
An extended project from 7-zip, which can use zstd,zh4, zh5, lizard, fast LZMA2, Brotli

+ 7za.exe
+ 7za.dll
+ 7zxa.dll
+ 7z/License.txt
+ 7z/history.txt
+ 7z/readme.txt

圧縮レベル9（最高圧縮）でPPMdアルゴリズムを使ってマルチスレッド（最大コア数）で圧縮
```
7za.exe a output.7z 0-open.dll -mx1 -mm=PPMd -mmt=8
```

圧縮レベル1（最高速）でzstandardアルゴリズムを使って8スレッドで圧縮
```
7za.exe a output.7z 0-open.dll -mx1 -mm=zstd -mmt=8
```

デフォルトの7-zipで使えるアルゴリズム
LZMA, PPMd, BZip2, Deflate, BCJ, BCJ2, Copy
LZMA: mx 0(copy), 1(fastest),3,5,7,9(ultra compressing)

追加で使えるアルゴリズム
zstd, lz4, lz5, lizard, fast LZMA2, Brotli

### entropy
コマンドラインで計算するエントロピーの計算プログラムが入っている．コンパイル済みのものはwindows用

#### Usage for entropy.exe
```
entropy.exe file_name
```
出力は，入力サイズ，エントロピー，エントロピーに基づく理想的な圧縮結果の情報．

sourceはバイナリファイルを生成したVisual Studio2015のプロジェクトファイル
Linux でもentropy.cppをgcc/g++でコンパイルが通る．

# 3. 画像符号化1 (Image coding 1)
[データダウンロード](./data_3/data_3.zip)

ディレクトリ構成 (Directory Structure)
+ [data_3/data_3.zip


画像が9種類入っている．

# 4. 画像符号化2 (Image coding 2)

# 5. 映像符号化1 (Video coding 1)

# 6. 映像符号化2 (Video coding 2)
 課題無し (No short report)

# 7. 映像符号化3 (Video coding 3)

