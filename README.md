*This project has been created as part of the 42 curriculum by swaragay, ttatsuno.*


# Push_swap — Adaptive Sorting with Two Stacks

## Description
`push_swap` は、2つのスタック（`a` と `b`）と制限された一連の操作命令（`sa`, `pb`, `ra` など）のみを使用し、ランダムに与えられた整数列を最小の手数（操作回数）でソートするプログラムです。
本プロジェクトでは、アルゴリズムの時間・空間複雑度（Big-O）の深い理解と、与えられた入力データの「無秩序度（Disorder Metric）」に応じて最適なアルゴリズムを動的に選択する**適応型アルゴリズム（Adaptive Algorithm）**の実装を目的としています。

---

## Technical Choices & Algorithms
本プログラムは、実行時にスタックの「無秩序度（Disorder）」を以下の数式（0.0〜1.0）に基づいて算出します。

$$\text{disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}$$

算出された無秩序度に応じて、以下の4つのアルゴリズム（すべてC言語による自作）を動的に切り替えます。

### 1. Simple Algorithm ($O(n^2)$)
* **選択フラグ**: `--simple`
* **使用アルゴリズム**: `選択ソート`
* **解説と空間・時間計算量**:
  `未確定の要素を比べて最小値（or 最大値）をみつけて並び替える`
  * stack_aの数字をすべて比べて最小値を探す.
ex:（n-1）,(n-2)　数字の部分が確定した数字の数
  * 最小値を先頭持ってきてｂに移動
`操作数を減らすために`
先頭からのindexをつけ、過半数以下なら上に１つずつ先頭に持っていく
過半数なら下から先頭に持っていく

### 2. Medium Algorithm ($O(n\sqrt{n})$)
* **選択フラグ**: `--medium`
* **使用アルゴリズム**: `$\sqrt{n}$ 個のチャンク分割ソート`
* **解説と空間・時間計算量**:
  探索する数を√ｎ個ずつに分ける
  ex: ノードが１００の場合＝$\sqrt{10}$　
  探索する数字を10個ずつに分ける　0~9/10~19/20~29/30~39/40~49/50~59/60~69/70~79/80~89/90~99
  stack_aを探索してまず0~9内の数字（座標圧縮されたインデックス）をさがす
  みつけたらstack_bにいれていく

  `操作数を減らすために`
ｂに送る際に数を数えてその数が偶数だった場合は上に奇数だった場合はraをして下に入れる

### 3. Complex Algorithm ($O(n \log n)$)
* **選択フラグ**: `--complex`
* **使用アルゴリズム**: `基数ソート(Radix Sort)`
* **解説と空間・時間計算量**:
各数字の1bitの数字を比べてソートしていく
1→stack_aのまま（raをして先頭を変える）
0→stack_bに移動
すべてのノードが比べ終わったらbに入っているものを上からaに戻す
/>>右シフトしてビットを１つずらす
再度０１で振り分ける
それを座標圧縮の最大値のbit数分繰り返す

### 4. Custom Adaptive Algorithm (デフォルト)
* **選択フラグ**: `--adaptive` (またはフラグなし時のデフォルト挙動)
* **設計思想と閾値の正当性**:
  無秩序度に応じて以下の閾値で上記の各アルゴリズムを呼び出します。
  * **Low disorder ( $< 0.2$ )**: $O(n^2)$ の手法を適用。
  * **Medium disorder ( $0.2 \le \text{disorder} < 0.5$ )**: $O(n\sqrt{n})$ の手法を適用。
  * **High disorder ( $\ge 0.5$ )**: $O(n \log n)$ の手法を適用。

---

## Contribution & Collaboration
* **[ttatsuno]**:
  * 担当範囲: `[例: Complex（Radix/Quick）アルゴリズムの実装、Adaptive選択ロジック、デバッグ用チェッカー、テストスクリプトの作成]`
* **[swaragay]**:
  * 担当範囲: `READMEの作成。`


---

## Instructions

### Compilation
プロジェクトのビルドには `cc` と `Makefile` を使用します。
```bash
# 必須パート（push_swap）のビルド
make

# ボーナスパート（checker）のビルド（該当する場合のみ）
make bonus

# クリーンアップ
make clean
make fclean
make re

```

### Execution

```bash
# デフォルト（Adaptive）モードでの実行
./push_swap 2 1 3 6 5 8

# フラグを使用しての実行
./push_swap --simple 1 4 2 3 5
./push_swap --medium 10 4 2 9 1
./push_swap --complex 4 67 3 87 23

# エラーケースの挙動（標準エラー出力に "Error" を出力）
./push_swap 3 2 3

```

### Benchmark Mode (`--bench`)

`--bench` フラグを有効にすると、ソート用の命令（標準出力）に加えて、以下の分析メトリクスを **標準エラー出力** に出力します。

```bash
$ ARG="4 67 3 87 23"; ./push_swap --bench $ARG 2> bench.txt \vert{} ./checker$ARG
OK
$ cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0

```

---

## Resources & AI Usage

### References & Resources

* Donald Knuth, *The Art of Computer Programming* (Big-O Notation and Sorting Algorithms)
* **[ttatsuno]**:
* **[swaragay]**:
  * [ソートアルゴリズム](https://www.study-pg.com/c4-basic/bit-shifts-operators/)
  * [計算量](https://tukumolog.com/what-is-computational-complexity/)
  * [座標圧縮の解説](https://algo-logic.info/coordinate-compress/) `min_index`
  * [選択ソート](https://ja.wikipedia.org/wiki/%E9%81%B8%E6%8A%9E%E3%82%BD%E3%83%BC%E3%83%88) `simple(選択ソート)`
  * [チャンクソート](https://www.linkedin.com/pulse/push-swap-art-sorting-two-stacks-anass-outiskte-bjsje) `medium(チャンクソート)`
  * [基数ソートの仕組み](https://tukumolog.com/radix-sort-introduction/) `complex(基数ソート)`
  * [ビットシフトとシフト演算子の基本](https://www.study-pg.com/c4-basic/bit-shifts-operators/) `complex(基数ソート)　bit演算の処理`
### AI Tool Usage Disclosure
* **使用したタスク**:
* `READMEの枠組み作成`
