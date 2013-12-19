import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			int rows = 0;
			int cols = 0;
			if(scan.hasNextLine()) {
				String info = scan.nextLine();
				if("".equals(info.trim())) {
					scan.close();
					return;
				}
				String[] infoArr = info.split("\\s+");
				rows = Integer.parseInt(infoArr[0]);
				cols = Integer.parseInt(infoArr[1]);
			} 
			String[][] pAgeArr = getData(scan, rows, cols);
			boolean isHavePoint = false;
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
					isHavePoint = true;
					System.out.println((i + 1) + " " + (maxRowIndexList.get(k) + 1));
					if(k == maxRowIndexList.size() - 1) {
						System.out.println();
					}
				}
			}
			
			if(!isHavePoint) {
				System.out.println("No Point");
				System.out.println();
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

	private static String[][] getData(Scanner scan, int rows, int cols) {
		List<String[]> lineList = new ArrayList<String[]>();
		String[][] dataArr = null; 
		int rowCount = 0;
		while(scan.hasNextLine() && rowCount < rows) {
			rowCount++;
			String oneLine = scan.nextLine();
			if("0".equals(oneLine.trim())) {
				break;
			}
			String[] oneLineArr = oneLine.split("\\s+");
			if(oneLineArr.length != cols) {
				throw new RuntimeException("colum num is not equal to " + cols);
			}
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
