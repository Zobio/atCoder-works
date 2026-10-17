## 用途
WindowsとMac間でのatCoder用ファイルの管理

## ABC用C++ファイルの作成

リポジトリのルートで次のように実行すると、`work` フォルダにA〜Eの5ファイルを作成し、VS Codeの同じウィンドウで開きます。

```sh
python3 work/create_abc.py 480
```

ファイルの内容には、VS CodeのC++ユーザースニペット `include` の本文を使います。既存ファイルは上書きしません。VS Code CLIが見つからない場合はファイルだけ作成し、エラーを表示します。ファイルの作成だけを行い、VS Codeで開かない場合は `--no-open` を付けてください。
