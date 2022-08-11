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
レベル9でPPMdアルゴリズムを使ってマルチスレッドで圧縮
```
7z.exe a output.7z input.txt –mx9 -mm=PPMd –mmt=on
```

レベル0でzstandardアルゴリズムを使ってマルチスレッドで圧縮
```
7z.exe a output.7z input.txt –mx0 -mm=zstd –mmt=on
```

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

# 4. 画像符号化2 (Image coding 2)

# 5. 映像符号化1 (Video coding 1)

# 6. 映像符号化2 (Video coding 2)
 課題無し (No short report)

# 7. 映像符号化3 (Video coding 3)

