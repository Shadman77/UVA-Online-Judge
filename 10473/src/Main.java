import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		String question = "0";// initializing to 0 to prevent compiler error
		for (;;) {
			question = scanner.nextLine();
			question.toUpperCase();
			if (question.charAt(0) == '-')// program should terminate
				break;
			else {// should process
				if (question.length() > 1) {
					if (question.charAt(1) == 'x') {// if question is a octal
						toDecimal(question);
					} else {// if question is a decimal (length greater than 1)
						toHexadecimal(question);
					}
				} else {// if question is a decimal (just one digit)
					toHexadecimal(question);
				}
			}
		}
		scanner.close();
	}

	public static void toDecimal(String question) {// remember that in the case of base x to y conversion decimal can be
													// an intermediary
		long decimal = 0;
		int buffer, j = 0;
		for (int i = question.length() - 1; i > 1; i--) {
			if (question.charAt(i) <= '9') {
				buffer = question.charAt(i) - '0';
			} else {
				buffer = question.charAt(i) - 'A' + 10;
			}
			decimal += buffer * Math.pow(16, j);
			j++;
		}
		System.out.println(decimal);
	}

	public static void toHexadecimal(String question) {
		long buffer = 0;// the decimal value will be here
		char bufferChar = '0';
		int bufferMod;
		buffer = Long.parseLong(question);
		String answer = "";// the final answer will be stored here
		for (;;) {
			if (buffer == 0)
				break;
			bufferMod = (int) buffer % 16;
			if (bufferMod > 9) {
				bufferChar = 'A';
				bufferChar += (bufferMod - 10);// 10 = A
			} else {
				bufferChar = '0';
				bufferChar += bufferMod;
			}
			answer = String.format("%s%c", answer, bufferChar);
			buffer /= 16;
		}

		System.out.printf("0x");
		for (int i = answer.length() - 1; i >= 0; i--) {
			System.out.printf("%c", answer.charAt(i));
		}
		System.out.println();
	}
}
