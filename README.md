# aoj

C++17 用の AOJ (Aizu Online Judge) ローカル実行環境です。

## 必要なもの

- `make`
- `g++`

## 使い方

新しい問題ファイルを作成します。

```sh
./aoj n ITP1_1_A
```

解答は `problems/<PROBLEM>.cpp` に置きます。

テストケースが 1 つだけなら、従来通り次のファイルを使えます。

```text
samples/<PROBLEM>.in
samples/<PROBLEM>.out
```

テストケースが複数ある場合は、次のように置きます。

```text
samples/<PROBLEM>/1.in
samples/<PROBLEM>/1.out
samples/<PROBLEM>/2.in
samples/<PROBLEM>/2.out
```

`make new` / `./aoj n` は `samples/<PROBLEM>/1.in` と
`samples/<PROBLEM>/1.out` を作成します。

ビルドして実行します。

```sh
./aoj r ITP1_1_A
```

期待出力と比較します。

```sh
./aoj t ITP1_1_A
```

複数ケースがある場合は、対象問題の全ケースをまとめて実行します。

サニタイザ付きで実行します。

```sh
./aoj d ITP1_1_A
```

## 自作 C++ ライブラリ

GitHub 上のヘッダライブラリは `lib/` に取得して使います。

```sh
./aoj lib git@github.com:USER/REPOSITORY.git
```

取得後は、`include/`、`lib/`、`lib/REPOSITORY/`、
`lib/REPOSITORY/include/` が自動で include パスに入ります。
たとえば `lib/cp-library/data_structure/segtree.hpp` がある場合は、
次のように書けます。

```cpp
#include "cp-library/data_structure/segtree.hpp"
```

取得先ディレクトリ名を指定したい場合は、第 2 引数を使います。

```sh
./aoj lib git@github.com:USER/REPOSITORY.git lib/cp-library
```

ブランチを指定したい場合は、第 3 引数を使います。

```sh
./aoj lib git@github.com:USER/REPOSITORY.git lib/cp-library main
```

取得先ディレクトリを省略してブランチだけ指定する場合は、`--branch` を使います。

```sh
./aoj lib git@github.com:USER/REPOSITORY.git --branch main
```

インストール済みの Git ライブラリをまとめて更新するには、次を実行します。

```sh
./aoj update-lib
```

特定のライブラリだけを更新する場合は、`lib/` 配下の名前またはパスを指定します。

```sh
./aoj update-lib cp-library
# または
./aoj update-lib lib/cp-library
```

更新は `git pull --ff-only` で行われます。ローカルの変更があるライブラリや、
追跡先ブランチが設定されていないライブラリは安全のため更新しません。
更新されたヘッダは次回のビルド時に自動検出されます。

## 提出コード生成

AOJ に提出する前に、自作ライブラリの include を展開した単一ファイルを生成できます。
`#include "cp/io.hpp"` と `#include <cp/io.hpp>` のどちらも、ローカルライブラリに
見つかるものは展開します。標準ライブラリの include はそのまま残します。

```sh
./aoj s ITP1_4_A
```

生成先は `submit/ITP1_4_A.cpp` です。生成したコードはクリップボードにもコピーされます。
問題名を省略した場合は、最後に更新された `problems/*.cpp` を使います。

クリップボードへのコピーには、WSL の `clip.exe`、macOS の `pbcopy`、または Linux の
`wl-copy` / `xclip` / `xsel` のうち利用可能なものを使います。コピーできない環境でも
提出ファイルの生成は完了します。

`make` から直接実行する場合は次の通りです。

```sh
make s PROBLEM=ITP1_4_A
```

問題名を省略すると、最後に更新された `problems/*.cpp` を使います。

```sh
./aoj t
./aoj r
```

Bash の Tab 補完を使う場合は、最初に読み込みます。

```sh
source completion/aoj.bash
```

その後は次のように補完できます。

```sh
./aoj t ITP<Tab>
```

`make` を直接使う場合も短縮ターゲットを使えます。

```sh
make t PROBLEM=ITP1_1_A
make r PROBLEM=ITP1_1_A
make d PROBLEM=ITP1_1_A
```

## ディレクトリ

- `template.cpp`: 新規問題用テンプレート
- `problems/`: AOJ に提出する C++ ファイル
- `samples/`: ローカルテスト用の入力・期待出力
- `build/`: ビルド成果物

## 例

`problems/ITP1_1_A.cpp` は動作確認用の Hello World です。
