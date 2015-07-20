package enmu;

/**
 * 求一个点可以消灭更多的敌人 map.txt 是敌人分布图 #是强 .是空地 G是敌人
 */
public class BoomPosi {
	public static void main(String[] args) {
		char[][] a = new char[14][14];
		 a[1] = "#############".toCharArray();
		 a[2] = "#GG.GGG#GGG.#".toCharArray();
		 a[3] = "###.#G#G#G#G#".toCharArray();
		 a[4] = "#.......#..G#".toCharArray();
		 a[5] = "#G#.###.#G#G#".toCharArray();
		 a[6] = "#GG.GGG.#.GG#".toCharArray();
		 a[7] = "#G#.#G#.#.###".toCharArray();
		 a[8] = "##G...G.....#".toCharArray();
		 a[9] = "#G#.#G###.#G#".toCharArray();
		a[10] = "#...G#GGG.GG#".toCharArray();
		a[11] = "#G#.#G#G#.#G#".toCharArray();
		a[12] = "#GG.GGG#G.GG#".toCharArray();
		a[13] = "#############".toCharArray();
		int i, j, sum=0, max=0, x, y,p=0,q=0;
		// 下面求出一个炸弹点使得消灭的敌人最多
		for (i = 1; i <= 13; i++) {
			for (j = 0; j <= 12; j++) {
				if (a[i][j] == '.') {// 当前必须为空地
					sum = 0;
					x = i;
					y = j;
					//先往上搜索
					while(a[x][y]!='#'){
						if(a[x][y]=='G')
							sum++;
						x--;
					}
					
					x = i;
					y = j;
					//先往下搜索
					while(a[x][y]!='#'){
						if(a[x][y]=='G')
							sum++;
						x++;
					}
					
					x = i;
					y = j;
					//先往左搜索
					while(a[x][y]!='#'){
						if(a[x][y]=='G')
							sum++;
						y--;
					}
					
					x = i;
					y = j;
					//先往右搜索
					while(a[x][y]!='#'){
						if(a[x][y]=='G')
							sum++;
						y++;
					}
					
					if(sum>max){
						max = sum;
						p = i;
						q = j;
					}
				}
			}
		}
		System.out.println("在点"+p +","+(q+1)+"处能消灭更多敌人为:"+max);
	}
}
