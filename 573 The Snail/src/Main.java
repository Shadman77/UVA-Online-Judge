import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int height, climb, fall, fatigue;// fatigue is in percentage
		Scanner scanner = new Scanner(System.in);
		for (;;) {
			height = scanner.nextInt();
			if (height == 0)
				break;
			climb = scanner.nextInt();
			fall = scanner.nextInt();
			fatigue = scanner.nextInt();
			days(height, climb, fall, fatigue);
		}
		scanner.close();
	}

	public static void days(int height, int climb, int fall, int fatigue) {
		double heightClimbed = 0;
		double climbRate = climb;
		double decreaseRate = ((climbRate / 100) * fatigue);
		int days = 1;
		boolean attempt = false;
		for (;;) {
			heightClimbed += climbRate;
			if (heightClimbed > (double) height) {
				attempt = true;
				break;
			}
			heightClimbed -= fall;
			if (heightClimbed < 0) {
				attempt = false;
				break;
			}
			if(climbRate > 0)
			climbRate = climbRate - decreaseRate;
			days++;
		}
		if(attempt==true) 
			System.out.println("success on day "+days);
		else
			System.out.println("failure on day "+days);
	}

}
