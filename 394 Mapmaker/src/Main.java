import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, r;
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();// number of arrays
		r = scanner.nextInt();// number of references
		String arrayName[] = new String[n];
		int base[] = new int[n];
		int bytes[] = new int[n];
		int dimension[] = new int[n];
		int lowerBound[][] = new int[n][];
		int upperBound[][] = new int[n][];
		for (int i = 0; i < n; i++) {// scanning the arrays
			arrayName[i] = scanner.next();
			base[i] = scanner.nextInt();
			bytes[i] = scanner.nextInt();
			dimension[i] = scanner.nextInt();
			lowerBound[i] = new int[dimension[i]];
			upperBound[i] = new int[dimension[i]];
			for (int j = 0; j < dimension[i]; j++) {
				lowerBound[i][j] = scanner.nextInt();
				upperBound[i][j] = scanner.nextInt();
			}
		}
		int index;
		int c[];
		int cO;
		int id[];// indexes of the reference
		int finalAnswer;
		String refference;
		for (int i = 0; i < r; i++) {// working on the references
			refference = scanner.next();
			index = stringMatching(refference, arrayName, n);// n is the number of total arrays
			id = indexOfRefference(dimension[index], scanner);
			c = cd(lowerBound[index], upperBound[index], dimension[index], bytes[index]);// all values of cd
			cO = co(lowerBound[index], dimension[index], base[index], c, bytes[index]);
			finalAnswer = answer(cO, dimension[index], c, id, bytes[index]);
			System.out.printf("%s[%d", arrayName[index], id[0]);
			for (int l = 1; l < dimension[index]; l++) {
				System.out.printf(", %d", id[l]);
			}
			System.out.printf("] = %d\n", finalAnswer);
		}
	}

	public static int stringMatching(String ref, String[] arrayNames, int n) {// to get the correct array
		for (int i = 0; i < n; i++) {
			if (ref.equals(arrayNames[i]))
				return i;
		}
		return -1;
	}

	public static int[] cd(int lowerBound[], int upperBound[], int dimension, int bytes) {// returns all cds from 1<=d<D
		try {
		int answer[] = new int[dimension - 1];// one less than d
		answer[dimension - 2] = bytes * (upperBound[dimension - 1] - lowerBound[dimension - 1] + 1);// starting from
																										// last value
		for (int i = dimension - 3; i >= 0; i--) {// from D-2 to 1
			answer[i] = answer[i + 1] * (upperBound[i + 1] - lowerBound[i + 1] + 1);// this formula seems to be
																					// correct!!
		}
		return answer;
		}catch(Exception exception) {
			return new int[0];
		}
	}

	public static int co(int lowerBound[], int dimension, int base, int cd[], int bytes) {
		int sum = base;
		for (int i = 0; i < dimension - 1; i++) {// from 0 to D-1
			sum -= (cd[i] * lowerBound[i]);
		}
		sum -= (bytes * lowerBound[dimension - 1]);
		return sum;
	}

	public static int answer(int co, int dimension, int cd[], int indexes[], int bytes) {// will directly scan the
																				// values of i from
																				// reference
		int sum = 0;
		sum += co;
		for (int i = 0; i < dimension - 1; i++) {// from 0 to D-1
			sum += (cd[i] * indexes[i]);// cd * index
		}
		sum += (bytes * indexes[dimension - 1]);// cD*index
		return sum;
	}

	public static int[] indexOfRefference(int dimension, Scanner scanner) {// scans the indexes of the references
		int indexes[] = new int[dimension];
		for (int i = 0; i < dimension; i++) {
			indexes[i] = scanner.nextInt();
		}
		return indexes;
	}
}
