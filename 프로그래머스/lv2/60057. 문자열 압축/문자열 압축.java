import java.io.*;
import java.util.*;

class Pair{
	
	String s;
	int cnt;
	Pair(String s,int cnt){
		this.s = s;
		this.cnt = cnt;
	}
	
	
}

class Solution {
    public int solution(String s) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int answer = 1000000;
        
      
        
        
        int s_size = s.length();
        int slice_size = 1;
    
        
        for(int i = slice_size; i <=s.length(); i++) {
        	
        	Pair [] pairs = new Pair[1001];
        	int idx = 0;
        	
        	for(int j = 0; j <s.length();j += i) {
        		String tmp = "";
        		for(int k = j; k < j + i; k++) {
        			
        			if(k >= s.length())
        				break;
        			
        			tmp = tmp + s.charAt(k);
 
        			
        		}
        		if(j == 0) {
        			pairs[idx] = new Pair(tmp,1);
        			
        		}else {
        			
        			if(!pairs[idx].s.equals(tmp)) {
        				idx++;
        				pairs[idx] = new Pair(tmp,1);
        			}else {
        				pairs[idx].cnt = pairs[idx].cnt + 1;
        			}
        			
        		}
        		
        	}
        	String ans = "";
        	
        	for(int a = 0; a<= idx; a++) {
        		if(pairs[a].cnt != 1) {
        			ans = ans + Integer.toString((pairs[a].cnt)) + pairs[a].s;
        		}else {
        			ans = ans + pairs[a].s;
        		}
        		
        	} 	
        	answer = Math.min(answer, ans.length());
        	    	
        }
        
            
            
        
        
        
        
        
        
        return answer;
    }
}