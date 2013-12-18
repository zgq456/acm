import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class PlayGroundDance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String[][] pAgeArr = getData();
		for (int i = 0; i < pAgeArr.length; i++) {
			List<Integer> maxRowIndexList = getMaxRowIndex(pAgeArr[i]);
//			System.out.println("maxRowIndexList1:" + maxRowIndexList);
			int size = maxRowIndexList.size();
			for (int j = size - 1; j >= 0; j--) {
				for (int j2 = 0; j2 < pAgeArr.length; j2++) {
					Integer targetColumn = maxRowIndexList.get(j);
					int oneColumnAge = Integer.parseInt(pAgeArr[j2][targetColumn]);
					int targetAge = Integer.parseInt(pAgeArr[i][targetColumn]);
					if(oneColumnAge < targetAge) {
						maxRowIndexList.remove(j);
						break;
					}
				}
			}
//			System.out.println("maxRowIndexList2:" + maxRowIndexList);
			for (int k = 0; k < maxRowIndexList.size(); k++) {
				System.out.println((i + 1) + " " + (maxRowIndexList.get(k) + 1));
			}
		}
	}

	private static List<Integer> getMaxRowIndex(String[] rowArr) {
		List<Integer> maxRowIndexList = new ArrayList<Integer>();
	    int max = 0; 
		for (int i = 0; i < rowArr.length; i++) {
			int oneAge = Integer.parseInt(rowArr[i]);
			if(oneAge > max) {
				//judge whether to clear existed list
				if(!maxRowIndexList.isEmpty()) {
					maxRowIndexList.clear();
				}
				max = oneAge;
				maxRowIndexList.add(i);
			} else if(oneAge == max) {
				maxRowIndexList.add(i);
			}
		}
		return maxRowIndexList;
	}

	private static String[][] getData() {
		List<String[]> lineList = new ArrayList<String[]>();
		String[][] dataArr = null; 
		Scanner scan = new Scanner(System.in);
		while(scan.hasNextLine()) {
			String oneLine = scan.nextLine();
			if("0".equals(oneLine.trim())) {
				break;
			}
			String[] oneLineArr = oneLine.split("\\s+");
			lineList.add(oneLineArr);
		}
		int lineCount = lineList.size();
		dataArr = new String[lineCount][];
		for (int i = 0; i < lineCount; i++) {
			dataArr[i] = lineList.get(i);
		}
		
		
		return dataArr;
	}

}
