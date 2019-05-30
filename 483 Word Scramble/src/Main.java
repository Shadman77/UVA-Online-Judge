import java.util.Scanner;

public class Main {

	static String question, answer, buffer;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext()) {
			question = scanner.nextLine();
			convert();
		}
		scanner.close();
	}

	public static void convert() {
		buffer = "";
		answer = "";
		for (int i = 0; i < question.length(); i++) {
			if (question.charAt(i) == ' ') {
				answer += (new StringBuilder(buffer).reverse().toString());
				answer += " ";
				buffer = "";
			} else {
				buffer += question.charAt(i);
			}
		}
		
		answer += (new StringBuilder(buffer).reverse().toString());
		
		System.out.println(answer);
	}

}
