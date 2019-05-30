import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/* THERE SEEMS TO BE AN OVERALL PROBLEM WITH THE RANGE! */
	public static void main(String[] args) {
		// http://codeforces.com/contest/913/problem/C
		long typesOfBottles, volumeNeeded;// this is also act as the size of the array of prices
		long[] prices = new long[30];// prices of respective bottles
		long[] index = new long[30];// quantity of each bottle selected
		int[] sortedTypes = new int[30];// sorted types of bottles arranged from lowest per liter price

		Scanner scanner = new Scanner(System.in);

		// scanning the questions
		while (scanner.hasNext()) {
			typesOfBottles = scanner.nextLong();
			volumeNeeded = scanner.nextLong();
			for (int i = 0; i < typesOfBottles; i++) {
				prices[i] = scanner.nextLong();
				index[i] = -1;
			}

			// calculating the answer
			sort(prices, sortedTypes, index, typesOfBottles);// sorting bottles in terms of price per liter
			System.out.println(lowestCost(prices, sortedTypes, index, typesOfBottles, volumeNeeded));// final answer
		}
		scanner.close();
	}

	public static BigInteger lowestCost(long[] prices, int[] sortedTypes, long[] index, long typesOfBottles,
			long volumeNeeded) {
		BigInteger lowestCost = new BigInteger("0");
		long buffer, buffer2;
		BigInteger buffer3 = new BigInteger("0");

		// starting with the lowest price per liter bottle and moving onwards
		buffer = (long) Math.pow(2, sortedTypes[0]);// volume of first one bottle
		index[sortedTypes[0]] = (volumeNeeded / buffer);// finding roughly the number of bottles needed
		if ((buffer * index[sortedTypes[0]]) < volumeNeeded) {// checking if current volume is enough
			index[sortedTypes[0]]++;// if not enough then adding another bottle
		}
		
		lowestCost = BigInteger.valueOf(prices[sortedTypes[0]]).multiply(BigInteger.valueOf(index[sortedTypes[0]]));
		// initial lowest price

		// checking all other possible configuration
		for (int a = 1; a < typesOfBottles; a++) {
			// check if there is any extra volume
			buffer = 0;
			for (int b = 0; b < typesOfBottles; b++) {
				buffer += ((long) Math.pow(2, b) * index[b]);// the total volume we have now
			}

			if (volumeNeeded == buffer)
				break;// ends since we have our lowest possible cost!

			// breaks apart and gets smaller bottles
			index[sortedTypes[a - 1]]--;// minus one bottle of the previous type
			buffer = buffer - (long) Math.pow(2, sortedTypes[a - 1]);// the volume after losing a bottle of previous
																		// type

			buffer2 = (long) Math.pow(2, sortedTypes[a]);// volume of one current type of bottle

			buffer = volumeNeeded - buffer;// the volume that we need to add
			index[sortedTypes[a]] = buffer / buffer2;// adding the required (or -1) bottles of this type
			if ((buffer2 * index[sortedTypes[a]]) < buffer) {// if we need to add another bottle
				index[sortedTypes[a]]++;// adding another bottle
			}

			// get the price
			buffer3 = BigInteger.valueOf(0);// initializing
			for (int b = 0; b < typesOfBottles; b++) {
				buffer3 = buffer3.add(BigInteger.valueOf(prices[b]).multiply(BigInteger.valueOf(index[b])));
				// total price with current configuration
			}
			// lowestCost = buffer3;// then setting this as the lowest price
			if (buffer3.compareTo(lowestCost) == -1)// if this is the lowest price
				lowestCost = buffer3;// then setting this as the lowest price
		}

		return lowestCost;// the final answer
	}

	public static void sort(long[] prices, int[] sortedTypes, long[] index, long typesOfBottles) {
		double[] respectivePricePerV = new double[(int) typesOfBottles];
		double bufferLargestPosVal = Math.pow(10, 9) + 1;

		// sorting from lowest per liter price of the bottle to the highest price

		for (int i = 0; i < typesOfBottles; i++) {
			respectivePricePerV[i] = prices[i] / Math.pow(2, i);// getting price per liter of all bottles
		}

		int tempType = 0;
		double minimum;
		for (int i = 0; i < typesOfBottles; i++) {
			minimum = bufferLargestPosVal;// initializing minimum
			for (int j = 0; j < typesOfBottles; j++) {
				if (index[j] == -1) {// if the bottle is already not added in the sorted list
					if (respectivePricePerV[j] < minimum) {// if this is the new minimum per liter price
						minimum = respectivePricePerV[j];// sets the new minimum
						tempType = j;// stores the bottle in a buffer tempType
					}
				}

			}
			sortedTypes[i] = tempType;// adds the lowest per liter price bottle of this iteration to the sorted list
			index[tempType] = 0;// marks that the type has been added to the sorted list

		}
	}
}
