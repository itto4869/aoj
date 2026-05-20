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
