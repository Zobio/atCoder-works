import java.util.Scanner;

public class Sample {

  public static void main(String[] args) {

    // Scannerクラスのインスタンスを作成
    // 引数で標準入力System.inを指定する
    Scanner scanner = new Scanner(System.in);

    // 入力を促すメッセージ
    System.out.print("入力してください > ");

    //入力された内容をインスタンスから取得
    String input_text = scanner.nextLine();

    //入力された内容を画面に表示
    System.out.println(input_text + "が入力されました");

    // Scannerクラスのインスタンスをクローズ
    scanner.close();

  }

}