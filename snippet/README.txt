各ファイル説明

modify_to_json_body.exe : txtファイルを読み込んで、C++のjsonファイル(cpp.json)のbody部分の書式に変換してくれるプログラム。コマンド打っても起動させてもいいし、そのままダブルクリックして使ってもいい。
modify_to_json_body.cpp : そのソースコード
modify_to_json_body.txt : 変換したいテキストを保存しておくファイル
modified_to_json_body.txt : 変換先

注意 : テキストファイルの名前を変えると作動しなくなるので注意。また、実行ファイルとテキストファイルが同じディレクトリにないと正常に実行されないので注意。

modified_to_json_body.txtに変換したら、Tabスペースを通常のスペースに変更する必要がある。
方法:Tabスペースを範囲選択して、Ctrl+H --> "置換後の文字列"にスペースを4つ打って、"すべて置換"をクリック