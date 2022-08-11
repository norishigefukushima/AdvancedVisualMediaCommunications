# 映像メディア通信特論の第２回情報源符号化概論の課題用ファイル
## ディレクトリ構成    
+ data (圧縮するデータと7zの圧縮コマンドライン（windows用）が入っている)
+ entropy（エントロピーの計算プログラムが入っている）

## 7zによる圧縮コマンドサンプル
### レベル9でPPMdアルゴリズムを使ってマルチスレッドで圧縮
7z.exe a output.7z input.txt –mx9 -mm=PPMd –mmt=on

### レベル0でzstandardアルゴリズムを使ってマルチスレッドで圧縮
7z.exe a output.7z input.txt –mx0 -mm=zstd –mmt=on

