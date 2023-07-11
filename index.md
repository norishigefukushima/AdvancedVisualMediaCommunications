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

# 4. 画像符号化2 (Image Coding 2)
[データダウンロード](./data_4/data_4.zip)

# 5. 映像符号化1 (Video Coding 1)

[データとffmpegダウンロード](./data_5/data_5.zip)

# 6. 映像符号化2 (Video Coding 2)
 課題無し (No short report)

# 7. 映像符号化3 (Video Coding 3)

## libhief
[libhief](https://github.com/strukturag/libheif)は，HEIFフォーマットを扱うためのライブラリです．
libhief.libなどを使って，様々な言語からHEIFのIOを実現するために使います．
libheifを使っている代表的なライブラリとしては下記のものが上げられます．
* GIMP
* ImageMagick


ここでは，そのライブラリを使った，付随する以下のコマンドラインツールの使い方を解説します．

* [heif-enc](https://www.mankier.com/1/heif-enc): エンコーダ
* [heif-convert](https://www.mankier.com/1/heif-convert): デコーダ

Windows用のVisual Studio 2022 Communityでコンパイル済みのバイナリを下記用意します．

[ダウンロード](./heiftools.zip)

### heif-encの使い方（簡易版）

一番シンプルな使い方は下記になります．入力画像lena.pngを圧縮して，lena.heifを出力します．
```
heif-enc lena.png
```

出力ファイル名を指定する場合は下記になります．この場合，out.heifを出力します．
```
heif-enc -o out.heif lena.png
```

品質パラメータまで指定したい場合は下記になります．品質60で出力します．デフォルトは50で0-100の値が指定可能です．
```
heif-enc -o out.heif -q 60 lena.png
```

### heif-encの使い方（詳細版）

オプションとして下記のものを指定できます．
* -q: クオリティ設定（説明済み）で0（最小）-100（最大）（デフォルト50）の範囲で設定可能です．
* -v: 詳細情報を表示します．
* -p: パラメータの詳細を指定します．

例えば-vを指定して下記コマンドを打つと次が出力され，どのようなアルゴリズムを使ったか，エンコードの時間，圧縮のビットなどの情報が分かります．

コマンド
```
heif-enc -v lena.png
```

出力
```console
x265 [info]: HEVC encoder version 3.5+103-8f18e3a
x265 [info]: build info [Windows][MSVC 1936][64 bit] 8bit
x265 [info]: using cpu capabilities: MMX2 SSE2Fast LZCNT SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
x265 [info]: Main Still Picture profile, Level-3 (Main tier)
x265 [debug]: detected NUMA node 0 with 8 logical cores
x265 [debug]: NUMA node 0 may use 8 logical cores
x265 [debug]: NUMA node 1 may use 0 logical cores
x265 [info]: Thread pool created using 8 threads
x265 [info]: Slices                              : 1
x265 [info]: frame threads / pool features       : 3 / wpp(8 rows)
x265 [warning]: Source height < 720p; disabling lookahead-slices
x265 [info]: Coding QT: max CU size, min CU size : 64 / 8
x265 [info]: Residual QT: max TU size, max depth : 32 / 1 inter / 2 intra
x265 [info]: ME / range / subpel / merge         : star / 57 / 3 / 3
x265 [info]: Lookahead / bframes / badapt        : 0 / 0 / 0
x265 [info]: b-pyramid / weightp / weightb       : 0 / 0 / 0
x265 [info]: References / ref-limit  cu / depth  : 1 / off / off
x265 [info]: AQ: mode / str / qg-size / cu-tree  : 1 / 1.0 / 32 / 0
x265 [info]: Rate Control / qCompress            : CRF-25.0 / 0.60
x265 [info]: tools: rect amp rd=4 psy-rd=1.00 rdoq=2 psy-rdoq=1.00 signhide
x265 [info]: tools: tmvp strong-intra-smoothing deblock sao
x265 [info]: frame I:      1, Avg QP:22.82  kb/s: 237.16

encoded 1 frames in 0.16s (6.33 fps), 237.16 kb/s, Avg QP:22.82
```

-pのパラメータには下記等が設定できます．
* preset, default=slow, { ultrafast,superfast,veryfast,faster,fast,medium,slow,slower,veryslow,placebo }
* tune, default=ssim, { psnr,ssim,grain,fastdecode }
* tu-intra-depth, default=2, [1;4]
* x265
* complexity, [0;100]
* chroma, default=420, { 420,422,444 }

例えば下記コマンドは，詳細を表示し(-v)，品質を40に設定し(-q)，プリセットにfastオプションを設定し(-p preset=fast)，また，SSIMを高めるパラメータチューンを行い（-p tune=ssim），presetやtuneで設定されたオプションを上書きするようにx265を呼び出すために，x265:no-strong-intra-smoothing=1でstrong-intra-smoothing(SIS)を無効化し，-p x265:no-deblock=1でデブロッキングフィルタを使用しないように設定し，-p x265:sao=0でサンプルアダプティブオフセットを切ります．また，x265:psnr=1や -p x265:ssim=1で-vオプションで表示する情報にPSNRやSSIMを加えます．
```
heif-enc -v -q 40 -p preset=fast -p tune=ssim -p x265:no-strong-intra-smoothing=1 -p x265:no-deblock=1 -p x265:sao=0 -p x265:psnr=1 -p x265:ssim=1 lena.png
```

出力は下記になります．
```
x265 [info]: HEVC encoder version 3.5+103-8f18e3a
x265 [info]: build info [Windows][MSVC 1936][64 bit] 8bit
x265 [info]: using cpu capabilities: MMX2 SSE2Fast LZCNT SSSE3 SSE4.2 AVX FMA3 BMI2 AVX2
x265 [warning]: --psnr used with psy on: results will be invalid!
x265 [warning]: --tune psnr should be used if attempting to benchmark psnr!
x265 [info]: Main Still Picture profile, Level-3 (Main tier)
x265 [debug]: detected NUMA node 0 with 8 logical cores
x265 [debug]: NUMA node 0 may use 8 logical cores
x265 [debug]: NUMA node 1 may use 0 logical cores
x265 [info]: Thread pool created using 8 threads
x265 [info]: Slices                              : 1
x265 [info]: frame threads / pool features       : 3 / wpp(8 rows)
x265 [warning]: Source height < 720p; disabling lookahead-slices
x265 [info]: Coding QT: max CU size, min CU size : 64 / 8
x265 [info]: Residual QT: max TU size, max depth : 32 / 1 inter / 2 intra
x265 [info]: ME / range / subpel / merge         : hex / 57 / 2 / 2
x265 [info]: Lookahead / bframes / badapt        : 0 / 0 / 0
x265 [info]: b-pyramid / weightp / weightb       : 0 / 0 / 0
x265 [info]: References / ref-limit  cu / depth  : 1 / off / off
x265 [info]: AQ: mode / str / qg-size / cu-tree  : 1 / 1.0 / 32 / 0
x265 [info]: Rate Control / qCompress            : CRF-30.0 / 0.60
x265 [info]: tools: rect amp rd=2 psy-rd=1.00 signhide tmvp fast-intra
x265 [info]: frame I:      1, Avg QP:27.82  kb/s: 126.74    PSNR Mean: Y:36.899 U:40.140 V:39.832  SSIM Mean: 0.936291 (11.958dB)

encoded 1 frames in 0.06s (15.62 fps), 126.74 kb/s, Avg QP:27.82, Global PSNR: 37.670, SSIM Mean Y: 0.9362913 (11.958 dB)
```

x265に関する詳細オプションは，下記でで確認できます．
[https://x265.readthedocs.io/en/stable/presets.html](https://x265.readthedocs.io/en/stable/presets.html)

complexityは，大きいほど圧縮オプションが重たいものを選ぶようになりますが，意味合いがtuneやpresetとかぶります．どちらかでオプションが上書きされるため，一方を指定するだけで良いでしょう（詳細については検証していませんが）．

HEIFはロスレス圧縮も可能ですがここでは詳細は割愛します．

### heif-convertの使い方
下記コマンドでhiefをpngに変換できます．
```
heif-convert out.heif out.png
```

対応している出力フォーマットは，jpeg, png, y4mです．
なお，JPEGにする意味は薄いので共有しているexeには，JPEG機能を追加していません．

### libheifのVisual Studio 2022でのコンパイル用のメモ
まず，下記ライブラリをコンパイルします．全てcmakeでslnが作れます．
* zlib
* libpng
* libde265
* x265

次にlibheifをcmakeでslnを作ってコンパイルします．その時に上記をコンパイルしたヘッダやlibのディレクトリを教えてあげます．
その後ビルドします．
その際，zlib, libpng, x265, libde265のリンクオブジェクトの指定やディレクトリが抜けているので（おそらく環境変数に指定しないとうまくslnを作ってくれない），プロジェクトファイルに追加してコンパイルしてください．