/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while( T > 0 ){
		    int[] dp = new int[9];
		    boolean winnerX = false;
		    boolean winnerO = false;
		    int countX=0,countO=0;
		    for(int i = 0 ; i < 3 ; i++ ){
		        String str = sc.next();
		        for(int j=0;j<3;j++){
		            char ch = str.charAt(j);
		            if(ch == 'X'){
		                dp[i*3+j] = 1;
		                countX++;
		            }
		            if(ch == 'O'){
		                dp[i*3+j] = 0;
		                countO++;
		            }
		            if(ch == '_'){
		                dp[i*3+j] = -1;
		            }
		        }
		    }
		    // for rows
		    for(int i=0;i<3;i++){
		        if((dp[i*3+0]==1 && dp[i*3+1]==1 && dp[i*3+2]==1)){
		            winnerX = true;
		        }
		        if((dp[i*3+0]==0 && dp[i*3+1]==0 && dp[i*3+2]==0)){
		            winnerO = true;
		        }
		    }
		    
		    // column
		    for(int i=0;i<3;i++){
		            if(dp[i+0]==1 && dp[i+3]==1 && dp[i+6]==1){
		                winnerX = true;
		            }
		            if(dp[i+0]==0 && dp[i+3]==0 && dp[i+6]==0){
		              //  if(winnerO==true){
		              //      winnerX = true;
		              //  }
		                winnerO = true;
		            }
		    }
		    
		    // normal diag
		    if(dp[0]==1 && dp[4]==1 && dp[8]==1){
		      //  if(winnerX==true){
		      //      winnerO = true;
		      //  }
		        winnerX = true;
		    }
		    if(dp[0]==0 && dp[4]==0 && dp[8]==0){
		      //  if(winnerO==true){
		      //      winnerX = true;
		      //  }
		        winnerO = true;
		    }
		    
		    // reverse diag
		    if(dp[2]==1 && dp[4]==1 && dp[6]==1){
		      //  if(winnerX==true){
		      //      winnerO = true;
		      //  }
		        winnerX = true;
		    }
		    if(dp[2]==0 && dp[4]==0 && dp[6]==0){
		      //  if(winnerO==true){
		      //      winnerX = true;
		      //  }
		        winnerO = true;
		    }
		    if((countX+countO==9 && countX-countO==1 && winnerX == false && winnerO == false) || (winnerX==true && winnerO == false && countX-countO==1) || (winnerO==true && winnerX==false && countX-countO==0)){
		        System.out.println(1);
		    }
		    else if(countX+countO<9 && winnerX == false && winnerO == false && (countX-countO==1 || countX-countO==0)){
		        System.out.println(2);
		    }
		    else{
		        System.out.println(3);
		    }
		    T--;
		}
	}
}